#include <SharpIR.h>

#define IR1 A1 // define signal pin
#define IR2 A2 // define signal pin

#define model1 1080 // for GP2Y0A21YK0F  used 1080
#define model2 1080 // for GP2Y0A21YK0F  used 1080

// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
/*
2 to 15 cm GP2Y0A51SK0F  use 215
4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
10 to 80 cm GP2Y0A21YK0F  use 1080
10 to 150 cm GP2Y0A60SZLF use 10150
20 to 150 cm GP2Y0A02YK0F use 20150
100 to 550 cm GP2Y0A710K0F  use 100550
*/
SharpIR SharpIR1(IR1, model1);
SharpIR SharpIR2(IR2, model2);

void setup() {
    // Multiple Sharp IR Distance meter code for Robojax.com
 Serial.begin(9600);
 Serial.println("Robojax Sharp IR  ");

 // extra pin for 5V if needed
 pinMode(2,OUTPUT);// define pin 2 as output
 digitalWrite(2, HIGH);// set pin 2 HIGH so it always have 5V
  // Robojax.com 20181201
}

void loop() {
    // Sharp IR code for Robojax.com 20181201
    delay(500);   

  unsigned long startTime=millis();  // takes the time before the loop on the library begins

  int dis1=SharpIR1.distance();  // this returns the distance for sensor 1
  int dis2=SharpIR2.distance();  // this returns the distance for sensor 2
  // Sharp IR code for Robojax.com 20181201

  Serial.print("Distance (1): ");
  Serial.print(dis1);
  Serial.println("cm");
  
  Serial.print("Distance (2): ");
  Serial.print(dis2);
  Serial.println("cm");
     // Sharp IR code for Robojax.com
     
}
