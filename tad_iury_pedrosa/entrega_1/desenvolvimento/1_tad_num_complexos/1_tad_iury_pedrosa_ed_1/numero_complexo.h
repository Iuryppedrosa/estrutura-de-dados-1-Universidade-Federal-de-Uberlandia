#ifndef NUMERO_COMPLEXO_H_
#define NUMERO_COMPLEXO_H_


// a struct é do tipo *numero_complexo* e seu nome é NC.
typedef struct numero_complexo NC;
NC *cria();
int set_nro(NC *nc, double parte_real, double parte_imaginaria);
int get_nro(NC *nc, double *parte_real, double *parte_imaginaria);
void apaga(NC **nc);
int soma(NC *nc1, NC *nc2, NC *nc3);
int sub(NC *nc1, NC *nc2, NC *nc3);
int multi(NC *, NC *, NC *);


#endif
