#include <Servo.h>

Servo myServo;  // Create a servo object to control a servo
int minPosition = 0;
int maxPosition = 180;

void setup() {
  myServo.attach(5);  // Attach the servo to pin 5
  Serial.begin(9600);
}

void loop() {
  Serial.println("Identifying working range of the servo...");

  // Sweep from min to max position
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(10);  // Adjust delay based on servo speed

    int actualPos = myServo.read();  // Read the current position
    Serial.print("Trying position: ");
    Serial.print(pos);
    Serial.print(" degrees, Servo moved to: ");
    Serial.print(actualPos);
    Serial.println(" degrees");

    // Check if servo reached the intended position
    if (actualPos != pos) {
      if (pos < 90) {
        minPosition = pos - 1;  // Set min position just before failure
        Serial.print("Minimum working position identified: ");
        Serial.print(minPosition);
        Serial.println(" degrees");
        break;
      } else {
        maxPosition = pos - 1;  // Set max position just before failure
        Serial.print("Maximum working position identified: ");
        Serial.print(maxPosition);
        Serial.println(" degrees");
        break;
      }
    }
  }

  // Report the identified range
  Serial.print("Servo working range identified: ");
  Serial.print(minPosition);
  Serial.print(" to ");
  Serial.print(maxPosition);
  Serial.println(" degrees");

  delay(5000);  // Wait for a while before running the loop again
}
