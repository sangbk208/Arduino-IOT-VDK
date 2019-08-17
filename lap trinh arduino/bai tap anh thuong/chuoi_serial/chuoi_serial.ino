//kiem tra trong chuoi co ky tu a hay khong
//la sua cuoi: 11h45 11/11/2017
int dem;
String chuoi="" ;
void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{  
      if (Serial.available()>0)
      {
         chuoi=Serial.readString();
         Serial.println(chuoi);
         for (int i = 0; i < chuoi.length(); i++)
          {
            if (chuoi[i]=='a') {dem++; Serial.println(i);}
          }
      if (dem==0) Serial.println("-1");
      }
}

