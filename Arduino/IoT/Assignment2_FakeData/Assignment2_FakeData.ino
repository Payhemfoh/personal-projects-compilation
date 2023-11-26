#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

const char* SSID = "Yafumin";
const char* PASSWORD = "4387137a";
const char* AIO_SERVER = "io.adafruit.com";
const int AIO_SERVER_PORT = 1883;
#define AIO_USERNAME "Yafumin"
const char* AIO_KEY = "aio_pOEY412pXt1CyBXeZoktVwPjrBF8";

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVER_PORT,AIO_USERNAME,AIO_KEY);
Adafruit_MQTT_Publish velocity_publisher = Adafruit_MQTT_Publish(&mqtt,"Yafumin/feeds/low-velocity.velocity-gauge");
Adafruit_MQTT_Publish momentum_publisher = Adafruit_MQTT_Publish(&mqtt,"Yafumin/feeds/low-velocity.momentum-gauge");

void MQTT_connect();
void sendDataToMQTT(double velocity,double momentum);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.printf("Connecting to WiFi with SSID %s\n",SSID);
  WiFi.begin(SSID,PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.printf("Successfully connected to WiFi %s\n",SSID);
}

void loop() {
  static float velocity = 30.0;
  const float step_value = 0.4;
  // put your main code here, to run repeatedly:
  MQTT_connect();

  
  if(velocity<=50){
    velocity_publisher.publish(velocity);
    momentum_publisher.publish(velocity*100);
    velocity += step_value;
  }
  
  if(!mqtt.ping())
    mqtt.disconnect();

  delay(5000);
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
