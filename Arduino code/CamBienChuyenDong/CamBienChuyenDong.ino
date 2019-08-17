#define led12 12
#define loa 10
#define chanCamBien 2
int docGiaTri=0; 
void setup()
{
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
void loop()
{
  docGiaTri=digitalRead(chanCamBien);
  if (docGiaTri==HIGH)
  {
    ledCanhBao(2);
    
  }
  else 
  {
    ledCanhBao(0);
  
  }
}

