#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quadra.h"

struct quadra{
    char locatario[50];
    char inicio[50];
    char fim[50];
    int cod_quadra;
    int disponibilidade;
};


Quadra *cria_quadra(){

    Quadra *q = (Quadra *) malloc(sizeof(struct quadra));
    if(q != NULL){
        strcpy(q->locatario, "criado");
        strcpy(q->inicio, "inicio");
        strcpy(q->inicio, "fim");
        q->cod_quadra = 20;
        q->disponibilidade = 1;
    }
    return q;
};

void acessa_quadra(Quadra *q, int *cod_quadra, int *disponibilidade){
    *cod_quadra = q->cod_quadra;
    *disponibilidade = q->disponibilidade;
};


void agendar(Quadra *q, char *locatario, char *inicio, char *fim, int cod_quadra){
    if(q->disponibilidade == 1){
        strcpy(q->locatario, locatario);
        strcpy(q->inicio, inicio);
        strcpy(q->fim, fim);
        q->cod_quadra = cod_quadra;
        q->disponibilidade = 0;
    }
}
