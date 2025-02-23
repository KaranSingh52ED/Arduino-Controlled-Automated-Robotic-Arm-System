#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13; // Changed d5 to pin 5
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int op = 0;
int count = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  op = digitalRead(7);
  if (op == 0) {
    count += 1;
    }
  lcd.setCursor(0,1);
  lcd.print(count);
  delay(500);
}
