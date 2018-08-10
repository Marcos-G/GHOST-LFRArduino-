int max[]={0,0,0,0,0,0,0,0,0};
int min[]={1024,1024,1024,1024,1024,1024,1024,1024,1024};
bool invertir=true;//true para smd(733)
bool calibrado=false;
int s[]={0,0,0,0,0,0,0,0,0};
float posSen[]={1.8,2.8,3.8,4.8,6.0,7.2,8.2,9.2,10.2};
void sensado(){//eso que dice
  if(calibrado){//si ya esta calibrado empezamos a medir
  float prom=0;
  float sum=0;
  for(int a=0;a<9;a++){
    s[a]=map(analogRead(a),min[a],max[a],0,1023);//mapeo de el minimo y max a 0-1023
    if(invertir){//si es el 733 se invierte
      s[a]=1023-s[a];
    }
    //s[a]=(analogRead(a))/4;
    prom+=s[a]*posSen[a];
    sum+=s[a];
  }
   pos=prom/sum;
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
