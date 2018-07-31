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
  String msg="{";
///
  msg+=(F("\"KP\":"));
  msg+=(kp);
  msg+=(F(",\"KI\":"));
  msg+=(ki);
  msg+=(F(",\"KD\":"));
  msg+=(kd);
  msg+=(",");
  msg+=(F("\"POS\":"));
  msg+=(pos);
  msg+=(F(",\"EP\":"));
  msg+=(ep);
  msg+=(F(",\"EI\":"));
  msg+=(ei);
  msg+=(F(",\"ED\":"));
  msg+=(ed);
  msg+=(F(",\"S0\":"));
  msg+=(s[0]);
  msg+=(F(",\"S1\":"));
  msg+=(s[1]);
  msg+=(F(",\"S2\":"));
  msg+=(s[2]);
  msg+=(F(",\"S3\":"));
  msg+=(s[3]);
  msg+=(F(",\"S4\":"));
  msg+=(s[4]);
  msg+=(F(",\"S5\":"));
  msg+=(s[5]);/*
  msg+=(F(",\"S6\":"));
  msg+=(s[6]);
  msg+=(F(",\"S7\":"));
  msg+=(s[7]);
  msg+=(F(",\"S8\":"));
  msg+=(s[8]);
  msg+=(F(",\"S9\":"));
  msg+=(s[9]);
  msg+=(F(",\"S10\":"));
  msg+=(s[10]);*/
  msg+=("}\n");
  Serial1.print(msg);
}
ISR(TIMER4_COMPA_vect) // timer compare interrupt service routine
{
  sendState();
}
