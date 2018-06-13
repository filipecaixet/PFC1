#include "Arduino.h"
#include "sensordecor.h"

int vermelho = 0;
int azul = 0;
int verde = 0;

char vm;
char az;
char vd;

const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;

void inicializaSensor()
{ 
 
pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);
pinMode(out, INPUT);
Serial.begin(9600);

digitalWrite(s0, HIGH);
digitalWrite(s1, HIGH);
}

char detectaCor()
{
color();

Serial.println();
Serial.print("Vermelho: ");
Serial.print(vermelho, DEC);
Serial.print(" Verde: ");
Serial.print(verde, DEC);
Serial.print(" Azul: ");
Serial.print(azul, DEC);
Serial.println();

if(vermelho <= azul && vermelho < verde && vermelho <= 25)
  {
  Serial.print("VERMELHO DETECTADO");
  return vm;
  }
else if(azul < vermelho && azul < verde && azul < 25)
  {
  Serial.print("AZUL DETECTADO");
  return az;
  }
else if(verde < vermelho && verde < azul)
  {
  Serial.print("VERDE DETECTADO");
  return vd;
  }

}

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  vermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);

  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);

  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}

