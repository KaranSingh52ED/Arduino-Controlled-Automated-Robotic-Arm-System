
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(3, analogRead(A2));  // turn the LED on (HIGH is the voltage level)
}
