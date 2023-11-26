#include "DHT.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

//declare constant values
const int LED = D8;
const int DHTPIN = D6;
const int DHTYPE = DHT22;
const int LEDFREQUENCY = 1000;
const int LOOPFREQUENCY = 100;
const int COM_CHANNEL = 9600;
const int TIMEOUT = 2000;
DHT dht(DHTPIN, DHTYPE);

//define screen size
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 32;
const int OLED_RESET = -1; //share with arduino board
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,OLED_RESET);

void DisplaySetting(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.cp437(true); //ASCII
}

void ledSetting(int led){
  if(led % 2 == 0){
    digitalWrite(LED,LOW);
  }
  else{
    digitalWrite(LED,HIGH);
  }
}

void displayHumidity(const float humidity){
  if(isnan(humidity)){
      Serial.println("Failed to read from DHT Sensor");
      return ;
    }
    else{
      DisplaySetting();
      display.print("Humidity\n");
      display.print(humidity);
      display.print(" %");
      display.display();
  
      Serial.print("Humidity :");
      Serial.println(humidity);
    }
}

void displayTemperature(const float temperature){
  if(isnan(temperature)){
      Serial.println("Failed to read from DHT Sensor");
      return ;
    }
    else{
      DisplaySetting();
      display.print("Temp\n");
      display.print(temperature);
      display.write(248);
      display.print("C");
      display.display();
    }
}


void setup(){
   //part 1 circuit feel free to delete
  pinMode(LED,OUTPUT);
  
  //part 2 code
  Serial.begin(COM_CHANNEL);
  Serial.setTimeout(TIMEOUT);
  if(Serial)
    Serial.println("Device connected");

  dht.begin();

  //start part 3 code
  //0x3C address to 128 x 32
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

  DisplaySetting();
  display.print("Loading...");
  display.display();
  delay(1000);
}

void loop(){
  static int timeSinceLastRead = 0;
  static int timeSinceLastLedModify = 0;
  static int ledOn = 0;
  static int displayStatus = 0;

  //deal with dht sensor
  if(timeSinceLastRead > 4000){
    displayStatus % 2 == 0 ?
    displayHumidity(dht.readHumidity()) :
    displayTemperature(dht.readTemperature());

    ++displayStatus;
    timeSinceLastRead = 0;
  }

  //part 1 circuit feel free to delete
  if(timeSinceLastLedModify > LEDFREQUENCY){
    ledSetting(ledOn);
  
    ledOn+=1;
    timeSinceLastLedModify = 0;
  }
  
  delay(LOOPFREQUENCY);
  timeSinceLastRead += LOOPFREQUENCY;
  timeSinceLastLedModify += LOOPFREQUENCY;
}
