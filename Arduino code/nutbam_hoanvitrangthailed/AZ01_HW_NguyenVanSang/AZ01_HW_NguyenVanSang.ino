//chương trình mỗi khi nhấn nút thì đèn đảo trạng thái 
#define led 13
#define button 4
int ttNut, dem=1;
int BanDau=0;
 void setup() 
{
  pinMode(button, INPUT); 
  digitalWrite(led,LOW);
  Serial.begin(9600);
  Serial.print("MOI BAN NHAT NUT \n");
}
void loop()
{
  ttNut=(digitalRead(button));
  while (ttNut==0) 
 {
  dem++;
  if (dem%2==0)
  { 
    digitalWrite(led,HIGH); delay(200); Serial.println("Da nhan nut- Led On");
  }
  if (dem%2==0) {break;}
  if (dem%2!=0)
  { 
    digitalWrite(led,LOW); delay(200); Serial.println("Da nhan nut- Led Off");
  }
  if (dem%2!=0) {break;}
 }
}

