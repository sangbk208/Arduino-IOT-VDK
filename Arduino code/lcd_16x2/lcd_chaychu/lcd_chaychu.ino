#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
int i;
LiquidCrystal_I2C lcd(0x3F,16,2); 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2); 
  }
void chayxuoi()
 {
  for(i=0;i<17;i++)
   {
    lcd.setCursor(i, 0); 
    lcd.print("DO TON TIEN");
    delay(100);
    lcd.clear();delay(50);
    if (i==16) break;
   }
 }
void chaynguoc()
 {
  for(i=16;i>=0;i--)
  {
    lcd.setCursor(i, 0); 
    lcd.print("DO TON TIEN");
    delay(100);
    lcd.clear();delay(50);
    if (i==0) break;
  }
 }
void nhay(int n)
 {
   int i;
   for(i=1;i<=n;i++)
   {
   lcd.setCursor(2, 0); 
   lcd.print("DO TON TIEN"); delay(200);
   lcd.clear();delay(200);
   }
} 
void loop() 
{
nhay(3);
chayxuoi();
chaynguoc();
}
