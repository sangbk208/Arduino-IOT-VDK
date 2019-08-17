#include <Wire.h>
void setup() 
{
  Wire.begin(8); 
  pinMode(13,OUTPUT);
  Wire.onRequest(ngat);
  Serial.begin(9600); 
}
char c ="";
void loop() 
{
   while(Serial.available()) 
   {
      c = Serial.read();
       if(c == "1')
    {
      digitalWrite(13,1);
      Serial.println(c);
    }
     else if(c == '0')
    {
      digitalWrite(13,0);
      Serial.println(c);
    }
   }
}
void ngat()
{
   Wire.write(c);
}
 
