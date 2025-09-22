#ifndef LISTA_H_
#define LISTA_H_
typedef struct lista * Lista;
Lista cria_lista();

int lista_vazia(Lista);
int lista_cheia(Lista);

int insere_elem(Lista, int);
int insere_elem_ord(Lista, int);

int remove_elem(Lista, int);
int remove_elem_ord(Lista, int);

void exibir_lista(Lista, int *);
#endif
