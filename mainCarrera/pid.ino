


double ep=0.0;double ei=0.0;double ed=0.0;

double pos=60.0;
double preve=0.0;
double prevpos=60.0;
double setpoint=60.0;
unsigned long medTime=0;
void setPidClock(){//para que sea mas bonito
  setearTimer50htz();
}
void setearTimer50htz(){//seteo de timer de 50khz con variables de registro
  noInterrupts(); // disable all interrupts
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;
  OCR3A = 625; // compare match register 16MHz/256/50Hz (20016micros)
  TCCR3B |= (1 << WGM32); // CTC mode
  TCCR3B |= (1 << CS32 ); // 256 prescaler
  TIMSK3 |= (1 << OCIE3A); // enable timer compare interrupt
  interrupts();
}
ISR(TIMER3_COMPA_vect) // rutina de interrupcion 3
{
  if(correr){
  sensado();//llamado a sensar
  pidCalc();//calculo del pid
  correccion();//seteo de motores
  }
}
void pidCalc(){ //calculo del pid
    double e=setpoint-pos;
    ep=e*kp;
    if(abs(out)<255 or ei*e<0){
  ei+=ki*e;
  }
    ed=(e-preve)*kd;
    out=ep+ei+ed;
    freno=max(abs(e-preve)*kFrenoD,abs(e)*kFrenoP);
    preve=e;
}
