int EA=9,EB=6,I1=53,I2=8,I3=7,I4=16;
void setDriverModes(){
  pinMode (EA, OUTPUT); 
  pinMode (EB, OUTPUT);
  pinMode (I1, OUTPUT);
  pinMode (I2, OUTPUT);
  pinMode (I3, OUTPUT);
  pinMode (I4, OUTPUT);
}
void correccion(int dir,int vel){
  
}
void motorIzq(int vel){
    analogWrite(EA,abs(vel));
    digitalWrite(I1,vel>0);
    digitalWrite(I2,vel<0);
}
void motorDer(int vel){
    analogWrite(EB,abs(vel));
    digitalWrite(I3,vel>0);
    digitalWrite(I4,vel<0);
}
void soltarDer(){
  analogWrite(EB,0);
}
void soltarIzq(){
  analogWrite(EA,0);
}
