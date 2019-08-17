#define in1 2
#define in2 3
#define out1 11
#define out2 10
#define led12 12
#define loa 10
#define chanCamBien 4
int docGiaTri=0; 
int i=1,k=1;
void setup() 
{
  Serial.begin(9600);
pinMode(k,OUTPUT);
pinMode(in1,INPUT_PULLUP);
pinMode(in2,INPUT_PULLUP);
attachInterrupt(0,ngat1,CHANGE);
attachInterrupt(1,ngat2,CHANGE);
 pinMode(led12,OUTPUT);
  pinMode(loa,OUTPUT);
  pinMode(chanCamBien,INPUT);
}
void loaKeu(int Time,int mucLoaKeu)
{
  analogWrite(loa,mucLoaKeu);
  delay(Time);
  analogWrite(loa,0);
}
void ledCanhBao(int lan)
{
  for(int i=0;i<lan;i++)
  {
  digitalWrite(led12,1);
  delay(300);
  digitalWrite(led12,0);
  delay(300);
  }
}
void ngat1()
{
  if (digitalRead(in1)==0)
  {
    delay(100);
     if (digitalRead(in1)==0)
      i++;
  }
}
void ngat2()
{
  if (digitalRead(in2)==0)
  {
    delay(100);
     if (digitalRead(in2)==0)
      k++;
  }
}
void relay1()
{
  if(i%2==0)
   digitalWrite(out1,1);
  else 
   digitalWrite(out1,0);
  if(i==10) i=2;
}
void relay2()
{
  if(k%2==0)
   digitalWrite(out2,1);
  else 
   digitalWrite(out2,0);
  if(k==10) k=2;
}
void loop() 
{
   relay1();
   relay2();
 docGiaTri=digitalRead(chanCamBien);
  if (docGiaTri==HIGH)
  {
    digitalWrite(led12,1);
    delay(300);
  }
  else 
  {
    digitalWrite(led12,0);
  }
  
}
