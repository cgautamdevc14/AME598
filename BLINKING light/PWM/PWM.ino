int led_pin = 22;
int led_pin1 = 21;
void setup() {
  //Declaring LED pin as output
  pinMode(led_pin, OUTPUT);
}
void loop() {
  //Fading the LED
    digitalWrite(led_pin, LOW);
        digitalWrite(led_pin1, LOW);
    delay(3);

    digitalWrite(led_pin, HIGH);
        digitalWrite(led_pin1, HIGH);

    delay(20);
}
