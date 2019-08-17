int sensorPin = A0;// chân analog kết nối tới cảm biến LM35
 
void setup() {
  Serial.begin(9600);  //Khởi động Serial ở mức baudrate 9600
  // Bạn không cần phải pinMode cho các chân analog trước khi dùng nó
}
 
void loop() {
 //đọc giá trị từ cảm biến LM35
 int reading = analogRead(sensorPin);  
 
 //tính ra giá trị hiệu điện thế (đơn vị Volt) từ giá trị cảm biến
 float voltage = reading * 5.0 / 1024.0; 
 
 // ở trên mình đã giới thiệu, cứ mỗi 10mV = 1 độ C.
 // Vì vậy nếu biến voltage là biến lưu hiệu điện thế (đơn vị Volt)
 // thì ta chỉ việc nhân voltage cho 100 là ra được nhiệt độ!
 

 
 Serial.println(voltage*100);
 /*Mẹo:
   Các bạn phaỉ khai báo phần thực cho toàn bộ các số thực nhé!
 */
 delay(1000);//đợi 1 giây cho lần đọc tiếp theo
}
