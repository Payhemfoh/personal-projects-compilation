const int piezo = A0;
const int threshold = 100;

int sensorRead = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorRead = analogRead(piezo);  //0 to 1024
  //Serial.println(sensorRead);

  if(sensorRead >= threshold){
    Serial.println("Pressure detected");
    Serial.println(sensorRead);
  }

  delay(100);
}
