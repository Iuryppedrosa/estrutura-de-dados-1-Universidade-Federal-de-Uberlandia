#ifndef TAD_H_
#define TAD_H_

typedef struct pilha * Pilha;

typedef struct func {
    int matricula;
    char nome[50];
    char setor;
    float salario;
} Func;

Pilha cria_pilha();
int pilha_vazia(Pilha);
int pilha_cheia(Pilha);

int push(Pilha, Func);
int pop(Pilha, Func *);

int get_topo(Pilha, Func *);

int apaga_pilha(Pilha *);
int esvazia_pilha(Pilha);

int tamanho_pilha(Pilha);



#endif
