/*
 * By: Payhemfoh
 * On: 14 March 2021
 * Function: the pikabot will move forward when powered on
 *           turn left 90 deg when detects obstacle within 20cm
 *           then continue to move forward until button is pressed
 */
#include "CytronMotorDriver.h"

//car class which represent the pikabot
class Car{
  private:
    const static int ECHOPIN = 4;
    const static int TRIGPIN = 5;
    int leftSpeed;
    int rightSpeed;
    CytronMD* motorLeft;
    CytronMD* motorRight;
  public:
    Car(){
      this->leftSpeed=0;
      this->rightSpeed=0;

      pinMode(TRIGPIN,OUTPUT);
      pinMode(ECHOPIN,INPUT);

      this->motorLeft = new CytronMD(PWM_PWM,11,10);
      this->motorRight = new CytronMD(PWM_PWM,9,3);
    }
    ~Car(){
      if(this->motorLeft)
        delete motorLeft;
      if(this->motorRight)
        delete motorRight;
    }
    int getLeftSpeed(){ return this->leftSpeed;}
    int getRightSpeed(){ return this->rightSpeed;}
    
    void setCarSpeed(int leftSpeed,int rightSpeed){
      this->leftSpeed = leftSpeed;
      this->rightSpeed = rightSpeed;
    }
    
    void stopCar(){
      this->leftSpeed = 0; 
      this->rightSpeed = 0;
    }
    
    void moveCar(){
        this->motorLeft->setSpeed(leftSpeed);
        this->motorRight->setSpeed(rightSpeed);
    }

    bool isStop(){
      return this->leftSpeed==0 && this->rightSpeed==0;
    }
    
    double getFrontObstacle(){
      //let the device send out sound wave
      digitalWrite(TRIGPIN,LOW);
      delayMicroseconds(2);
      digitalWrite(TRIGPIN,HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIGPIN,LOW);
  
      //catch the sound wave
      long duration = pulseIn(ECHOPIN,HIGH);
      return duration * 0.017;
    }
};

int main(){
  Car pikabot;
  const int BUTTON = 2;
  long distance = 0;

  pinMode(BUTTON,INPUT_PULLUP);
  //setup channel for communicate with pc
  Serial.begin(9600);

  bool loop = true;
  while(loop){
    distance = pikabot.getFrontObstacle();

    if(digitalRead(BUTTON)==LOW){
      if(pikabot.isStop())
        pikabot.setCarSpeed(200,200);
      else
        pikabot.stopCar();
    }
    else if(distance < 20){
      pikabot.setCarSpeed(0,200);  
    }
    else{
      pikabot.setCarSpeed(200,200);
    }
    
    pikabot.moveCar();
  }
  
  return 0;
}
