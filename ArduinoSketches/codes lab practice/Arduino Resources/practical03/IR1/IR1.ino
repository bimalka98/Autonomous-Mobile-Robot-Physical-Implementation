#define irPin A0 
#define numSamples 10 
  
void setup() {   
  pinMode (irPin, INPUT); 
  Serial.begin(115200); 
} 
  
void loop() {   
  int sample = analogRead(irPin);   // Map the sample from 0-5 
  float v = map(sample, 0, 1023, 0, 5000)/1000.0;

  Serial.println(v);
   
  // Approximate distance (in mm) using the following equation   
  int dist =(int)( 603.74 * pow(v, -1.16)); 
//  Serial.println(dist);   
  delay(200); 
  } 
 
