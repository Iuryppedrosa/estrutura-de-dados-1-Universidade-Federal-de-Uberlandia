#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica_encadeada_simples.h"

int main()
{
    Lista l = cria_lista();

    char palavra[4] = {'I', 'U', 'R', 'Y'};
    char letra;
    for(int i = 0; i < 4; i++){
        if(insere_elemento(&l, palavra[i]) == 1 && lista_vazia(&l) != 1){
            printf("Elemento %d inserido na lista\n", i);
        }

    }
    printf("-----------------------------\n");

    // fazer outro for para pegar a palavra
    for(int i = 0; i <4; i++){
        if(get_elemento_pela_posicao(&l, i, &letra) == 1){
            printf("%c ", letra);
        }
    }

    if(remove_elemento(&l, palavra[2]) == 1){
        printf("\nElemento removido!");
    }
    if(apaga_lista(&l) == 1){
        printf("\nLista apagada!");
    }




    return 0;
}
