/**
 * Project: Ultrasonic Proximity Alarm
 * Author: Hasan Ayberk Devki
 * Description: Measures distance using HC-SR04 and triggers a buzzer 
 * with variable frequency based on distance.
 */

// Pin Definitions
const int trigPin = 12;    // White cable
const int echoPin = 13;    // Yellow cable
const int buzzerPin = 8;   // Orange cable (+)

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Startup sound indicator
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  
  Serial.println("System Initialized...");
}

void loop() {
  long duration, distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by sending a 10us high pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance (Speed of sound is ~343m/s or 0.0343 cm/us)
  distance = (duration / 2) / 29.1;

  // Print distance to Serial Monitor
  Serial.print("Object Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Alarm Logic: Trigger if object is closer than 40cm
  if (distance > 0 && distance < 40) {
    digitalWrite(buzzerPin, HIGH);
    delay(50); // Short beep
    digitalWrite(buzzerPin, LOW);
    
    // Dynamic delay: Beeping speeds up as the object gets closer
    int beepDelay = distance * 8; 
    if(beepDelay < 20) beepDelay = 20; // Minimum delay for rapid beeping
    delay(beepDelay); 
  } else {
    // Standard idle delay when no object is detected
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
