int motor_input_1 = 2;
int motor_input_2 = 3;
int motor_input_3 = 4;
int motor_input_4 = 5;
int pwm_motor_1 = 9;
int pwm_motor_2 = 10;

int trig = 11;
int echo = 12;

long distance_threshold = 20;  // Threshold distance in cm

void setup() {
  Serial.begin(9600);

  // Motor control pins
  pinMode(motor_input_1, OUTPUT);
  pinMode(motor_input_2, OUTPUT);
  pinMode(motor_input_3, OUTPUT);
  pinMode(motor_input_4, OUTPUT);
  pinMode(pwm_motor_1, OUTPUT);
  pinMode(pwm_motor_2, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trig, OUTPUT);  // Trigger pin should be OUTPUT
  pinMode(echo, INPUT);   // Echo pin should be INPUT

  // Initial motor direction (forward)
  digitalWrite(motor_input_1, HIGH);
  digitalWrite(motor_input_2, LOW);
  digitalWrite(motor_input_3, HIGH);
  digitalWrite(motor_input_4, LOW);

  // Set initial PWM speed for motors
  analogWrite(pwm_motor_1, 200);  // Speed for motor 1
  analogWrite(pwm_motor_2, 200);  // Speed for motor 2
}

void loop() {
  long duration;
  long distance;

  // Send pulse to trigger the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the pulse duration from the echo pin
  duration = pulseIn(echo, HIGH);

  // Calculate the distance in centimeters
  distance = (duration * 0.0343) / 2;

  // Print the distance for debugging purposes
  Serial.print("Distance: ");
  Serial.println(distance);

  // If an object is detected within the threshold distance, stop the motors
  if (distance < distance_threshold) {
    analogWrite(pwm_motor_1, 0);  // Stop motor 1
    analogWrite(pwm_motor_2, 0);  // Stop motor 2
    Serial.println("PLANT DETECTED");
    
    delay(5000);  // Stop for 5 seconds
  }
  // Otherwise, continue moving forward
  else {
    analogWrite(pwm_motor_1, 200);  // Continue motor 1
    analogWrite(pwm_motor_2, 200);  // Continue motor 2
  }

  delay(100);  // Short delay before the next ultrasonic reading
}
