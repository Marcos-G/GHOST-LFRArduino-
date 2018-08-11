float kp=0.0;float ki=0.0;float kd=0.0;
float ep=0.0;float ei=0.0;float ed=0.0;
float pos=60.0;
float preve=0.0;
float setpoint=60.0;
int et=0;
void setPidClock(){//para que sea mas bonito
  setearTimer50htz();
}
void setearTimer50htz(){//seteo de timer de 50khz con variables de registro
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
ISR(TIMER3_COMPA_vect) // rutina de interrupcion 3
{
  pidCalc();
}
void pidCalc(){ //calculo del pid
  sensado();//llamado a sensar
  float e=pos-setpoint;
  ep=e*kp;
  ed=(e-preve)*kd;
  preve=e;
  et=ep+ed;
  correccion(et);
}
