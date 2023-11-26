#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "";
const char* pword = "";
const char* geoname_username = "";
WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid,pword);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  } 

  Serial.println("Wi-Fi connected!");  
}

void loop() {
  HTTPClient http;
  String url = String("http://api.geonames.org/findNearByWeatherJSON?lat=5.419484&lng=100.322610&username=")+geoname_username;
  http.begin(client,url.c_str()); //REST api request

  int httpcode = http.GET();

  if(httpcode == 200){
    String weatherJSON = http.getString();
    StaticJsonDocument<1000> doc;
    DeserializationError err = deserializeJson(doc,weatherJSON);
    if(err){
      //Serial.printf("Error: %s\n",err.c_str());
      return;
    }

    const char* countryCode = doc["weatherObservation"]["countryCode"];
    const char* stationName = doc["weatherObservation"]["stationName"];
    const char* dateTime = doc["weatherObservation"]["datetime"];
    float temperature = doc["weatherObservation"]["temperature"];
    float humidity = doc["weatherObservation"]["humidity"];
    float windSpeed = doc["weatherObservation"]["windSpeed"];
    double latitut = doc["weatherObservation"]["lat"];
    double lng = doc["weatherObservation"]["lng"];

    Serial.printf("Country code: %s\nStation name: %s\nDate Time: %s\n",countryCode,stationName,dateTime);
    Serial.printf("Temperature :%.2f\nHumidity : %.2f%%\nWind Speed: %.2f\nLocation:(%.6f,%.6f)\n",temperature,humidity,windSpeed,latitut,lng);
  }

  http.end();
  
  delay(10000);
  
  
}
