double ep = 0.0; double ei = 0.0; double ed = 0.0;
double kFrenoD = 0.0; double kFrenoP = 0.0;
double pos = 60.0;
double preve = 0.0;
double prevpos = 60.0;
double setpoint = 60.0;
unsigned long medTime = 0;
int usr = 1;
void setPidClock() { //para que sea mas bonito
  setearTimer50htz();
}
void setearTimer50htz() { //seteo de timer de 50khz con variables de registro
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
void sensado();
ISR(TIMER3_COMPA_vect) // rutina de interrupcion 3
{
if(correr){
    if(millis()-arrT<tar){
    vel=velar+pow(((millis()-arrT)/tar),2)*(velmax-velar);
  }else{
    vel=velmax;
  }
  sensado();//llamado a sensar
  pidCalc();//calculo del pid
  correccion();//seteo de motores
  }
  

}
void pidCalc() { //calculo del pid
  double e = setpoint - pos;
  if(curva){
  ep = e * kpc;
  if (abs(out) < 255 or ei * e < 0) {
    ei += kic * e;
  }
  ed = (e - preve) * kdc;
 
  }else{
    ep = e * kpr;
  if (abs(out) < 255 or ei * e < 0) {
    ei += kir * e;
  }
  ed = (e - preve) * kdr;
  }
   out = ep + ei + ed;
  freno = max(abs(e - preve) * kFrenoD, abs(e) * kFrenoP);
  preve = e;

}
