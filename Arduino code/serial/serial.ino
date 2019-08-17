#define led13 13
char nhap;
String chuoi="" ;
void setup() {
  pinMode(led13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 
  if (Serial.available()>0)
  {
    nhap=Serial.read();
     chuoi=chuoi+nhap;
    Serial.print(nhap);
    if (chuoi=="BAT LED") {digitalWrite(led13,HIGH) ;chuoi="";}
    else if (chuoi=="TAT LED"){ digitalWrite(led13,LOW) ;chuoi="";}
    
    }

}
