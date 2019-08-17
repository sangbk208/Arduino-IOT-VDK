int h[10]={0x05,0x9F,0x22,0x0B,0x99,0x49,0x41,0x1F,0x01,0x08};
String so="";;
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
  Serial.println("moi ban nhap chu so :");
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
  if (Serial.available()>0)
  {
    so=Serial.readString();
    Serial.println(so);

    if (so=="khong") { hienthi(0);so="";}
    else if (so=="mot") { hienthi(1);so="";}
    else if (so=="hai") { hienthi(2);so="";}
    else if (so=="ba")  { hienthi(3);so="";}
    else if (so=="bon") { hienthi(4);so="";}
    else if (so=="nam") { hienthi(5);so="";}
    else if (so=="sau") { hienthi(6);so="";}
    else if (so=="bay") { hienthi(7);so="";}
    else if (so=="tam") { hienthi(8);so="";}
    else if (so=="chin"){ hienthi(9);so="";}
  }
}
