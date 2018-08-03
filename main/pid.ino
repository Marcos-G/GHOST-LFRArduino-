float kp=0.0;float ki=0.0;float kd=0.0;
float ep=0.0;float ei=0.0;float ed=0.0;
float pos=6.0;
float preve=0.0;
float setpoint=6.0;
void setPidClock(){
  setearTimer50htz();
}
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
  pidCalc();
}
void pidCalc(){
  sensado();
  float e=pos-setpoint;
  ep=e*kp;
  ed=(e-preve)*kd;
  preve=e;
}
