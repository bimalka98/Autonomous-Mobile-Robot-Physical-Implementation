// Author : Avishka Sandeepa
// Create : 18.06.2020

// In this case we consider about only wall following part.
// In our task there are two alternative curved walls occurs.
// each wall occurs at 15cm from middle.
// To detect walls we use two SharpIR sensors wich has detecting range of 4cm - 30 cm.
// There is also wall free zone. When robot moves from one wall to other there is an empty region upto 5cm.


#include <SharpIR.h>  // Include SharpIR Library.

#define IR_Left A0    // Define Analog Pin as Left IR senor analog output pin.
#define IR_Right A1   // Define Analog Pin as Left IR senor analog output pin.
#define model 430     // Define IR model which we use in our project. In here we use GP2Y0A41 sensor and its range is 4-30cm.

// Define initial PID constants as follows for PID calculations.
// These values can be changed during calibration.
#define Kp 5.00
#define Ki 0.00
#define Kd 0.00

int error = 0;            // Initiated error value as zero.
int lastError = 0;        // Initiated previous error value as zero.
int propotional = 0;      // Initiated propotional term as zero.
int integral = 0;         // Initiated integral term as zero.
int derivative = 0;       // Initiated derivative term as zero.
int threshold = 20;       // Define threshold distance value to check wether wall occurs or not. If measure distance exceed threshold it means there is no wall.
int setDistance = 15;     // Define set distance as 15 cm.
#define motorSpeed 150    // Define default motor as 100 PWM value. This value can be changed during calibrations.

// Define digital pin 9 & 10 for left motor outputs and PWM pin 5 for enable pin.
#define left_motor_forward 9
#define left_motor_backward 10
#define left_motor_PWM 5

// Define digital pin 7 & 8 for right motor outputs and PWM pin 6 for enable pin.
#define right_motor_forward 7
#define right_motor_backward 8
#define right_motor_PWM 6

SharpIR ShrapIR_Left(IR_Left,model);       // To calculate distance by using Left IR sensor.
SharpIR ShrapIR_Right(IR_Right,model);     // To calculate distance by using Right IR sensor.


void setup() {
  pinMode(left_motor_forward,OUTPUT);           
  pinMode(left_motor_backward,OUTPUT);        // Assign left motor speed pins as OUTPUT pins.
  pinMode(left_motor_PWM,OUTPUT);
  pinMode(right_motor_forward,OUTPUT);
  pinMode(right_motor_backward,OUTPUT);       // Assign right motor speed pins as OUTPUT pins.
  pinMode(right_motor_PWM,OUTPUT);
  pinMode(IR_Left,INPUT);                     // Assign left Sharp IR pin as INPUT pin.
  pinMode(IR_Right,INPUT);                    // Assign right Sharp IR as INPUT pin.
  
  }


// Define motor driver function.
void motor_driver(int Left_motor_speed, int Right_motor_speed){
  if Left_motor_speed > 0{                              // Check wether left motor speed is posive and map into 0 - 255 to donot exceed max PWM value(255).
    if Left_motor_speed > 255{
      Left_motor_speed = 255;
      }
      
    digitalWrite(left_motor_forward,HIGH);              // Set left motor for foward rotation.
    digitalWrite(left_motor_backward,LOW); 
    analogWrite(left_motor_PWM,Left_motor_speed);       // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    delay(200)

    }else{                                              // Check wether left motor speed is negative and map into 0 - (-255) to donot exceed max PWM value(255).
      if Left_motor_speed < -255{
        Left_motor_speed = -255;
        }
      }

    digitalWrite(left_motor_forward,LOW);              // Set left motor for backward rotation.
    digitalWrite(left_motor_backward,HIGH);
    analogWrite(left_motor_PWM,Left_motor_speed*-1);   // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    delay(200)

// Do the same procedure for right motor as follows.
   if Right_motor_speed > 0{
    if Right_motor_speed > 255{
      Right_motor_speed = 255;
      }

    digitalWrite(right_motor_forward,HIGH);
    digitalWrite(right_motor_backward,LOW);
    analogWrite(right_motor_PWM,Right_motor_speed);
    delay(200)
    
    }else{
      if Right_motor_speed < -255{
        Right_motor_speed = -255;
        }
      }

    digitalWrite(right_motor_forward,LOW);
    digitalWrite(right_motor_backward,HIGH);
    analogWrite(right_motor_PWM,Right_motor_speed*-1);
    delay(200)
  
  }

// define function for PID calculations.
void PID_calculation(){
  error = current_left_distance - setDistance;             // Create error value.
  propotional = error * Kp;                                // Create propotional error term.
  integral = (error - lastError)*Ki;                       // Create integral error term.
  derivative = (error + lastError)*Kd;                     // Create derivative error term.

  lastError = error;                                       // Update last error term.
  error_term = propotional + integral + derivative;        // Create PID error control term.


  }



// Define a function for wall free zone.
void wall_free_zone(){
  Left_motor_speed = motorSpeed;                                              // Assign motor speeds to constants to go ahead.
  Right_motor_speed = motorSpeed;
  delay(2000)                           
  }



void loop() {
  int current_right_distance = ShrapIR_Right.distance();     // Define current distance of a right wall from robot in cm.
  int current_left_distance = SharpIR_Left.distance();       // Define current distance of a left wall from robot in cm.
  
  if current_left_distance > threshold && current_right_distance > threshold{      // verify there is no wall.
    wall_free_zone();                                                              // Call the pre  define functions.
    motor_driver(Left_motor_speed,Right_motor_speed);

  }else if current_left_distance <= threshold{                     // Check wether wall occurs or not on left side.
  PID_calculation();
  motor_driver(motorSpeed + error_term,motorSpeed - error_term);

  }else if current_right_distance <= threshold{                     // Check wether wall occurs or not on right side.
  PID_calculation();
  motor_driver(motorSpeed - error_term,motorSpeed + error_term);
  }

}

// End of the code!