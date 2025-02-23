#include <Servo.h>

Servo myservo;
int pos=0;
int val=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A2,INPUT);
  myservo.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A2));
  val = map(analogRead(A2),200,1010,0,180);
  myservo.write(val);
//    for (pos = 0; pos <= val; pos += 1) { // goes from 0 degrees to 180 degrees
//      // in steps of 1 degree
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15 ms for the servo to reach the position
//  }

}
