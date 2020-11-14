//Author: Ravindu Nagasinghe
#include <DualVNH5019MotorShield.h>
// pins for the encoder inputs
#define RH_ENCODER_A 3 
#define RH_ENCODER_B 5
#define LH_ENCODER_A 2
#define LH_ENCODER_B 4
 
// variables to store the number of encoder pulses
// for each motor
volatile unsigned long leftCount = 0;
volatile unsigned long rightCount = 0;
int millimeters = 180;// just defining length to travel for now
int ticks=0;
DualVNH5019MotorShield motors;
void setup() {
  motors.init();
  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
  
  // initialize hardware interrupts
  attachInterrupt(digitalPinToInterrupt(2), leftEncoderEvent, CHANGE);//2 is the LH Encoder A value
  attachInterrupt(digitalPinToInterrupt(3), rightEncoderEvent, CHANGE);//3 is the RH Encoder A value
  
  Serial.begin(9600);
  
}

void loop() {
int drivedistance(int millimeters)// function to give the needed distance to travel

}
void drivedistance(int millimeters){
  motors.setSpeeds( 00,  00);
  int tickGoal = (35*millimeters)/10;// Defining number of ticks required to travel the distance
  while ((leftCount<ticks) ||  (rightCount<ticks)){
    motors.setSpeeds( 20,  20);//starting motors to trael needed distance
    }
    motors.setSpeeds( 00,  00);//stopping motors after the required distance
  }
// encoder event for the interrupt call
void leftEncoderEvent() {
  if (digitalRead(LH_ENCODER_A) == HIGH) {
    if (digitalRead(LH_ENCODER_B) == LOW) {
      leftCount++;
    } else {
      leftCount--;
    }
  } else {
    if (digitalRead(LH_ENCODER_B) == LOW) {
      leftCount=0;
    } else {
      leftCount++;
    }
  }
}
 
// encoder event for the interrupt call
void rightEncoderEvent() {
  if (digitalRead(RH_ENCODER_A) == HIGH) {
    if (digitalRead(RH_ENCODER_B) == LOW) {
      rightCount++;
    } else {
      rightCount--;
    }
  } else {
    if (digitalRead(RH_ENCODER_B) == LOW) {
      rightCount=0;
    } else {
      rightCount++;
    }
  }
}
