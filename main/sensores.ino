int max[]={0,0,0,0,0,0,0,0,0};
int min[]={1024,1024,1024,1024,1024,1024,1024,1024,1024};
bool invertir=true;//true para smd(733)
bool calibrado=false;
int s[]={0,0,0,0,0,0,0,0,0};
float posSen[]={18.0,28.0,38.0,48.0,60.0,72.0,82.0,92.0,102.0};
int sPin[]={40,37,36,35,34,33,32,31,30};
void sensado(){//eso que dice
  if(calibrado){//si ya esta calibrado empezamos a medir
  float prom=0;
  float sum=0;
  for(int a=0;a<9;a++){
    //s[a]=map(analogRead(a),min[a],max[a],0,1023);//mapeo de el minimo y max a 0-1023
    s[a]=(digitalRead(sPin[a])*1024);
    if(invertir){//si es el 733 se invierte
      s[a]=1023-s[a];
    }
    if(s[a]<500) s[a]=0;
    //s[a]=(analogRead(a))/4;
    prom+=s[a]*posSen[a];
    sum+=s[a];
  }
  if(sum!=0){
   pos=prom/sum;
  }
  }
}
void calibrar(){//calibrar durante los primeros 5 segundos
  int tiempo = millis();
  while(millis()-tiempo<5000){
    for(int a=0;a<9;a++){
      int sen=analogRead(a);
      max[a]=max(max[a],sen);
      min[a]=min(min[a],sen);
    }
  }
  calibrado=true;
  
}
