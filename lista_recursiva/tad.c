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

Lista inserirInicio(Lista* l, int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL) return *l;

    novo->info = valor;
    novo->prox = *l;
    novo->ante = NULL;
    if (*l) (*l)->ante = novo;
    *l = novo;
    return *l;
}

int exibirRecursivo(Lista l) {
    if (l == NULL) {
        printf("\n");
        return 1;
    }
    printf("%d ", l->info);
    return exibirRecursivo(l->prox);
}

int destruirLista(Lista* l) {
    if (l == NULL || *l == NULL) return 0;

    while (!estaVazia(*l)) {
        struct No* temp = *l;
        *l = (*l)->prox;
        free(temp);
    }
    return 1;
}

void exibirLista(Lista l) {
    struct No* atual = l;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}
