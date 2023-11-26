#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <math.h>
#include <string>

const double MASS = 100.0;
const double SOUND_SPEED = 0.034;
const long TIME_INTERVAL = 500;
const long SERIAL_CHANNEL = 9600;
const int SONIC_TRIG_PIN = D6;
const int SONIC_ECHO_PIN = D5;
const int LED = D7;
const int SPEED_COUNT = 10;


const char* SSID = "";
const char* PASSWORD = "";
const char* AIO_SERVER = "io.adafruit.com";
const int AIO_SERVER_PORT = 1883;
#define AIO_USERNAME ""
const char* AIO_KEY = "";


WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVER_PORT,AIO_USERNAME,AIO_KEY);
Adafruit_MQTT_Subscribe btnState = Adafruit_MQTT_Subscribe(&mqtt,AIO_USERNAME"/feeds/led");
Adafruit_MQTT_Publish* velocity_publisher = NULL;
Adafruit_MQTT_Publish* momentum_publisher = NULL;

void MQTT_connect();
double getDistance(double duration);
double getDuration();
double calcVelocity(double distance1,double distance2);
double calcMomentum(double velocity);
void sendDataToMQTT(double velocity,double momentum);
void resetPublisher(Adafruit_MQTT_Publish** publisher);

void setup() {
  Serial.begin(SERIAL_CHANNEL);

  pinMode(SONIC_TRIG_PIN,OUTPUT);
  pinMode(SONIC_ECHO_PIN,INPUT);
  pinMode(LED,OUTPUT);
  
  Serial.printf("Connecting to WiFi with SSID %s\n",SSID);
  WiFi.begin(SSID,PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.printf("Successfully connected to WiFi %s\n",SSID);
  mqtt.subscribe(&btnState);
}

void loop() {
  MQTT_connect();
  //get distance, velocity, momentum
  static double distance1 = 0.0;
  static double distance2 = 0.0;
  static double velocity = 0.0;
  static double velocity_array[SPEED_COUNT] = {0.0};
  static double momentum = 0.0;
  static int velocity_counter = 0;
  long interval = 0;
  Adafruit_MQTT_Subscribe* read;

  //check if btn state is changed in cloud
  if(read = mqtt.readSubscription(5000)){
    if(read == &btnState){
      String msg = (const char*)btnState.lastread;
      Serial.println(msg);
      if(msg.indexOf("ON") != -1)
        digitalWrite(LED,HIGH);
      else if(msg.indexOf("OFF") != -1)
        digitalWrite(LED,LOW);
    }
  }

  //read velocity and send to cloud if led is on
  if(digitalRead(LED) == HIGH){
    distance1 = distance2;
    distance2 = getDistance(getDuration());
    if(distance1 != 0 || distance2 != 0){
      velocity_array[velocity_counter++] = calcVelocity(distance1,distance2);
      //store the velocity in array and get average after fixed number of reading
      if(velocity_counter == SPEED_COUNT){
        //get average from velocity_array
        for(int i=0;i<SPEED_COUNT;++i){
          velocity += velocity_array[i];
          velocity_array[i] = 0.0;
        }
        velocity /= SPEED_COUNT;
        momentum = calcMomentum(velocity);
        Serial.printf("Velocity:%.2f,Momentum:%.2f\n",velocity,momentum);
        velocity_counter = 0;
  
        //send data to mqtt
        resetPublisher(&velocity_publisher);
        resetPublisher(&momentum_publisher);
        
        if(velocity<10){
          velocity_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/low-velocity.velocity-gauge");
          momentum_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/low-velocity.momentum-gauge");
        }
        else if(velocity<30){
          velocity_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/medium-velocity.velocity-gauge");
          momentum_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/medium-velocity.momentum-gauge");
        }
        else{
          velocity_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/high-velocity.velocity-gauge");
          momentum_publisher = new Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/high-velocity.momentum-gauge");
        }
  	  
        if(!velocity_publisher  || !velocity_publisher->publish(velocity) || !momentum_publisher || !momentum_publisher->publish(momentum)){
          Serial.println("Failed to sent value");
        }
        else{
          Serial.println("value had been sent to mqtt");
        }
      
        if(!mqtt.ping())
          mqtt.disconnect();
        
  	    resetPublisher(&velocity_publisher);
        resetPublisher(&momentum_publisher);
      }
    }
  }
}

void MQTT_connect(){
  if(mqtt.connected())
    return;

  Serial.println("Connecting to MQTT...");
  int tries = 3;
  while(mqtt.connect() != 0){
    Serial.println("Retry MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);
    if(--tries == 0)
      while(true);
  }
  Serial.println("Connected to MQTT Server.");
}

double getDistance(double duration){
  return (1/2.0 * duration * SOUND_SPEED);
}

//get duration from ultrasonic sensor
double getDuration(){
  digitalWrite(SONIC_TRIG_PIN,LOW);
  delayMicroseconds(5);
  digitalWrite(SONIC_TRIG_PIN,HIGH);
  delayMicroseconds(5);
  digitalWrite(SONIC_TRIG_PIN,LOW);
  return pulseIn(SONIC_ECHO_PIN,HIGH);
}

//compute velocity
double calcVelocity(double distance1,double distance2){
  return ((distance1 - distance2)/ (TIME_INTERVAL/1000.0));
}

//calculate momentum
double calcMomentum(double velocity){
  return (velocity * MASS);
}

void resetPublisher(Adafruit_MQTT_Publish** publisher){
	if(*publisher){
        delete *publisher;
        *publisher = NULL;
    }
}
