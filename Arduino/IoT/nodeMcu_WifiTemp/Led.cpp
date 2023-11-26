#include "Led.h"

Led::Led(int pin, SerialMonitor* sm)
  :pin(pin),sm(sm),blink(true),bright(true),Async::Async(2000)
{
  pinMode(pin,OUTPUT);
}

void Led::On(){
  digitalWrite(pin,HIGH);
  bright = true;
  sm->print("Led is switched on.\n");
}
	
void Led::Off(){
  digitalWrite(pin,LOW);
  bright = false;
  sm->print("Led is switched off.\n");
}

void Led::blinking(bool status){
  blink = status;
  sm->print(blink ? "blinking is enabled" : "blinking is disabled");
}

bool Led::getStatus(){
  return bright;
}

void Led::intervalAction(){
	if(this->blink == true){
		if(this->bright == true){
			this->Off();
		}
		else{
			this->On();
		}
	}
}