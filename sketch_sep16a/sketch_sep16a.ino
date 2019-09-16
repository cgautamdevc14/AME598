void setup() {
  pinMode(21,OUTPUT)
  pinMode(22,OUTPUT)

}

void loop() {
   digitalWrite(22, HIGH);
  digitalWrite(21, HIGH);
  delay(1800);
  digitalWrite(22, LOW);
  digitalWrite(21, LOW);
  delay(1200);

}
