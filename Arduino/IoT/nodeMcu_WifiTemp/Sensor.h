#ifndef SENSOR_H
#define SENSOR_H
#include <DHT.h>

class Sensor{
  private:
    int pin;
    static const int DHTYPE = DHT22;
    DHT* dht;
  public:
    Sensor(int pin);

    ~Sensor();

    float getHumidity();

    float getTemperature();
};

#endif