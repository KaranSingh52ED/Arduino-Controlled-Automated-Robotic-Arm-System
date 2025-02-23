#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd1(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(A3, INPUT);
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);
  lcd1.begin(16, 2);
  Serial.begin(9600);
  // lcd1.setCursor(0,1);
  // Print a message to the LCD
}

// the loop function runs over and over again forever
void loop() {
  lcd.setCursor(0,0);
  lcd.print(analogRead(A3));
  Serial.println(analogRead(A3));

  delay(1000);
  lcd.clear();
  if(analogRead(A3)>700)
  {
    digitalWrite(11,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Light is On");
  }
  else
  {
    digitalWrite(11,LOW);
  }
}