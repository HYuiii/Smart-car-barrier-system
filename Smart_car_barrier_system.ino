#include<AmebaServo.h>

AmebaServo myservo;
const int trigPin=3;
const int echoPin=5; 
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

// measure time duration of pulse HIGH at echo pin
duration=pulseIn(echoPin, HIGH);

// calculate the distance from car to sensor
distance=(0.034*duration)/2;

if(distance<=20){
  myservo.write(90);
  }
else{
  myservo.write(0);
  }
  
  Serial.print("distance: ");
  Serial.println(distance);
  Serial.print(" cm");
  delay(1);
}
