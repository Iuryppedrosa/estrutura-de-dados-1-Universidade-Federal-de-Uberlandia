#ifndef TAD_H_
#define TAD_H_


typedef struct fila * FILA;
FILA cria_fila();
int fila_vazia(FILA);
int fila_cheia(FILA);
int insere_final(FILA, char *);
int remove_inicio(FILA, char *);

int apaga_fila(FILA *);
int esvazia_fila(FILA);

int tamanho_fila(FILA);




#endif // TAD_H_
