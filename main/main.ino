int PHANTOM_LED=38;
int PHANTOM_GO=24;
int arrT=0;
boolean correr=false;
boolean curva=false;



int velmax=250;//velocidad "frontal" del seguidor
int velar=100;//velocidad de arranque
float tar=2000;//tiempo en milisegundos de arranque
double kpc = 0.0; double kic = 0.0; double kdc = 0.0;
double kpr = 0.0; double kir = 0.0; double kdr = 0.0;



void setWifiSerialClock();
void setPidClock();
void calibrar();
void setup() {
  pinMode(PHANTOM_GO, INPUT);
  pinMode(PHANTOM_LED, OUTPUT);
  setWifiSerialClock();//se inicia el timer (que activa las interrupciones) y el Serial, para transmitir las comunicaciones wifi
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver

  while (!digitalRead(PHANTOM_GO)) {}
  setMotores(255, 255);
  delay(400);
  while (!digitalRead(PHANTOM_GO)) {}
  setMotores(0, 0);
  delay(400);
  while (!digitalRead(PHANTOM_GO)) {}
  digitalWrite(PHANTOM_LED, HIGH);
  calibrar();//5segundos de calibracion
  digitalWrite(PHANTOM_LED, LOW);
  delay(400);
  while (!digitalRead(PHANTOM_GO)) {}
  delay(400);
  while (digitalRead(PHANTOM_GO)) {}
  arrT = millis();
  correr = true;

}
void loop() {
}
