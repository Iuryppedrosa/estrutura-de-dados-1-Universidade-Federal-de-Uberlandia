#ifndef LISTA_SEQ_STRING_H_
#define LISTA_SEQ_STRING_H_

typedef char String[10];
typedef struct lista * Lista;
Lista cria_lista();
int lista_vazia(Lista);
int esvaziar_lista(Lista);
int lista_cheia(Lista);
int insere_elemento(Lista, String);
int remove_elemento(Lista, String);
int imprimir_lista(Lista, String[10]);
int apagar(Lista *);
int pegar_elemento(Lista, String, int);





#endif // LISTA_SEQ_STRING_H_
