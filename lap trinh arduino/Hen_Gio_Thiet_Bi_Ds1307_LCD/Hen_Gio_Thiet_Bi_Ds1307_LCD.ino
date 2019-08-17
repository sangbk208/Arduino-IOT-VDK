#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F,20,4); 

int t=0,j=0,k=0,l=0,x=0,y=0;
int n=0,m=0,a=0,b=0,c=0,d=0,f=0,e=0;
// nút điều khiển bơm
#define in1 2
#define in2 3
#define in3 18
#define in4 19
#define in5 51
#define in6 53
//khai bao ket noi cac nut nhan
#define MENU      8
#define TANG      9
#define GIAM      10
#define HEN_GIO   11
#define CHON_BOM  12
//
#define RELAY_1 4
#define RELAY_2 5
#define RELAY_3 6
#define RELAY_4 7

int i=0;
int second, minute, hour, day, wday, month, year;

const byte DS1307 = 0x68;
const byte NumberOfFields = 7;

void _HienThiSo(signed int SoDem);
void _ReadDS1307(void);
void _SetTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr);
int _BCD2DEC(byte num);
int _DEC2BCD(byte num);
void _HienThiThoiGian(void);

void setup() 
{
  pinMode(in1,INPUT_PULLUP);
  pinMode(in2,INPUT_PULLUP);
  pinMode(in3,INPUT_PULLUP);
  pinMode(in4,INPUT_PULLUP);
  pinMode(in5,INPUT_PULLUP);
  pinMode(in6,INPUT_PULLUP);
  //
  pinMode(RELAY_1,OUTPUT);
  pinMode(RELAY_2,OUTPUT);
  pinMode(RELAY_3,OUTPUT);
  pinMode(RELAY_4,OUTPUT);
  //
  pinMode(MENU,INPUT_PULLUP);
  pinMode(TANG,INPUT_PULLUP);
  pinMode(GIAM,INPUT_PULLUP);
  pinMode(HEN_GIO,INPUT_PULLUP);
  pinMode(CHON_BOM,INPUT_PULLUP);
  //
  attachInterrupt(0,ngat1,CHANGE);
  attachInterrupt(1,ngat2,CHANGE);
  attachInterrupt(5,ngat3,CHANGE);
  attachInterrupt(4,ngat4,CHANGE);
  //
  lcd.init();  
  lcd.backlight();
  Wire.begin();
  Serial.begin(9600);
  lcd.setCursor(7,1);lcd.print("HELLO");
  lcd.setCursor(4,2);lcd.print("SANG NGUYEN");
  delay(1998);
  lcd.clear();
}

//
void ngat1()
{
    if(digitalRead(in1)==0) t=1; else t=0;
}
void ngat2()
{
    if(digitalRead(in2)==0) j=1; else j=0;
}
void ngat3()
{
    if(digitalRead(in3)==0) k=1; else k=0;
}
void ngat4()
{
    if(digitalRead(in4)==0) l=1; else l=0;
}
void tt()
{
  if(t==0){lcd.setCursor(3,2);lcd.print("0");}
     else {lcd.setCursor(3,2);lcd.print("1");}
  if(j==0){lcd.setCursor(8,2);lcd.print("0");}
     else {lcd.setCursor(8,2);lcd.print("1");}
  if(k==0){lcd.setCursor(13,2);lcd.print("0");}
     else {lcd.setCursor(13,2);lcd.print("1");}
  if(l==0){lcd.setCursor(3,3);lcd.print("0");}
     else {lcd.setCursor(3,3);lcd.print("1");}
  if(x==0){lcd.setCursor(8,3);lcd.print("0");}
  if(y==0){lcd.setCursor(13,3);lcd.print("0");}  
}
void in56()
{
 while(digitalRead(in5)==0) 
 {
  x=1;if(x==1) {lcd.setCursor(8,3);lcd.print("1");}
  if(digitalRead(in5)==1){x=0;break; }
 }
 while(digitalRead(in6)==0) 
 {
  y=1;if(y==1) {lcd.setCursor(13,3);lcd.print("1");}
  if(digitalRead(in6)==1){y=0;break; }
 }
  }
