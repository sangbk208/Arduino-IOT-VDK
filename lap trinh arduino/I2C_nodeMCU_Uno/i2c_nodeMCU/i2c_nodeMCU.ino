#include <Wire.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "nodemcufirebase-38dc6.firebaseio.com" //Thay bằng địa chỉ firebase của bạn
#define FIREBASE_AUTH "bs3NPE6QdbL3PTsFVMWLIs3NobWhI962XDHGwgaF"   //Không dùng xác thực nên không đổi
#define WIFI_SSID "Lien Quan Center"   //Thay wifi và mật khẩu
#define WIFI_PASSWORD "xomtro123"

void setup() {
 Serial.begin(9600); /* begin serial for debug */
   pinMode(0,INPUT);
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

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
  //truyền
 Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write(Firebase.getInt("1135823918"));  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */

//nhận
 Wire.requestFrom(8, 1); /* request & read data of size 13 from slave */
 while(Wire.available()){
    int c = Wire.read();
  Serial.print(c);
Firebase.setInt("1135823918",c);
 }
 Serial.println();
 delay(1000);


}
