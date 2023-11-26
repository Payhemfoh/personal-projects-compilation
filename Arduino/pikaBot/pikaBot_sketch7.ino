/*
 * By: Yafumin
 * On: 16 May 2021
 * Function: pikabot will move forward when powered on
 *           and stop when detects obstacle or powered off
 *           
 * 
 */
#include "CytronMotorDriver.h"


class Car{
  private:
    int leftSpeed;
    int rightSpeed;
    CytronMD* motorLeft;
    CytronMD* motorRight;
  public:
    Car(){
      this->leftSpeed = 0;
      this->rightSpeed = 0;

      this->motorLeft = new CytronMD(PWM_PWM,11,10);
      this->motorRight = new CytronMD(PWM_PWM,9,3);
    }
    ~Car(){
      if(this->motorLeft)
        delete this->motorLeft;
      if(this->motorRight)
        delete this->motorRight;
    }
    
    void setCarSpeed(int left,int right){
      this->leftSpeed = left;
      this->rightSpeed = right;
    }
    
    void moveCar(){
      this->motorLeft->setSpeed(leftSpeed);
      this->motorRight->setSpeed(rightSpeed);
    }
    
    bool isStop(){return this->leftSpeed==0 && this->rightSpeed==0;}

};



#define IR_LEFT A0
#define IR_RIGHT A1
#define BUTTON 2
#define ECHOPIN 4
#define TRIGPIN 5
#define SERIALPORT 9600
unsigned long previous_time_counter = 0;
unsigned long previous_button_counter = 0;
unsigned long button_interval = 1000;
unsigned long sensor_reset_interval = 2000;
bool trig_active = true;
unsigned long sensor_active_interval = 12000;
long distance = 0;
Car pikabot;
  

void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  Serial.begin(SERIALPORT);
}

void loop() {
 //looping
    unsigned long current_time = millis();
    
    //check if button pressed
    if(digitalRead(BUTTON)==LOW){
      unsigned long passed = current_time - previous_button_counter;
      if(passed > button_interval){
        if(pikabot.isStop())
          pikabot.setCarSpeed(200,200);
        else
          pikabot.setCarSpeed(0,0);
        pikabot.moveCar();
        previous_button_counter = current_time;
      }
    }
    if(!pikabot.isStop()){
      unsigned long time_passed = current_time - previous_time_counter;
      if(time_passed < sensor_reset_interval ){
        digitalWrite(TRIGPIN,LOW);
        trig_active = false;
      }
      else if((time_passed < sensor_active_interval) && (trig_active == false)){
        digitalWrite(TRIGPIN,HIGH);
      trig_active = true;
      }
      else{
        digitalWrite(TRIGPIN,LOW);
      
        long duration = pulseIn(ECHOPIN,HIGH);
        distance = duration * 0.017;

        Serial.print("Distance : ");
        Serial.print(distance);
        Serial.println(" cm");

        if(distance>0 && distance < 15){
          pikabot.setCarSpeed(0,0);
          pikabot.moveCar();
        }
      
        trig_active = false;
        previous_time_counter = current_time;
      }

      if(!pikabot.isStop()){
        int left_sensor = digitalRead(IR_LEFT);
        int right_sensor = digitalRead(IR_RIGHT);

        if(left_sensor == 1 && right_sensor == 1){
          pikabot.setCarSpeed(0,0);
        }
        else if(left_sensor == 1){
          pikabot.setCarSpeed(-200,200);
        }
        else if(right_sensor == 1){
          pikabot.setCarSpeed(200,-200);
        }
        else{
          pikabot.setCarSpeed(200,200);
        }
        pikabot.moveCar();
      }
      
    }
}
