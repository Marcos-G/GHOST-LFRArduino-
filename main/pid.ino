double kp=0.0;double ki=0.0;double kd=0.0;
double ep=0.0;double ei=0.0;double ed=0.0;
double kFrenoD=0.0;double kFrenoP=0.0;
double pos=60.0;
double preve=0.0;
double prevpos=60.0;
double setpoint=60.0;
unsigned long medTime=0;
int usr=1;
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
  t=micros();
  medTime=millis();
  //Serial1.println("P1:"+(t-time));
  time=t;
  sensado();//llamado a sensar
  pidCalc();//calculo del pid
  correccion();//seteo de motores
  t=micros();
  //Serial1.println("P2:"+(t-time));
  time=t;
}
void pidCalc(){ //calculo del pid
  if(usr==0){//marcos
  double e=setpoint-pos;
  double dpos=pos-prevpos;
  ed=kd*dpos;//derivativo de la entrada
  if(abs(out)<255 or ei*e<0){
  ei+=ki*e;
  ep+=kp*dpos;
  }
  out=max(-255,min(255,ei-ep-ed));
  prevpos=pos;
  }else if(usr==1){//Lauta
    double e=setpoint-pos;
    ep=e*kp;
    if(abs(out)<255 or ei*e<0){
  ei+=ki*e;
  }
    ed=(e-preve)*kd;
    out=ep+ei+ed;
    freno=max(abs(e-preve)*kFrenoD,abs(e)*kFrenoP);
    preve=e;
  }else if(usr==2){//Joaco
    
  }
}
