#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica_encadeada_simples.h"


struct lista{
    char caractere;
    struct lista * prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista *l){
    if(l == NULL){
        return 1; // lista vazia
    }
    return 0;
}

int apaga_lista(Lista *lista){
    if(lista == NULL){
        return 0;
    }

    while(*lista != NULL){
        Lista aux = *lista;
        *lista = aux->prox;
        free(aux);
    }
    *lista = NULL;
    free(lista);
    return 1;
}

int insere_elemento(Lista *lista, char elemento){
    Lista novo_no = (Lista) malloc(sizeof(struct lista));
    if(novo_no == NULL) return 0;
    novo_no->caractere = elemento;
    novo_no->prox = *lista; //valor do que tem na lista, que no caso, é um endereco de memoria, no caso era NULL

    *lista = novo_no;
    return 1;
}

int remove_elemento(Lista *lista, char elemento){
    if(lista_vazia(lista) == 1 || lista == NULL){
        return 0;
    }
    Lista aux = *lista; // esse cara AUX recebe o valor que está em lista, no caso, endereco do primeiro no
    if((*lista)->caractere == elemento){ //desreferencia lista, que guarda o end do primeiro no, e acessa o valor do campo info
        *lista = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox->caractere != elemento && aux->prox != NULL){ // começa a avaliar o segundo no para frente
        aux = aux->prox;
    }
    if(aux->prox == NULL){
        return 0;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int get_elemento_pela_posicao(Lista *lista, int posicao, char *elemento){
    Lista aux = *lista;
    if(lista_vazia(lista) == 1 || lista == NULL){
        return 0;
    }

    if(posicao == 0){
        *elemento = (*lista)->caractere;
        return 1;
    }
    int contagem = 0;
    while(contagem < posicao){
        aux = aux->prox;
        contagem++;
    }
    *elemento = aux->caractere;
    return 1;
}
