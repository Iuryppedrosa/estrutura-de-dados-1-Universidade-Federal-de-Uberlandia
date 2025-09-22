#ifndef TAD_H_
#define TAD_H_

typedef struct no * Pilha;
Pilha cria_pilha();
int pilha_vazia(Pilha);

int push(Pilha *, char *);
//int push(Pilha *, char []);

int pop(Pilha *, char *); //deve devolver o elemento

int get_topo(Pilha, char *);
int apaga_pilha(Pilha *);

int tamanho_pilha(Pilha);


#endif // TAD_H_
