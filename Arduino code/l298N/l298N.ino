#define LED1 8
#define LED2 4
#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
 
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(LED1,LOW);
}
 
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
   digitalWrite(LED2,LOW);
}
 
void motor_1_Tien(int speed) 
{ 
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 255 - speed);
  digitalWrite(LED1,HIGH);
}
 
void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW); 
  analogWrite(IN2, speed);
  digitalWrite(LED1,HIGH);
}
 
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN3, LOW);
  digitalWrite(IN4, speed);
  digitalWrite(LED2,HIGH);
}
 
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN4, 255 - speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
  digitalWrite(LED2,HIGH);
}
void den()
{
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  delay(1000);
  digitalWrite(LED1,LOW);
  digitalWrite(LED1,LOW);
  delay(1000);
}
 
void loop()
{
 
  motor_1_Tien(MAX_SPEED); // motor 1 tiến
  motor_2_Tien(MAX_SPEED); // motor 1 tiến
  delay(3000);//tiến 5 s
  motor_1_Dung();
  motor_2_Dung();
  delay(1000);//dừng 10s
  motor_1_Lui(MAX_SPEED); //motor 2 lùi
   motor_2_Lui(MAX_SPEED); //motor 2 lùi
  // motor 1 vẫn tiến
  delay(3000);//tiến 2 s
  motor_1_Dung();
  motor_2_Dung();
  delay(1000);//dừng 10s
  motor_1_Tien(MAX_SPEED); // motor 1 tiến
  delay(1000);
   motor_1_Dung(); delay(200);
   motor_2_Tien(MAX_SPEED); // motor 1 tiến
   delay(1000);
   motor_2_Dung(); delay(200);
}
