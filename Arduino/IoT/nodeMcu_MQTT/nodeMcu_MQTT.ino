#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

const char* SSID = "";
const char* pword = "";
const int LED = D6;

const char* AIO_SERVER = "io.adafruit.com";
const int AIO_SERVERPORT = 1883;
#define AIO_USERNAME ""
#define AIO_KEY ""

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);
Adafruit_MQTT_Subscribe btnState = Adafruit_MQTT_Subscribe(&mqtt,AIO_USERNAME"/feeds/led");
Adafruit_MQTT_Publish counter = Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME"/feeds/gauge");

float count = 0.0f;

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect(){
  pinMode(LED,OUTPUT);
  int8_t ret;

  // Stop if already connected.
  if(mqtt.connected())
  return;

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  
  while((ret = mqtt.connect()) != 0){ // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(10000); // wait 10 seconds
    retries--;
    
    if(retries == 0) while (1); // basically die and wait for WDT to reset me
  }
  Serial.println("MQTT Connected!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);

  Serial.println("Adafruit MQTT");
  WiFi.begin(SSID,pword);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WLAN CONNECTED");
  Serial.println();

  mqtt.subscribe(&btnState);
}

void loop() {
  // put your main code here, to run repeatedly:
  MQTT_connect();
  Adafruit_MQTT_Subscribe* read;
  while(read = mqtt.readSubscription(5000)){
    if(read == &btnState){
      String message = (const char*)btnState.lastread;
      Serial.print("Button State: ");
      Serial.println(message);
      if(message.indexOf("ON") != -1){
        digitalWrite(LED,HIGH);
      }
      else if(message.indexOf("OFF") != -1){
        digitalWrite(LED,LOW);
      }
    }
  }

  Serial.print("Send count value : ");
  Serial.print(count);
  Serial.println("...");
  if(!counter.publish(count++)){
    Serial.println("Failed to sent the value");
  }
  else{
    Serial.println("value had been sent to mqtt");
  }
  if(count>100)
    count = 0;

  if(!mqtt.ping()) mqtt.disconnect();
}
