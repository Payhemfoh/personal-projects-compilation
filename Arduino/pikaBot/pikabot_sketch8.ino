#define IR_LEFT A0
#define IR_RIGHT A1

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_LEFT,INPUT);
  pinMode(IR_RIGHT,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("LEFT:");
  Serial.print(digitalRead(IR_LEFT));
  Serial.print("\tRight:");
  Serial.println(digitalRead(IR_RIGHT));
}
