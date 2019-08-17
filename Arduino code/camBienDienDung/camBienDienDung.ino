int i=0;
void setup()
{

pinMode(3,INPUT_PULLUP);
pinMode(13,OUTPUT);
attachInterrupt(1,ngat1,CHANGE);
Serial.begin(9600);
}
void ngat1()
{
  if(digitalRead(3)==HIGH)
 {
  i=!i;
 }
}
void loop() 
{
 
 digitalWrite(13,i);
 Serial.println(i);
}
