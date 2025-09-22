#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"
#include "ponto_tridimensional.h"

int main()
{
    printf("Hello world!\n");
    int distancia;
    int result;
    int result_2;

    PT pt;
    PT pt_2;

    pt = cria_pto();
    pt_2 = cria_pto();

    double eixo_x = 6, eixo_y = 4, eixo_z = 8;
    double eixo_x_2 = 4, eixo_y_2 = 8, eixo_z_2 = 7;

    result = set_pto(pt ,eixo_x, eixo_y, eixo_z);
    result_2 = set_pto(pt_2 ,eixo_x_2, eixo_y_2, eixo_z_2);


    distancia = dist(pt, pt_2);
    double pt_1_eixo_x, pt_1_eixo_y, pt_1_eixo_z, pt_2_eixo_x, pt_2_eixo_y, pt_2_eixo_z;

    double raio_esfera;
    double area_esfera;
    double volume_esfera;
    Esfera es;
    es = cria_esfera();
    if(set_esfera(es, pt, pt_2) == 1){
        printf("Valores setados!\n");
        if(get_esfera(es, &pt_1_eixo_x, &pt_1_eixo_y, &pt_1_eixo_z, &pt_2_eixo_x, &pt_2_eixo_y, &pt_2_eixo_z) == 0){
            printf("Erro ao pegar esfera");
        }
        printf("Coordenadas do centro da esfera(pt1): x:%.2f y: %.2f z: %.2f\n",
               pt_1_eixo_x, pt_1_eixo_y, pt_1_eixo_z);
        printf("Coordenadas da superficie da esfera(pt2): x:%.2f y: %.2f z: %.2f\n",
               pt_2_eixo_x, pt_2_eixo_y, pt_2_eixo_z);
    }
    raio_esfera = raio(es);
    printf("Valor do raio da esfera: %.2f \n", raio_esfera);
    area_esfera = area(es);
    printf("Valor da area da esfera: %.2f \n", area_esfera);
    volume_esfera = volume(es);
    printf("Valor do volume da esfera: %.2f \n", volume_esfera);


    apaga_pto(&pt);
    apaga_esfera(&es);
    return 0;
}
