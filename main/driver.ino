int EA=9,EB=6,I1=53,I2=8,I3=7,I4=16;//pines del driver
int vel=0;//velocidad "frontal" del seguidor
void setDriverModes(){
  pinMode (EA, OUTPUT); //todos outputs
  pinMode (EB, OUTPUT);
  pinMode (I1, OUTPUT);
  pinMode (I2, OUTPUT);
  pinMode (I3, OUTPUT);
  pinMode (I4, OUTPUT);
  pinMode(PHANTOM_LED,OUTPUT);
}
void correccion(int e){//giro    SOLO PARA ESTATICO(vel=0), despues hay que tocarlo
  if(e>0){//si el error es positivo girar a la derecha
    setMotores(vel+e,0);
      String smot="motores";
      smot+=vel+e;
      smot+=" , ";
      smot+=0;
      Serial1.println(smot);
    digitalWrite(PHANTOM_LED,HIGH);
  }
  if(e<0){//si el error es negativo girar a la izquierda
      setMotores(0,vel-e);
      String smot="motores";
      smot+=0;
      smot+=" , ";
      smot+=vel-e;
      Serial1.println(smot);
      digitalWrite(PHANTOM_LED,LOW);
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
    analogWrite(EB,abs(vel));
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
