#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 3

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // Initial position (closed lid)
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 15) { // Hand detected
    myServo.write(90); // Open lid
    delay(3000);       // Wait 3 seconds
    myServo.write(0);  // Close lid
  }

  delay(500);
}
