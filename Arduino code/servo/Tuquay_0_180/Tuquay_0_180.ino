#include <Servo.h>
int bt;
Servo myservo;
int i = A0;  
void setup() {
  myservo.attach(9); 
  Serial.begin(9600); 
}

void loop() 
{
   int k=analogRead(i);
   int t=map(k,0,1024,0,180);
    myservo.write(t);      
    Serial.println(t);     
}

