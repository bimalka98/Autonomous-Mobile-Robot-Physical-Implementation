// **********************Pins definitions for motor driver**********************
// #define PWM1 2   //Motor 1 PWM
// #define INAM1 22 //Motor 1
// #define INBM1 24 //Motor 1
// #define PWM2 3   //Motor 2 PWM
// #define INAM2 26 //Motor 2
// #define INBM2 28 //Motor 2

#include <DualVNH5019MotorShield.h>
DualVNH5019MotorShield motors;

const int base_speed = 90; // Speed of the motors at error 0
//const int max_speed = 150; // Speed of the motors at max error

//*******************Variables definitions for line following*******************
long sum_of =0;
long avg = 0;
long sensor[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
  //--------------------------PinMode setup for motors--------------------------
  motors.init();
  // pinMode(PWM1, OUTPUT);
  // pinMode(INAM1, OUTPUT);
  // pinMode(INBM1, OUTPUT);
  // pinMode(PWM2, OUTPUT);
  // pinMode(INAM2, OUTPUT);
  // pinMode(INBM2, OUTPUT);
  //---------------------------Communication with PC----------------------------
  Serial.begin(9600);
}

void loop()
{

  error_value = pid_calculation()/100;
  // Serial.print(error_value);
  // Serial.print(" ");
  motors.setSpeeds(base_speed - error_value, base_speed + error_value);
  //motor_driver(base_speed - error_value, base_speed + error_value);
  // Serial.print(base_speed - error_value);
  // Serial.print(" ");
  // Serial.print(base_speed + error_value);
  // Serial.println(" " );
  // delay(500);

}

//*****************************Function Definitions***************************//

//----------------------------Forward Motor Driving-----------------------------
// void motor_driver(int Left_motor_speed, int Right_motor_speed){
//   if (Left_motor_speed > 0){
//       if (Left_motor_speed > 255) Left_motor_speed = max_speed;
//     digitalWrite(INAM1,HIGH);
//     digitalWrite(INBM1,LOW);
//     analogWrite(PWM1,Left_motor_speed);
//     }
//   else {
//       if (Left_motor_speed < -255) Left_motor_speed = -1*max_speed;
//     digitalWrite(INAM1,LOW);
//     digitalWrite(INBM1,HIGH);
//     analogWrite(PWM1,Left_motor_speed*(-1));
//       }
// // Do the same procedure for right motor as follows.
//    if (Right_motor_speed > 0){
//      if (Right_motor_speed > 255) Right_motor_speed = max_speed;
//     digitalWrite(INAM2,HIGH);
//     digitalWrite(INBM2,LOW);
//     analogWrite(PWM2,Right_motor_speed);
//     }
//    else {
//      if (Right_motor_speed < -255) Right_motor_speed = -1*max_speed;
//     digitalWrite(INAM2,LOW);
//     digitalWrite(INBM2,HIGH);
//     analogWrite(PWM2,Right_motor_speed*-1);
//     }
//   }

//--------------------------Reading the IR sensor array-------------------------
int read_sensor(){
    long sum_of=0;
    long avg = 0;
    long pos = 0;
    for (int i =0; i<=15; i++){
      sensor[i] = analogRead(i);
      if (sensor[i]<100) sensor[i]=1;
      else sensor[i]=0;
      }
    for (int i =0; i<=15; i++){
      avg += sensor[i]*i*100;
      sum_of += sensor[i];
      // Serial.print(sensor[i]); Serial.print(' ');
      }
    if(sum_of == 0) pos = set_point;
    else  pos = avg/sum_of;
    // Serial.print(avg); Serial.print(' ');
    // Serial.print(sum_of); Serial.print(' ')
    // Serial.println(pos); delay(1000);
    return pos; //Output of the read_sensor function.
    }
//----------------------PID_calculation for line following----------------------
float pid_calculation(){
    error = read_sensor()- set_point;
    // Serial.println(error); delay(200);
    proportional = kp*error;
    // Serial.println(proportional); delay(200);
    derivative = kd*(error - last_error);
    last_error = error;
    error_value = proportional + derivative;
    return error_value;
    // Serial.println(error_value); delay(200);
    }
