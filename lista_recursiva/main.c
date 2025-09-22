#include <stdio.h>
#include "tad.h"

int main() {
    Lista lista;
    lista = inicializarLista(&lista);

    lista = inserirInicio(&lista, 8);
    if (lista) printf("Inseriu 8\n");
    lista = inserirInicio(&lista, 2);
    if (lista) printf("Inseriu 2\n");
    lista = inserirInicio(&lista, 5);
    if (lista) printf("Inseriu 5\n");

    exibirLista(lista);

    if (exibirRecursivo(lista)) printf("Exibi��o recursiva conclu�da\n");

    if (destruirLista(&lista)) printf("Lista destru�da\n");

    return 0;
}
