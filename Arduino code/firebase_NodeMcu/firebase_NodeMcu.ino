#include <SoftwareSerial.h>
#define tx 5
#define rx 4
SoftwareSerial nodeMCU(rx,tx);

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "nodemcufirebase-38dc6.firebaseio.com"        //Thay bằng địa chỉ firebase của bạn
#define FIREBASE_AUTH "bs3NPE6QdbL3PTsFVMWLIs3NobWhI962XDHGwgaF"   //Không dùng xác thực nên không đổi
#define WIFI_SSID "Lien Quan Center"   //Thay wifi và mật khẩu
#define WIFI_PASSWORD "wi    fi"
int i=1;

void setup() {
  nodeMCU.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(0,INPUT);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
//  while(1){
//  if(digitalRead(0)==0){
//    delay(200);
//    i=!i;
//    Firebase.setInt("led",i);
//  } 
  // nodeMCU.print(Firebase.getInt("led"));
   Serial.println(Firebase.setInt("led",i));
  //}
}
