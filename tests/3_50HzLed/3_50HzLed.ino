void setearTimer50htz(){
  noInterrupts(); // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;
  OCR3A = 1250; // compare match register 16MHz/256/50Hz (20016micros)
  TCCR3B |= (1 << WGM32); // CTC mode
  TCCR3B |= (1 << CS32 ); // 256 prescaler
  TIMSK3 |= (1 << OCIE3A); // enable timer compare interrupt
  interrupts();
}
ISR(TIMER3_COMPA_vect) // timer compare interrupt service routine
{
  digitalWrite(38,!digitalRead(38));                     // wait for a second
}
void setup() {
  // put your setup code here, to run once:
  pinMode(38, OUTPUT);
setearTimer50htz();
}

void loop() {
  // put your main code here, to run repeatedly:

}
