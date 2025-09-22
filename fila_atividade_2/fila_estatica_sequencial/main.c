#include <stdio.h>
#include <stdlib.h>
#include "tad.h"


void filaExiste(FILA f){
    if(f == NULL){
        printf("Fila nao existe\n");
    }else{
        printf("Fila existe\n");
    }
}


void estaVazia(FILA f){
    if(fila_vazia(f) == 1){
        printf("Esta vazia!\n");
    }else{
        printf("Nao esta vazia\n");
    }
}

void estaCheia(FILA f){
    if(fila_cheia(f) == 1){
        printf("Esta cheia!\n");
    }else{
        printf("Nao esta cheia\n");
    }
}


int main()
{
    char nome[30] = "Iury Alves";
    char nome2[30] = "Giovanna Camilo";
    char nome3[30] = "Marli Castro";
    char removido[30] = "";

    FILA f1 = cria_fila();
    FILA f_mostrar = cria_fila();
    if(insere_final(f1, nome) == 1){
        printf("Elemento inserido\n");
    }
    estaVazia(f1);
    if(insere_final(f1, nome2) == 1){
        printf("Elemento inserido\n");
    }

    if(insere_final(f1, nome3) == 1){
        printf("Elemento inserido\n");
    }
    estaCheia(f1);


    while(fila_vazia(f1) != 1){
        if(remove_inicio(f1, removido) == 1){
            if(insere_final(f_mostrar, removido) == 1){
                printf("Elemento: %s\n", removido);
            }
        }
    }

    if(remove_inicio(f1, removido) == 1){
        printf("Elemento %s removido!\n", removido);
    }
    if(esvazia_fila(f1) == 1){
        estaVazia(f1);
    }
    if(apaga_fila(&f1) == 1){
        filaExiste(f1);
    }

    return 0;
}
