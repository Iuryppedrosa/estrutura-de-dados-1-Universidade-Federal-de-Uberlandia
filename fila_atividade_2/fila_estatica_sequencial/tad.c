#include <stdio.h>
#include "tad.h"
#include <string.h>
#define MAX_COL 31
#define MAX_ROW 10



// definido estrutura de dados TAD FILA.
// possui uma matrix de caracteres, representando uma string.
// possui a variavel que recebe o inicio da fila estatica.
// possui a variavel que recebe o contador, que ira dizer quando a fila estará cheia.
// a implementacao será circular.
struct fila {
    char string[MAX_ROW][MAX_COL];
    int ini;
    int count;
};


// cria uma instancia (alocacao de memoria) de uma estrutura do tipo FILA.
// atribuio seu inicio como 0.
// atribui o contador como 0.
// criando-se a fila e deixando-a no estado vazia.
FILA cria_fila(){
    FILA f = (FILA) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = 0;
        f->count = 0;
    }
}

// insere-se na fila, pelo seu fim, respeitando a politica de acesso FIFO(primeiro a entrar, primeiro a sair).
int insere_final(FILA f, char * string){
    if(f == NULL || fila_cheia(f) == 1){
        return 0;
    }
    strcpy(f->string[(f->ini + f->count) % MAX_COL], string);
    f->count ++;
    return 1;
}

// a remocao em uma estrutura linear FILA, obedece a politica de acesso FIFO (primeiro a entrar, primeiro a sair).
// sendo assim, o primeiro a sair, significa remover sempre do inicio da fila.
// por obedecer a politica de acesso, tem-se que devolver o elemento removido para o cliente.
int remove_inicio(FILA f, char * string_devolucao){
    if(f == NULL || fila_vazia(f) == 1){
        return 0;
    }
    strcpy(string_devolucao, f->string[f->ini]);
    f->ini = (f->ini + 1) % MAX_COL;
    f->count --;
    return 1;
}

int esvazia_fila(FILA f){
    if(fila_vazia(f) == 1){
        return 0;
    }
    f->ini = 0;
    f->count = 0;
    return 1;
}

int apaga_fila(FILA *f){
    if(*f == NULL){
        return 0;
    }
    free(*f);
    *f = NULL;
    return 1;
}

// uma fila vazia tem a variavel inicio igual a 0.
int fila_vazia(FILA f){
    if(f == NULL || f->count != 0){
        return 0;
    }
    return 1;
}

int tamanho_fila(FILA f){
    if(fila_vazia(f) == 1){
        return 0;
    }
    if(fila_cheia(f) == 1){
        return MAX_COL;
    }
    return f->count;
}

// uma fila cheia, tem a variavel de contagem igual ao tamanho total de posicoes do vetor.
int fila_cheia(FILA f){
    if(f->count != MAX_COL || f == NULL){
        return 0;
    }
    return 1;

}
