/*
* This code is based on the Mecha_QMC5883L library
* https://github.com/keepworking/Mecha_QMC5883L
*/
#include <Wire.h> //I2C Arduino Library
#define addr 0x0D //I2C Address for The QMC5883
void setup(){
 Serial.begin(9600);

 Wire.begin();
 Wire.beginTransmission(addr); //start talking
 Wire.write(0x0B); // Set the Register
 Wire.write(0x01); // Tell the QMC5883 to Continuously Measure
 Wire.endTransmission();
}
void loop(){
 //Tell the HMC what regist to begin writing data into
 Wire.beginTransmission(addr);
 Wire.write(0x00); //start with register 0.
 Wire.endTransmission();
//Read the data.. 2 bytes for each axis.. 6 total bytes
 Wire.requestFrom(addr, 6);
 int x = Wire.read(); //LSB x
 x |= Wire.read() << 8; //MSB x
 int y = Wire.read(); //LSB z
 y |= Wire.read() << 8; //MSB z
 int z = Wire.read(); //LSB y
 z |= Wire.read() << 8; //MSB y

 // Estimate heading direction
 // Insert code here
  
 Serial.print("x: ");Serial.print(x);
 Serial.print(" y: ");Serial.print(y);
 Serial.print(" z: ");Serial.print(z);
 Serial.print(" heading: ");Serial.print(heading);
 Serial.println();
 delay(100);
}
