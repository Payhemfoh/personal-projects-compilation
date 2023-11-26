#include "SerialMonitor.h"

SerialMonitor::SerialMonitor(){
  Serial.begin(COM_CHANNEL);
  Serial.setTimeout(TIMEOUT);

  if(Serial)
	print("Device connected");
}

void SerialMonitor::print(String text){
  Serial.print(text);
}

void SerialMonitor::print(int text){
  Serial.print(text);
}