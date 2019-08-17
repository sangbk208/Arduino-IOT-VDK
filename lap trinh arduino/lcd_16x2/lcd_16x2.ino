#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,16,2); 

void setup() {
  lcd.init();  
  lcd.backlight();
  
  lcd.print("Nhiet do: ");
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
    
}
void dong2()
{
  lcd.setCursor(2, 1); 
  lcd.print("TU DONG HOA");
  delay(1000);
  lcd.clear(); delay(500);
}
void loop() 
{


}
