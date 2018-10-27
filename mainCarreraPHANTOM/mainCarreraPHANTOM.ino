//SETEO DE VARIABLES*********************
double kp=7.0;
double ki=0.0;
double kd=21.0;
//int vel=250;
int velmax=250;//velocidad "frontal" del seguidor
int velar=100;
float tar=2000.0;

double kFrenoD=0.0;
double kFrenoP=0.0;
//SOLO MODIFICAR ^^^ESOS^^^ VALORES
int vel=0;
int arrT=0;

int PHANTOM_LED=38;
int PHANTOM_GO=24;
boolean correr=false;
void setup() {
  //leerData();
  pinMode(PHANTOM_GO,INPUT);
  pinMode(PHANTOM_LED,OUTPUT);
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver
 
  while(!digitalRead(PHANTOM_GO)){}
  setMotores(255,255);
  delay(400);
  while(!digitalRead(PHANTOM_GO)){}
  setMotores(0,0);
  delay(400);
  while(!digitalRead(PHANTOM_GO)){}
  digitalWrite(PHANTOM_LED,HIGH);
 calibrar();//5segundos de calibracion
  digitalWrite(PHANTOM_LED,LOW);
  delay(400);
  while(!digitalRead(PHANTOM_GO)){}
  delay(400);
  while(digitalRead(PHANTOM_GO)){}
  arrT=millis();
  correr=true;
}
void loop() {
}
