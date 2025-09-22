#include <stdio.h>
#include <stdlib.h>
#include "quadra.h"
int main()
{
    printf("Hello world!\n");

    Quadra *q;
    int cod_quadra_1;
    int disponibilidade = 5;

    char locatario[50] = "Luciano";
    char inicio[50] = "29/06/2025";
    char fim[50] = "10/07/2025";

    q = cria_quadra();
    acessa_quadra(q, &cod_quadra_1, &disponibilidade);
    printf("Codigo da quadra criada: %d\nDisponibilidade: %d\n", cod_quadra_1, disponibilidade);

    agendar(q, locatario, inicio, fim, cod_quadra_1);
    acessa_quadra(q, &cod_quadra_1, &disponibilidade);
    printf("Codigo da quadra criada: %d\nDisponibilidade: %d", cod_quadra_1, disponibilidade);

    return 0;
}
