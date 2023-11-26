#include "CytronMotorDriver.h"

int main(){
  init();
  bool repeat = true;
  CytronMD motorLeft(PWM_PWM,11,10);
  CytronMD motorRight(PWM_PWM,9,3);

  while(repeat){
    motorLeft.setSpeed(-100);
    motorRight.setSpeed(100);
    delay(5000);
    motorLeft.setSpeed(0);
    motorRight.setSpeed(0);
    repeat = false;
  }
}
