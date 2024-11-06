#include <Arduino.h>

int Sensorwert = 0;

#define SENSOR_PIN A0
#define LED1 D0
#define LED2 D1
#define LED3 D2
#define LED4 D3
#define LED5 D4
#define LED6 D5
#define LED7 D6
#define LED8 D7


uint8_t ledStatus[] = {
    0b00000000,
    0b00000001,
    0b00000011,
    0b00000111,
    0b00001111,
    0b00011111,
    0b00111111,
    0b01111111,
    0b11111111,
};

void setup() {
 Serial.begin(9600);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(LED5, OUTPUT);
 pinMode(LED6, OUTPUT);
 pinMode(LED7, OUTPUT);
 pinMode(LED8, OUTPUT);
}

void loop() {
 Sensorwert = analogRead(SENSOR_PIN);
 delay(20);
 Serial.println(Sensorwert);


    int index = 0;
 if ( Sensorwert <= 30) {
        index = 0;
 }
 else if (Sensorwert > 30 && Sensorwert <= 50) {
        index = 1;
 }
 else if (Sensorwert > 50 && Sensorwert <=70) {
        index = 2;
 } 
 else if (Sensorwert > 70 && Sensorwert <=90) {
        index = 3;
 }
 else if (Sensorwert > 90 && Sensorwert <=110) {
        index = 4;
 }
 else if (Sensorwert > 110 && Sensorwert <=130) {
        index = 5;
 }
 else if (Sensorwert > 130 && Sensorwert <=150) {
        index = 6;
 }
 else if (Sensorwert > 150 && Sensorwert <=170) {
        index = 7;
 }
 else if (Sensorwert > 170 && Sensorwert <=200) {
        index = 8;
 }

    digitalWrite(D0, ledStatus[index] & 0b00000001);
    digitalWrite(D1, ledStatus[index] & 0b00000010);
    digitalWrite(D2, ledStatus[index] & 0b00000100);
    digitalWrite(D3, ledStatus[index] & 0b00001000);
    digitalWrite(D4, ledStatus[index] & 0b00010000);
    digitalWrite(D5, ledStatus[index] & 0b00100000);
    digitalWrite(D6, ledStatus[index] & 0b01000000);
    digitalWrite(D7, ledStatus[index] & 0b10000000);
}
  
