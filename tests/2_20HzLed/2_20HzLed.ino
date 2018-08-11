void setearTimer20htz(){
  noInterrupts(); // disable all interrupts
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5 = 0;
  OCR5A = 3125; // compare match register 16MHz/256/20Hz (20016micros)
  TCCR5B |= (1 << WGM52); // CTC mode
  TCCR5B |= (1 << CS52 ); // 256 prescaler
  TIMSK5 |= (1 << OCIE5A); // enable timer compare interrupt
  interrupts();
}
ISR(TIMER5_COMPA_vect) // timer compare interrupt service routine
{
  digitalWrite(38,!digitalRead(38));                     // wait for a second
}
void setup() {
  // put your setup code here, to run once:
  pinMode(38, OUTPUT);
setearTimer20htz();
}

void loop() {
  // put your main code here, to run repeatedly:

}