//
void loop() 
{ 
  byte CheDo=0;
  byte CheDo1=0;
  signed char GioHen=0, PhutHen=0; 
  signed char GioHen2=0, PhutHen2=0;
  signed char GioB2_1=0, PhutB2_1=0; 
  signed char GioB2_2=0, PhutB2_2=0;
  signed char GioB3_1=0, PhutB3_1=0; 
  signed char GioB3_2=0, PhutB3_2=0;
  signed char GioB4_1=0, PhutB4_1=0; 
  signed char GioB4_2=0, PhutB4_2=0;
  byte HenBom=0;
   while(1)
   { 
    tt();
    in56();
// điều khiện hẹn giờ thiết bị 1    
    if(hour==GioHen && minute==PhutHen && a==1)
      {
        digitalWrite(RELAY_1,HIGH);a=0;
      }
     if(hour==GioHen2 && minute==PhutHen2 && b==1)
      {
        digitalWrite(RELAY_1,LOW);b=0;
      }      
//     
//điều kiện hẹn giờ thiết bị 2
     if(hour==GioB2_1 && minute==PhutB2_1 && c==1)
      {
        digitalWrite(RELAY_2,HIGH);c=0;
      }
     if(hour==GioB2_2 && minute==PhutB2_2 && d==1)
      {
        digitalWrite(RELAY_2,LOW);d=0;
      }      
//
//điều kiện hẹn giờ thiết bị 3
     if(hour==GioB3_1 && minute==PhutB3_1 && e==1)
      {
        digitalWrite(RELAY_3,HIGH);e=0;
      }
     if(hour==GioB3_2 && minute==PhutB3_2 && f==1)
      {
        digitalWrite(RELAY_3,LOW);f=0;
      }      
//
//điều kiện hẹn giờ thiết bị 4
     if(hour==GioB4_1 && minute==PhutB4_1 && n==1)
      {
        digitalWrite(RELAY_4,HIGH);n=0; 
      }
     if(hour==GioB4_2 && minute==PhutB4_2 && m==1)
      {
        digitalWrite(RELAY_4,LOW);m=0;
      }      
//
      _ReadDS1307();      
      _HienThiThoiGian(); 
//### Hen Giờ Bơm     
     if(digitalRead(HEN_GIO)==0)
     {
        while(digitalRead(HEN_GIO)==0); 
        CheDo1=1;//chuyen sang che do cai dat
        lcd.clear();//xoa man hinh LCD
     }
//che do chọn bơm     
     while(CheDo1==1)
      {
       lcd.setCursor(0,0);
       lcd.print("CHE DO HEN GIO");

      if(digitalRead(HEN_GIO)==0)
        {
          while(digitalRead(HEN_GIO)==0); 
          CheDo1++;//chuyen sang che do cai dat
          lcd.clear();//xoa man hinh LCD
        }
      }
 // chon bơm 1     
       while(CheDo1==2)
      {
          lcd.setCursor(0,0);
          lcd.print("CHE DO CHON TB");
          lcd.setCursor(0,1);
          lcd.print("Moi chon TB1");
         while(HenBom==0) 
         {      
          if(digitalRead(CHON_BOM)==0)
         {
          while(digitalRead(CHON_BOM)==0); 
          HenBom=1;//chuyen sang che do cai dat
          lcd.clear();//xoa man hinh LCD
         } else break;
  // Hẹn giờ bật bơm 1      
         while(HenBom==1)
         {
           lcd.setCursor(0,0);
           lcd.print("TB1: HEN GIO BAT");
           lcd.setCursor(0,1);
           lcd.print("GIO BAT: ");
           _HienThiSo(GioHen);

           if(digitalRead(TANG)==0)//neu nhan nut nhan
             {
               while(digitalRead(TANG)==0);
               GioHen = GioHen+1;
               if(GioHen>23)
                 {
                  GioHen=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
              {
                while(digitalRead(GIAM)==0);
                GioHen = GioHen-1;
                if(GioHen<0)
                {
                 GioHen=23;
                }       
              }   
          if(digitalRead(CHON_BOM)==0)
          {
           while(digitalRead(CHON_BOM)==0); 
           HenBom++;
           lcd.clear();//xoa man hinh LCD
          }
         }
 // Hẹn phút bật bơm      
       while(HenBom==2)
            {
              lcd.setCursor(0,0);
              lcd.print("TB1: HEN PHUT BAT");
              lcd.setCursor(0,1);
              lcd.print("PHUT BAT: ");
              _HienThiSo(PhutHen);
            if(digitalRead(TANG)==0)//neu nhan nut nhan
              {
                while(digitalRead(TANG)==0);
                PhutHen = PhutHen+1;
                if(PhutHen>59)
                 {
                  PhutHen=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
             {
              while(digitalRead(GIAM)==0);
              PhutHen = PhutHen-1;
              if(PhutHen<0)
                {
                 PhutHen=59;
                }       
             }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              a=1;
              lcd.clear();//xoa man hinh LCD
             }
           }
   // Hẹn Giờ tắt bơm
         while(HenBom==3)
              {
               lcd.setCursor(0,0);
               lcd.print("TB1: HEN GIO TAT");
               lcd.setCursor(0,1);
               lcd.print("GIO TAT: ");
               _HienThiSo(GioHen2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 GioHen2 = GioHen2+1;
                 if(GioHen2>23)
                   {
                    GioHen2=0;
                   }       
                }
             if(digitalRead(GIAM)==0)//neu nhan nut nhan
               {
                while(digitalRead(GIAM)==0);
                GioHen2 = GioHen2-1;
             if(GioHen2<0)
               {
                GioHen2=23;
               }       
               }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }              
         }
  // Hẹn Phút tắt bơm   
       while(HenBom==4)
            {
               lcd.setCursor(0,0);
               lcd.print("TB1: HEN PHUT TAT");
               lcd.setCursor(0,1);
               lcd.print("PHUT TAT: ");
               _HienThiSo(PhutHen2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 PhutHen2 = PhutHen2+1;
                if(PhutHen2>59)
                   {
                    PhutHen2=0;
                   }       
                }
              if(digitalRead(GIAM)==0)//neu nhan nut nhan
                {
                  while(digitalRead(GIAM)==0);
                  PhutHen2 = PhutHen2-1;
                  if(PhutHen2<0)
                    {
                     PhutHen2=59;
                    }       
                 } 
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              b=1;
              lcd.clear();//xoa man hinh LCD
             } 
          }                 
// Thông báo hẹn giờ ok cho bơm 1                 
       while(HenBom==5)
            {
               lcd.setCursor(0,0);
               lcd.print("TB1: HEN GIO OK !");
            
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom=0;CheDo1++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }
            }                
         }
  //---     
          if(digitalRead(HEN_GIO)==0)
            {
             while(digitalRead(HEN_GIO)==0); 
             CheDo1++;//chuyen sang che do cai dat
             lcd.clear();//xoa man hinh LCD
            }
      }
 // chọn bơm 2     
      while(CheDo1==3)
      {
         lcd.setCursor(0,0);
         lcd.print("CHE DO CHON TB");
         lcd.setCursor(0,1);
         lcd.print("Moi chon TB2");
          while(HenBom==0) 
         {      
          if(digitalRead(CHON_BOM)==0)
         {
          while(digitalRead(CHON_BOM)==0); 
          HenBom=1;//chuyen sang che do cai dat
          lcd.clear();//xoa man hinh LCD
         } else break;
         //
// Hẹn giờ bật bơm 2     
         while(HenBom==1)
         {
           lcd.setCursor(0,0);
           lcd.print("TB2: HEN GIO BAT");
           lcd.setCursor(0,1);
           lcd.print("GIO BAT: ");
           _HienThiSo(GioB2_1);

           if(digitalRead(TANG)==0)//neu nhan nut nhan
             {
               while(digitalRead(TANG)==0);
               GioB2_1 = GioB2_1+1;
               if(GioB2_1>23)
                 {
                  GioB2_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
              {
                while(digitalRead(GIAM)==0);
                GioB2_1 = GioB2_1-1;
                if(GioB2_1<0)
                {
                 GioB2_1=23;
                }       
              }   
          if(digitalRead(CHON_BOM)==0)
          {
           while(digitalRead(CHON_BOM)==0); 
           HenBom++;
           lcd.clear();//xoa man hinh LCD
          }
         }
 // Hẹn phút bật bơm 2      
       while(HenBom==2)
            {
              lcd.setCursor(0,0);
              lcd.print("TB2: HEN PHUT BAT");
              lcd.setCursor(0,1);
              lcd.print("PHUT BAT: ");
              _HienThiSo(PhutB2_1);
            if(digitalRead(TANG)==0)//neu nhan nut nhan
              {
                while(digitalRead(TANG)==0);
                PhutB2_1 = PhutB2_1+1;
                if(PhutB2_1>59)
                 {
                  PhutB2_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
             {
              while(digitalRead(GIAM)==0);
              PhutB2_1 = PhutB2_1-1;
              if(PhutB2_1<0)
                {
                 PhutB2_1=59;
                }       
             }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              c=1;
              lcd.clear();//xoa man hinh LCD
             }
           }
   // Hẹn Giờ tắt bơm 2
         while(HenBom==3)
              {
               lcd.setCursor(0,0);
               lcd.print("TB2: HEN GIO TAT");
               lcd.setCursor(0,1);
               lcd.print("GIO TAT: ");
               _HienThiSo(GioB2_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 GioB2_2 = GioB2_2+1;
                 if(GioB2_2>23)
                   {
                    GioB2_2=0;
                   }       
                }
             if(digitalRead(GIAM)==0)//neu nhan nut nhan
               {
                while(digitalRead(GIAM)==0);
                GioB2_2= GioB2_2-1;
             if(GioB2_2<0)
               {
                GioB2_2=23;
               }       
               }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }              
         }
  // Hẹn Phút tắt bơm 2
       while(HenBom==4)
            {
               lcd.setCursor(0,0);
               lcd.print("TB2: HEN PHUT TAT");
               lcd.setCursor(0,1);
               lcd.print("PHUT TAT: ");
               _HienThiSo(PhutB2_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 PhutB2_2 = PhutB2_2+1;
                if(PhutB2_2>59)
                   {
                    PhutB2_2=0;
                   }       
                }
              if(digitalRead(GIAM)==0)//neu nhan nut nhan
                {
                  while(digitalRead(GIAM)==0);
                  PhutB2_2 = PhutB2_2-1;
                  if(PhutB2_2<0)
                    {
                     PhutB2_2=59;
                    }       
                 } 
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              d=1;
              lcd.clear();//xoa man hinh LCD
             } 
          }                 
// Thông báo hẹn giờ ok cho bơm 1                 
       while(HenBom==5)
            {
               lcd.setCursor(0,0);
               lcd.print("TB2: HEN GIO OK !");
            
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom=0;CheDo1++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }
            }                
         }
                if(digitalRead(HEN_GIO)==0)
            {
             while(digitalRead(HEN_GIO)==0); 
             CheDo1++;//chuyen sang che do cai dat
             lcd.clear();//xoa man hinh LCD
            }
      }
  //
 // chọn bơm 3     
      while(CheDo1==4)
      {
         lcd.setCursor(0,0);
         lcd.print("CHE DO CHON TB");
         lcd.setCursor(0,1);
         lcd.print("Moi chon TB3");
          while(HenBom==0) 
         {      
          if(digitalRead(CHON_BOM)==0)
         {
          while(digitalRead(CHON_BOM)==0); 
          HenBom=1;//chuyen sang che do cai dat
          lcd.clear();//xoa man hinh LCD
         } else break;
// Hẹn giờ bật bơm 3     
         while(HenBom==1)
         {
           lcd.setCursor(0,0);
           lcd.print("TB3: HEN GIO BAT");
           lcd.setCursor(0,1);
           lcd.print("GIO BAT: ");
           _HienThiSo(GioB3_1);

           if(digitalRead(TANG)==0)//neu nhan nut nhan
             {
               while(digitalRead(TANG)==0);
               GioB3_1 = GioB3_1+1;
               if(GioB3_1>23)
                 {
                  GioB3_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
              {
                while(digitalRead(GIAM)==0);
                GioB3_1 = GioB3_1-1;
                if(GioB3_1<0)
                {
                 GioB3_1=23;
                }       
              }   
          if(digitalRead(CHON_BOM)==0)
          {
           while(digitalRead(CHON_BOM)==0); 
           HenBom++;
           lcd.clear();//xoa man hinh LCD
          }
         }
 // Hẹn phút bật bơm 3      
       while(HenBom==2)
            {
              lcd.setCursor(0,0);
              lcd.print("TB3: HEN PHUT BAT");
              lcd.setCursor(0,1);
              lcd.print("PHUT BAT: ");
              _HienThiSo(PhutB3_1);
            if(digitalRead(TANG)==0)//neu nhan nut nhan
              {
                while(digitalRead(TANG)==0);
                PhutB3_1 = PhutB3_1+1;
                if(PhutB3_1>59)
                 {
                  PhutB3_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
             {
              while(digitalRead(GIAM)==0);
              PhutB3_1 = PhutB3_1-1;
              if(PhutB3_1<0)
                {
                 PhutB3_1=59;
                }       
             }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              e=1;
              lcd.clear();//xoa man hinh LCD
             }
           }
   // Hẹn Giờ tắt bơm 3
         while(HenBom==3)
              {
               lcd.setCursor(0,0);
               lcd.print("TB3: HEN GIO TAT");
               lcd.setCursor(0,1);
               lcd.print("GIO TAT: ");
               _HienThiSo(GioB3_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 GioB3_2 = GioB3_2+1;
                 if(GioB3_2>23)
                   {
                    GioB3_2=0;
                   }       
                }
             if(digitalRead(GIAM)==0)//neu nhan nut nhan
               {
                while(digitalRead(GIAM)==0);
                GioB3_2= GioB3_2-1;
             if(GioB3_2<0)
               {
                GioB3_2=23;
               }       
               }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }              
         }
  // Hẹn Phút tắt bơm 3
       while(HenBom==4)
            {
               lcd.setCursor(0,0);
               lcd.print("TB3: HEN PHUT TAT");
               lcd.setCursor(0,1);
               lcd.print("PHUT TAT: ");
               _HienThiSo(PhutB3_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 PhutB3_2 = PhutB3_2+1;
                if(PhutB3_2>59)
                   {
                    PhutB3_2=0;
                   }       
                }
              if(digitalRead(GIAM)==0)//neu nhan nut nhan
                {
                  while(digitalRead(GIAM)==0);
                  PhutB3_2 = PhutB3_2-1;
                  if(PhutB3_2<0)
                    {
                     PhutB3_2=59;
                    }       
                 } 
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              f=1;
              lcd.clear();//xoa man hinh LCD
             } 
          }                 
// Thông báo hẹn giờ ok cho bơm 3                 
       while(HenBom==5)
            {
               lcd.setCursor(0,0);
               lcd.print("TB3: HEN GIO OK !");
            
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom=0;CheDo1++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }
            }                
         }
                if(digitalRead(HEN_GIO)==0)
            {
             while(digitalRead(HEN_GIO)==0); 
             CheDo1++;//chuyen sang che do cai dat
             lcd.clear();//xoa man hinh LCD
            }
      }
  //
         

 // chọn bơm 4     
      while(CheDo1==5)
      {
         lcd.setCursor(0,0);
         lcd.print("CHE DO CHON TB");
         lcd.setCursor(0,1);
         lcd.print("Moi chon TB4");
        while(HenBom==0) 
         {      
          if(digitalRead(CHON_BOM)==0)
         {
          while(digitalRead(CHON_BOM)==0); 
          HenBom=1;//chuyen sang che do cai dat
          lcd.clear();//xoa man hinh LCD
         } else break;
  //////     
  // Hẹn giờ bật bơm 4     
         while(HenBom==1)
         {
           lcd.setCursor(0,0);
           lcd.print("TB4: HEN GIO BAT");
           lcd.setCursor(0,1);
           lcd.print("GIO BAT: ");
           _HienThiSo(GioB4_1);

           if(digitalRead(TANG)==0)//neu nhan nut nhan
             {
               while(digitalRead(TANG)==0);
               GioB4_1 = GioB4_1+1;
               if(GioB4_1>23)
                 {
                  GioB4_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
              {
                while(digitalRead(GIAM)==0);
                GioB4_1 = GioB4_1-1;
                if(GioB4_1<0)
                {
                 GioB4_1=23;
                }       
              }   
          if(digitalRead(CHON_BOM)==0)
          {
           while(digitalRead(CHON_BOM)==0); 
           HenBom++;
           lcd.clear();//xoa man hinh LCD
          }
         }
 // Hẹn phút bật bơm 4      
       while(HenBom==2)
            {
              lcd.setCursor(0,0);
              lcd.print("TB4: HEN PHUT BAT");
              lcd.setCursor(0,1);
              lcd.print("PHUT BAT: ");
              _HienThiSo(PhutB4_1);
            if(digitalRead(TANG)==0)//neu nhan nut nhan
              {
                while(digitalRead(TANG)==0);
                PhutB4_1 = PhutB4_1+1;
                if(PhutB4_1>59)
                 {
                  PhutB4_1=0;
                 }       
              }
           if(digitalRead(GIAM)==0)//neu nhan nut nhan
             {
              while(digitalRead(GIAM)==0);
              PhutB4_1 = PhutB4_1-1;
              if(PhutB4_1<0)
                {
                 PhutB4_1=59;
                }       
             }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              n=1;
              HenBom++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }
           }
   // Hẹn Giờ tắt bơm 4
         while(HenBom==3)
              {
               lcd.setCursor(0,0);
               lcd.print("TB4: HEN GIO TAT");
               lcd.setCursor(0,1);
               lcd.print("GIO TAT: ");
               _HienThiSo(GioB4_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 GioB4_2 = GioB4_2+1;
                 if(GioB4_2>23)
                   {
                    GioB4_2=0;
                   }       
                }
             if(digitalRead(GIAM)==0)//neu nhan nut nhan
               {
                while(digitalRead(GIAM)==0);
                GioB4_2= GioB4_2-1;
             if(GioB4_2<0)
               {
                GioB4_2=23;
               }       
               }
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }              
         }
  // Hẹn Phút tắt bơm 4
       while(HenBom==4)
            {
               lcd.setCursor(0,0);
               lcd.print("TB4: HEN PHUT TAT");
               lcd.setCursor(0,1);
               lcd.print("PHUT TAT: ");
               _HienThiSo(PhutB4_2);
              if(digitalRead(TANG)==0)//neu nhan nut nhan
                {
                 while(digitalRead(TANG)==0);
                 PhutB4_2 = PhutB4_2+1;
                if(PhutB4_2>59)
                   {
                    PhutB4_2=0;
                   }       
                }
              if(digitalRead(GIAM)==0)//neu nhan nut nhan
                {
                  while(digitalRead(GIAM)==0);
                  PhutB4_2 = PhutB4_2-1;
                  if(PhutB4_2<0)
                    {
                     PhutB4_2=59;
                    }       
                 } 
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom++;//chuyen sang che do cai dat
              m=1;
              lcd.clear();//xoa man hinh LCD
             } 
          }                 
// Thông báo hẹn giờ ok cho bơm 4                 
       while(HenBom==5)
            {
               lcd.setCursor(0,0);
               lcd.print("TB4: HEN GIO OK !");
            
          if(digitalRead(CHON_BOM)==0)
             {
              while(digitalRead(CHON_BOM)==0); 
              HenBom=0;CheDo1++;//chuyen sang che do cai dat
              lcd.clear();//xoa man hinh LCD
             }
            }                
         }
  /////  
         
        if(digitalRead(HEN_GIO)==0)
        {
          while(digitalRead(HEN_GIO)==0); 
          CheDo1++;//chuyen sang che do cai dat
          if(CheDo1>5)
        {
          CheDo1=0;
        }
          lcd.clear();//xoa man hinh LCD
        }
      }
//### set time     
     if(digitalRead(MENU)==0)//neu nhan nut
       {
         while(digitalRead(MENU)==0);
         CheDo=1;//chuyen sang che do cai dat
         lcd.clear();//xoa man hinh LCD
       }
 // cài giờ
       while(CheDo==1)//che do cai gio
      {
      lcd.setCursor(0,0);
      lcd.print("CHE DO CAI GIO");
      lcd.setCursor(0,1);
      lcd.print("GIO: ");
      _HienThiSo(hour);

      if(digitalRead(TANG)==0)//neu nhan nut nhan
      {
        while(digitalRead(TANG)==0);
        hour = hour+1;
        if(hour>23)
        {
          hour=0;
        }
        _SetTime(hour, minute, second, wday, day, month, year);
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
      {
        while(digitalRead(GIAM)==0);
        hour = hour-1;
        if(hour<0)
        {
          hour=23;
        }
        _SetTime(hour, minute, second, wday, day, month, year);        
      }
       if(digitalRead(MENU)==0)//neu nhan nut
      {
        while(digitalRead(MENU)==0);
        CheDo=CheDo+1;//chuyen sang che do cai dat khac
        lcd.clear();//xoa man hinh LCD
      }
    }
 // cài phút    
     while(CheDo==2)//che do cai phut
    {
      lcd.setCursor(0,0);
      lcd.print("CHE DO CAI PHUT");
      lcd.setCursor(0,1);
      lcd.print("PHUT: ");
      _HienThiSo(minute);

      if(digitalRead(TANG)==0)//neu nhan nut nhan
      {
        while(digitalRead(TANG)==0);
        minute = minute+1;
        if(minute>59)
        {
          minute=0;
        }
        _SetTime(hour, minute, second, wday, day, month, year);
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
      {
        while(digitalRead(GIAM)==0);
        minute = minute-1;
        if(minute<0)
        {
          minute=59;
        }
        _SetTime(hour, minute, second, wday, day, month, year);        
      }        
      if(digitalRead(MENU)==0)//neu nhan nut
      {
        while(digitalRead(MENU)==0);
        CheDo=CheDo+1;//chuyen sang che do cai dat khac
        lcd.clear();//xoa man hinh LCD
      } 
    }
// cài giây 
   while(CheDo==3)//che do cai giay
    {
      lcd.setCursor(0,0);
      lcd.print("CHE DO CAI GIAY");
      lcd.setCursor(0,1);
      lcd.print("GIAY: ");
      _HienThiSo(second);

      if(digitalRead(TANG)==0)//neu nhan nut nhan
      {
        while(digitalRead(TANG)==0);
        second = second+1;
        if(second>59)
        {
          second=0;
        }
        _SetTime(hour, minute, second, wday, day, month, year);
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
      {
        while(digitalRead(GIAM)==0);
        second = second-1;
        if(second<0)
        {
          second=59;
        }
        _SetTime(hour, minute, second, wday, day, month, year);        
      }        
      if(digitalRead(MENU)==0)//neu nhan nut
      {
        while(digitalRead(MENU)==0);
        CheDo=CheDo+1;//chuyen sang che do cai dat khac
        lcd.clear();//xoa man hinh LCD
      }
    }  
// cài ngày
     while(CheDo==4)//che do cai ngay
      {
        lcd.setCursor(0,0);
        lcd.print("CHE DO CAI NGAY");
        lcd.setCursor(0,1);
        lcd.print("NGAY: ");
        _HienThiSo(day);
  
        if(digitalRead(TANG)==0)//neu nhan nut nhan
        {
          while(digitalRead(TANG)==0);
          day = day+1;
          if(day>99)
          {
            day=0;
          }
          _SetTime(hour, minute, second, wday, day, month, year);
        }
        if(digitalRead(GIAM)==0)//neu nhan nut nhan
        {
          while(digitalRead(GIAM)==0);
          day = day-1;
          if(day<0)
          {
            day=5;
          }
          _SetTime(hour, minute, second, wday, day, month, year);        
        }        
        if(digitalRead(MENU)==0)//neu nhan nut
        {
          while(digitalRead(MENU)==0);
          CheDo=CheDo+1;//chuyen sang che do cai dat khac
          lcd.clear();//xoa man hinh LCD
        } 
      }
// cài tháng
   while(CheDo==5)//che do cai thang
    {
      lcd.setCursor(0,0);
      lcd.print("CHE DO CAI THANG");
      lcd.setCursor(0,1);
      lcd.print("THANG: ");
      _HienThiSo(month);

      if(digitalRead(TANG)==0)//neu nhan nut nhan
      {
        while(digitalRead(TANG)==0);
        month = month+1;
        if(month>12)
        {
          month=1;
        }
        _SetTime(hour, minute, second, wday, day, month, year);
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
      {
        while(digitalRead(GIAM)==0);
        month = month-1;
        if(month<1)
        {
          month=12;
        }
        _SetTime(hour, minute, second, wday, day, month, year);        
      }        
      if(digitalRead(MENU)==0)//neu nhan nut
      {
        while(digitalRead(MENU)==0);
        CheDo=CheDo+1;//chuyen sang che do cai dat khac
        lcd.clear();//xoa man hinh LCD
      }  
    } 
 // cài năm
   while(CheDo==6)//che do cai nam
    {
      lcd.setCursor(0,0);
      lcd.print("CHE DO CAI NAM");
      lcd.setCursor(0,1);
      lcd.print("NAM: ");
      _HienThiSo(year);

      if(digitalRead(TANG)==0)//neu nhan nut nhan
      {
        while(digitalRead(TANG)==0);
        year = year+1;         
        _SetTime(hour, minute, second, wday, day, month, year);
      }
      if(digitalRead(GIAM)==0)//neu nhan nut nhan
      {
        while(digitalRead(GIAM)==0);
        year = year-1;
        
        _SetTime(hour, minute, second, wday, day, month, year);        
      }        
      if(digitalRead(MENU)==0)//neu nhan nut
      {
        while(digitalRead(MENU)==0);
        CheDo=CheDo+1;//chuyen sang che do cai dat khac
        if(CheDo>6)
        {
          CheDo=0;
        }
        lcd.clear();//xoa man hinh LCD
      }
    }                   
    }
    }
         
//----------------------------
void _HienThiSo(signed int SoDem)
{
  signed char Ngan, Tram, Chuc, DonVi;
  signed int Tam = SoDem;

  DonVi = SoDem%10;
  SoDem = SoDem/10;

  Chuc = SoDem%10;
  SoDem = SoDem/10;

  Tram = SoDem%10;
  SoDem = SoDem/10;

  Ngan = SoDem%10;       
  
  if(Tam<99)
  {
    lcd.print(Chuc);lcd.print(DonVi);    
  }
  else
  {
    lcd.print(Ngan);lcd.print(Tram);lcd.print(Chuc);lcd.print(DonVi);        
  }
}

void _ReadDS1307(void)
{
    Wire.beginTransmission(DS1307);
    Wire.write((byte)0x00);
    Wire.endTransmission();
    Wire.requestFrom(DS1307, NumberOfFields);
    
    second = _BCD2DEC(Wire.read() & 0x7F);
    minute = _BCD2DEC(Wire.read() );
    hour   = _BCD2DEC(Wire.read() & 0x3F); // chế độ 24h.
    wday   = _BCD2DEC(Wire.read() );
    day    = _BCD2DEC(Wire.read() );
    month  = _BCD2DEC(Wire.read() );
    year   = _BCD2DEC(Wire.read() );   
}

/* Chuyển từ format BCD (Binary-Coded Decimal) sang Decimal */
int _BCD2DEC(byte num)
{
        return ((num/16 * 10) + (num % 16));
}
/* Chuyển từ Decimal sang BCD */
int _DEC2BCD(byte num)
{
        return ((num/10 * 16) + (num % 10));
}

/* cài đặt thời gian cho DS1307 */
void _SetTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0x00)); // đặt lại pointer
    Wire.write(_DEC2BCD(sec));
    Wire.write(_DEC2BCD(min));
    Wire.write(_DEC2BCD(hr));
    Wire.write(_DEC2BCD(wd)); // day of week: Sunday = 1, Saturday = 7
    Wire.write(_DEC2BCD(d)); 
    Wire.write(_DEC2BCD(mth));
    Wire.write(_DEC2BCD(yr));
    Wire.endTransmission();
}

