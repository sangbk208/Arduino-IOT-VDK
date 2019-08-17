#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
void setup() {
  delay(1000);
  mySerial.begin(9600);
  delay(100);
  mySerial.write("AT+CMGF=1\r\n");
  delay(100);
  mySerial.write("AT+CMGS=\"01266595004\"\r\n");
  delay(100);
  mySerial.write("sang dai ca");
  delay(100);
  mySerial.write(0x1A);
}

void loop() 
{
 
}
