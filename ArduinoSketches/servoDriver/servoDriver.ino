//Date June 03, 2020
//Author Bimalka Piyaruwan Thalagala
//TabNine::config
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
//int potpin = 5; // Pin where the pot is connected
//int val; // variable to keep the analog read value of pot.


//-----------------------------------------------------

void setup() {
  //Attach the servo to one of the PWM supported digital pins.
  //Here D9 pin is used to attach the servo.
  Serial.begin(9600);
  mg90servo.attach(9);
}

void loop() {
    for (pos = 0; pos <= 50; pos +=1) {
    mg90servo.write(pos);
    delay(15);
  }
  //Shaft position is Decremented by steps of 1 degree.
  for (pos = 50; pos >=0; pos -=1) {
    mg90servo.write(pos);
    delay(15);
}
}
