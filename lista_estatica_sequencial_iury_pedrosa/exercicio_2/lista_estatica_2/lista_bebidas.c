#include "lista_bebidas.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct lista{
    bebida itens;
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
    if(l->fim != 15){
        return 0;
    }
    return 1;
}

int insere_ord(Lista l, Bebida nova) {
    if (l == NULL || lista_cheia(l))
        return 0;

    int i = l->fim - 1;
    while (i >= 0 && strcmp(nova.nome, l->itens[i].nome) < 0) {
        l->itens[i + 1] = l->itens[i];
        i--;
    }
    l->itens[i + 1] = nova;
    l->fim++;
    return 1;
}

int remove_ord(Lista l, char nome[]) {
    if (l == NULL || lista_vazia(l))
        return 0;

    int i = 0;
    while (i < l->fim && strcmp(l->itens[i].nome, nome) < 0)
        i++;

    if (i == l->fim || strcmp(l->itens[i].nome, nome) != 0)
        return 0;

    for (int j = i; j < l->fim - 1; j++)
        l->itens[j] = l->itens[j + 1];

    l->fim--;
    return 1;
}

int get_elem_pos(Lista l, int pos, Bebida* b) {
    if (l == NULL || pos < 0 || pos >= l->fim)
        return 0;
    *b = l->itens[pos];
    return 1;
}

int esvazia_lista(Lista l) {
    if (l == NULL)
        return 0;
    l->fim = 0;
    return 1;
}

int apaga_lista(Lista* l) {
    if (l != NULL && *l != NULL) {
        free(*l);
        *l = NULL;
        return 1;
    }
    return 0;
}

void imprime_lista(Lista l) {
    if (l == NULL || lista_vazia(l)) {
        printf("Lista vazia ou inexistente.\n");
        return;
    }

    printf("\n--- Lista de Bebidas ---\n");
    for (int i = 0; i < l->fim; i++) {
        printf("%d. Nome: %s | Volume: %dml | Preço: R$%.2f\n",
               i + 1, l->itens[i].nome, l->itens[i].volume, l->itens[i].preco);
    }
    printf("-------------------------\n");
}

