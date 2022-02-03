/*
  Assignment 1
  Author: Neil Lamont
  HWUID: H00298429

  This code is designed to create and alter a set of waveforms 
  using an ESP32 board and an oscilloscope to verify results.
*/

#include<stdio.h>

#define A 1.2
#define B 50
#define C 17
#define D 6

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
  
  if(buttonState1 == LOW){ // enable waveform
    if(buttonState2 == LOW) { // normal waveform
      digitalWrite(ledPin2, HIGH); // begin sig B
      delay(B*20); // wait 1 second 
      digitalWrite(ledPin2, LOW); // end sig B
      for(i = 0; i < 5; i++) { // iterate 5 times for testing
        digitalWrite(ledPin1, HIGH); // begin sig A
        delay(A*833); // wait 1 second
        digitalWrite(ledPin1, LOW); // end sig A
      }
      
      
    }
    else if(buttonState2 == HIGH) { // inverted waveform
      
    }
  }
  else if(buttonState1 == HIGH) { // disable waveform

  }
  
 }
