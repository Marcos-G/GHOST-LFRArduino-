int max[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int min[] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
bool invertir = false; //true para smd(733)
bool calibrado = false;
int s[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
float posSen[] = {18.0, 28.0, 38.0, 48.0, 60.0, 72.0, 82.0, 92.0, 102.0};
int sPin[] = {40, 37, 36, 35, 34, 33, 32, 31, 30};
boolean linea = false;

void sensado() { //eso que dice
  if (calibrado) { //si ya esta calibrado empezamos a medir

    if (digitalizar(analogRead(0), min[0], max[0]) == 1 && digitalizar(analogRead(8), min[8], max[8]) == 1) {
      if (!linea)
        curva = !curva;
      linea = true;
    } else
      linea = false;
    digitalWrite(PHANTOM_LED, curva);
    float prom = 0;
    float sum = 0;
    if(curva){
      ai=1;af=8;
    }else{
      ai=2;af=7;
    }
    for (int a = ai; a < af; a++) {
      s[a] = digitalizar(analogRead(a), min[a], max[a]) * 1023; //ANALOGICODigitalizado
      if (invertir) { //si es el 733 se invierte
        s[a] = 1023 - s[a];
      }
      prom += s[a] * posSen[a];
      sum += s[a];
    }
    if (sum != 0 ){//&& sum < 3000) {
      pos = prom / sum;
    }
  }
}


int digitalizar(int s, int mi, int ma) {
  float me = (mi + ma) / 2;
  if (s < me)
    return 0;
  else
    return 1;
}
void calibrar() { //calibrar durante los primeros 5 segundos
  int tiempo = millis();
  while (millis() - tiempo < 5000) {
    for (int a = 0; a < 9; a++) {
      int sen = analogRead(a);
      max[a] = max(max[a], sen);
      min[a] = min(min[a], sen);
    }
  }
  calibrado = true;

}
