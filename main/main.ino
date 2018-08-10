int PHANTOM_LED=38;
void setup() {
  setWifiSerialClock();//se inicia el timer (que activa las interrupciones) y el Serial, para transmitir las comunicaciones wifi
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver
  calibrar();//5segundos de calibracion
}
void loop() {
updateK();//revisar si hay valores para actualizar las constantes del pid
}
