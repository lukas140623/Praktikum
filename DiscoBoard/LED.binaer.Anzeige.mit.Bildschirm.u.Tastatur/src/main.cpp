#include <Arduino.h>

#include <U8g2lib.h>

// Display initialisieren (I2C-Anschlüsse und Modell prüfen, ggf. anpassen)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

  int Taster_zahl_0 = D8;
  int Taster_zahl_1 = D10;
  int Taster_zahl_2 = D11;
  int Taster_zahl_3 = D12;
  int Taster_zahl_4 = D13;
  int Taster_zahl_5 = A0;
  int Taster_zahl_6 = A1;
  int Taster_zahl_7 = A2;
  int Taster_zahl_8 = A3;
  int Taster_zahl_9 = A4;
  int Taster_Delete = A5;
  int LED_1 = D9;
  int LED_2 = D7;
  int LED_4 = D6;
  int LED_8 = D5;
  int LED_16 = D4;
  int LED_32 = D3;
  int LED_64 = D2;
  int LED_128 = D1;
  int LED_256 = D0;
  int B_2048;
  int B_1024;
  int B_512;
  int B_256;
  int B_128;
  int B_64;
  int B_32;
  int B_16;
  int B_8;
  int B_4;
  int B_2;
  int B_1;
  int zahl = 0;
  int tasterWert;

