#ifndef TAD_H
#define TAD_H

typedef struct No* Lista;

Lista inicializarLista(Lista* l);
int estaVazia(Lista l);
Lista inserirInicio(Lista* l, int valor);
int exibirRecursivo(Lista l);
int destruirLista(Lista* l);
void exibirLista(Lista l);

#endif
