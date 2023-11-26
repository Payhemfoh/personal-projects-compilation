#include "CytronMotorDriver.h"

int main(){
  init();
  bool repeat = true;
  CytronMD moterLeft(PWM_PWM,11,10);
  CytronMD moterRight(PWM_PWM,9,3);

  while(repeat){
    moterLeft.setSpeed(200);
    moterRight.setSpeed(200);
    delay(1000);

    moterLeft.setSpeed(0);
    moterRight.setSpeed(0);
    delay(500);

    moterLeft.setSpeed(-200);
    moterRight.setSpeed(-200);
    delay(2000);

    moterLeft.setSpeed(0);
    moterRight.setSpeed(0);
    delay(500);
  }
}
