const int transmitterPin = 14;  // Pin 14 (A0) as the transmitter
const int receiverPin = 15;     // Pin 15 (A1) as the receiver
const int threshold=500;
void setup() {
  // Set the transmitter pin as OUTPUT and the receiver pin as INPUT
  pinMode(transmitterPin, OUTPUT);
  pinMode(receiverPin, INPUT);

  // Start Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Transmit signal (send HIGH signal to the transmitter pin)
  digitalWrite(transmitterPin, HIGH);  // Turn on the transmitter
  digitalWrite(receiverPin, HIGH);  // Turn on the 

  // Read the signal from the receiver pin
  int receiverValue = analogRead(receiverPin);  // Read the digital value

  // Check if the receiver is detecting something
  if (receiverValue > threshold) {
    Serial.println("Object detected!");
    Serial.println(analogRead(receiverPin));
    // Object detected by the proximity sensor
  } else {
    Serial.println("No object detected.");  // No object detected
    Serial.println(analogRead(receiverPin));
  }
  // Wait for a short period before the next check
  delay(500);
}
