#include "Arduino.h"
#include "funcionamentoParalelo.h"

/*
volatile int cor = 5;
volatile int tam; 
*/
void inicializacao()
{
inicializaInfra(sensor1);
inicializaInfra(sensor2);
inicializaInfra(sensor3);
inicializaInfra(sensor4);
inicializaInfra(sensor5);
inicializaInfra(sensor6);
inicializaInfra(sensor7);
inicializaInfra(sensor8);
inicializaSensor();
inicializaMotores();
inicializaServo();
motor1Stop();
motor2Stop();
motor3Stop();
}
/*
// liga esteira 1
void esteira1()
{ 
  motor1Forward(); 
}

// guarda a cor que foi detectada

void guardaCor()
{
	if (detectaCor() == 0)
  		{
    	cor = vermelho;
  		}
	// objeto é azul
	if (detectaCor() == 1)
  		{
    	cor = azul;
  		}
}

// liga a esteira 2
void esteira2()
{
	// objeto grande e azul indo da esteira 1 para esteira 2
	if (estado(sensor5) == 1 && cor == azul)
  		{
  		tam = grande; // guarda que o objeto detectado é grande
    	//delayMicroseconds(2000000);
    	motor1Stop();
    	motor2Backward();
  		}
	// demais objetos indo da esteira 1 para esteira 2  
	if ((estado(sensor5) == 0 && cor == azul) || (estado(sensor5) == 0 && cor == vermelho))
  		{
  		tam = pequeno; // guarda que o objeto detectado é pequeno
    	//delayMicroseconds(2000000);
    	motor1Stop();
    	motor2Forward();
  		}
  if (estado(sensor5) == 1 && cor == vermelho)
  		{
  		tam = grande; // guarda que o objeto detectado é grande
    	//delayMicroseconds(2000000);
    	motor1Stop();
    	motor2Forward();
  		}
}
// liga a esteira 3
void esteira3()
{
// objeto grande e vermelho  
if (tam == grande && cor == vermelho)
  {
    servoFecha();
    //delayMicroseconds(1500000);
    motor2Stop();
    motor3Forward();
  }
//objeto pequeno e azul  
if (tam == pequeno && cor == azul)
  {
    servoAbre();
    //delayMicroseconds(1000000);
    motor2Stop();
    motor3Backward();
  }
//objeto pequeno e vermelho
if (tam == pequeno && cor == vermelho)
  {
    servoAbre();
    //delayMicroseconds(1000000);
    motor2Stop();
    motor3Forward();
  }
}

void desligaEsteira3Frente()
{
    //delayMicroseconds(1000000);
    servoAbre();
    motor3Stop();
}

void desligaEsteira3Tras()
{
	  //delayMicroseconds(1000000);
    motor3Stop();
}

void desligaEsteira2Tras()
{
    //delayMicroseconds(1500000);
    motor2Stop();
}
*/