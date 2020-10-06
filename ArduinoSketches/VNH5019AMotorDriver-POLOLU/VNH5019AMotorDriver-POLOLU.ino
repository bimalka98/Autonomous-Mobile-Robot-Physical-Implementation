#include <DualVNH5019MotorShield.h>



DualVNH5019MotorShield motors;

void setup()
{
  motors.init();
}

void loop(){

for(int i =100; i<=400; i++) {motors.setSpeeds(i, i);delay(10);}
motors.setSpeeds( 00,  00);
delay(1000);
for(int i =400; i>=-400; i--) motors.setSpeeds(i, i);delay(1000);
for (int i = -400; i <= 0; i++) motors.setSpeeds(i, i);delay(1000);
}
