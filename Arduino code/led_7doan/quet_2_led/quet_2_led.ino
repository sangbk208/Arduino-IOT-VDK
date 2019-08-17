int h[10]={0x05,0x9F,0x22,0x0B,0x99,0x49,0x41,0x1F,0x01,0x08};
String so="";
char A[]="";
int k;
void setup() 
{
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,0);
  digitalWrite(12,0);
  Serial.begin(9600);
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
  if (Serial.available()>0)
    { 
      digitalWrite(11,1);
      digitalWrite(12,1);
     so=Serial.readString();
     Serial.println(so);
     so.toCharArray(A,3);
     k=((A[0]-48)*10+(A[1]-48));
    }  
      digitalWrite(12,1); digitalWrite(11,0);
      hienthi(k/10);delay(10);
      digitalWrite(11,1); digitalWrite(12,0);
      hienthi(k%10);delay(10);   
  }

