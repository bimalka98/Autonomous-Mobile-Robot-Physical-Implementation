//************************Including necessary libraries*************************
#include <DualVNH5019MotorShield.h> // Library for motor driver
#include <SharpIR.h> // Library for SharpIRs
#include <Wire.h> // Library for I2C communication
#include <Adafruit_PWMServoDriver.h> // Library for servo driver

// *******************************Defining macros*******************************
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define Gripper 11
#define GripperBase 0
#define Arm 6

//*******************************Defining objects*******************************
DualVNH5019MotorShield motors;
SharpIR SharpIR1(A0, 1080); // define input pin and model for SharpIR1
//SharpIR SharpIR2(A13, 1080); // define input pin and model for SharpIR2
// SharpIR1.distance();  // this returns the distance to the object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//*******************Variables definitions for line following*******************
const int base_speed = 90; // Speed of the motors at error 0
const int max_speed = 150; // Speed of the motors at max error

long sum_of = 0;
long avg = 0;
long sensor[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // A0-A11 analogRead store
long error = 0;
long last_error = 0;
long set_point = 750;
long pos = 0;
long proportional = 0;
long derivative = 0;
long error_value = 0;
long kp = 9.5;
long kd = 25;


void setup() {
  motors.init(); //PinMode setup for motors
  Serial.begin(9600); //enable communication with PC
  pwm.begin();
  pwm.setOscillatorFrequency(12000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(500);
}

void loop()
{
  Serial.println(SharpIR1.distance());
  if (SharpIR1.distance() == 16) {
    delay(250);
    if (SharpIR1.distance() == 16) {
      Serial.println(SharpIR1.distance());
      initializeArm();
      rotateBox();
      restArm();
    }
  }
  //error_value = pid_calculation() / 100;
  // Serial.print(error_value);
  // Serial.print(" ");
  //motors.setSpeeds(base_speed - error_value, base_speed + error_value);
  //motor_driver(base_speed - error_value, base_speed + error_value);
  // Serial.print(base_speed - error_value);
  // Serial.print(" ");
  // Serial.print(base_speed + error_value);
  // Serial.println(" " );
  // delay(500);

}

//*****************************Function Definitions***************************//

//--------------------------Reading the IR sensor array-------------------------
int read_sensor() {
  long sum_of = 0;
  long avg = 0;
  long pos = 0;
  for (int i = 0; i < 12; i++) {
    sensor[i] = analogRead(i);
    if (sensor[i] < 100) sensor[i] = 1;
    else sensor[i] = 0;
  }
  for (int i = 0; i < 12; i++) {
    avg += sensor[i] * i * 100;
    sum_of += sensor[i];
    // Serial.print(sensor[i]); Serial.print(' ');
  }
  if (sum_of == 0) pos = set_point;
  else  pos = avg / sum_of;
  // Serial.print(avg); Serial.print(' ');
  // Serial.print(sum_of); Serial.print(' ')
  // Serial.println(pos); delay(1000);
  return pos; //Output of the read_sensor function.
}
//----------------------PID_calculation for line following----------------------
float pid_calculation() {
  error = read_sensor() - set_point;
  // Serial.println(error); delay(200);
  proportional = kp * error;
  // Serial.println(proportional); delay(200);
  derivative = kd * (error - last_error);
  last_error = error;
  error_value = proportional + derivative;
  return error_value;
  // Serial.println(error_value); delay(200);
}
// -----------------------Functions related to Robot arm------------------------
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
  // Sending arm to the rest
  for (uint16_t microsec = 2000; microsec <= 6000; microsec++) pwm.writeMicroseconds(Arm, microsec); delay(500);
  for (uint16_t microsec = 1000; microsec >= 400; microsec--) pwm.writeMicroseconds(Gripper, microsec); delay(500);
  for (uint16_t microsec = 3200; microsec >= 2500; microsec--) pwm.writeMicroseconds(GripperBase, microsec); delay(500);
}
