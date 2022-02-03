/*
  Assignment 1
  Author: Neil Lamont
  HWUID: H00298429

  This code is designed to create and alter a set of waveforms 
  using an ESP32 board and an oscilloscope to verify results.
*/

#include<stdio.h>
#inclue<time.h>

// defining the corresponding pins to the ESP32 board 
const int ledPin1 = 15;
const int ledPin2 = 21;
const int button1 = 22;
const int button2 = 23;

int buttonState1 = 0;
int buttonState2 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  
  if(button1 == LOW){ // enable waveform
    if(button2 == LOW) { // normal waveform

    }
    else if(button2 == HIGH) { // inverted waveform
      
    }
  }
  else if(button1 == HIGH) { // disable waveform

  }
  
 }
