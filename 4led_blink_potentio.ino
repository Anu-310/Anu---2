#include<Servo.h>
int motor_input_1=2;
int motor_input_2=3;
int motor_input_3=4;
int motor_input_4=5;
int pwm_motor_1 = 9;
int pwm_motor_2 =10;

int trig = 12;
int echo = 11;

Servo servo_1;
int servopin=11;
int moisturesensor=A0;

long distance_threshold = 8;
int moisture_threshold_value = 20;

int moisturevalue;

int relaypin=12;


 
void setup() {
Serial.begin(9600);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,INPUT);
pinMode(12,OUTPUT);

servo_1.attach(11);

digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);


}

void loop() {

moisturevalue = analogRead(moisturesensor);

long duration;
long distance;

digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
  
distance = (duration*0.0343)/2;

Serial.print("Distance:");
Serial.println(distance);

if ( distance<distance_threshold){
  digitalWrite(9,0);
  digitalWrite(10,0);
  Serial.print("PLANT DETECTED");
  Serial.println(distance);
  servo_1.write(90);
  delay(5000);
  servo_1.write(0);
}

else{
 digitalWrite(9,200);
  digitalWrite(10,200);  
}

int moisture_percentage;

moisture_percentage = map(moisturevalue,0,1023,0,100);

if (moisture_percentage<moisture_threshold_value){
  digitalWrite(relaypin,HIGH);
  delay(5000);
  Serial.print("Moisture Percentage");
  Serial.println(moisture_percentage);
  Serial.println("%");
}

else{
  digitalWrite(relaypin,LOW);
}

delay(5000);


}
