// Date: Oct 01, 2020
// Author: Bimalka Piyaruwan Thalagala

//-----------------------------------------------------------------------------
//EN1 and EN2 pins are used to send PWM signals to the driver.

#define PWM1 2
#define PWM2 3

//For other logical inputs for motors any other digital pin can be used.
#define INAM1 22
#define INBM1 24
#define INAM2 26
#define INBM2 28
const int avrageSpeed = 160;

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(INAM1, OUTPUT);
  pinMode(INBM1, OUTPUT);

  pinMode(PWM2, OUTPUT);
  pinMode(INAM2, OUTPUT);
  pinMode(INBM2, OUTPUT);
}

void loop() {


}

void motor_driver(int Left_motor_speed, int Right_motor_speed){
  if Left_motor_speed > 0{                              // Check wether left motor speed is posive and map into 0 - 255 to donot exceed max PWM value(255).
    if Left_motor_speed > 255{
      Left_motor_speed = 255;
      }

    digitalWrite(INAM1,HIGH);              // Set left motor for foward rotation.
    digitalWrite(INBM1,LOW);
    analogWrite(PWM1,Left_motor_speed);       // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    delay(200)

    }else{                                              // Check wether left motor speed is negative and map into 0 - (-255) to donot exceed max PWM value(255).
      if Left_motor_speed < -255{
        Left_motor_speed = -255;
        }
      }

    digitalWrite(INAM1,LOW);              // Set left motor for backward rotation.
    digitalWrite(INBM1,HIGH);
    analogWrite(PWM1,Left_motor_speed*-1);   // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    delay(200)

// Do the same procedure for right motor as follows.
   if Right_motor_speed > 0{
    if Right_motor_speed > 255{
      Right_motor_speed = 255;
      }

    digitalWrite(INAM2,HIGH);
    digitalWrite(INBM2,LOW);
    analogWrite(PWM2,Right_motor_speed);
    delay(200)

    }

    else{
      if (Right_motor_speed < -255)
      {
        Right_motor_speed = -255;
      }

      }

    digitalWrite(INAM2,LOW);
    digitalWrite(INBM2,HIGH);
    analogWrite(PWM2,Right_motor_speed*-1);
    delay(200)
  }
