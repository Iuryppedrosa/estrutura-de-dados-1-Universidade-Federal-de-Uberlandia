#ifndef QUADRA_H_
#define QUADRA_H_

typedef struct quadra Quadra;


Quadra *cria_quadra();
void agendar(Quadra *q, char *locatario, char *inicio, char *fim,  int cod_quadra);


#endif
