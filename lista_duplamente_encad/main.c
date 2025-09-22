#include <stdio.h>
#include "tad.h"

int main() {
    Lista lista;
    lista = inicializarLista(&lista);

    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 8);

    if (removerElemento(&lista, 2)) printf("Removeu 2\n");

    exibirLista(lista);

    if (destruirLista(&lista)) printf("Lista destruída\n");

    return 0;
}
