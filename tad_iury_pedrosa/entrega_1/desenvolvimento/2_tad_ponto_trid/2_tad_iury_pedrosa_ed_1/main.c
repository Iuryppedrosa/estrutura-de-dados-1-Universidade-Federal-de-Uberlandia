#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\iuryp\OneDrive\Desktop\Pessoal\UFU\Estudos\semestre_2\ed_1\TAD-IuryPedrosa\entrega_1\desenvolvimento\2_3_tads_ponto_trid_&_esfera\2_tad_iury_pedrosa_ed_1\ponto_tridimensional.h"

int main()
{
    printf("Hello world!\n");
    int result;
    int result_2;

    int distancia;
    PT pt;
    PT pt_2;

    pt = cria_pto();
    pt_2 = cria_pto();


    double eixo_x = 6, eixo_y = 4, eixo_z = 8;
    double eixo_x_2 = 4, eixo_y_2 = 8, eixo_z_2 = 7;


    result = set_pto(pt ,eixo_x, eixo_y, eixo_z);
    result_2 = set_pto(pt_2 ,eixo_x_2, eixo_y_2, eixo_z_2);

    if(result == 1){
        if(get_pto(pt, &eixo_x, &eixo_y, &eixo_z) == 1){
            printf("eixo_x: %.2f\n", eixo_x);
            printf("eixo_x: %.2f\n", eixo_y);
            printf("eixo_x: %.2f\n\n\n", eixo_z);
        }
    }

    if(result_2 == 1){
        if(get_pto(pt_2, &eixo_x_2, &eixo_y_2, &eixo_z_2) == 1){
            printf("eixo_x: %.2f\n", eixo_x_2);
            printf("eixo_x: %.2f\n", eixo_y_2);
            printf("eixo_x: %.2f\n", eixo_z_2);
        }
    }

    distancia = dist(pt, pt_2);
    if(distancia != 0){
        printf("Resultado da distancia: %d\n", distancia);
    }else{
        printf("Nao foi possivel calcular a distancia\n");
    };

    apaga_pto(&pt);
    apaga_pto(&pt_2);
    return 0;
}
