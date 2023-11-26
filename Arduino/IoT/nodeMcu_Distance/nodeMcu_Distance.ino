const int TRIG_PIN = D5;
const int ECHO_PIN = D6;
long duration;
double distance;
long BR = 9600;
const double soundSpeed = 0.034;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BR);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);
  duration = pulseIn(ECHO_PIN,HIGH);
  
  distance = 1/2.0 * duration * soundSpeed;
  Serial.printf("Distance : %.2f\n",distance);
  delay(1000);
}
