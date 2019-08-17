#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,20,4); 
#define in1 2
#define in2 3
#define in3 18
#define in4 19
#define in5 4
#define in6 5

int t=0,j=0,k=0,l=0,y=0,x=0;
void setup() 
{
pinMode(in1,INPUT_PULLUP);
pinMode(in2,INPUT_PULLUP);
pinMode(in3,INPUT_PULLUP);
pinMode(in4,INPUT_PULLUP);
pinMode(in5,INPUT_PULLUP);
pinMode(in6,INPUT_PULLUP);

attachInterrupt(0,ngat1,CHANGE);
attachInterrupt(1,ngat2,CHANGE);
attachInterrupt(5,ngat3,CHANGE);
attachInterrupt(4,ngat4,CHANGE);

  Wire.begin();
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight(); 
  lcd.setCursor(3,0);
  lcd.print("DIEU KHIEN BOM");
   lcd.setCursor(0,2);
  lcd.print("B1:");
  lcd.setCursor(5,2);
  lcd.print("B2:");
  lcd.setCursor(10,2);
  lcd.print("B3:");
  lcd.setCursor(0,3);
  lcd.print("B4:");
  lcd.setCursor(5,3);
  lcd.print("B5:");
  lcd.setCursor(10,3);
  lcd.print("B6:");
}
void ngat1()
{
    if(digitalRead(in1)==0) t=1; else t=0;
}
void ngat2()
{
    if(digitalRead(in2)==0) j=1; else j=0;
}
void ngat3()
{
    if(digitalRead(in3)==0) k=1; else k=0;
}
void ngat4()
{
    if(digitalRead(in4)==0) l=1; else l=0;
}
void tt()
{
  if(t==0){lcd.setCursor(3,2);lcd.print("0");}
     else {lcd.setCursor(3,2);lcd.print("1");}
  if(j==0){lcd.setCursor(8,2);lcd.print("0");}
     else {lcd.setCursor(8,2);lcd.print("1");}
  if(k==0){lcd.setCursor(13,2);lcd.print("0");}
     else {lcd.setCursor(13,2);lcd.print("1");}
  if(l==0){lcd.setCursor(3,3);lcd.print("0");}
     else {lcd.setCursor(3,3);lcd.print("1");}
  if(x==0){lcd.setCursor(8,3);lcd.print("0");}
  if(y==0){lcd.setCursor(13,3);lcd.print("0");}  
}
void in56()
{
 while(digitalRead(in5)==0) 
 {
  x=1;if(x==1) {lcd.setCursor(8,3);lcd.print("1");}
  if(digitalRead(in5)==1){x=0;break; }
 }
 while(digitalRead(in6)==0) 
 {
  y=1;if(y==1) {lcd.setCursor(13,3);lcd.print("1");}
  if(digitalRead(in6)==1){y=0;break; }
 }
  }
void loop() 
{
 tt();
 in56();
}
