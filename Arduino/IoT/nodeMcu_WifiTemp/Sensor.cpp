#include "Sensor.h"

Sensor::Sensor(int pin)
: pin(pin)
{
  dht = new DHT(pin,DHTYPE);
  dht->begin();
}

Sensor::~Sensor(){
  if(dht)
	delete dht;
}

float Sensor::getHumidity(){
  return dht->readHumidity();
}

float Sensor::getTemperature(){
  return dht->readTemperature();
}