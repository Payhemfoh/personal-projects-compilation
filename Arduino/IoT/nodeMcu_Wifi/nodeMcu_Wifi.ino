#include <ESP8266WiFi.h>

const char* ssid = "Foh_Family 2.4G@unifi"; //Hotspot name
const char* password = "4709477a";
const int LED = D8;

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

  // setup and connect to WiFi
  WiFi.begin(ssid,password);

  Serial.println("Start to Connect to Server");
  
  //loop while not connected to WiFi
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Retry Connection");
  }

  //start the server at port 80
  server.begin();
  Serial.println("Server started at port 80");

  //print out success message
  Serial.printf("Success to connect to WLAN %s\n",ssid);
  Serial.printf("URL=http://%s/\n",WiFi.localIP().toString().c_str());
}

void loop() {
  //check if server is available
  WiFiClient client = server.available();
  if(!client) return;

  //wait until client connected
  while(!client.available()) delay(1);

  //print request message from client
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  //check request
  if(request.indexOf("/LED=ON") != -1){
    Serial.println("Led is switched on.");
    digitalWrite(LED,HIGH);
  }
  else if(request.indexOf("/LED=OFF") != -1){
    Serial.println("Led is switched off.");
    digitalWrite(LED,LOW);
  } 
}
