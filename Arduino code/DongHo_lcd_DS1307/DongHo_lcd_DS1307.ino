// Đồng Hồ lcd Thời Gian Thực
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,16,2); 
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
/* khai báo các biến thời gian */
int second, minute, hour, day, wday, month, year;
#define MENU1    8
#define TANG     10
#define GIAM     11
#define MENU2    9
byte g=0,p=0,m=0;
byte caiChuong[8]={
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};

//SETUP---------

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(MENU1,INPUT_PULLUP);
  pinMode(TANG,INPUT_PULLUP);
  pinMode(MENU2,INPUT_PULLUP);
  pinMode(GIAM,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  lcd.init();  
  lcd.backlight(); 
  lcd.setCursor(2,0);
  lcd.print("DONG HO LCD");
  lcd.setCursor(2,1);
  lcd.print("SANG NGUYEN");
  delay(3000);
  lcd.clear();
void SetTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr);
}
//LOOP---------

void loop()
{
  byte CheDo1=0;
  byte CheDo2=0;
     while(1)
     { 
         readDS1307();      
         digitalClockDisplay();  
      if(digitalRead(MENU1)==0)//neu nhan nut
       {
         while(digitalRead(MENU1)==0);
         CheDo1=1;//chuyen sang che do cai dat
         lcd.clear();//xoa man hinh LCD
       }
  // chỉnh Giờ        ----------------------------
      while(CheDo1==1)//che do cai gio
      {
        lcd.setCursor(0,0);
        lcd.print("CAI DAT : GIO");
        gio(hour);
        if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          hour = hour+1;
          if(hour>24)
          {
            hour=1;
          }
          SetTime(hour, minute, second, wday, day, month, year);
        }
         if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          hour = hour-1;
          if(hour<1)
          {
            hour=24;
          }
          SetTime(hour, minute, second, wday, day, month, year);
  // chỉnh phút        ----------------------------
        }
        if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1;//chuyen sang che do cai dat khac
        }
        while(CheDo1==2)//che do cai phut
      {
         lcd.setCursor(0,0);
        lcd.print("CAI DAT : PHUT");
         phut(minute);
         if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          minute = minute+1;
          if(minute>59)
          {
            minute=0;
          }
         SetTime(hour, minute, second, wday, day, month, year);
        }
          if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          minute = minute-1;
          if(minute<0)
          {
            minute=59;
          }
          SetTime(hour, minute, second, wday, day, month, year);
        }
  // Chỉnh GIÂY ---------------------------------------------------------     
        if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1;//chuyen sang che do cai dat khac
        }
        while(CheDo1==3)//che do cai giay
      {
         lcd.setCursor(0,0);
         lcd.print("CAI DAT : GIAY");
         giay(second);
         if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          second = second+1;
          if(second>59)
          {
            second=0;
          }
          SetTime(hour, minute, second, wday, day, month, year);
          }
          if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          second = second-1;
          if(second<0)
          {
            second=59;
          }
          SetTime(hour, minute, second, wday, day, month, year);
        }

 //----- cài hẹn giờ
        if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1; lcd.clear();//chuyen sang che do cai dat khac
        }
      while(CheDo1==4)//che do hẹn giờ
      {
       lcd.setCursor(0,0);
       lcd.print("CAI DAT HEN GIO");
       gio2();
      if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          g = g+1;
          if(g>24)
          {
            g=1;
          }
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          g = g-1;
          if(g<1)
          {
            g=24;
          }
        }
  //hen phut      ------------
          if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1;//chuyen sang che do cai dat khac
        }
      while(CheDo1==5)//che do hẹn giờ
      {
       lcd.setCursor(0,0);
       lcd.print("CAI DAT HEN GIO");
       phut2();
      if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          p = p+1;
          if(p>59)
          {
            p=0;
          }
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          p = p-1;
          if(p<0)
          {
            p=59;
          }
     }
  //---hẹn giây
    if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1;//chuyen sang che do cai dat khac
        }
      while(CheDo1==6)//che do hẹn giờ
      {
       lcd.setCursor(0,0);
       lcd.print("CAI DAT HEN GIO");
       giay2();
      if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          m = m+1;
          if(p>59)
          {
            m=0;
          }
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          m = m-1;
          if(m<0)
          {
            m=59;
          }
     }   
     if(digitalRead(MENU1)==0)//neu nhan nut
        {
          while(digitalRead(MENU1)==0);
          CheDo1=CheDo1+1;//chuyen sang che do cai dat khac
        }
        if (CheDo1>6) CheDo1=0;
      }
}
}
      }
      }
      }
