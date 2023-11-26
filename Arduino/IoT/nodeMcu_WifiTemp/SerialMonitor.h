#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H
#include <SoftwareSerial.h>

class SerialMonitor{
  private:
    const int COM_CHANNEL = 9600;
    const int TIMEOUT = 2000;
  public:
    SerialMonitor();

    void print(String text);

    void print(int text);
};

#endif