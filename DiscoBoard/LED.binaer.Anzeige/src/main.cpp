#include <Arduino.h>

void setup()
{ 
  int LED_S = D0;
  int LED_A = D1;
  int LED_V = D2;
  int LED_Z = D3;
  int LED_E = D4;

  int zahl = 26;
  int S = zahl / 16;
  int A = (zahl - (S*16))/ 8;
  int V = (zahl - (S*16) - (A*8)) / 4;
  int Z = (zahl - (S*16) - (A*8) - (V*4)) / 2;
  int E = (zahl - (S*16) - (A*8) - (V*4) - (Z*2)) / 1;

  Serial.begin(9600);

  pinMode(LED_S, OUTPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_Z, OUTPUT);
  pinMode(LED_E, OUTPUT);

  if (S == 1) {
    digitalWrite(LED_S, HIGH);
  } else {
    digitalWrite(LED_S, LOW);
  }

  if (A == 1) {
    digitalWrite(LED_A, HIGH);
  } else {
    digitalWrite(LED_A, LOW);
  }

  if (V == 1) {
    digitalWrite(LED_V, HIGH);
  } else {
    digitalWrite(LED_V, LOW);
  }

  if (Z == 1) {
    digitalWrite(LED_Z, HIGH);
  } else {
    digitalWrite(LED_Z, LOW);
  }

  if (E == 1) {
    digitalWrite(LED_E, HIGH);
  } else {
    digitalWrite(LED_E, LOW);
  }

  Serial.print("Binar: ");
  
  Serial.print(S);
  Serial.print(A);
  Serial.print(V);
  Serial.print(Z);
  Serial.println(E);
}

void loop()
{

}
   