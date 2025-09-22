#ifndef LISTA_DINAMICA_ENCADEADA_SIMPLES_H_

typedef struct lista * Lista;
Lista cria_lista();
int lista_vazia(Lista *);
int apaga_lista(Lista *);
int insere_elemento(Lista *, char elemento);
int remove_elemento(Lista *, char elemento);

int get_elemento_pela_posicao(Lista *, int posicao, char *);


#define LISTA_DINAMICA_ENCADEADA_SIMPLES_H_
#endif // LISTA_DINAMICA_ENCADEADA_SIMPLES_H_
