// Author : Avishka Sandeepa
// Create : 15.06.2020


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
long kp = 0;
long kd = 0;


void setup(){
  
  Serial.begin(9600);
  
  }

void loop(){
  read_sensor();
  pid_calculation();


    }


    
void read_sensor(){
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
      
//      Serial.print(sensor[i]);
//      Serial.print(' ');
      }

      pos = avg/sum_of;
      Serial.print(avg);
      Serial.print(' ');
      Serial.print(sum_of);
      Serial.print(' ');
      Serial.print(pos);
      

      Serial.println(' ');
      delay(1000);
  
  }

void pid_calculation(){
  error = pos - set_point;
  proportional = kp*error;
  derivative = kd*(error - last_error);
  last_error = error;

  error_value = int(proportional + derivative);
  
  }
    
    
