#include <stdio.h>
#include <string.h>
#include "tad.h"

struct no {
    char string[20];
    struct no * prox;
};

Pilha cria_pilha(){
    return NULL;
}
int pilha_vazia(Pilha p){
    if(p == NULL){
        return 1;
    }
    return 0;
}

/*
int push(Pilha *p, char string[]){
    Pilha no = (Pilha) malloc(sizeof(struct no));
    if(no == NULL){
        return 0;
    }
    strcpy(no->string, string);
    no->prox = *p;
    *p = no;
    return 1;
}
*/
int push(Pilha *p, char *string){
    Pilha no = (Pilha) malloc(sizeof(struct no));
    if(no == NULL){
        return 0;
    }
    strcpy(no->string, string);
    no->prox = *p;
    *p = no;
    return 1;
}

int pop(Pilha *p, char * string_devolutiva){
    if(pilha_vazia(*p) == 1 || *p == NULL){
        return 0;
    }
    Pilha aux = *p;
    strcpy(string_devolutiva, aux->string);
    *p = aux->prox;
    free(aux);
    return 1;
}

int get_topo(Pilha p, char * string_devolutiva){
    if(pilha_vazia(p) == 1 || p == NULL){
        return 0;
    }
    strcpy(string_devolutiva, p->string);
    return 1;
}

int apaga_pilha(Pilha *p){
    if(*p == NULL)
    {
        return 0;
    }
    Pilha aux = *p;
    Pilha temp;
    while(aux != NULL){
        temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(*p);
    *p = NULL;
    return 1;
}

int tamanho_pilha(Pilha p){
    int tamanho = 1;
    if(pilha_vazia(p) == 1){
        return 0;
    }
    Pilha aux = p;
    while(aux->prox != NULL){
        aux = aux->prox;
        tamanho++;
    }
    return tamanho;
}
