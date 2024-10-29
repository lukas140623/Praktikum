#include <Arduino.h>

int istPrimzahl(int a);

int zahl = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int a = zahl; a <= 100;a++){ 
    int istPrimezahl = istPrimzahl(a);
  
    if (istPrimezahl == 1){
      Serial.print("true");
      Serial.print("  --> ");
      Serial.println(a);
    } else {
      /*Serial.print("false");
      Serial.print(" --> ");
      Serial.println(a);*/
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

int istPrimzahl(int a)
{
  int istPrimezahl = 1;

  if (a <= 1) {
    istPrimezahl = 0;
  } else {
    for (int b = 2; b < a; b++) {
      if (a % b == 0) {
        istPrimezahl = 0 ;
        break;
      }
    }
  }

  return istPrimezahl;
}