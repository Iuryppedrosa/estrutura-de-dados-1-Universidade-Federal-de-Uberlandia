#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

void estaVazia(Pilha p){
    if(pilha_vazia(p) == 1){
        printf("Pilha vazia!\n");
    }else{
        printf("Possui elemento\n");
    }
}

int main()
{
    Pilha p1 = cria_pilha();
    estaVazia(p1);
    char topo[20];
    char devolutiva[20];
    int tamanho;

    char nome[20] = "Iury Pedrosa";
    char nome2[20] = "Joao Augusto";
    char nome3[20] = "Jose Saidinho";
    if(push(&p1, nome) == 1 && push(&p1, nome2) == 1 && push(&p1, nome3) == 1){
        printf("Elementos inseridos!\n");
    }
    if(pop(&p1, devolutiva) == 1){
        printf("Elemento removido: %s\n", devolutiva);
    }
    if(get_topo(p1, topo) == 1){
        printf("Topo: %s\n", topo);
    }
    tamanho = tamanho_pilha(p1);
    printf("Tamanho pilha: %d\n", tamanho);

    estaVazia(p1);
    if(apaga_pilha(&p1) == 1){
        printf("Pilha apagada\n");
    }
    estaVazia(p1);


    Pilha p2 = cria_pilha();
    char nome4[20] = "Jovem Estudante";
    char nome5[20] = "Jovem cansado";
    char nome6[20] = "Jovem aprendiz";
    if(push(&p2, nome4) == 1 && push(&p2, nome5) == 1 && push(&p2, nome6) == 1){
        printf("Elementos inseridos!\n");
    }

    //desempilhando e imprimindo a pilha
    while(pilha_vazia(p2) == 0){
        if(pop(&p2, devolutiva) == 1){
            printf("Nome: %s\n", devolutiva);
        }
    }
    estaVazia(p2);

    return 0;
}
