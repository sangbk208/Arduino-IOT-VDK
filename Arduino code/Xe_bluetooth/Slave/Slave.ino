#include <SoftwareSerial.h>
#define tx 11
#define rx 10
#define enA 9
#define in1 8
#define in2 7
#define in3 6
#define in4 4
#define enB 5
#define den 12
int p=0;
SoftwareSerial bluetooth(rx,tx);
void setup() 
 {
   for(int i=2;i<=9;i++)
    {
      pinMode(i,OUTPUT);
    }
    pinMode(den,OUTPUT);
    Serial.begin(9600);
  bluetooth.begin(38400);
 }
void motor_truoc(int i,int j)// 0-0: motor dung, 1-0: re trai, 0-1: re phai;
{
    digitalWrite(in1,i);
   digitalWrite(in2,j);
   analogWrite(enA,127);
   
}
void motor_sau(int i,int j)// 0-0: motor dung, 1-0: motor tien, 0-1: motor lui;
 {
   digitalWrite(in3,i);
   digitalWrite(in4,j);
   analogWrite(enB,255);
   }
 
void loop()     
{ 
  char blueRead;
  while(bluetooth.available())
  {
    blueRead=bluetooth.read();
    Serial.println(blueRead);
    if(blueRead=='B'){motor_sau(1,0);motor_truoc(0,0);}
    if(blueRead=='F'){motor_sau(0,1);motor_truoc(0,0);}
    if(blueRead=='R')  motor_truoc(0,1);
    if(blueRead=='L')  motor_truoc(1,0);
    if(blueRead=='G'){motor_sau(0,1);motor_truoc(1,0);}
    
    if(blueRead=='I'){motor_sau(0,1);motor_truoc(0,1);}
    
   if(blueRead=='H'){motor_sau(1,0);motor_truoc(1,0);}
    
  if(blueRead=='J'){motor_sau(1,0);motor_truoc(0,1);}
    
    if(blueRead=='S') {motor_sau(0,0);motor_truoc(0,0);}
    if(blueRead=='W') {p=!p;digitalWrite(den,p);Serial.print(p);}
    delay(10); 
 }
 }

