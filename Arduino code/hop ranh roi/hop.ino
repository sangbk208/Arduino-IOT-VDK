#include <Servo.h>
#define camBien 5
int dem;

Servo myservo1,myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos1 = 0,pos2=0;    // variable to store the servo position


void setup() {
  pinMode(camBien,INPUT_PULLUP);
  myservo1.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(7);
  myservo1.write(120);
  myservo2.write(180);//180-57
  Serial.begin(9600); 
}
void servo1_Mo(int x){
     for (pos1 = 120; pos1 <= 155; pos1 += 1) { 
          myservo1.write(pos1);           
          delay(x); 
      }       
}
void servo1_Dong(int x){
     for (pos1 = 155; pos1 >= 120; pos1 -= 1) { 
           myservo1.write(pos1);             
           delay(x);                    
      }  
}
void servo2_Mo(int x){
     for (pos2 = 180; pos2 >= 52; pos2 -= 1) { 
           myservo2.write(pos2);             
           delay(x);            
      }  
}
void servo2_Dong(int x){
     for (pos2 = 52; pos2 <= 180; pos2 += 1) { 
           myservo2.write(pos2);             
           delay(x);            
      }  
}
void loop() {
  while (digitalRead(camBien)==0){
     delay(100);
     dem=random(0,8);
     delay(100);
     while(dem==1){
         servo1_Mo(8);
         servo2_Mo(8);
         servo2_Dong(8);
         servo1_Dong(8);
         break;
     }
     while(dem==2){
         servo1_Mo(8);
         delay(500);
         servo1_Dong(8);
         delay(700);
         servo1_Mo(8);
         servo2_Mo(8);
         servo2_Dong(8);
         servo1_Dong(8);
         break;
     }
     while(dem==3){
         servo1_Mo(10);
         for (pos2 = 180; pos2 >= 60; pos2 -= 1) { 
           myservo2.write(pos2);             
           delay(25);
         }
         delay(1000);
         myservo2.write(52); 
         delay(50);          
         servo2_Dong(5);
         servo1_Dong(5);
         break;
     }
     while(dem==4){
         servo1_Mo(15);
         delay(17);
         servo1_Dong(8);
         servo1_Mo(10);
          delay(17);
         servo1_Dong(8);
         servo1_Mo(10);
          delay(17);
         servo1_Dong(8);
         servo1_Mo(10);
          delay(17);
         servo1_Dong(8);
         servo1_Mo(10);
         servo2_Mo(8);
         servo2_Dong(8);
         servo1_Dong(8);
         break;
     }
    while(dem==5){
      servo1_Mo(8);
      servo2_Mo(8);
      servo1_Dong(8);
      delay(1000);
      servo1_Mo(8);
      delay(500);
      servo2_Dong(3);
      servo1_Dong(4);
      break;
    }
   while(dem==6){
     servo1_Mo(8);
     servo2_Mo(8);
     delay(100);
     for(int i=0;i<=4;i++){
        for (pos2 = 52; pos2 <= 87; pos2 += 1) { 
             myservo2.write(pos2);             
             delay(10);            
        } 
        delay(50);
     }
     servo2_Dong(4);
     servo1_Dong(8);
     delay(1500);
     servo1_Mo(6);
     delay(700);
     servo1_Dong(6);
     break;
   }
   while(dem==7){
    servo1_Mo(40);
    servo2_Mo(25);
    servo2_Dong(20);
    delay(700);
    servo1_Dong(4);
    break;
   }
  }
}
