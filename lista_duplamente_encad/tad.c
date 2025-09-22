#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct No {
    int info;
    struct No* prox;
    struct No* ante;
};

Lista inicializarLista(Lista* l) {
    *l = NULL;
    return *l;
}

int estaVazia(Lista l) {
    return l == NULL;
}

Lista inserirOrdenado(Lista* l, int valor) {
    struct No* novo = malloc(sizeof(struct No));
    if (!novo) return *l;

    novo->info = valor;
    novo->prox = NULL;
    novo->ante = NULL;

    if (estaVazia(*l) || valor < (*l)->info) {
        novo->prox = *l;
        if (*l) (*l)->ante = novo;
        *l = novo;
    } else {
        struct No* atual = *l;
        while (atual->prox && atual->prox->info < valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        novo->ante = atual;
        if (atual->prox) atual->prox->ante = novo;
        atual->prox = novo;
    }
    return *l;
}

int removerElemento(Lista* l, int valor) {
    if (estaVazia(*l)) return 0;

    struct No* atual = *l;
    while (atual && atual->info != valor) {
        atual = atual->prox;
    }

    if (!atual) return 0;

    if (atual->ante == NULL) {
        *l = atual->prox;
        if (*l) (*l)->ante = NULL;
    } else {
        atual->ante->prox = atual->prox;
    }

    if (atual->prox) {
        atual->prox->ante = atual->ante;
    }

    free(atual);
    return 1;
}

int destruirLista(Lista* l) {
    if (!l || !*l) return 0;

    while (!estaVazia(*l)) {
        struct No* temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    return 1;
}

void exibirLista(Lista l) {
    struct No* atual = l;
    while (atual) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}
