void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=100;i>=0;i-=5){
    analogWrite(5,i);
    delay(300);
  }
}
