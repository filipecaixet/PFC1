#include "Arduino.h"
#include "sensordedistancia.h"

void inicializaInfra()
{
  pinMode( 7, INPUT);
  Serial.begin(9600);
}

void imprimeEstado()
{
  if (( ( digitalRead(7) ) == ( HIGH ) ))
  {
    Serial.print("DESATIVADO");
    Serial.println();
  }
  else
  {
    Serial.print("ATIVADO");
    Serial.println();
  }
}