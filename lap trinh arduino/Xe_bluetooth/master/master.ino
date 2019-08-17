#include <SoftwareSerial.h>
#define tx 11
#define rx 10
SoftwareSerial bluetooth(rx,tx);
#define F 2
#define B 3
#define L A3
#define R A2
void setup() 
 {
  pinMode(F,INPUT_PULLUP);
  pinMode(B,INPUT_PULLUP);
  pinMode(L,INPUT_PULLUP);
  pinMode(R,INPUT_PULLUP);
  Serial.begin(9600);
  bluetooth.begin(9600);
 }
void loop() 
{ 
 while(1)
 {
  bluetooth.print("S");
  if(digitalRead(F)==0) while(digitalRead(F)==0) 
  {bluetooth.print("F"); if((digitalRead(R)==0)&&(digitalRead(F)==0)){while((digitalRead(R)==0)&&(digitalRead(F)==0)){bluetooth.print("I");}}
  if((digitalRead(L)==0)&&(digitalRead(F)==0)){while((digitalRead(L)==0)&&(digitalRead(F)==0)){bluetooth.print("G");}}
  if(digitalRead(F)==1){bluetooth.print("S");break;}}

  if(digitalRead(B)==0) while(digitalRead(B)==0) 
  {bluetooth.print("B"); if((digitalRead(B)==0)&&(digitalRead(R)==0)){while((digitalRead(R)==0)&&(digitalRead(B)==0)){bluetooth.print("J");}}
  if((digitalRead(L)==0)&&(digitalRead(B)==0)){while((digitalRead(L)==0)&&(digitalRead(B)==0)){bluetooth.print("H");}}
  if(digitalRead(B)==1){bluetooth.print("S");break;}}
  
  
  if(digitalRead(R)==0) while(digitalRead(R)==0) {bluetooth.print("R");
  if((digitalRead(R)==0)&&(digitalRead(F)==0)){while((digitalRead(R)==0)&&(digitalRead(F)==0)){bluetooth.print("I");}}
  if((digitalRead(R)==0)&&(digitalRead(B)==0)){while((digitalRead(R)==0)&&(digitalRead(B)==0)){bluetooth.print("J");}}
  if(digitalRead(R)==1){bluetooth.print("S");break;}}
  
  if(digitalRead(L)==0) while(digitalRead(L)==0) {bluetooth.print("L");
   if((digitalRead(L)==0)&&(digitalRead(F)==0)){while((digitalRead(L)==0)&&(digitalRead(F)==0)){bluetooth.print("G");}}
  if((digitalRead(L)==0)&&(digitalRead(B)==0)){while((digitalRead(L)==0)&&(digitalRead(B)==0)){bluetooth.print("H");}}
  if(digitalRead(L)==1){bluetooth.print("S");break;}}  
  
 }
 
}
