#include <Wire.h>
int c;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(5,INPUT);
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 //Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */
 digitalWrite(5,0);
}

void loop() {
 delay(100);
 if(digitalRead(5)==1){
  delay(100);
   c=!c;
 Wire.onRequest(Wire.write(c));
 digitalWrite(13,c);
 }
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
     c = Wire.read();      /* receive byte as a character */
    Serial.print(c);           /* print the character */
     digitalWrite(13,c);
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
 Wire.write("Hello NodeMCU");  /*send string on request */
}
