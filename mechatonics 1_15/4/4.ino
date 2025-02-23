/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
// const int buttonPin = 7;
// const int buttonPin = 8;
// const int buttonPin = 9;  // the number of the pushbutton pin
// const int ledPin = 11;
// const int ledPin = 12;
// const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(11, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(7, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(8, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ( digitalRead(7)==0) {
    // turn LED on:
    digitalWrite(13, HIGH);
  } else {
    // turn LED off:
    digitalWrite(13, LOW);
  }
  if ( digitalRead(8)==0) {
    // turn LED on:
    digitalWrite(12, HIGH);
  } else {
    // turn LED off:
    digitalWrite(12, LOW);
  }
  if ( digitalRead(9)==0) {
    // turn LED on:
    digitalWrite(11, HIGH);
  } else {
    // turn LED off:
    digitalWrite(11, LOW);
  }
}
