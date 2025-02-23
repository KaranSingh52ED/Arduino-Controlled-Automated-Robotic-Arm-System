const int irSensorPin = A2; // Pin connected to the IR sensor's digital output
const int electromagnetPin = 7; // Pin connected to the electromagnet

void setup() {
  Serial.begin(9600); // Start the serial communication
  pinMode(irSensorPin, INPUT); // Set the IR sensor pin as input
  pinMode(electromagnetPin, OUTPUT); // Set the electromagnet pin as output
}

void loop() {
  int sensorValue = analogRead(irSensorPin); // Read the IR sensor value

  if (sensorValue >990) { // If the sensor detects an object
    digitalWrite(electromagnetPin, HIGH); // Turn on the electromagnet
    Serial.println("Electromagnet ON");
  } else {
    digitalWrite(electromagnetPin, LOW); // Turn off the electromagnet
    Serial.println("Electromagnet OFF");
  }

  delay(100); // Delay before the next reading
}
