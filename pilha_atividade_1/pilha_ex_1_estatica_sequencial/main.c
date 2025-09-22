#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

int main()
{
    Pilha p = cria_pilha();
    Func f;
    f.matricula = 12354345;
    strcpy(f.nome, "Iury\0");
    f.setor = 'S';
    f.salario = 5000;

    Func f2;
    f2.matricula = 67891212;
    strcpy(f2.nome, "Joao\0");
    f2.setor = 'T';
    f2.salario = 10000;

    Func f3;
    f3.matricula = 1231123;
    strcpy(f3.nome, "Gustavo\0");
    f3.setor = 'U';
    f3.salario = 30000;

    Func f4;
    f4.matricula = 42342323;
    strcpy(f4.nome, "Mario\0");
    f4.setor = 'U';
    f4.salario = 90000;

    Func f_recebedor;
    Func f_apagado;
    Func f_mostrar;

    if(pilha_vazia(p) == 1)
        printf("Pilha vazia!\n");

    if(pilha_cheia(p) == 1)
        printf("Pilha cheia!\n");

    if(push(p, f) == 1){
        printf("Elemento inserido na pilha!\n");
    }
    if(pilha_vazia(p) != 1)
        printf("Pilha nao esta mais vazia!\n");

    if(push(p, f2) == 1){
        printf("Elemento inserido na pilha!\n");
    }

    if(push(p, f3) == 1){
        printf("Elemento inserido na pilha!\n");
    }

    if(get_topo(p, &f_recebedor) == 1){
        printf("Nome topo: %s\n", f_recebedor.nome);
    }

    int tamanho = tamanho_pilha(p);
    printf("Tamanho pilha: %d\n", tamanho);

    /*
    //desempilhando e mostrando
    printf("Desempilhando...\n");
    while(pop(p, &f_mostrar) != 0){
        printf("Nome: %s\n", f_mostrar.nome);
    }
    printf("Fim desempilhamento.\n");
    */

    //apagando elemento e mostrando
    if(pop(p, &f_apagado) == 1){
        printf("Elemento apagado: %s\n", f_apagado.nome);
    }
    tamanho = tamanho_pilha(p);
    printf("Tamanho pilha: %d\n", tamanho);

    if(push(p, f4) == 1){
        printf("Elemento inserido na pilha!\n");
    }
    if(esvazia_pilha(p) == 1){
        printf("...esvaziando pilha\n");
        if(pilha_vazia(p) == 1){
            printf("Pilha vazia!\n");
        }
    }
    tamanho = tamanho_pilha(p);
    printf("Tamanho pilha: %d\n", tamanho);

    if(apaga_pilha(&p) == 1){
        printf("...apagando pilha\n");
        if(p == NULL){
            printf("Pilha apagada.\n");
        }
    }


    return 0;
}
