#include <Wire.h> 

// Pin definitions
const int redLED = 9;
const int greenLED = 10;
const int blueLED = 11;
const int ldrPin = A2;

// Variables to store LDR values
int redValue, greenValue, blueValue;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating...");
  
  // Set LED pins as OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // Set initial LED states to off
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);

  Serial.begin(9600);
}

void loop() {
  ManualCalibrate();
}

void ManualCalibrate() {
  while (true) {
    // Shine red, green, and blue colors
    analogWrite(redLED, 255);
    delay(100);
    redValue = analogRead(ldrPin);
    analogWrite(redLED, 0);

    analogWrite(greenLED, 255);
    delay(100);
    greenValue = analogRead(ldrPin);
    analogWrite(greenLED, 0);

    analogWrite(blueLED, 255);
    delay(100);
    blueValue = analogRead(ldrPin);
    analogWrite(blueLED, 0);
    
    // Print the read values on the LCD
    Serial.println("R:");
    Serial.println(redValue);
    Serial.println(" G:");
    Serial.println(greenValue);
    Serial.println("B:");
    Serial.println(blueValue);

    // Find the max value and adjust potentiometers
    int maxValue = max(max(redValue, greenValue), blueValue);
    // Adjust potentiometers accordingly (this part needs to be manually done)

    delay(50);

    // Check for user stop command
    if (Serial.available()) {
      char input = Serial.read();
      if (input == '1') {
        break;
      }
    }
  }
  Serial.println("Calibration done!");
}
