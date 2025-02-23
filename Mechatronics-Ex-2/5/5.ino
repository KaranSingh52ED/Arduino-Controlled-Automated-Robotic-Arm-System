#include <Servo.h>  // Include Servo library

Servo myServo;      // Create a Servo object
int servoPos = 0;   // Variable to store the servo position
bool sweepEnabled = false;  // Flag to track if sweeping is enabled

void setup() {
  // Attach the servo on pin 9
  myServo.attach(5);

  // Start Serial communication for receiving commands
  Serial.begin(9600);
  
  // Print initial instructions
  Serial.println("Enter '1' to START sweeping and '2' to STOP sweeping.");
}

void loop() {
  // Check if any data has been sent over Serial
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command sent from serial monitor

    // Check if command is valid and update the sweepEnabled flag
    if (command == '1') {
      sweepEnabled = true;   // Turn ON servo sweeping
      Serial.println("Servo sweeping ON");
    } 
    else if (command == '2') {
      sweepEnabled = false;  // Turn OFF servo sweeping
      Serial.println("Servo sweeping OFF");
    } 
    else{
      Serial.println("Invalid command. Enter '1' to START and '2' to STOP.");
    }
  }

  // If sweeping is enabled, sweep the servo back and forth
  if (sweepEnabled) {
    for (servoPos = 0; servoPos <= 180; servoPos++) {  // Move from 0 to 180 degrees
      myServo.write(servoPos);  // Set the servo position
      delay(15);  // Wait for the servo to reach the position
    }
    for (servoPos = 180; servoPos >= 0; servoPos--) {  // Move from 180 to 0 degrees
      myServo.write(servoPos);  // Set the servo position
      delay(15);  // Wait for the servo to reach the position
    }
  } else {
    myServo.write(90);  // If servo is off, hold at the default position (90 degrees)
  }
}
