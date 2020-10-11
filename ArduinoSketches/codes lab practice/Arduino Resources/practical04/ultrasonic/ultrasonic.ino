const int triggerPin = 8;
const int echoPin = 10;
long duration;
int distance;
const float sec_to_microsec = 1000000.0;
const float meter_to_cm = 100.0;
const float speed_of_sound = 340.0; //meters per second

void setup() {
  pinMode(triggerPin, OUTPUT); // Set the triggerPin as an Output
  pinMode(echoPin, INPUT); // Set the echoPin as an Input
  Serial.begin(115200); // Start the serial communication
}

void loop() {
  
  // Initiate triggerPin as LOW
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Set the triggerPin HIGH for atleast 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Monitor the echoPin and
  duration = pulseIn(echoPin, HIGH); //Returns the length of the pulse in microseconds
  
  // Calculate distance and print on Serial Monitor
  distance = (duration/sec_to_microsec)*(speed_of_sound*meter_to_cm)/2.0;
  
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(500);
}
