#include <Servo.h>

Servo myservo;  // Create a servo object

int pos = 0;    // Variable to store the servo position

void setup() {
  myservo.attach(8
  
  
  
  );  // Attach servo to pin 9
}

void loop() {
  // Move the servo from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);  // Tell servo to go to 'pos'
    delay(15);           // Wait for the servo to reach the position
  }
  // Move the servo back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
