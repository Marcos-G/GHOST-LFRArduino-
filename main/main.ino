
void setup() {
  
  setWifiSerialClock();
  setPidClock();
  setDriverModes();
  calibrar();
}
void loop() {
updateK();
}
