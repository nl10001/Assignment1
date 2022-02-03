/*
  Assignment 1
  Author: Neil Lamont
  HWUID: H00298429

  This code is designed to create and alter a set of waveforms 
  using an ESP32 board and an oscilloscope to verify results.
*/

#include<stdio.h>

// defining the corresponding pins to the ESP32 board 
const int ledPinA = 15;
const int ledPinB = 21;
const int buttonA = 22;
const int buttonB = 23;

int buttonStateA = 0;
int buttonStateB = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonStateA = digitalRead(buttonA);
  buttonStateB = digitalRead(buttonB);

  if(buttonStateA == HIGH ) {
    digitalWrite(ledPinA, HIGH);
    digitalWrite(ledPinB, LOW);
  }
  else if(buttonStateB == HIGH) {
    digitalWrite(ledPinB, HIGH);
    digitalWrite(ledPinA, LOW);
  }
  else{
    digitalWrite(ledPinA, LOW);
    digitalWrite(ledPinB, LOW);
  }
 }
