#ifndef TAD_H
#define TAD_H

typedef struct No* Lista;

Lista inicializarLista(Lista* l);
int estaVazia(Lista l);
Lista inserirOrdenado(Lista* l, int valor);
int removerElemento(Lista* l, int valor);
int destruirLista(Lista* l);
void exibirLista(Lista l);

#endif
