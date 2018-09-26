
long encI=0;
long encD=0;
void encoderI() {
  encI+=1;
  Serial1.print("I");Serial1.println(encI);
}
void encoderD() {
  Serial1.println("D");
  encD+=1;
  
}void setup() {
  Serial1.begin(115200);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
attachInterrupt(digitalPinToInterrupt(3), encoderI, RISING);
  attachInterrupt(digitalPinToInterrupt(2), encoderD, RISING);
Serial1.println("Hola");
}

void loop() {
  // put your main code here, to run repeatedly:

}

