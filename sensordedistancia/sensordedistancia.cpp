#include "Arduino.h"
#include "sensordedistancia.h"

void inicializaInfra(int pin)
{
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

int estado(int pin)
{
  if (( ( digitalRead(pin) ) == ( HIGH ) ))
  {
    return 0;
  }
  else
  {
    //Serial.print(sensores[pin] );
    return 1;
  }
}

void imprimeEstado(int pin)
{

  if (( ( digitalRead(pin) ) == ( HIGH ) ))
  {
    Serial.print(pin);
    Serial.print(" DESATIVADO");
    Serial.println();
  }
  else
  {
    //Serial.print(sensores[pin] );
    Serial.print(pin);
    Serial.print(" ATIVADO");
    Serial.println();
  }
} 
