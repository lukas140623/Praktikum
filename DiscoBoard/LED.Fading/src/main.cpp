#include <Arduino.h>

#define LED1 D8
#define LED2 D9
#define LED3 D10
#define LED4 D11
#define LED5 D12

#define MAX_LEDVALUE 32
#define LEDVALUE_THRESHOLD (MAX_LEDVALUE / 8)

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}


int loopCounter = 0;
int ledPins[5] = {LED1, LED2, LED3, LED4, LED5};
int ledValue[5] = {0,0,0,0,0};
int ledDir[5] = {0,0,0,0,0};
int maxIndex = 1;

int zustand = 0;

void loop() 
{

  switch(zustand) {
    case 0:
      ledDir[0] = 1;
      if (ledValue[0] >= MAX_LEDVALUE/8) {
        zustand = 1;
      }
      break;

    case 1:
      ledDir[1] = 1;
      
      if (ledValue[1] >= MAX_LEDVALUE/8) {
        zustand = 2;
      }
      break;

    case 2:
      ledDir[2] = 1;
      
      if (ledValue[2] >= MAX_LEDVALUE/8) {
        zustand = 3;
      }
      break;

    case 3:
      ledDir[3] = 1;
      
      if (ledValue[3] >= MAX_LEDVALUE/8) {
        zustand = 4;
      }
      break;

    case 4:
      ledDir[4] = 1;
      
      if (ledValue[4] >= MAX_LEDVALUE) {
        zustand = 10;
      }
      break;

    case 10:
      delay(150);
      zustand = 5;
      break;

    case 5:
      ledDir[0] = -1;
      
      if (ledValue[0] == MAX_LEDVALUE/8*7) {
        zustand = 6;
      }
      break;

    case 6:
      ledDir[1] = -1;
      
      if (ledValue[1] == MAX_LEDVALUE/8*7) {
        zustand = 7;
      }
      break;

    case 7:
      ledDir[2] = -1;
      
      if (ledValue[2] == MAX_LEDVALUE/8*7) {
        zustand = 8;
      }
      break;

    case 8:
      ledDir[3] = -1;
      
      if (ledValue[3] == MAX_LEDVALUE/8*7) {
        zustand = 9;
      }
      break;

    case 9:
      ledDir[4] = -1;
      
      if (ledValue[4] == MAX_LEDVALUE/8-4) {
        zustand = 11;
      }
      break;

    case 11:
      delay(500);
      zustand = 0;
      break;


  }

  // setzt i auf 0, fragt ab ob i kleiner als maxIndex ist, erhöht i um 1
  for (int i = 0; i < 5; i++)
  {
    //ledpin (LED1) wird auf ledValue (0) gesetzt 
    analogWrite(ledPins[i], ledValue[i]);
    // ledValue bekommt einen neuen wert = ledValue + ledDir (1)
    ledValue[i] = ledValue[i] + ledDir[i];
    if (ledValue[i] >= MAX_LEDVALUE) 
      ledValue[i] = MAX_LEDVALUE;
    if (ledValue[i] <= 0) 
      ledValue[i] = 0;
  }  

  delay(30);
  loopCounter++;
}

 
