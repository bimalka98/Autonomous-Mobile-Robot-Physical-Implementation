// Date: June 2, 2020
// Author: Bimalka Piyaruwan Thalagala

//L298N motor driver is used for controlling the motors.

//-----------------------------------------------------------------------------
//EN1 and EN2 pins are used to send PWM signals to the driver.
//To do that digital pins capble of sending PWM signals must be chosen.
//Here pin D9 and pin D3 are used in Arduino Uno.

int EN1 = 9;
int EN2 = 3;

//For other logical inputs for motors any other digital pin can be used.
//Here  D8,D7,D5 and D4 are used.

int IN1 = 8;
int IN2 = 7;
int IN3 = 5;
int IN4 = 4;

//-----------------------------------------------------------------------------
// Set all the pins defined above to be output pins.

void setup() {

  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

//-----------------------------------------------------------------------------
//Define void loop where all the functions are executed.
void loop() {
  /*
  Any function given below can be executed by putting Here
  with necessary arguments.
  As an example  try putting
  Mot1ForwardFix(200); argument must be in the range 0-255
   */
}

//-----------------------------------------------------------------------------

//Definig necessary functions.




//-----------------------------------------------------------------------------
//To drive the motors with fixed speed.

void Mot1ForwardFix(int speed) {
  //To rotate motor 1 in forward direction
  //We need to first configure the logic input at IN1 and IN2
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Direction can be simply changed by swapping the STATE.{HIGH <--> LOW}
  // To enable the motor necessary voltage must be supplied to the enable pin.
  //Second argument is a value between 0-255 which defines the pulse width of PWM signal.
  analogWrite(EN1, speed);
}

void Mot2ForwardFix(int speed) {
  //To rotate motor 2 in forward direction
  //We need to first configure the logic input at IN3 and IN4
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //Direction can be simply changed by swapping the STATE.{HIGH <--> LOW}
  // To enable the motor necessary voltage must be supplied to the enable pin.
  //Second argument is a value between 0-255 which defines the pulse width of PWM signal.
  analogWrite(EN2, speed);
}


//-----------------------------------------------------------------------------
//To drive the motors with increasing speed.
void accelerate() {
  //To accelerate the speed from zero to maximum we can vary the pulse width
  //from min to maximum.
  // A for loop can be used for this purpose.
  //Fist give necessary logical inputs to the IN pins to configure the direction.
  // Say we need to rotate forward.

  //motor1 configuration
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //motor2 configuration
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  //speed is controlled by input to the enable pin pulse width.
  //
  for (int i = 0; i < 256; i++) {
    analogWrite(EN1, i);
    analogWrite(EN2, i);
  }
  //To decelrate the same function can be used with reversed iteration.

  /*
  for (int i = 255; i >= 0; i--) {
    analogWrite(EN1, i)
    analogWrite(EN2, i)
  }
  */
}
//-----------------------------------------------------------------------------
//To control with a joystic
