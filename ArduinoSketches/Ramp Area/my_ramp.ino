//Author:Ravindu Nagasinghe
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  forward();//go in dotted line
if T_junction(){ //detect t junction
// turn acording to value taken from circle area
if (value%2 ==0){ 
turn_left();
foward();
int side =1;
}
else{
turn_left();
foward();
int side = 2;
}
driveDistance(int millimeters, int power);//give a distance to go to bottom of the ramp using encoders
analogWrite (PWM1,50);//reduce motor speed 
int pillar_count=0;
int flag_till _pillar_is_present= 0;// when pillar is present this becomes 1 and when pillar is not present this becomes zero
while (sensor_Read != (110000000000 ||00000000011) ){// this is for detecting if a junction is present
//enter function to turn on ultrasonic function here
if (distance==15){
  int pillar_count=pillar_count+1;
  flag=1;
  }
else{
  flag=0;
  }
}
}

//after pillar detection
if (int side ==2){
if (pillar_count==value){
  turn_right();
  foward();
  }
else{
  turn_left();
  turn_left();
  }
}
else{
  if (pillar_count==value){
  turn_left();
  foward();
  }
else{
  turn_right();
  turn_right();
  
  }
bool pole= true;

}
