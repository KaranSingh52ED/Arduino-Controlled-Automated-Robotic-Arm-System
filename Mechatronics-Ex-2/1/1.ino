#include <Servo.h>

Servo myServo;  // Create a servo object
int servoPos = 90;  // Initial position of the servo
const int switchCW = 7;  // Pin for the switch controlling clockwise rotation
const int switchCCW = 8;  // Pin for the switch controlling counterclockwise rotation

void setup() {
  // Initialize the servo
  myServo.attach(5);  // Attach the servo to pin 9
  myServo.write(servoPos);  // Set the servo to the initial position (90 degrees)

  // Set the pins for the switches
  pinMode(switchCW, INPUT_PULLUP);  // Set switch 7 as input with internal pull-up
  pinMode(switchCCW, INPUT_PULLUP);  // Set switch 8 as input with internal pull-up

  Serial.begin(9600);  // Initialize serial communication (optional for debugging)
}

void loop() {
  // Check for clockwise rotation (switch 7)
  if (digitalRead(switchCW) == LOW) {
    // Debounce the switch
    delay(50);
    if (digitalRead(switchCW) == LOW) {
      if (servoPos < 180) {  // Ensure servo doesn't go beyond 180 degrees
        servoPos++;  // Increase the position by 1 degree
        myServo.write(servoPos);  // Update the servo position
        Serial.print("CW to position: ");
        Serial.println(servoPos);
        delay(200);  // Wait for the switch release
      }
    }
  }

  // Check for counterclockwise rotation (switch 8)
  if (digitalRead(switchCCW) == LOW) {
    // Debounce the switch
    delay(50);
    if (digitalRead(switchCCW) == LOW) {
      if (servoPos > 0) {  // Ensure servo doesn't go below 0 degrees
        servoPos--;  // Decrease the position by 1 degree
        myServo.write(servoPos);  // Update the servo position
        Serial.print("CCW to position: ");
        Serial.println(servoPos);
        delay(50);  // Wait for the switch release
      }
    }
  }
}
