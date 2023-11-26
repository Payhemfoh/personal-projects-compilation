#include <ESP8266WiFi.h>
#include <math.h>

//user preference
const char* ID = "Car02"; //another set ID is "Car01" with MASS = 208
const double MASS = 198;
const long TIME_INTERVAL  = 1000;
const long SERIAL_CHANNEL = 9600;

//constant
const double SOUND_SPEED = 0.034;
const int SONIC_TRIG_PIN = D6;
const int SONIC_ECHO_PIN = D5;

//wireless setup
const char* SSID = "";
const char* PASSWORD = "";
const int PORT = 80;

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

//compute velocity with formula of distance travelled(cm) / time passed(s)
double calcVelocity(double distance1,double distance2){
	double travelled = distance1 - distance2;
	double velocity = travelled / (TIME_INTERVAL/1000.0);
	return velocity;
}

//calculate momentum by velocity (cm/s) * mass (g)
double calcMomentum(double velocity){
	double momentum = 0.0;
	momentum = velocity * MASS;
	return momentum;
}

//send data to client in html format
void sendDataToClient(WiFiClient& client,double velocity,double momentum){
  double abs_velocity = abs(velocity);
	client.println(F("HTTP/1.1 200 OK"));
	client.println(F("Content-Type: text/html"));
	client.println(F(""));
	client.println(F("<!DOCTYPE html><html lang='en'>"));
	client.println(F("<head><title>Momentum Meter</title><meta charset='utf-8'></head>"));
	client.println(F("<body>"));
	client.printf("<h1>ID: %s</h1>",ID);
	client.printf("<p>Mass: %.2f Gram</p>\n",MASS);
	client.printf("<p>Velocity: %.2f cm/s</p>\n",velocity);
	client.printf("<p>Momentum: %.2f gcm/s</p>\n",momentum);
	client.println(F("<p>Status: "));
  //send status based on finite state machine in format of speed, mass
  if(abs_velocity<1){
    client.print(F("Rest,"));
  }
  else if(abs_velocity<5){
    client.print(F("Slow Speed,"));
  }
  else if(abs_velocity<15){
    client.print(F("Medium Speed,"));
  }
  else{
    client.print(F("High Speed,"));
  }
  
  if(MASS<100){
    client.print(F("Light Weight"));
  }
  else if(MASS < 200){
    client.print(F("Normal Weight"));
  }
  else{
    client.print(F("Over Weight"));
  }
  client.println(F("</p>"));
  client.println(F("<script>setTimeout(()=>{window.location.reload();},1000)</script>"));
	client.println(F("</body></html>"));
	
	return;
}

void setup(){
	//setup serial channel
	Serial.begin(SERIAL_CHANNEL);
	
	if(Serial)
		Serial.println("Serial Connected!");

  //setup pinmode for ultrasonic sensor
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
  static long interval = 0;
  
	WiFiClient client = server.available();

  if(!client)
    return;
	
	while(!client.available()){
    //read data every second while no client connected
    if(interval >= TIME_INTERVAL){
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
      interval = 0;
    }
    ++interval;
    delay(1);
	}
 
	//print request message from client
	String request = client.readStringUntil('\r');
	Serial.println(request);
	client.flush();

  //send data to client then disconnect client to prevent heap overflow
	sendDataToClient(client,velocity,momentum);
  client.stop();
  return;
}
