int h[10]={0x05,0x9F,0x22,0x0B,0x99,0x49,0x41,0x1F,0x01,0x08};

int k=99;

void setup() 

{
  
for (int i=4;i<=12;i++)
  
{
    
pinMode(i,OUTPUT);
 
 }
  
pinMode(1,OUTPUT);
  
digitalWrite(11,0);
 
 digitalWrite(12,0);
 
 Serial.begin(9600);
 
 pinMode(2,INPUT_PULLUP);
 
 pinMode(3,INPUT_PULLUP);
 
 attachInterrupt(0,nut2,CHANGE);

  attachInterrupt(1,nut3,CHANGE);
}

void nut2()
{
  
if(digitalRead(2)==0)
  
{
    
delay(100);
    if(digitalRead(2)==0)
  k++;
  }

}

void nut3()
{

  if(digitalRead(3)==0)
  {
  
  delay(100);
    if(digitalRead(3)==0)
  k--;
  }
}

void hienthi(int a){ 
  
int d=h[a];
  for (int i=10;i>=4;i--)
    {
   
   d=d>>1;
      digitalWrite(i,d&1);
    }
}

void loop()
{
 if ((k<=0)||(k>99)) k=0;


      digitalWrite(12,1); 
digitalWrite(11,0);
    
  hienthi(k/10);
delay(10);
     
 digitalWrite(11,1);
 digitalWrite(12,0);
   
   hienthi(k%10);delay(10);  
  
}

