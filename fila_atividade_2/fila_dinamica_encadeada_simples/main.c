#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"
int main()
{

    Produto devolucao;
    int tamanho_da_fila;

    Produto p;
    p.codigo = 123;
    strcpy(p.descricao, "Yogurt");
    p.valor = 12,99;

    Produto p2;
    p2.codigo = 456;
    strcpy(p2.descricao, "Morango");
    p2.valor = 5,99;

    Produto p3;
    p3.codigo = 789;
    strcpy(p3.descricao, "Banana");
    p3.valor = 2,99;

    FILA f1 = cria_fila();
    //teste insere
    if(insere_fim(f1, p) == 1){
        printf("Produto inserido na fila!\n");
    }
    //teste fila vazia
    if(fila_vazia(f1) == 1){
        printf("Fila vazia!");
    }else{
        printf("Fila com elementos");
    }

    // teste remove
    if(remove_inicio(f1, &devolucao) == 1){
        printf("Produto removido:\nCodigo: %d\nNome: %s\nValor:%.2f\n", devolucao.codigo, devolucao.descricao, devolucao.valor);
    }

    if(fila_vazia(f1) == 1){
        printf("Fila vazia!");
    }else{
        printf("Fila com elementos");
    }

    if(insere_fim(f1, p) == 1){
        printf("Produto inserido na fila!\n");
    }
    if(insere_fim(f1, p2) == 1){
        printf("Produto inserido na fila!\n");
    }
    if(insere_fim(f1, p3) == 1){
        printf("Produto inserido na fila!\n");
    }

    printf("\n--- Imprimindo a fila ---\n");
    FILA fila_temp = imprimir_fila(f1);

    if (fila_temp != NULL) {
        Produto paux;
        while (remove_inicio(fila_temp, &paux) == 1) {
            printf("Codigo: %d | Nome: %s | Valor: %.2f\n",
                   paux.codigo, paux.descricao, paux.valor);
        }
    }

    if(tamanho_fila(f1, &tamanho_da_fila) == 1){
       printf("Tamanho atual da fila: %d elementos\n", tamanho_da_fila);
    }
    if(esvazia_fila(f1) == 1 && fila_vazia(f1) == 1){
        printf("Fila vazia!\n");
    }
    if(apaga_fila(&f1) == 1){
        printf("Fila Apagada\n");
    }
}
