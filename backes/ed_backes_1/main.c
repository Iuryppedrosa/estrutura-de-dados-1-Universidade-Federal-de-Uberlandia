#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main()
{
    float d;
    Ponto *p, *q;

    float coord_x_p, coord_y_p;
    float coord_x_q, coord_y_q;



    p = pto_cria(10, 21);
    q = pto_cria(7, 25);

    pto_acessa(p, &coord_x_p, &coord_y_p);
    printf("Valor de j - x: %f\n", coord_x_p);
    printf("Valor de k - y: %f\n", coord_y_p);

    d = pto_distancia(p, q);
    printf("Distancia entre os pontos: %f\n", d);

    pto_libera(p);
    pto_libera(q);
    printf("Hello world!\n");
    return 0;
}
