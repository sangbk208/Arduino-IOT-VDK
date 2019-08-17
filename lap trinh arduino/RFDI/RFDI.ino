#include <SPI.h>
#include <MFRC522.h> // thu vien "RFID".
#include <Servo.h> // thu vien "servo".
#include <Wire.h>  // thu vien i2c

#include <SoftwareSerial.h>

SoftwareSerial unoSerial(3, 4); // RX, TX

const int coi = 2; // còi
#define camBien  5 

/*
Ket noi voi Arduino Uno hoac Mega
 ----------------------------------------------------- Nicola Coppola
 * Pin layout should be as follows:
 * Signal     Pin              Pin               Pin
 *            Arduino Uno      Arduino Mega      MFRC522 board
 * ------------------------------------------------------------
 * Reset      9                5                 RST
 * SPI SS     10               53                SDA
 * SPI MOSI   11               51                MOSI
 * SPI MISO   12               50                MISO
 * SPI SCK    13               52                SCK
 
 */

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);       
unsigned long uidDec, uidDecTemp; // hien thi so UID dang thap phan
byte bCounter, readBit;
unsigned long ticketNumber;

Servo myservo;
int pos = 0;


bool stringComplete = false;

void setup() {
  myservo.attach(6);
  myservo.write(125);  
  //
  unoSerial.begin(9600);
  //
  pinMode(coi, OUTPUT);
  pinMode(camBien, INPUT);
  Serial.begin(9600);     
  SPI.begin();            
  mfrc522.PCD_Init();     
  Serial.println("Prilozhite kartu / Waiting for card...");
}


void loop() {
    serialEventVao();

  // Tim the moi
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
      return;
  }

  // Doc the
  if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
  }

  uidDec = 0;
  Serial.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
  Serial.println("================================================");
  // Hien thi so UID cua the
  Serial.println("Serijnyj nomer karty / Card UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec*256+uidDecTemp;
  } 
  Serial.println(uidDec);
  unoSerial.print(uidDec);
  mfrc522.PICC_HaltA();
  ////////////////////   
}

void serialEventVao() {
     while(unoSerial.available()){
           char inCharVao = (char)unoSerial.read();
           Serial.println(inCharVao);
           stringComplete = true;
           if(stringComplete){
              if(inCharVao=='m'){
                 Serial.println("Mở cổng vào");  
                 coiBao(1);
                 servoMo();
                 stringComplete = false;   
              }else if(inCharVao=='k'){
                       Serial.println("không Mở");
                       coiBao(3);
                       stringComplete = false;}
              }
     }
}
  
void servoMo(){
       for(pos = 125; pos >= 35; pos -= 1) { // goes from 180 degrees to 0 degrees
                 myservo.write(pos);              // tell servo to go to position in variable 'pos'
                 delay(15); // waits 15ms for the servo to reach the position              
                 }
}                 
void servoDong(){
       for(pos = 35; pos <= 125; pos += 1) { // goes from 180 degrees to 0 degrees
                 myservo.write(pos);              // tell servo to go to position in variable 'pos'
                 delay(15); // waits 15ms for the servo to reach the position              
                 }
}

void coiBao(int j){
        for(int i=1;i<=j;i++){
            digitalWrite(coi,1);
            delay(400);
            digitalWrite(coi,0);
            delay(400);
        }
}


 
