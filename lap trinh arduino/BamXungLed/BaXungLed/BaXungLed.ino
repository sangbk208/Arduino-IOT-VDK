#define led 1
#define tang 5
#define thap 0
void setup() {
  pinMode(led,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  
  analogWrite(led,thap);
  led=led+tang;
  if(led==0|| led==250)
  {
    led=-thang;
    }
    delay(5);
  // put your main code here, to run repeatedly:

}
