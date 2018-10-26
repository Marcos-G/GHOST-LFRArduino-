int EA = 9, EB = 6, I1 = 53, I2 = 8, I3 = 7, I4 = 16; //pines del driver
int vel = 0; //velocidad "frontal" del seguidor
int freno = 0;
double out = 0.0;
int maxm = 255;
int minm = -255;
void setDriverModes() {
  pinMode (EA, OUTPUT); //todos outputs
  pinMode (EB, OUTPUT);
  pinMode (I1, OUTPUT);
  pinMode (I2, OUTPUT);
  pinMode (I3, OUTPUT);
  pinMode (I4, OUTPUT);
}
void correccion() { //giro
  int v = max(0, vel - freno);
  if (out > 0) { //si el error es positivo girar a la derecha
    setMotores(max(minm, v - out), v);
  } else if (out < 0) { //si el error es negativo girar a la izquierda
    setMotores(v, max(minm, v + out));
  }
  else {
    setMotores(v, v);
  }
}
void setMotores(int t velD) { //funcion para setear velocidades
  motorIzq(velI);
  motorDer(velD);
}
void motorDer(int veteo de velocidad al derecho
              analogWrite(EA, a);
              digitalWrite(I1, vel < 0);
              digitalWrite(I2, vel > 0);
}
void motorIzq(int vel) { //seteo de velocidad al izq
analogWrite(EB, abs(vel)); file: ///usr/share/applications/arduino.desktop
  digitalWrite(I3, vel < 0);
  digitalWrite(I4, vel > 0);
}
