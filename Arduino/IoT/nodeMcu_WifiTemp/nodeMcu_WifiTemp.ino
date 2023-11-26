#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include "Async.h"
#include "Led.h"
#include "SerialMonitor.h"
#include "Sensor.h"

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 32;
const int RESET = -1;
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,RESET);
SerialMonitor sm;
Led l(D8,&sm);
Sensor sensor(D6);
const char* ssid = "";
const char* password = "";
WiFiServer server(80);

int interval = 4000;
  int timer = 0;
  int sensorStatus = 0;

void displayText(String text){
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.cp437(true);  //ASCII

  display.print(text);
  display.display();
}

void setup(){

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("SSD1306 allocation failed\n");
    for(;;);
  }

  displayText("Loading...");
  delay(1000);

  WiFi.begin(ssid,password);
  sm.print("Start to connect to Server\n");
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Retry Connection");
    delay(500);
  }
  server.begin();

  Serial.printf("Success to connect to WLAN %s \n",ssid);
  
  Serial.println("Server started at port 80 \n");
  Serial.printf("URL=http://%s/\n",WiFi.localIP().toString().c_str());
}

void loop(){
  WiFiClient client = server.available();
  if(!client) return;
  
  while(!client.available()){
    if(timer >= interval){
      if(sensorStatus%2==0)
        displayText(String("Humidity\n")+String(sensor.getHumidity())+String(" %"));
      else
        displayText(String("Temp\n")+String(sensor.getTemperature())+String((char)248)+String(" C"));
      timer = 0;
      ++sensorStatus;
    }
    
    l.increaseInterval();
    timer +=1;
    delay(1);
  }
  
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if(request.indexOf("/LED=ON") != -1){
    l.On();
    l.blinking(false);
  }
  else if(request.indexOf("/LED=OFF") != -1){
    l.Off();
    l.blinking(false);
  }
  else if(request.indexOf("/BLINK=TRUE") != -1){
    l.blinking(true);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html lang='en'><head><title>ESP8266</title><meta charset='utf-8'></head>");
  client.printf(String(String("<body><h1>Welcome to ESP8266</h1>")+
  String("Humidity: %.2f%<br>")+
  String("Temperature: %.2fC<br>")+
  String("Led : %s<br>")+
  String("<a href='LED=ON'><button>Turn On</button></a>")+
  String("<a href='LED=OFF'><button>Turn Off</button></a>")+
  String("</body></html>")).c_str(),sensor.getHumidity(),sensor.getTemperature(),l.getStatus()?"On":"Off");
  
  if(timer >= interval){
    if(sensorStatus%2==0)
      displayText(String("Humidity\n")+String(sensor.getHumidity())+String(" %"));
    else
      displayText(String("Temp\n")+String(sensor.getTemperature())+String((char)248)+String(" C"));
    timer = 0;
    ++sensorStatus;
  }
}
