#ifndef sensordedistancia_h
#define sensordedistancia_h
#define sensor1 27
#define sensor2 25
#define sensor3 23
#define sensor4 31
#define sensor5 29
#define sensor6 34
#define sensor7 44
#define sensor8 33
#define sensor9 35


//#include <map>
//#include <string>

// using namespace std;

//std::map<int, std::string> sensores;
//sensores[23] = "sensor 1";


#include "Arduino.h"

void inicializaInfra(int);

int estado(int);

void imprimeEstado(int);

#endif
