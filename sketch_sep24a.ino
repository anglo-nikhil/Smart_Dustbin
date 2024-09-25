#include <Servo.h>
// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int beep = 2;
Servo myServo;  // Create a servo object
void setup() {
  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
    myServo.attach(11);  // Attach the servo to pin 9  
  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(beep, OUTPUT);
}
void loop() {
  // Variables to store the duration and distance
  long duration;
  int distance;
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  // Send a 10us HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  // Read the echoPin (returns the sound wave travel time in microseconds)
  duration = pulseIn(echoPin, HIGH); 
  // Calculate the distance (speed of sound is ~343 m/s or 0.0343 cm/us)
  distance = duration * 0.034 / 2; // Divided by 2 because it's the round trip
  // Display the distance on the Serial Monitor
  delay(500);
while(distance<60 && distance>10){
digitalWrite(beep, HIGH);
     myServo.write(0);

 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10us HIGH pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin (returns the sound wave travel time in microseconds)
  duration = pulseIn(echoPin, HIGH);
 // Calculate the distance (speed of sound is ~343 m/s or 0.0343 cm/us)
  distance = duration * 0.034 / 2; // Divided by 2 because it's the round trip
delay(1000);
}
digitalWrite(beep, LOW);
myServo.write(180);
delay(500);
}
