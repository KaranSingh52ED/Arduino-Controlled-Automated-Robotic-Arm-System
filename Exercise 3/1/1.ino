const int pin = 7; // Pin you want to energize

void setup() {
  pinMode(pin, OUTPUT); // Set the pin as an output
}

void loop() {
  digitalWrite(pin, HIGH); // Energize the pin
  delay(5000); // Wait for 5 seconds
  digitalWrite(pin, LOW); // Turn off the pin
  delay(2000); // Wait for 2 seconds
}
 
