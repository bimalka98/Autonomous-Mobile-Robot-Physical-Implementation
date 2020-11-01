
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define Gripper 11
#define GripperBase 0
#define Arm 6


void setup() {
  pwm.begin();
  // In theory the internal oscillator is 25MHz but it really isn't
  // that precise. You can 'calibrate' by tweaking this number till
  // you get the frequency you're expecting!
  pwm.setOscillatorFrequency(12000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}
void loop() {

  initializeArm();
  rotateBox();
  restArm();

}

void initializeArm() {
  //Get the  arm to the initial position from wherever it was
  for (uint16_t microsec = 6000; microsec >= 2000; microsec--) pwm.writeMicroseconds(Arm, microsec); delay(1000);
  for (uint16_t microsec = 1000; microsec >= 400; microsec--) pwm.writeMicroseconds(Gripper, microsec); delay(500);
  for (uint16_t microsec = 3200; microsec >= 2500; microsec--) pwm.writeMicroseconds(GripperBase, microsec); delay(500);
  for (uint16_t microsec = 2000; microsec >= 400; microsec--) pwm.writeMicroseconds(Arm, microsec); delay(1000);
}

void rotateBox() {
  // Roate the box 90 degred toward the robot
  for (uint16_t microsec = 400; microsec <= 2200; microsec++) pwm.writeMicroseconds(Gripper, microsec); delay(500);
  for (uint16_t microsec = 400; microsec <= 2500; microsec++) pwm.writeMicroseconds(Arm, microsec); delay(500);
  for (uint16_t microsec = 2500; microsec <= 5500; microsec++) pwm.writeMicroseconds(GripperBase, microsec); delay(500);
  for (uint16_t microsec = 2500; microsec >= 2000; microsec--) pwm.writeMicroseconds(Arm, microsec); delay(500);
  for (uint16_t microsec = 2200; microsec >= 400; microsec--) pwm.writeMicroseconds(Gripper, microsec); delay(1000);
}

void restArm() {
  for (uint16_t microsec = 2000; microsec <= 6000; microsec++) pwm.writeMicroseconds(Arm, microsec); delay(500);
  for (uint16_t microsec = 1000; microsec >= 400; microsec--) pwm.writeMicroseconds(Gripper, microsec); delay(500);
  for (uint16_t microsec = 3200; microsec >= 2500; microsec--) pwm.writeMicroseconds(GripperBase, microsec); delay(500);
}
