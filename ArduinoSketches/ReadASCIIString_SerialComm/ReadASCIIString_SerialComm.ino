//-----------------------------------------------------------------------------
// Author               : Bimalka Piyaruwan Thalagala
// GitHub               : https://github.com/bimalka98
// Last Modified        : 25.12.2020
//-----------------------------------------------------------------------------

const int pwm[3] = {3,5,6};

void setup(){
  Serial.begin(9600);
  for(int x: pwm)pinMode(x, OUTPUT);
}
void loop(){
  while(Serial.available()> 0){ // AS LONG AS THERE IS AN INPUT STRING
    int val[3];
    for(int i = 0; i<3; i++) val[i]= Serial.parseInt(); // Get readings from CSV
    for(int i = 0; i<3; i++) val[i] = constrain(val[i], 0, 255);

    if(Serial.read()=='\n'){
      for(int i = 0; i<3; i++) analogWrite(pwm[i],val[i]);
      for(int i = 0; i<3; i++) Serial.print(val[i], HEX);
      Serial.println();
      }
    }
}
