int PHANTOM_LED=38;
unsigned long time=0;
unsigned long t=0;
void setup() {
  //leerData();
  setWifiSerialClock();//se inicia el timer (que activa las interrupciones) y el Serial, para transmitir las comunicaciones wifi
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver
  calibrar();//5segundos de calibracion
  attachInterrupt(digitalPinToInterrupt(3), encoderI, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), encoderD, CHANGE);

}
void loop() {
//revisar si hay valores para actualizar las constantes del pid
}
