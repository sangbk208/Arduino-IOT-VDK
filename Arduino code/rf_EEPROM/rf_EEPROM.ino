#include <EEPROM.h>
#define in1 2
#define in2 3
#define out1 4
#define out2 5
void setup() 
{
Serial.begin(9600);
pinMode(in1,INPUT_PULLUP);
pinMode(in2,INPUT_PULLUP);
attachInterrupt(0,ngat1,CHANGE);
attachInterrupt(1,ngat2,CHANGE);
pinMode(out1,OUTPUT);
pinMode(out2,OUTPUT);
}
void ngat1()
{
  if (digitalRead(in1)==0)
  {
    delay(100);
     if (digitalRead(in1)==0)
      EEPROM.write(1,!EEPROM.read(1));
  }
}
void ngat2()
{
  if (digitalRead(in2)==0)
  {
    delay(100);
     if (digitalRead(in2)==0)
     EEPROM.write(2,!EEPROM.read(2));
  }
}
void relay1()
{
   digitalWrite(out1,EEPROM.read(1));
}
void relay2()
{
  digitalWrite(out2,EEPROM.read(2));
}
void loop() 
{
  relay1();
  relay2();
  Serial.println(EEPROM.read(1));
 
}
