#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ponto_tridimensional.h"

struct ponto_tridimensional{
    double eixo_x;
    double eixo_y;
    double eixo_z;
};

PT cria_pto(){
   PT pt = malloc(sizeof(struct ponto_tridimensional));
   if(pt == NULL){
       printf("Nao foi possivel criar o ponto tridimensional");
       return NULL;
   };
   return pt;
};

int set_pto(PT pt, double eixo_x, double eixo_y, double eixo_z){
    if(pt == NULL){
        printf("Endereço da estrutura ponto tridimensional nao encontrado");
        return 0;
    }
    pt->eixo_x = eixo_x;
    pt->eixo_y = eixo_y;
    pt->eixo_z = eixo_z;

    return 1;
}

int get_pto(PT pt, double *eixo_x, double *eixo_y, double *eixo_z){
    if(pt == NULL){
        printf("Endereço da estrutura ponto tridimensional nao encontrado");

        return 0;
    }
    *eixo_x = pt->eixo_x;
    *eixo_y = pt->eixo_y;
    *eixo_z = pt->eixo_z;

    return 1;
}

int dist(PT pt_1, PT pt_2){
    if(pt_1 == NULL || pt_2 == NULL){
        return 0;
    }
    double dx = pt_2->eixo_x - pt_1->eixo_x;
    double dy = pt_2->eixo_y - pt_1->eixo_y;
    double dz = pt_2->eixo_z - pt_1->eixo_z;
    double dx_2 = pow(dx, 2);
    double dy_2 = pow(dy, 2);
    double dz_2 = pow(dz, 2);
    double soma = dx_2 + dy_2 + dz_2;
    double raiz = sqrt(soma);
    return raiz;
}

void apaga_pto(PT *pt){
    free(*pt);
    *pt = NULL;
};
