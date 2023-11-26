void setup(){
  pinMode(4,OUTPUT);
  pinMode(2,INPUT_PULLUP);
}

void loop(){
  if(digitalRead(2) == LOW)
    digitalWrite(4,HIGH);
  else
    digitalWrite(4,LOW);
}