void _HienThiThoiGian(void)
{    
     lcd.setCursor(0,0);    
    lcd.print("DATE:");
    _HienThiSo(day); lcd.print(":");          
    _HienThiSo(month); lcd.print(":");    
    _HienThiSo(year);   

    lcd.setCursor(0,1);
    lcd.print("TIME:");
    _HienThiSo(hour); lcd.print(":");    
    _HienThiSo(minute); lcd.print(":");    
    _HienThiSo(second);

  lcd.setCursor(15,0);
  lcd.print("TB1:");
  lcd.setCursor(15,1);
  lcd.print("TB2:");
  lcd.setCursor(15,2);
  lcd.print("TB3:");
  lcd.setCursor(15,3);
  lcd.print("TB4:");

  if(digitalRead(RELAY_1)==0) {lcd.setCursor(19,0);lcd.print("0");} else {lcd.setCursor(19,0);lcd.print("1");}
  if(digitalRead(RELAY_2)==0) {lcd.setCursor(19,1);lcd.print("0");} else {lcd.setCursor(19,1);lcd.print("1");}
  if(digitalRead(RELAY_3)==0) {lcd.setCursor(19,2);lcd.print("0");} else {lcd.setCursor(19,2);lcd.print("1");}
  if(digitalRead(RELAY_4)==0) {lcd.setCursor(19,3);lcd.print("0");} else {lcd.setCursor(19,3);lcd.print("1");}

  lcd.setCursor(0,2);
  lcd.print("B1:");
  lcd.setCursor(5,2);
  lcd.print("B2:");
  lcd.setCursor(10,2);
  lcd.print("B3:");
  lcd.setCursor(0,3);
  lcd.print("B4:");
  lcd.setCursor(5,3);
  lcd.print("B5:");
  lcd.setCursor(10,3);
  lcd.print("B6:");
}

