#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "numero_complexo.h"

struct numero_complexo{
    double parte_real;
    double parte_imaginaria;
};


NC *cria(){
    NC *nc = (NC *) malloc(sizeof(struct numero_complexo));
    if(nc == NULL){
        printf("Nao foi possivel criar o numero complexo");
        return NULL;
    };
    return nc;
}

int set_nro(NC *nc, double parte_real, double parte_imaginaria){
    if(nc != NULL){
        nc->parte_real = parte_real;
        nc->parte_imaginaria = parte_imaginaria;
    }else{
        return 0;
    };
    return 1;
}

int get_nro(NC *nc, double *parte_real, double *parte_imaginaria){
    if(nc != NULL){
        *parte_real = nc->parte_real;
        *parte_imaginaria = nc->parte_imaginaria;
    }else{
        return 0;
    };
    return 1;
}

void apaga(NC **nc){
    free(*nc);
    *nc = NULL;
}

int soma(NC *nc_1, NC *nc_2, NC *nc_sum){
    if(nc_1 != NULL && nc_2 != NULL && nc_sum != NULL){
        nc_sum->parte_real = nc_1->parte_real + nc_2->parte_real;
        nc_sum->parte_imaginaria = nc_1->parte_imaginaria + nc_2->parte_imaginaria;
    }else{
        return 0;
    }
    return 1;
}

int sub(NC *nc_1, NC *nc_2, NC *nc_sum){
    if(nc_1 != NULL && nc_2 != NULL && nc_sum != NULL){
        nc_sum->parte_real = nc_1->parte_real - nc_2->parte_real;
        nc_sum->parte_imaginaria = nc_1->parte_imaginaria - nc_2->parte_imaginaria;
    }else{
        return 0;
    }
    return 1;
}

int multi(NC *nc_1, NC *nc_2, NC *nc_sum){
    if(nc_1 != NULL && nc_2 != NULL && nc_sum != NULL){
        nc_sum->parte_real = (nc_1->parte_real * nc_2->parte_real) - (nc_1->parte_imaginaria * nc_2->parte_imaginaria);
        nc_sum->parte_imaginaria = (nc_1->parte_real * nc_2->parte_imaginaria) + (nc_1->parte_imaginaria * nc_2->parte_real);
    }else{
        return 0;
    }
    return 1;
}
