/*
 * By: Payhemfoh
 * On: 14 March 2021
 * Function: the pikabot will move forward when powered on
 *           turn left 90 deg when detects obstacle within 20cm
 *           then continue to move forward until button is pressed
 */
#include "CytronMotorDriver.h"

class Car{
  private:
    int leftSpeed;
    int rightSpeed;
  public:
    Car(){this->leftSpeed=0;this->rightSpeed=0;}
    int getLeftSpeed(){ return this->leftSpeed;}
    int getRightSpeed(){ return this->rightSpeed;}
    void setLeftSpeed(int speed){this->leftSpeed = speed;}
    void setRightSpeed(int speed){this->rightSpeed = speed;}
    void stop(){this->leftSpeed = 0; this->rightSpeed = 0;}
    void move(){}
};

int main(){
  const int ECHOPIN = 4;
  const int TRIGPIN = 5;
  long distance = 0,duration = 0;

  //setup pin mode
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  //setup channel for communicate with pc
  Serial.begin(9600);

  bool loop = false;
  while(loop){
    //let the device send out sound wave
    digitalWrite(TRIGPIN,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN,LOW);

    //catch the sound wave
    duration = pulseIn(ECHOPIN,HIGH);
    distance = duration * 0.017;

    if(distance < 20){
      
    }
    else{
      
    }
  }
  
  return 0;
}
