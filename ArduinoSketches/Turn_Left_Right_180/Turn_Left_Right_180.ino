#include <DualVNH5019MotorShield.h>



DualVNH5019MotorShield motors;

void setup()
{
  motors.init();
}

void loop(){

}


void turn_left(){
  motors.setSpeeds(-100, 100);
  delay(1500);
  motors.setSpeeds(00, 00);
  delay(10);
}


void turn_right(){
  motors.setSpeeds(100, -100);
  delay(1500);
  motors.setSpeeds(00, 00);
  delay(10);
}


void turn_180(){
  motors.setSpeeds(-100, 100);
  delay(3000);
  motors.setSpeeds(00, 00);
  delay(10);
}
