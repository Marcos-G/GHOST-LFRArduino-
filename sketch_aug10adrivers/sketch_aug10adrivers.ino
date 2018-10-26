int EA=9,EB=6,I1=53,I2=8,I3=7,I4=16;
int vel=0;
void setDriverModes(){
  pinMode (EA, OUTPUT); 
  pinMode (EB, OUTPUT);
  pinMode (I1, OUTPUT);
  pinMode (I2, OUTPUT);
  pinMode (I3, OUTPUT);
  pinMode (I4, OUTPUT);
}
void correccion(int e){
  if(e>0){
    motorIzq(vel+e);
    soltarDer();
  }
  if(e<0){
      motorDer(vel+e);
      soltarIzq();
  }
}
void motorDer(int vel){
    analogWrite(EA,abs(vel));
    digitalWrite(I1,vel<0);
    digitalWrite(I2,vel>0);
}
void motorIzq(int vel){
    analogWrite(EB,abs(vel));
    digitalWrite(I3,vel<0);
    digitalWrite(I4,vel>0);
}
void soltarIzq(){
  analogWrite(EB,0);
}
void soltarDer(){
  analogWrite(EA,0);
}
void setup() {
setDriverModes();
}

void loop() {
motorDer(255);
soltarIzq();
delay(1000);
motorIzq(255);
soltarDer();
delay(1000);
}
