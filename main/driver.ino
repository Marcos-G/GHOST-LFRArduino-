int EA=9,EB=6,I1=53,I2=8,I3=7,I4=16;//pines del driver
int vel=0;//velocidad "frontal" del seguidor
int freno=0;
double out=0.0;
void setDriverModes(){
  pinMode (EA, OUTPUT); //todos outputs
  pinMode (EB, OUTPUT);
  pinMode (I1, OUTPUT);
  pinMode (I2, OUTPUT);
  pinMode (I3, OUTPUT);
  pinMode (I4, OUTPUT);
}
void correccion(){//giro
  int v=max(0,vel-freno);
  if(out>0){//si el error es positivo girar a la derecha
    setMotores(max(-255,v-out),v);
  }else if(out<0){//si el error es negativo girar a la izquierda
    setMotores(v,max(-255,v+out));
  }
  else{
    setMotores(v,v);
  }
}
void setMotores(int velI,int velD){//funcion para setear velocidades
  motorIzq(velI);
  motorDer(velD);
}
void motorDer(int vel){//seteo de velocidad al derecho
    analogWrite(EA,abs(vel));
    digitalWrite(I1,vel<0);
    digitalWrite(I2,vel>0);
}
void motorIzq(int vel){//seteo de velocidad al izq
    analogWrite(EB,abs(vel));file:///usr/share/applications/arduino.desktop
    digitalWrite(I3,vel<0);
    digitalWrite(I4,vel>0);
}
void trabarIzq(){//trabar motores
  analogWrite(EB,128);
  digitalWrite(I3,false);
  digitalWrite(I4,false);
}
void trabarDer(){//trabar motores
  analogWrite(EA,128);
  digitalWrite(I1,false);
  digitalWrite(I2,false);
}
