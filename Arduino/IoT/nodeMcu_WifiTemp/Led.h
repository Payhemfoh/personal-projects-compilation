#ifndef Led_H
#define Led_H
#include "SerialMonitor.h"
#include "Async.h"

class Led : public Async{
  private:
	int pin;
	bool blink;
	bool bright;
	SerialMonitor* sm;

  public:
	Led(int pin, SerialMonitor* sm);

	void On();

	void Off();

	void blinking(bool status);

	bool getStatus();
	
	void intervalAction();
};
#endif