#include "lista_seq_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
    String nomes_pessoas[10];
    int fim;
};


Lista cria_lista(){
    Lista l = (Lista) malloc(sizeof(struct lista));
    if(l == NULL)
        return NULL;
    l->fim = 0;
    return l;
};

int lista_vazia(Lista l){
    if(l->fim != 0){
        return 0;
    }
    return 1;
};

int lista_cheia(Lista l){
    if(l->fim != 10){
        return 0;
    }
    return 1;
}

int insere_elemento(Lista l, String nome){
    if(l == NULL && lista_cheia(l) != 1){
        return 0;
    }
    strcpy(l->nomes_pessoas[l->fim], nome);
    l->fim++;
    return 1;
};

int remove_elemento(Lista l, String nome){
    if(l == NULL && lista_vazia(l) == 1){
        return 0;
    }
    int aux = 0;
    int i = 0;
    while(strcmp(l->nomes_pessoas[aux], nome) != 0 && aux < l->fim){
        aux++;
        if(aux == l->fim){
            return 0;
        }
    }
    for(i = aux + 1; i < l->fim; i++){
        strcpy(l->nomes_pessoas[i - 1], l->nomes_pessoas[i]);
    }
    l->fim--;
    return 1;
}

int imprimir_lista(Lista l, String lista[10]){
    if(lista_vazia(l) != 1 || lista[0] == NULL){
        return 0;
    }
    for(int i = 0; i < l->fim; i++){
        strcpy(lista[i], l->nomes_pessoas[i]);
    }
    return l->fim;
}

int pegar_elemento(Lista l, String lista, int elemento){
    if(lista_vazia(l) != 1 || lista[0] == NULL){
        return 0;
    }
    strcpy(lista, l->nomes_pessoas[elemento]);
    return 1;
}

int apagar(Lista *l){
    free(*l);
    *l = NULL;
}

int esvaziar_lista(Lista l){
    l->fim = 0;
}

