void setup() {
delay(2000);
pinMode(24,INPUT);
pinMode(38,INPUT);
}

void loop() {
digitalWrite(38,!digitalRead(24));
}
