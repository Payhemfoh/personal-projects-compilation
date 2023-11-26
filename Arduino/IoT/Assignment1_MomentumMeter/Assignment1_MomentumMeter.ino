#include <ESP8266WiFi.h>
#include <math.h>

const double SOUND_SPEED = 0.034;
const long TIME_INTERVAL	= 1000;
const long SERIAL_CHANNEL = 9600;
const int SONIC_TRIG_PIN = D6;
const int SONIC_ECHO_PIN = D5;

const char* SSID = "UOW Malaysia KDU";
const char* PASSWORD = "kdu@batu-kawan";
const int PORT = 80;
const double MASS = 208;

WiFiServer server(PORT);

//calculate distance from duration
double getDistance(double duration){
	double distance = 1/2.0 * duration * SOUND_SPEED;
	return distance;
}

//get duration from ultrasonic sensor
double getDuration(){
	digitalWrite(SONIC_TRIG_PIN,LOW);
	delayMicroseconds(5);
	digitalWrite(SONIC_TRIG_PIN,HIGH);
	delayMicroseconds(5);
	digitalWrite(SONIC_TRIG_PIN,LOW);
	double duration = pulseIn(SONIC_ECHO_PIN,HIGH);
	return duration;
}

//compute velocity
double calcVelocity(double distance1,double distance2){
	double travelled = distance1 - distance2;
	double velocity = travelled / (TIME_INTERVAL/1000.0);
	return velocity;
}

//calculate momentum
double calcMomentum(double velocity){
	double momentum = 0.0;
	momentum = velocity * MASS;
	return momentum;
}

//send data to client
void sendDataToClient(WiFiClient& client,double velocity,double momentum){
  double abs_velocity = abs(velocity);
	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text/html");
	client.println("");
	client.println("<!DOCTYPE html>");
	client.println("<html lang='en'>");
	client.println("<head>");
	client.println("<title>Momentum Meter</title>");
	client.println("<meta charset='utf-8'>");
	client.println("</head>");
	client.println("<body>");
	client.println("<h1>ID: Car01</h1>");
	client.printf("<p>Mass: %.2f Gram</p>\n",MASS);
	client.printf("<p>Velocity: %.2f cm/s</p>\n",velocity);
	client.printf("<p>Momentum: %.2f gcm/s</p>\n",momentum);
	client.println("<p>Status: ");
  if(abs_velocity<1){
    client.println("Rest,");
  }
  else if(abs_velocity<5){
    client.println("Slow Speed,");
  }
  else if(abs_velocity<15){
    client.println("Medium Speed,");
  }
  else{
    client.println("High Speed,");
  }
  if(MASS<50){
    client.println("Light Weight");
  }
  else if(MASS < 100){
    client.println("Normal Weight");
  }
  else{
    client.println("Over Weight");
  }
  client.println("</p>");
  client.println("<script>setTimeout(()=>{window.location.reload();},1000)</script>");
	client.println("</body></html>");
	
	return;
}

void setup(){
	//setup serial channel
	Serial.begin(SERIAL_CHANNEL);
	
	if(Serial)
		Serial.println("Serial Connected!");
	
	pinMode(SONIC_TRIG_PIN,OUTPUT);
	pinMode(SONIC_ECHO_PIN,INPUT);
	
	//connect to wifi
	WiFi.begin(SSID,PASSWORD);
	
	Serial.printf("Trying to connect to WiFi connection : %s\n",SSID);
	
	while(WiFi.status() != WL_CONNECTED){
		delay(1000);
		Serial.println("Retry Connection");
	}
	
	//setup wifi server
	server.begin();
	Serial.printf("server started at port %d\n",PORT);
	
	Serial.printf("Successfully connected to WLAN %s\n",SSID);
	Serial.printf("URL : http://%s/\n",WiFi.localIP().toString().c_str());
}

void loop(){
  static double distance1 = 0.0;
  static double distance2 = 0.0;
  static double velocity = 0.0;
  static double momentum = 0.0;
  long interval = 0;

  distance1 = distance2;
  distance2 = getDistance(getDuration());
  if(distance1 != 0 || distance2 != 0){
    velocity = calcVelocity(distance1,distance2);
    momentum = calcMomentum(velocity);
    
    Serial.printf("Distance 1: %.2f\n",distance1);
    Serial.printf("Distance 2: %.2f\n",distance2);
    Serial.printf("Velocity : %.2f\n",velocity);
    Serial.printf("Momentum : %.2f\n",momentum);
    
  }
  delay(TIME_INTERVAL);
  
	//read distance
	WiFiClient client = server.available();

  if(!client)
    return;
	
	while(!client.available()){
    delay(1);
	}
 
	//print request message from client
	String request = client.readStringUntil('\r');
	Serial.println(request);
	client.flush();
	
	sendDataToClient(client,velocity,momentum);
  client.stop();
  return;
}
