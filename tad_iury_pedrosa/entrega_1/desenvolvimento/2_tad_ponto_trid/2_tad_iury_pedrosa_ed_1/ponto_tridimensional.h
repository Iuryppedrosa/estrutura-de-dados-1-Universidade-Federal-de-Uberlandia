#ifndef PONTO_TRIDIMENSIONAL_H
#define PONTO_TRIDIMENSIONAL_H

// a struct é do tipo *ponto trimensional* e seu nome é PT.
typedef struct ponto_tridimensional * PT;
PT cria_pto();
int set_pto(PT, double, double, double);
int get_pto(PT, double *, double *, double *);
void apaga_pto(PT *);
int dist(PT, PT);

#endif // PONTO_TRIDIMENSIONAL_H
