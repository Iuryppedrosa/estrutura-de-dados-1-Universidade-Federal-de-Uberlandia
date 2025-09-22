#include <stdio.h>
#include "tad.h"
#define FIM_PILHA 10

struct pilha {
    struct func funcionarios[10];
    int topo;
};

Pilha cria_pilha(){
    Pilha p = (Pilha) malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = -1;
    return p;
};

int pilha_vazia(Pilha p){
    if(p->topo < 0)
        return 1;
    return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo == FIM_PILHA - 1)
        return 1;
    return 0;
}

int push(Pilha p, Func f){
    if(pilha_cheia(p) == 1)
        return 0;
    p->topo++;
    p->funcionarios[p->topo] = f;
    return 1;
}

int pop(Pilha p, Func *f){
    if(pilha_vazia(p) == 1)
        return 0;
    *f = p->funcionarios[p->topo];
    p->topo--;
    return 1;
}

int get_topo(Pilha p, Func *f){
    if(pilha_vazia(p) == 1)
        return 0;
    *f = p->funcionarios[p->topo];
    return 1;
}

int tamanho_pilha(Pilha p){
    if(pilha_vazia(p) == 1)
        return 0;
    if(pilha_cheia(p) == 1)
        return 10;

    int tamanho = 0;
    int aux = p->topo;
    while(aux != -1){
        tamanho++;
        aux--;
    }
    return tamanho;
}

int esvazia_pilha(Pilha p){
    if(pilha_vazia(p) == 1)
        return 0;

    while(p->topo != -1){
        p->topo--;
    }
    return 1;
}

int apaga_pilha(Pilha *p){
    if(p == NULL){
        return 0;
    }
    free(*p);
    *p = NULL;
    return 1;
}
