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
int millimetersLeft = 180;// just defining length to travel for left encoder
int millimetersRight = 10;// just defining length to travel for Right encoder
int millimetersStraight = 50;// just defining length to travel for  encoder to go straight
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
int drivedistanceLeft(int millimetersLeft);// function to give the needed distance to travel for left encoder
int drivedistanceRight(int millimetersRight);// function to give the needed distance to travel for right encoder
int drivedistanceStraight(int millimetersStraight);// function to give the needed distance to travel straight for any encoder
}
void drivedistanceStraight(int millimetersStraight){
  motors.setSpeeds( 00,  00);
  delay(10);
  int tickGoalStraight = (35*millimetersStraight)/10;// Defining number of ticks required to travel the distance
  while ((leftCount<tickGoalStraight) || (rightCount<tickGoalStraight)){
    motors.setSpeeds( 20,  20);//starting motors to trael needed distance
    delay(1000);
    }
    motors.setSpeeds( 00,  00);//stopping motors after the required distance
    delay(10);
  }
void drivedistanceLeft(int millimetersLeft){
  motors.setSpeeds( 00,  00);
  delay(10);
  int tickGoalLeft = (35*millimetersLeft)/10;// Defining number of ticks required to travel the distance
  while (leftCount<tickGoalLeft){
    motors.setSpeeds( 20,  -20);//starting motors to trael needed distance
    delay(1000);
    }
    motors.setSpeeds( 00,  00);//stopping motors after the required distance
    delay(10);
  }
 void drivedistanceRight(int millimetersRight){
  motors.setSpeeds( 00,  00);
  delay(10);
  int tickGoalRight = (35*millimetersRight)/10;// Defining number of ticks required to travel the distance
  while (rightCount<tickGoalRight){
    motors.setSpeeds( -20,  20);//starting motors to trael needed distance
    delay(1000);
    }
    motors.setSpeeds( 00,  00);//stopping motors after the required distance
    delay(10);
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
