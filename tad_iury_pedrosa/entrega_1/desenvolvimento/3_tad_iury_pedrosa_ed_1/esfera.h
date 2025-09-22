#ifndef ESFERA_H_
#define ESFERA_H_
#include "ponto_tridimensional.h"
typedef struct esfera * Esfera;
typedef struct ponto_tridimensional * PT;

Esfera cria_esfera();
int set_esfera(Esfera, PT, PT);
int get_esfera(Esfera, double*, double*, double*, double*, double*, double*);
void apaga_esfera(Esfera *);
double raio(Esfera);
double area(Esfera);
double volume(Esfera);


#endif
