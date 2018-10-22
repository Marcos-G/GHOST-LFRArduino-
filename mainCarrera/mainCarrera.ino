//SETEO DE VARIABLES*********************
double kp=9.0;
double ki=0.0;
double kd=24.0;
int vel=250;
//int velmax=250;//velocidad "frontal" del seguidor
//int velar=100;
//int tar=2000;

double kFrenoD=0.0;
double kFrenoP=0.0;
//SOLO MODIFICAR ^^^ESOS^^^ VALORES
//int vel=0;
//int arrT=0;

int PHANTOM_LED=38;
int PHANTOM_GO=24;
boolean correr=false;
void setup() {
  //leerData();
  pinMode(PHANTOM_GO,INPUT);
  pinMode(PHANTOM_LED,OUTPUT);
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver
 
  
  digitalWrite(PHANTOM_LED,HIGH);
 calibrar();//5segundos de calibracion
  digitalWrite(PHANTOM_LED,LOW);
 
  correr=true;
}
void loop() {
}
