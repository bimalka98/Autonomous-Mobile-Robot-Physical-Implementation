//++++++++++++++++++++motor+++++++++++++++++++++++++++++
#define PWM1 2   //Motor 1 PWM
#define INAM1 22 //Motor 1
#define INBM1 24 //Motor 1
#define PWM2 3   //Motor 2 PWM
#define INAM2 26 //Motor 2
#define INBM2 28 //Motor 2
const int avrageSpeed = 160;

//++++++++++++++++++++++++++++++++lINE following++++++++
long sum_of =0;
long avg = 0;
long sensor[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
long error = 0;
long last_error = 0;
long set_point = 7500;
long pos = 0;
long proportional = 0;
long derivative = 0;
long error_value = 0;
long kp = 0.01;
long kd = 0.2;


void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(INAM1, OUTPUT);
  pinMode(INBM1, OUTPUT);

  pinMode(PWM2, OUTPUT);
  pinMode(INAM2, OUTPUT);
  pinMode(INBM2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //read_sensor();
  error_value = pid_calculation();
 Serial.println(error_value);
motor_driver(avrageSpeed + error_value, avrageSpeed - error_value);
//  Serial.print(avrageSpeed + error_value);
//  Serial.print(" ");
// Serial.print(avrageSpeed - error_value);
// Serial.println(" " );
 
}

void motor_driver(int Left_motor_speed, int Right_motor_speed){
  if (Left_motor_speed > 0){                              // Check wether left motor speed is posive and map into 0 - 255 to donot exceed max PWM value(255).
    if (Left_motor_speed > 255){
      Left_motor_speed = 255;
      }

    digitalWrite(INAM1,HIGH);              // Set left motor for foward rotation.
    digitalWrite(INBM1,LOW);
    analogWrite(PWM1,Left_motor_speed);       // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    //delay(5000);

    }
  else {                                              // Check wether left motor speed is negative and map into 0 - (-255) to donot exceed max PWM value(255).
      if (Left_motor_speed < -255){
        Left_motor_speed = -255;
        }
        digitalWrite(INAM1,LOW);              // Set left motor for backward rotation.
    digitalWrite(INBM1,HIGH);
    analogWrite(PWM1,Left_motor_speed*(-1));   // Set left motor speed as analod value using PWM. Multiply by -1 to convert speed to positive. Because PWM can only detect positive.
    //delay(5000);
      }

    

// Do the same procedure for right motor as follows.
   if (Right_motor_speed > 0){
    if (Right_motor_speed > 255){
      Right_motor_speed = 255;
      }

    digitalWrite(INAM2,HIGH);
    digitalWrite(INBM2,LOW);
    analogWrite(PWM2,Right_motor_speed);
    //delay(5000);

    }

    else {
      if (Right_motor_speed < -255)
      {
        Right_motor_speed = -255;
      }
    digitalWrite(INAM2,LOW);
    digitalWrite(INBM2,HIGH);
    analogWrite(PWM2,Right_motor_speed*-1);
    //delay(5000);
      }


  }

int read_sensor(){
    long sum_of=0;
    long avg = 0;
    long pos = 0;
    for (int i =0; i<=15; i++){
      sensor[i] = analogRead(i);
      if (sensor[i]<100)
      sensor[i]=1;

      else
      sensor[i]=0;
      }
      for (int i =0; i<=15; i++){

        avg += sensor[i]*i*1000;
        sum_of += sensor[i];

//        Serial.print(sensor[i]);
//        Serial.print(' ');
        }

        pos = avg/sum_of;
//         Serial.print(avg);
//         Serial.print(' ');
//         Serial.print(sum_of);
//         Serial.print(' ');
//         Serial.print(pos);
//        
//        
//         Serial.println(' ');
//         delay(1000);

      return pos;
    }

 int pid_calculation(){
    error = read_sensor()- set_point;
//    Serial.println(error);
//    delay(200);
    proportional = kp*error;
    derivative = kd*(error - last_error);
    last_error = error;
    error_value = int((proportional + derivative)*1000);
    return error_value;
    //Serial.println(error_value);
    //delay(200);
    }
