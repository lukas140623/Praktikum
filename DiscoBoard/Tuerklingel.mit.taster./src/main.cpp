#include <Arduino.h>

int speakerPin = D9; 
int Taster_0 = D8;

void setup() {
  pinMode(speakerPin, OUTPUT); 
  pinMode(Taster_0, INPUT);
}

void loop() {
  if (digitalRead(Taster_0) == HIGH)
  {
  // Note E5
  tone(speakerPin, 660, 500); 
  delay(650); 

  // Note C5
  tone(speakerPin, 523, 500); 
  delay(650); 

  // Note D5
  tone(speakerPin, 587, 500); 
  delay(650); 

  // Note G4
  tone(speakerPin, 392, 500);  
  delay(650);

  // Note G4
  tone(speakerPin, 392, 500);  
  delay(650);

  // Note D5
  tone(speakerPin, 587, 500); 
  delay(650); 

  // Note E5
  tone(speakerPin, 660, 500); 
  delay(650);

  // Note C5
  tone(speakerPin, 523, 500); 
  delay(650); 

  delay(2000); 
  }
  else {
    noTone(D9);
  }
}