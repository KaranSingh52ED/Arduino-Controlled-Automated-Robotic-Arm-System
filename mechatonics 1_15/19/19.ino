#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String receivedString = "";  // To store the received serial data
String extractedNumbers = "";  // To store extracted numbers

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  lcd.begin(16, 2);    // Initialize the 16x2 LCD
}

void loop() {
  // Check if data is available on the serial port
  lcd.setCursor(0,0);
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read each character from serial
    
    // Check if the character is a digit (0-9)
    if (isDigit(receivedChar)) {
      extractedNumbers += receivedChar;  // Append the number to the string
    }

    // If a newline character is received, process the string
    if (receivedChar == '\n') {
      displayNumbersOnLCD();  // Display the extracted numbers
      receivedString = "";    // Reset for the next string
      extractedNumbers = "";  // Reset the extracted numbers
    }
  }
}

void displayNumbersOnLCD() {
  lcd.clear();  // Clear the LCD
  lcd.setCursor(0, 0);
  
  // If no numbers were extracted, display "No numbers"
  if (extractedNumbers.length() == 0) {
    lcd.print("No numbers");
  } else {
    lcd.print("Numbers:");     // Print "Numbers:" on the LCD
    lcd.setCursor(0, 1);       // Move to the second line
    lcd.print(extractedNumbers);
    Serial.println(extractedNumbers);// Display the extracted numbers
  }
}
