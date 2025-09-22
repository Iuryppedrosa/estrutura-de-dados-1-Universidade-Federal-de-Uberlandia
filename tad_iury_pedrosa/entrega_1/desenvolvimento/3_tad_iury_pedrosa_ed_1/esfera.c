#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ponto_tridimensional.h"
#include "esfera.h"


struct esfera{
    PT centro;
    PT superficie;
};

Esfera cria_esfera(){
    Esfera es = malloc(sizeof(struct esfera));
    if(es == NULL){
        return NULL;
    }
    return es;
};

int set_esfera(Esfera es, PT pt_1, PT pt_2){
    if(es == NULL || pt_1 == NULL || pt_2 == NULL){
        return 0;
    }

    es->centro = pt_1;
    es->superficie = pt_2;
    return 1;
}

int get_esfera(Esfera es, double *pt_1_eixo_x, double *pt_1_eixo_y, double *pt_1_eixo_z, double *pt_2_eixo_x, double *pt_2_eixo_y, double *pt_2_eixo_z){
    if(es == NULL){
        return 0;
    }
    if(get_pto(es->centro, pt_1_eixo_x, pt_1_eixo_y, pt_1_eixo_z) == 0 || get_pto(es->superficie, pt_2_eixo_x, pt_2_eixo_y, pt_2_eixo_z) == 0){
        return 0;
    }
    return 1;
}

double raio(Esfera es){
    if(es == NULL){
        return 0;
    }
    double raio;
    raio = (double) dist(es->centro, es->superficie);
    return raio;
}

double area(Esfera es){
    if(es == NULL){
        return 0;
    }
    double area = 4 * 3.14 * pow(raio(es), 2);
    return area;
}

double volume(Esfera es){
    if(es == NULL){
        return 0;
    }
    double volume = 4 * 3.14 * pow(raio(es), 3) / 3;
    return volume;
}

void apaga_esfera(Esfera *es){
    free(*es);
    *es = NULL;
}
