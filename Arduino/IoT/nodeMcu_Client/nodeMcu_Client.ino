#include <ESP8266WiFi.h>

const char* ssid = "";
const char* password = "";

const char* host = "";
const int port = 80;
bool state = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("Start to connect to Server");

  while(WiFi.status() != WL_CONNECTED){
    Serial.println("Retry Connection");
    delay(500);
  }

  Serial.printf("Success to connect to WLAN %s\n",ssid);
  Serial.printf("URL=http://%s/\n",WiFi.localIP().toString().c_str());
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;

  if(!client.connect(host,port)){
    Serial.println("Server not found.");
    return;
  }

  //send request
  String request;
  if(state == false){
    request = "LED=ON";
    state = true;
  }
  else{
    request = "LED=OFF";
    state = false;
  }

  client.println(String("GET /")+request+ " HTTP/1.1\r\n" + "Host: "+host+ "\r\n"+"Connection: close\r\n\r\n");

  client.flush();

  delay(2000);
}
