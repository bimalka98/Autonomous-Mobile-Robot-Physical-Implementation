
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2700 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

void setup() {
  pwm.begin();
  // In theory the internal oscillator is 25MHz but it really isn't
  // that precise. You can 'calibrate' by tweaking this number till
  // you get the frequency you're expecting!
  pwm.setOscillatorFrequency(12000000);  // The int.osc. is closer to 27MHz
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}
void loop() {

  for (uint16_t microsec = 400; microsec < 1200; microsec++) {
    pwm.writeMicroseconds(6, microsec);
  }
  for (uint16_t microsec = 1200; microsec > 400; microsec--) {
    pwm.writeMicroseconds(6, microsec);
  }
  delay(1000);
  for (uint16_t microsec = 3000; microsec > 3800; microsec++) {
    pwm.writeMicroseconds(0, microsec);
  }
    for (uint16_t microsec = 400; microsec < 2800; microsec++) {
    pwm.writeMicroseconds(11, microsec);
  }
  delay(1000);
  for (uint16_t microsec = 2800; microsec > 400; microsec--) {
    pwm.writeMicroseconds(11, microsec);
  }
  delay(1000);
}
