void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==HIGH){
    digitalWrite(5,HIGH);
  }else
    digitalWrite(5,LOW);
}
