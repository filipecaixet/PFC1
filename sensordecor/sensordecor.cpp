#include "Arduino.h"
#include "sensordecor.h"

int vermelho = 0;
int azul = 0;
int verde = 0;

const int s0 = 50;
const int s1 = 53;
const int s2 = 51;
const int s3 = 49;
const int out = 47;

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

int detectaCor()
{
color();

if((vermelho < azul) && (vermelho < verde) && (vermelho <= 25))
  {
  return 10; //vermelho
  }
else if(azul < vermelho && azul < verde && azul <= 22)
  {
  return 20; //azul
  }
else if(verde < vermelho && verde < azul)
  {
  return 30; //verde
  }

}

void imprimeCor()
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

if(vermelho < azul && vermelho < verde && vermelho <= 25)
  {
  Serial.print("VERMELHO DETECTADO");
  }
else if(azul < vermelho && azul < verde && azul <= 22)
  {
  Serial.print("AZUL DETECTADO");
  }
else if(verde < vermelho && verde < azul && verde <= 22)
  {
  Serial.print("VERDE DETECTADO");
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
