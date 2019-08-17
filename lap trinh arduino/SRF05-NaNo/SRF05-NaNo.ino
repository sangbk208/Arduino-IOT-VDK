#define led13 13
const int trig = 2;  
const int echo = 3; 
void setup()
{
    pinMode(led13,OUTPUT);
    Serial.begin(9600);     
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);   
}
 
void loop()
{
    unsigned long duration; // biến đo thời gian
    int distance;           
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
  Serial.print(distance);Serial.println("cm");
  if(distance<20) digitalWrite(led13,1);else digitalWrite(led13,0);
}
