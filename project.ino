// Define pins for Ultrasonic Sensor HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Define pin for Infrared Sensor GP2Y0A21YK
const int irPin = A0;

// Variables to store the distance values
long duration;
int distanceUltrasonic;
int distanceInfrared;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize the IR pin as input
  pinMode(irPin, INPUT);
}

void loop() {
  // Get distance from Ultrasonic Sensor
  distanceUltrasonic = getUltrasonicDistance();
  // Get distance from Infrared Sensor
  distanceInfrared = getInfraredDistance();
  
  // Print the distances to Serial Monitor
  Serial.print("Ultrasonic Distance: ");
  Serial.print(distanceUltrasonic);
  Serial.print(" cm, ");
  
  Serial.print("Infrared Distance: ");
  Serial.print(distanceInfrared);
  Serial.println(" cm");
  
  // Delay before the next reading
  delay(500);
}

int getUltrasonicDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, and return the distance in cm
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

int getInfraredDistance() {
  // Read the analog value from the IR sensor
  int analogValue = analogRead(irPin);
  
  // Convert the analog value to distance (in cm)
  int distance = map(analogValue, 0, 1023, 80, 10); // Adjust the mapping based on your sensor's characteristics
  return distance;
}