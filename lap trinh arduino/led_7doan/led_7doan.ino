int h[10]={0x05,0x9F,0x22,0x0B,0x99,0x49,0x41,0x1F,0xFE,0x08};

void setup() 
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,0);
  Serial.begin(9600);
}
void hienthi(int a){ 
  int d=h[a],i=8;
  while(i>=2)
    {
      d=d>>1;
      digitalWrite(i,d&1);
      delay(1);
      i--;
    }
}
void loop() 
{ 
  for(int j=0;j<=9;j++)
  {
   hienthi(j);delay(500);
  }
}

