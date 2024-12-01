int motor_input_1 = 2;
int motor_input_2 = 3;
int motor_input_3 = 4;
int motor_input_4 = 5;
int pwm_motor_1 = 9;
int pwm_motor_2 = 10;

void setup(){
  pinMode(motor_input_1, OUTPUT);
  pinMode(motor_input_2, OUTPUT);
  pinMode(motor_input_3, OUTPUT);
  pinMode(motor_input_4, OUTPUT);
  pinMode(pwm_motor_1, OUTPUT);
  pinMode(pwm_motor_2, OUTPUT);
 
  Serial.begin(9600);

  // Set initial PWM values for motors
  analogWrite(pwm_motor_1, 200);
  analogWrite(pwm_motor_2, 200);

  // Move the motors forward
  digitalWrite(motor_input_1, HIGH);
  digitalWrite(motor_input_2, LOW);
  digitalWrite(motor_input_3, HIGH);
  digitalWrite(motor_input_4, LOW);
}

void loop(){
  // You can place additional motor control code here if needed
}
