//Date June 03, 2020
//Author Bimalka Piyaruwan Thalagala
TabNine::config
//------------------------------------------------------
//include the library needs to control the Servo.
#include <Servo.h>

//------------------------------------------------------
//Define the servo object
Servo mg90servo;

//-----------------------------------------------------
// Define a global variable to store the position of the Servo
int pos = 0;
//Define varibles to use in potCtrlServo() function.
int potpin = 5; // Pin where the pot is connected
int val; // variable to keep the analog read value of pot.


//-----------------------------------------------------

void setup() {
  //Attach the servo to one of the PWM supported digital pins.
  //Here D9 pin is used to attach the servo.
  Serial.begin(9600);
  mg90servo.attach(9);
}

void loop() {
//calling defined functions
//sweepServo();
potCtrlServo();
}


//------------------------------------------------------------
//Function defining.

//Function to rotate theservo back and forth repeatedly

void sweepServo() {
  //Shaft position is incremented by steps of 1 degree.
  for (pos = 0; pos <= 180; pos +=1) {
    mg90servo.write(pos);
    delay(15);
  }
  //Shaft position is Decremented by steps of 1 degree.
  for (pos = 180; pos >=0; pos -=1) {
    mg90servo.write(pos);
    delay(15);
  }
}

//Function to control the position of the serovo by a pot.

void potCtrlServo() {
val = analogRead(potpin);
Serial.println(val);
val = map(val, 0, 1023, 0, 180);
mg90servo.write(val);
delay(20);
}
