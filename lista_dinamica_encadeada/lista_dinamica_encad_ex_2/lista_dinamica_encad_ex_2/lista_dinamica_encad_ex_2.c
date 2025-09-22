#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica_encad_ex_2.h"

struct no {
    struct termo *termo;
    struct no *prox;
};

Lista cria_lista() {
    Lista cab = (Lista) malloc(sizeof(struct no));
    if (cab == NULL) {
        return NULL;
    }
    cab->prox = NULL;
    cab->termo = NULL;
    return cab;
}

int lista_vazia(Lista cab) {
    if (cab->prox == NULL) {
        return 1;
    }
    return 0;
}

int insere_polinomio_ord(Lista *cab, Termo *termo) {
    Lista novo_no = (Lista) malloc(sizeof(struct no));
    if (novo_no == NULL) {
        return 0;
    }
    novo_no->termo = termo;
    if (lista_vazia(*cab) || (*cab)->prox == NULL || (*cab)->prox->termo->coeficiente >= termo->coeficiente) {
        novo_no->prox = (*cab)->prox;
        (*cab)->prox = novo_no;
        return 1;
    }
    Lista aux = *cab;
    while (aux->prox != NULL && aux->prox->termo->coeficiente < termo->coeficiente) {
        aux = aux->prox;
    }
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
    return 1;
}

int remove_polinomio_ord(Lista *cab, Termo *termo) {
    if (lista_vazia(*cab)) {
        return 0;
    }
    Lista aux = *cab;
    while (aux->prox != NULL && aux->prox->termo->coeficiente < termo->coeficiente) {
        aux = aux->prox;
    }
    if (aux->prox == NULL || aux->prox->termo->coeficiente != termo->coeficiente) {
        return 0;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2->termo);
    free(aux2);
    return 1;
}

int get_elem_pos(Lista cab, int pos, Termo **termo) {
    if (lista_vazia(cab) || pos < 1) {
        return 0;
    }
    Lista aux = cab->prox;
    int count = 1;
    while (aux != NULL && count < pos) {
        aux = aux->prox;
        count++;
    }
    if (aux == NULL) {
        return 0;
    }
    *termo = aux->termo;
    return 1;
}

void esvazia_lista(Lista cab) {
    Lista aux = cab->prox;
    while (aux != NULL) {
        Lista temp = aux;
        aux = aux->prox;
        free(temp->termo);
        free(temp);
    }
    cab->prox = NULL;
}

void apaga_lista(Lista *cab) {
    esvazia_lista(*cab);
    free(*cab);
    *cab = NULL;
}

void imprime_lista(Lista cab) {
    if (lista_vazia(cab)) {
        printf("Lista vazia.\n");
        return;
    }
    Lista aux = cab->prox;
    printf("Polinomio: ");
    while (aux != NULL) {
        printf("%d%c^%d", aux->termo->coeficiente, aux->termo->parte_desconhecida, aux->termo->expoente);
        if (aux->prox != NULL) {
            printf(" + ");
        }
        aux = aux->prox;
    }
    printf("\n");
}
