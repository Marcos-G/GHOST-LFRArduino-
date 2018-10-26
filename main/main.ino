int PHANTOM_LED = 38;
unsigned long time = 0;
unsigned long t = 0;
void setup() {
  setWifiSerialClock();//se inicia el timer (que activa las interrupciones) y el Serial, para transmitir las comunicaciones wifi
  setPidClock();//se inicia el timer que activa el calculo del pid
  setDriverModes();//seteo de salidas para el driver
  digitalWrite(PHANTOM_LED, HIGH);
  calibrar();//5segundos de calibracion
  digitalWrite(PHANTOM_LED, LOW);

}
void loop() {
}
