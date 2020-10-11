#define irPin A0 
#define numSamples 10 
  
int Adcres = 10; 
int refVoltage = 5000; 
  
//Function for sorting an array 

void sort(int a[], int len) {     
  for(int i=0; i<(len-1); i++) { 
        bool flag = true; 
        for(int o=0; o<(len-(i+1)); o++) { 
            if(a[o] > a[o+1]) {                 
              int t = a[o];                 
              a[o] = a[o+1];                 
              a[o+1] = t;                 
              flag = false; 
            }
        }         
        if (flag) break; 
  } 
} 
  
void setup() {   
  pinMode (irPin, INPUT); 
  Serial.begin(115200); 
} 
  
void loop() { 
  
  // Sample values from the analog read of irPin    
  int ir_val[numSamples]; 
  for (int i=0; i<numSamples; i++){ 
        // Read analog value 
        ir_val[i] = analogRead(irPin); 
  } 
  
  // Find the median of sampled values   
  sort(ir_val,numSamples); 
  int sampleMedian = ir_val[numSamples / 2]; 
  
  // Map the sampleMedian from 0-5 
  float v = map(sampleMedian, 0, 1023, 0, 5000)/1000.0;   
  
  // Approximate distance using the following equation   
  int distanceMM =(int)( 603.74 * pow(v, -1.16)); 
  
  Serial.print(sampleMedian); 
  Serial.print(' '); 
  Serial.println(distanceMM);   
  delay(200); 
}
