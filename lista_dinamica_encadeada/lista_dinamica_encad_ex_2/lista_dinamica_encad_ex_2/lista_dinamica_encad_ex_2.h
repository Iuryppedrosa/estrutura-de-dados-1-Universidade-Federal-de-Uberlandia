#ifndef LISTA_ENCAD_EX_2
#define LISTA_ENCAD_EX_2

typedef struct termo {
    int coeficiente;
    char parte_desconhecida;
    int expoente;
} Termo;
typedef struct no * Lista;


Lista cria_lista();
int lista_vazia(Lista);
int insere_polinomio_ord(Lista *, Termo *);
int remove_polinomio_ord(Lista *, Termo *);

int get_elem_pos(Lista, int, Termo **);
void apaga_lista(Lista *);
void esvazia_lista(Lista);
void imprime_lista(Lista);


#endif
