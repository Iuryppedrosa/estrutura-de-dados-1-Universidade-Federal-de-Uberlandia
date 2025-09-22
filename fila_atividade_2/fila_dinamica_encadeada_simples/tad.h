#ifndef TAD_H_
#define TAD_H_

typedef struct produto {
    int codigo;
    char descricao[10];
    float valor;
}  Produto;

typedef struct fila * FILA;
FILA cria_fila();
int fila_vazia(FILA);
int insere_fim(FILA, Produto);
int remove_inicio(FILA, Produto *);

int tamanho_fila(FILA, int *);
int esvazia_fila(FILA);
int apaga_fila(FILA *);


FILA imprimir_fila(FILA);
#endif // TAD_H_

