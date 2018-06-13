#include "Arduino.h"
#include "sensordedistancia.h"

void inicializaInfra()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
}

int imprimeEstado()
{
  if (( ( digitalRead(2) ) == ( HIGH ) ))
  {
    Serial.print("DESATIVADO");
    Serial.println();
    return 0;
  }
  else
  {
    Serial.print("ATIVADO");
    Serial.println();
    return 1;
  }
}