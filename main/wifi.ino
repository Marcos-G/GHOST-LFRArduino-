void setWifiSerialClock(){//Serial y timer
  Serial1.begin(115200);
  setearTimer20htz();
}
void setearTimer20htz(){//seteo del timer a 20Htz
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
void updateK(){//actualizo las K si hay algun dato en el serial
  if (Serial1.available()>0) {
    String input=Serial1.readStringUntil('\n');
    char k=input[0];
    float val=input.substring(1).toFloat();
    if(k=='P'){
      kp=val;
    }
    else if(k=='I'){
      ki=val;
    }
    else if(k=='D'){
      kd=val;
    }
    else if(k=='V'){
      vel=val;
    }
    else if(k=='U'){
      usr=val;
    }
    else if(k=='F'){
      kFrenoD=val;
    }
    else if(k=='R'){
      kFrenoP=val;
    }
    //guardarData();
  }
}
void sendState(){//String que se envia por wifi
  String msg="{";
///
  msg+=(F("\"TIME\":"));
  msg+=(medTime);
  msg+=(F(",\"KP\":"));
  msg+=(kp);
  msg+=(F(",\"KI\":"));
  msg+=(ki);
  msg+=(F(",\"KD\":"));
  msg+=(kd);
  msg+=(F(",\"VEL\":"));
  msg+=(vel);
  msg+=(F(",\"FRENOD\":"));
  msg+=(kFrenoD);
  msg+=(F(",\"FRENOP\":"));
  msg+=(kFrenoP);
  msg+=(F(",\"ENCI\":"));
  msg+=(encI);
  msg+=(F(",\"ENCD\":"));
  msg+=(encD);
  msg+=(F(",\"USR\":"));
  msg+=(usr);
  msg+=(F(",\"POS\":"));
  msg+=(pos);
  msg+=(F(",\"EP\":"));
  msg+=(-ep);
  msg+=(F(",\"EI\":"));
  msg+=(ei);
  msg+=(F(",\"ED\":"));
  msg+=(-ed);
  msg+=(F(",\"OUT\":"));
  msg+=(out);
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
  msg+=(s[5]);
  msg+=(F(",\"S6\":"));
  msg+=(s[6]);
  msg+=(F(",\"S7\":"));
  msg+=(s[7]);
  msg+=(F(",\"S8\":"));
  msg+=(s[8]);
  msg+=("}");
  Serial1.println(msg);
  encI=0;
  encD=0;
}
ISR(TIMER5_COMPA_vect) // rutina de la interrupcion 4
{
  t=micros();
  //Serial1.println("W1:"+(t-time));
  time=t;
  updateK();
  sendState();
  t=micros();
  //Serial1.println("W2:"+(t-time));
  time=t;
}