//------so sánh báo thứ với time------------------------------
if ((g==hour)&&(p==minute)&&(m==second)) loaKeu(10);
     }
} 
void gio2()
{      int q,w;
       lcd.setCursor(0,1);
       lcd.print(">>>");
       lcd.setCursor(12,1);
       lcd.print(" <<<");
     if(g < 10) 
          {w=4;q=5;
          lcd.setCursor(w,1);
          lcd.print("0");
          lcd.setCursor(q,1);
          lcd.print(g);}
          if (g>=10) 
          {q=4;
          lcd.setCursor(q,1);
          lcd.print(g);}     
}
void phut2()
{
    int i,k;
    lcd.setCursor(6,1);
    lcd.print(":");
   if(p < 10) {k=7;i=8;
    lcd.setCursor(k,1);
    lcd.print("0");
    lcd.setCursor(i,1);
    lcd.print(p);}
   if (p>=10) 
    {i=7;
    lcd.setCursor(i,1);
    lcd.print(p);}
}
void giay2()
{
  int i,k;
    lcd.setCursor(9,1);
    lcd.print(":");
   if(m < 10) 
    {k=10;i=11;
    lcd.setCursor(k,1);
    lcd.print("0");
    lcd.setCursor(i,1);
    lcd.print(m);}
   if (m>=10) 
    {i=10;
    lcd.setCursor(i,1);
    lcd.print(m);}
}
void readDS1307()
{
        Wire.beginTransmission(DS1307);
        Wire.write((byte)0x00);
        Wire.endTransmission();
        Wire.requestFrom(DS1307, NumberOfFields);
        second = bcd2dec(Wire.read() & 0x7f);
        minute = bcd2dec(Wire.read() );
        hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
        wday   = bcd2dec(Wire.read() );
        day    = bcd2dec(Wire.read() );
        month  = bcd2dec(Wire.read() );
        year   = bcd2dec(Wire.read() );
        year += 2000;    
}
/* Chuyển từ format BCD (Binary-Coded Decimal) sang Decimal */
int bcd2dec(byte num)
{
        return ((num/16 * 10) + (num % 16));
}
/* Chuyển từ Decimal sang BCD */
int dec2bcd(byte num)
{
        return ((num/10 * 16) + (num % 10));
}
void digitalClockDisplay(){
    gio(hour); phut(minute); giay(second); thu(wday); ngay(day); thang(month); nam(year);
}
void nam(int digits) { lcd.setCursor(12,0); lcd.print(digits);}
void thang(int digits)
{ int k,i;
  if (digits<10)
  { k=9,i=10;
    lcd.setCursor(k,0);
    lcd.print("0");
    lcd.setCursor(i,0);
    lcd.print(digits);
  }
  if (digits>=10)
  { i=9;
    lcd.setCursor(i,0);
    lcd.print(digits);
   }
    lcd.setCursor(11,0);
    lcd.print("/"); 
} 
void ngay(int digits)
{ int k,i;
  if (digits<10)
  { k=5,i=7;
    lcd.setCursor(k,0);
    lcd.print(" 0");
    lcd.setCursor(i,0);
    lcd.print(digits);
  }
  if (digits>=10)
  { i=6;
    lcd.setCursor(i,0);
    lcd.print(digits);
   }
    lcd.setCursor(8,0);
    lcd.print("/");  
}
void thu(int digits)
{
  lcd.setCursor(0,0);
  lcd.print("Thu:");
  lcd.setCursor(4,0);
  lcd.print(digits);
}
void gio(int digits)
{
   int i,k;
    lcd.setCursor(0,1);
    lcd.print(">>>");
    lcd.setCursor(12,1);
    lcd.print(" <<<");
   if(digits < 10) 
   {k=4;i=5;
    lcd.setCursor(k,1);
    lcd.print("0");
    lcd.setCursor(i,1);
    lcd.print(digits);}
   if (digits>=10) 
    {i=4;
    lcd.setCursor(i,1);
    lcd.print(digits);}
}
void phut(int digits)
{
   int i,k;
    lcd.setCursor(6,1);
    lcd.print(":");
   if(digits < 10) {k=7;i=8;
    lcd.setCursor(k,1);
    lcd.print("0");
    lcd.setCursor(i,1);
    lcd.print(digits);}
   if (digits>=10) 
    {i=7;
    lcd.setCursor(i,1);
    lcd.print(digits);}
}
void giay(int digits)
{
   int i,k;
    lcd.setCursor(9,1);
    lcd.print(":");
   if(digits < 10) 
    {k=10;i=11;
    lcd.setCursor(k,1);
    lcd.print("0");
    lcd.setCursor(i,1);
    lcd.print(digits);}
   if (digits>=10) 
    {i=10;
    lcd.setCursor(i,1);
    lcd.print(digits);}
} 
void SetTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
    Wire.beginTransmission(DS1307);
        Wire.write(byte(0x00)); // đặt lại pointer
        Wire.write(dec2bcd(sec));
        Wire.write(dec2bcd(min));
        Wire.write(dec2bcd(hr));
        Wire.write(dec2bcd(wd)); // day of week: Sunday = 1, Saturday = 7
        Wire.write(dec2bcd(d)); 
        Wire.write(dec2bcd(mth));
        Wire.write(dec2bcd(yr));
        Wire.endTransmission();
}
void loaKeu(int lan)
{
  lcd.clear();
  for(int i=0;i<=lan;i++)
  {
  digitalWrite(12,1);
  lcd.setCursor(4,0);
  lcd.print("BAO THUC");
  delay(800);
  digitalWrite(12,0);
  lcd.setCursor(4,0);
  lcd.print("        ");
  delay(800);
  }
}

