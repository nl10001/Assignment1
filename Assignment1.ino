/*
  Assignment 1 B31DG
  Author: Neil Lamont
  HWUID: H00298429

  This code is designed to create and alter a waveform 
  using an ESP32 board and an oscilloscope to verify results.

  To disable the stream of pulses press down and hold button 1.
  To alter the waveform to run from largest to smallest press and hold button 2 (mode 2).
*/

#include<stdio.h>

#define A 1200 // the time for which signal A will be high in microseconds
#define B 100 // the time for which signal A will be low in microseconds
#define C 17 // the number of times signal A will be high
#define D 6 // the time that will delay after completing the waveform before starting again in milliseconds
#define sigB 50 // the time for which signal B will be high in microseconds
#define calc_Diff(i) (i * 50) // a simple function for calculating the different times signal A will be high for

// defining the corresponding pins to the ESP32 board 
const int ledPin1 = 15;
const int ledPin2 = 21;
const int button1 = 22;
const int button2 = 23;

// initialising the button state variables to low (default)
int buttonState1 = 0;
int buttonState2 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialise buttons as inputs and LEDs as outputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// the loop function runs indefinitely
void loop() {
  buttonState1 = digitalRead(button1); // determine whether button 1 is high or low
  buttonState2 = digitalRead(button2); // determine whether button 2 is high or low
  
  if(buttonState1 == LOW){ // enable waveform
    if(buttonState2 == LOW) { // normal waveform
      digitalWrite(ledPin2, HIGH); // begin sig B
      delayMicroseconds(sigB); // wait B 
      digitalWrite(ledPin2, LOW); // end sig B
      for(int i = 0; i < C; i++) { // iterate 17 times
        digitalWrite(ledPin1, HIGH); // begin sig A
        delayMicroseconds(A + calc_Diff(i)); // wait A with correct delay
        digitalWrite(ledPin1, LOW); // end sig A
        delayMicroseconds(B);
      }
      delay(D);
    }
    else { // inverted waveform
      digitalWrite(ledPin2, HIGH); // begin sig B
      delayMicroseconds(sigB); // wait B
      digitalWrite(ledPin2, LOW); // end sig B
      for(int i = (C-1); i > -1; i--) { // iterate 17 times
        digitalWrite(ledPin1, HIGH); // begin sig A
        delayMicroseconds(A + calc_Diff(i)); // wait A with correct delay
        digitalWrite(ledPin1, LOW); // end sig A
        delayMicroseconds(B);
      }
      delay(D);
    }
  }
  else { // disable waveform
    return;
  }
  
 }
