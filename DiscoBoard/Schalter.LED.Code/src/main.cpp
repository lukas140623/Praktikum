#include <Arduino.h>

int ButtonPin = D11;
int LED1 = D12;

void setup() {

pinMode(ButtonPin, INPUT);
pinMode(LED1, OUTPUT);
Serial.begin(9600);
}

void loop() {

int schalterzustand;
schalterzustand = digitalRead(ButtonPin);
Serial.println(schalterzustand);

if (schalterzustand == HIGH) {
digitalWrite(LED1, HIGH);
} 
  else 
{
  digitalWrite(LED1, LOW);
}
}