void setup()
{

  Serial.begin(9600);

  u8g2.begin(); // Display starten

  pinMode(Taster_zahl_0, INPUT);
  pinMode(Taster_zahl_1, INPUT);
  pinMode(Taster_zahl_2, INPUT);
  pinMode(Taster_zahl_3, INPUT);
  pinMode(Taster_zahl_4, INPUT);
  pinMode(Taster_zahl_5, INPUT);
  pinMode(Taster_zahl_6, INPUT);
  pinMode(Taster_zahl_7, INPUT);
  pinMode(Taster_zahl_8, INPUT);
  pinMode(Taster_zahl_9, INPUT);
  pinMode(Taster_Delete, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_16, OUTPUT);
  pinMode(LED_32, OUTPUT);
  pinMode(LED_64, OUTPUT);
  pinMode(LED_128, OUTPUT);
  pinMode(LED_256, OUTPUT);   

}
void loop()
{

 int tasterWert = 0;

  if (digitalRead(Taster_zahl_0) == HIGH)
  {
  zahl = zahl * 10 + 0;
   tasterWert = 1;
   delay(10);
  }

  if (digitalRead(Taster_zahl_1) == HIGH)
    {
    zahl = zahl * 10 + 1;
     tasterWert = 2;
     delay(10);
    }

  if (digitalRead(Taster_zahl_2) == HIGH)
    {
    zahl = zahl * 10 + 2;
     tasterWert = 3;
     delay(10);
    }

  if (digitalRead(Taster_zahl_3) == HIGH)
    {
    zahl = zahl * 10 + 3;
     tasterWert = 4;
     delay(10);
    }

  if (digitalRead(Taster_zahl_4) == HIGH)
    {
    zahl = zahl * 10 + 4;
     tasterWert = 5;
     delay(10);
    }

  if (digitalRead(Taster_zahl_5) == HIGH)
    {
    zahl = zahl * 10 + 5;
     tasterWert = 6;
     delay(10);
    }

  if (digitalRead(Taster_zahl_6) == HIGH)
    {
    zahl = zahl * 10 + 6;
     tasterWert = 7;
     delay(10);
    }

  if (digitalRead(Taster_zahl_7) == HIGH)
    {
    zahl = zahl * 10 + 7;
     tasterWert = 8;
     delay(10);
    }

  if (digitalRead(Taster_zahl_8) == HIGH)
    {
    zahl = zahl * 10 + 8;
     tasterWert = 9;
     delay(10);
    }
  
  if (digitalRead(Taster_zahl_9) == HIGH) 
    {
    zahl = zahl * 10 + 9;
     tasterWert = 10;
     delay(10);
    }

  if (digitalRead(Taster_Delete) == HIGH) 
  {
   zahl = 0;
   tasterWert = 11;
   delay(10);
  }


  if (zahl <= 4095 && zahl >= 0) {
 
   B_2048 = zahl / 2048;
   B_1024 = (zahl - (B_2048*2048)) / 1024;
   B_512 = (zahl - (B_2048*2048) - (B_1024*1024)) / 512;
   B_256 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512)) / 256;
   B_128 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256)) / 128;
   B_64 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128)) / 64;
   B_32 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64)) / 32;
   B_16 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64) - (B_32*32)) / 16;
   B_8 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64) - (B_32*32) - (B_16*16)) / 8;
   B_4 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64) - (B_32*32) - (B_16*16) - (B_8*8)) / 4;
   B_2 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64) - (B_32*32) - (B_16*16) - (B_8*8) - (B_4*4)) / 2;
   B_1 = (zahl - (B_2048*2048) - (B_1024*1024) - (B_512*512) - (B_256*256) - (B_128*128) - (B_64*64) - (B_32*32) - (B_16*16) - (B_8*8) - (B_4*4) - (B_2*2)) / 1;

 if (zahl <= 511) {
   if (B_256 == 1) {
    digitalWrite(LED_256, HIGH);
  } else {
    digitalWrite(LED_256, LOW);
  }

   if (B_128 == 1) {
    digitalWrite(LED_128, HIGH);
  } else {
    digitalWrite(LED_128, LOW);
  }

   if (B_64 == 1) {
    digitalWrite(LED_64, HIGH);
  } else {
    digitalWrite(LED_64, LOW);
  }

   if (B_32 == 1) {
    digitalWrite(LED_32, HIGH);
  } else {
    digitalWrite(LED_32, LOW);
  }

  if (B_16 == 1) {
    digitalWrite(LED_16, HIGH);
  } else {
    digitalWrite(LED_16, LOW);
  }

  if (B_8 == 1) {
    digitalWrite(LED_8, HIGH);
  } else {
    digitalWrite(LED_8, LOW);
  }

  if (B_4 == 1) {
    digitalWrite(LED_4, HIGH);
  } else {
    digitalWrite(LED_4, LOW);
  }

  if (B_2 == 1) {
    digitalWrite(LED_2, HIGH);
  } else {
    digitalWrite(LED_2, LOW);
  }

  if (B_1 == 1) 
  {
  digitalWrite(LED_1, HIGH);
  }
   else
  {
   digitalWrite(LED_1, LOW);
  }
 }
  else {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_16, LOW);
    digitalWrite(LED_32, LOW);
    digitalWrite(LED_64, LOW);
    digitalWrite(LED_128, LOW);
    digitalWrite(LED_256, LOW);
  }
}
 else {  


  u8g2.sendBuffer();                
  delay(5); 

    while (zahl == zahl && digitalRead(Taster_Delete) == LOW) {
    
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_16, LOW);
    digitalWrite(LED_32, LOW);
    digitalWrite(LED_64, LOW);
    digitalWrite(LED_128, LOW);
    digitalWrite(LED_256, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_16, LOW);
    digitalWrite(LED_32, LOW);
    digitalWrite(LED_64, LOW);
    digitalWrite(LED_128, LOW);
    digitalWrite(LED_256, LOW);

    u8g2.clearBuffer();                    
    u8g2.setFont(u8g2_font_helvB24_tr);        
    u8g2.drawStr(0, 50, "FEHLER");         
    u8g2.sendBuffer();                     

    delay(400);

    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_16, HIGH);
    digitalWrite(LED_32, HIGH);
    digitalWrite(LED_64, HIGH);
    digitalWrite(LED_128, HIGH);
    digitalWrite(LED_256, HIGH);

    u8g2.clearBuffer(); 
    u8g2.sendBuffer(); 

    delay(400);
    }
  }
  
  

  u8g2.clearBuffer();                    
  u8g2.setFont(u8g2_font_10x20_tr);        
  u8g2.drawStr(5, 35, "Zahl: ");         

  char buffer[10];                     
  sprintf(buffer, "%d", zahl);         
  u8g2.drawStr(60, 35, buffer); 

  sprintf(buffer, "%d%d%d%d%d%d%d%d%d%d%d%d", B_2048, B_1024, B_512, B_256, B_128, B_64, B_32, B_16, B_8, B_4, B_2, B_1);
  u8g2.drawStr(5, 55, buffer);

  u8g2.sendBuffer();                     
  delay(5); 

  Serial.print("zahl: ");
  Serial.print(zahl);
  Serial.print(", Binaer: ");
  Serial.print(B_256);
  Serial.print(B_128);
  Serial.print(B_64);
  Serial.print(B_32);
  Serial.print(B_16);
  Serial.print(B_8);
  Serial.print(B_4);
  Serial.print(B_2);
  Serial.print(B_1);
  if (tasterWert == 1) {
   Serial.print(", Taster 0 gedrückt");
   Serial.print("                   ");
   delay(1500);
   tasterWert = 0;
  }
   else if (tasterWert == 2) {
    Serial.print(", Taster 1 gedrückt");
    Serial.print("                   ");
    delay(500);
    tasterWert = 0;
   }
    else if (tasterWert == 3) {
     Serial.print(", Taster 2 gedrückt");
     Serial.print("                   ");
     delay(500);
     tasterWert = 0;
    }
     else if (tasterWert == 4) {
      Serial.print(", Taster 3 gedrückt");
      Serial.print("                   ");
      delay(500);
      tasterWert = 0;
     }
      else if (tasterWert == 5) {
       Serial.print(", Taster 4 gedrückt");
       Serial.print("                   ");
       delay(500);
       tasterWert = 0;
      }
       else if (tasterWert == 6) {
        Serial.print(", Taster 5 gedrückt");
        Serial.print("                   ");
        delay(500);
        tasterWert = 0;
       }
        else if (tasterWert == 7) {
         Serial.print(", Taster 6 gedrückt");
         Serial.print("                   ");
         delay(500);
         tasterWert = 0;
        }
         else if (tasterWert == 8) {
          Serial.print(", Taster 7 gedrückt");
          Serial.print("                   ");
          delay(500);
          tasterWert = 0;
          }
           else if (tasterWert == 9) {
            Serial.print(", Taster 8 gedrückt");
            Serial.print("                   ");
            delay(500);
            tasterWert = 0;
           }
            else if (tasterWert == 10) {
             Serial.print(", Taster 9 gedrückt");
             Serial.print("                   ");
             delay(500);
             tasterWert = 0;
            }
             else if (tasterWert == 11) {
              Serial.print(", DELETE");
              Serial.print("                   ");
              delay(500);
              tasterWert = 0;
             }
              else if (tasterWert == 0) {
               Serial.print("                   ");
              }

  Serial.print("\r");
}
   