#include <SoftwareSerial.h>

String readString;
SoftwareSerial mySerial(10, 11); // RX, TX
String trangthaiweb;

void setup() 
{
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.print("AT+CIPSHUT\r\n");
  delay(6000);
}

void loop() 
{ 
  mySerial.print("AT+CIPSTART=\"TCP\",\"iot04.tapit.vn\",\"80\"\r\n");
  delay(2000);
  String x = mySerial.readString(); Serial.println(x);
  mySerial.print("AT+CIPSEND\r\n");
  delay(4000);
  x = mySerial.readString(); Serial.println(x);
  mySerial.print("GET /iot_source/status.php HTTP/1.1\r\n");
  Serial.flush();
  x = mySerial.readString(); Serial.println(x);
  mySerial.print("Host: iot04.tapit.vn\r\n");
 // Serial.flush();
  mySerial.print("Connection: Keep-Alive\r\n\r\n");
 // Serial.flush();
  x = mySerial.readString(); Serial.println(x);
  mySerial.print("\x1A");
  x = mySerial.readString(); 
  Serial.println(x);

     if(x.endsWith("|1"))
      {
        Serial.print("theo ly thuyet den da bat");
        digitalWrite(LED_BUILTIN,HIGH);
      }
      else  if(x.endsWith("|0"))
      {
         Serial.print("theo ly thuyet den da tat");
         digitalWrite(LED_BUILTIN,LOW);
      }
    mySerial.print("AT+CIPSHUT\r\n");
   
    delay(4000);
    delay(4000);
    delay(4000);
    delay(4000);
    delay(4000);

}


