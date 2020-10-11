void setup() {
  // put your setup code here, to run once:

}

void loop() {
  driveDistance(89, 12);
  
  }



  
void driveDistance(int millimeters, int power){
  sensorValue[leftEncoder]=0;
  int tickGoal = (35*millimeters)/10;
  while (SensorValue[leftEncoder]<tickGoal){
    motor[leftservo]=power;
    motor[rightServo]=power;
    
    }
    motor[leftServo]=0;
    motor[rightServo]=0;
  }
