int max[]={0,0,0,0,0,0};
int min[]={1024,1024,1024,1024,0,0};
bool calibrado=false;
int s[]={0,0,0,0,0,0};
float posSen[]={1.2,3.1,4.7,6.4,8.0,10.0};
void sensado(){
  float prom=0;
  float sum=0;
  for(int a=0;a<6;a++){
    s[a]=((analogRead(a)-min[a])*255.0/max[a]);
    //s[a]=(analogRead(a))/4;
    prom+=s[a]*posSen[a];
    sum+=s[a];
  }
   pos=prom/sum;
}
void calibrar(){
  if(millis()<10000){
    for(int a=0;a<6;a++){
      int sen=analogRead(a);
      if(sen>max[a]){
        max[a]=sen;
      }
      if(sen<min[a]){
        min[a]=sen;
      }
    }
  }
  else{
    calibrado=true;
  }
}
