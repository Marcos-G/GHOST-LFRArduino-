void setearTimer20htz(){
  noInterrupts(); // disable all interrupts
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4 = 0;
  OCR4A = 3125; // compare match register 16MHz/256/20Hz (20016micros)
  TCCR4B |= (1 << WGM42); // CTC mode
  TCCR4B |= (1 << CS42 ); // 256 prescaler
  TIMSK4 |= (1 << OCIE4A); // enable timer compare interrupt
  interrupts();
}
void sendState(){
  
  Serial1.println("Hola");
}
ISR(TIMER4_COMPA_vect) // timer compare interrupt service routine
{
  sendState();
}
void setup() {
Serial1.begin(115200);
delay(100);
pinMode(38,OUTPUT);
setearTimer20htz();
}
char output=' ';
void loop() {
  if(Serial1.available()>0){
      output=Serial.read();
      digitalWrite(38,!digitalRead(38));
  }

}
