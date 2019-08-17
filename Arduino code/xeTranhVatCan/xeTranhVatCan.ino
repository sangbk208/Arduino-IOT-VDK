#include<Servo.h>
#include<UltraDistSensor.h>
#define IN1 5
#define IN2 4
#define IN3 3
#define IN4 2
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
int phai,trai;
Servo myservo;
UltraDistSensor mysensor;
int pos = 0;
float reading;
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  myservo.attach(9); 
  mysensor.attach(6,7);
  Serial.begin(9600);
}
void motor_1_Dung() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 void motor_2_Dung() 
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_1_Tien(int speed) 
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
}
 void motor_1_Lui(int speed) 
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
}
 void motor_2_Lui(int speed) 
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN4, speed);
  digitalWrite(IN3, LOW);
}
 void motor_2_Tien(int speed) 
{
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN4, 255 - speed);
  digitalWrite(IN3, HIGH);
}
 void quayTrai()
 {
   for (pos = 0; pos <= 170; pos++) 
    {
       myservo.write(pos);  
       delay(5);      
    }
 }
 void quayPhai()
 {
   for (pos = 90; pos >= 0; pos--) 
    {
       myservo.write(pos);  
       delay(5);      
    }
 }
 void traihonphai()
 {
   myservo.write(90);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(500);
    motor_1_Lui(MAX_SPEED);
    motor_2_Lui(MAX_SPEED);
    delay(500);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(500);
    motor_1_Tien(MAX_SPEED);
    motor_2_Dung() ;
    delay(300);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(1000);
 }
 void phaihontrai()
 {
   myservo.write(90);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(500);
    motor_1_Lui(MAX_SPEED);
    motor_2_Lui(MAX_SPEED);
    delay(500);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(500);
    motor_2_Tien(MAX_SPEED);
    motor_1_Dung() ;
    delay(300);
    motor_1_Dung() ;
    motor_2_Dung() ;
    delay(1000);
 }
 void quay()
 {
    for (pos = 90; pos >= 80; pos--) 
    {
       myservo.write(pos);  
       delay(5);      
    }
  for (pos = 80; pos <= 110; pos++) 
    {
       myservo.write(pos);  
       delay(5);      
    }
    
 }
 void loop()
{
   motor_2_Lui(MAX_SPEED);
}

