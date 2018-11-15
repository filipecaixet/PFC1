#ifndef motorbib_h
#define motorbib_h

#include "Arduino.h"
#include "Servo.h"

#define MOTORLATCH 45
#define MOTORCLK 39
#define MOTORENABLE 41
#define MOTORDATA 43
#define SERVO1 48

static uint8_t motor = 0;

static Servo servo1; 

void inicializaMotores();

void motor1Forward();

void motor1Backward();

void motor1Stop();

void motor2Forward();

void motor2Backward();

void motor2Stop();

void motor3Forward();

void motor3Backward();

void motor3Stop();

void motor4Forward();

void motor4Backward();

void motor4Stop();

void inicializaServo();

void servoAbre();

void servoFecha();

void esteira1();

#endif