#ifndef LISTA_BEBIDAS_H_
#define LISTA_BEBIDAS_H_

typedef struct {
    char nome[20];
    int volume;
    float preco;
} Bebida;

typedef struct lista * Lista;
typedef Bebida bebida[15];

Lista cria_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_ord(Lista, Bebida);
int remove_ord(Lista, char nome[]);
int get_elem_pos(Lista, int pos, Bebida* b);
int esvazia_lista(Lista);
int apaga_lista(Lista*);
void imprime_lista(Lista);
#endif // LISTA_BEBIDAS_H_
