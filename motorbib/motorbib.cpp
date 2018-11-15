#include "Arduino.h"
#include "motorbib.h"

void inicializaMotores()
{
  pinMode(MOTORLATCH, OUTPUT);
  pinMode(MOTORCLK, OUTPUT);
  pinMode(MOTORENABLE, OUTPUT);
  pinMode(MOTORDATA, OUTPUT);
  digitalWrite(MOTORENABLE, LOW);
  servo1.write(180);
  bitWrite(motor, 0, 0);  
  bitWrite(motor, 1, 0);
  bitWrite(motor, 2, 0);  
  bitWrite(motor, 3, 0);
  bitWrite(motor, 4, 0);  
  bitWrite(motor, 5, 0);
  bitWrite(motor, 6, 0);  
  bitWrite(motor, 7, 0);
}

void motor1Forward()
{
bitWrite(motor, 4, 1);  
bitWrite(motor, 5, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor1Backward()
{
bitWrite(motor, 4, 0);  
bitWrite(motor, 5, 1);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor1Stop()
{
bitWrite(motor, 4, 0);  
bitWrite(motor, 5, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor4Forward()
{
bitWrite(motor, 3, 0);  
bitWrite(motor, 6, 1);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor4Backward()
{
bitWrite(motor, 3, 1);  
bitWrite(motor, 6, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor4Stop()
{
bitWrite(motor, 3, 0);  
bitWrite(motor, 6, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor3Forward()
{
bitWrite(motor, 0, 0);  
bitWrite(motor, 2, 1);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor3Backward()
{
bitWrite(motor, 0, 1);  
bitWrite(motor, 2, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor3Stop()
{
bitWrite(motor, 0, 0);  
bitWrite(motor, 2, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor2Forward()
{
bitWrite(motor, 1, 1);  
bitWrite(motor, 7, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor2Backward()
{
bitWrite(motor, 1, 0);  
bitWrite(motor, 7, 1);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void motor2Stop()
{
bitWrite(motor, 1, 0);  
bitWrite(motor, 7, 0);

digitalWrite(MOTORLATCH, LOW);
shiftOut(MOTORDATA, MOTORCLK, LSBFIRST, motor);
digitalWrite(MOTORLATCH, HIGH);
}

void inicializaServo()
{
servo1.attach(SERVO1);
servo1.write(180);
}

void servoAbre()
{
servo1.write(180);
}

void servoFecha()
{
servo1.write(90);
}