// 1 độ tương ứng với 10mV
int i=A0;
int k;
void setup() 
{
 Serial.begin(9600);
}
void loop() 
{
k=analogRead(i);
float nd=k*(5.0/1024.0)*100;
Serial.println(nd);delay(1000);
}
