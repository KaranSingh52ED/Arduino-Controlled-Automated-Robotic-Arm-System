#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 8, d6 = 12, d7 = 13;
int count=0;
unsigned long startTime;
const unsigned long duration = 10000;  // 5 seconds duration

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(A3, INPUT);
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  startTime = millis();
  // lcd1.setCursor(0,1);
  // Print a message to the LCD
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentTime = millis();
  lcd.setCursor(0,0);
  lcd.print(analogRead(A3));
  Serial.println(analogRead(A3));

  delay(1000);
  lcd.clear();
  if(analogRead(A3)>500)
  {
    digitalWrite(11,HIGH);
    lcd.setCursor(0,1);
    count+=1;
    lcd.print(count);
  }
  else
  {
    digitalWrite(11,LOW);
  }
  if (currentTime - startTime >= duration) {
    lcd.setCursor(0, 0);
    lcd.print("Time up!       ");
    lcd.setCursor(0, 1);
    lcd.print("Final count: ");
    lcd.print(count);
    while (1);  
    count=0;
  }
}
