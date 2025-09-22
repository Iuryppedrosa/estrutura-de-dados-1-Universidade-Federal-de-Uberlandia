#include <stdio.h>
#include <stdlib.h>
#include "tad.h"


struct no {
    struct produto Produto;
    struct no * prox;
};

struct fila {
    struct no * no_inicio;
    struct no * no_fim;
};


// operacao para criar uma instancia de fila, que nessa implementacao
// significa criar (alocar) a estrutura fila, que comporta dois valores de endereco
// para o no inicio e para o no fim
FILA cria_fila(){
    FILA f;
    f = (FILA) malloc(sizeof(struct fila));
    if(f != NULL){
        f->no_fim = NULL;
        f->no_inicio = NULL;
    }
    return f;
}

int insere_fim(FILA f, Produto p){
    if(f == NULL)
        return 0;
    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));
    if(N == NULL)
    {
        return 0;
    }
    N->Produto = p;
    N->prox = NULL;

    // se fila vazia, o campo que recebe o endereco do no inicio, recebe o endereco
    // do no alocado
    if(fila_vazia(f) == 1){
       f->no_inicio = N;
    }

    // se nao vazia, o ultimo no, tem que apontar para o novo
    else{
        (f->no_fim)->prox = N;
    }
    // fim sempre vai ser o ultimo inserido
    // mesmo a fila sendo vazia.
    f->no_fim = N;
    return 1;
}

int remove_inicio(FILA f, Produto * devolucao){
    if(f == NULL || fila_vazia(f) == 1){
        return 0;
    }
    struct no * aux = f->no_inicio;
    *devolucao = aux->Produto;


    // verifica se existe apenas um no
    if(f->no_inicio == f->no_fim){
        f->no_fim = NULL;
    }
    // aux-prox pode ser null
    f->no_inicio = aux->prox;
    free(aux);
    return 1;
}

int esvazia_fila(FILA f){
    if(fila_vazia(f) == 1){
        return 0;
    }
    struct no * aux = f->no_inicio;
    struct no * temp = aux;
    while(aux != NULL){
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
    f->no_inicio = NULL;
    f->no_fim = NULL;
    return 1;
}

int apaga_fila(FILA *f){
    if(esvazia_fila(*f) == 1 || fila_vazia(*f) == 1){
        free(*f);
        *f = NULL;
        return 1;
    }
    return 0;
}

int tamanho_fila(FILA f, int * tamanho){
    int tamanho_aux = 1;
    if(f == NULL){
        return 0;
    }
    if(fila_vazia(f) == 1){
        *tamanho = 0;
    }
    *tamanho = 1;
    struct no * aux = f->no_inicio;
    while(aux->prox != NULL){
        tamanho_aux ++;
        aux = aux->prox;
        *tamanho = tamanho_aux;
    }
    return 1;
}

int fila_vazia(FILA f){
    if(f->no_inicio == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}



FILA imprimir_fila(FILA f) {
    if (f == NULL || fila_vazia(f) == 1) {
        return NULL;
    }

    Produto tempProd;
    FILA filaTemp = cria_fila();

    // remove todos os elementos da fila original e joga na fila temporária
    while (remove_inicio(f, &tempProd) == 1) {
        insere_fim(filaTemp, tempProd);
    }

    // devolve os elementos da fila temporária para a fila original
    struct no *aux = filaTemp->no_inicio;
    while (aux != NULL) {
        insere_fim(f, aux->Produto);
        aux = aux->prox;
    }

    return filaTemp; // devolvemos a fila temporária para o main exibir
}
