int a,b,dem=0;
#define led13 9
const int trig = 7;  
const int echo = 8;   
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,16,2);  
void setup()
{
    pinMode(led13,OUTPUT);
    Serial.begin(9600);     
    pinMode(trig,OUTPUT);  
    pinMode(echo,INPUT);  
    lcd.init();
    lcd.backlight();
    lcd.begin(16,2);
}
 
void loop()
{
    unsigned long duration;
    int distance;          
    digitalWrite(trig,0);   
    delayMicroseconds(2);
    digitalWrite(trig,1);   
    delayMicroseconds(5);   
    digitalWrite(trig,0);   
    
  
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    dem++;
    lcd.setCursor(0, 0); 
    lcd.print(distance);
    lcd.setCursor(3, 0);
    lcd.print("CM");
    delay(2000);
    lcd.clear();delay(500);
    if (dem%2!=0) a=distance; else b=distance;
    while (dem%2==0)  
    {
      if (a>b){lcd.setCursor(2, 1);
       lcd.print("NUOC DANG LON");delay(5000);lcd.clear();dem=0;break;} else  if (a<b){lcd.setCursor(2, 1);{ lcd.print("NUOC DANG RUT"); delay(5000);lcd.clear();dem=0;break;}
    } }
    distance=0;
    delay(1000);
}
