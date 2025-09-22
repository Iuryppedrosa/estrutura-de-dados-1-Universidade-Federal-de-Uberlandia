#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int menu(){
    int escolha = 0;
    printf("(1) Criar lista NAO ordenada(ja 10 elementos) e mostra-la \n");
    printf("(2) Criar lista ORDENADA(ja 10 elementos). e mostra-la\n");
    printf("(3) Remover elemento da lista 'NAO ORDENADA'\n");
    printf("(4) Remover elemento da lista 'ORDENADA'\n");
    printf("(5) Sair.\n");

    scanf("%d", &escolha);
    return escolha;
}

void remover_elemento(Lista l, int escolha){
    int elemento = 0;
    int remover;
    printf("Qual elemento deseja remover? ");
    scanf("%d", &elemento);
    if(escolha == 3)
        remover = remove_elem(l, elemento);
    if(escolha == 4)
        remover = remove_elem_ord(l, elemento);
    if(remover == 1){
        printf("Elemento removido!\n");
    }else{
        printf("Elemento nao removido, pois a lista está vazia ou o elemento está fora dela!\n");
    }
}

void insere_elem_in_not_ord(Lista l, int * list_not_ord){
    int inserindo = 0;
    for(int i = 0; i <= 10; i++){
        inserindo = insere_elem(l, list_not_ord[i]);
        if(inserindo != 1 && i != 10){
            printf("Falha ao inserir!\n");
            return 0;
        }
    }
    printf("Lista inserida sem ordem!\n");
    return 1;
}

void insere_elem_in_ord(Lista l, int * l_ord){
    int inserindo = 0;
    for(int i = 0; i <= 10; i++){
        inserindo = insere_elem_ord(l, l_ord[i]);
        if(inserindo != 1 && i != 10){
            printf("Falha ao inserir\n");
        }
    }
    printf("Lista inserida em ordem!\n");
}

void exibicao_lista(Lista l, int *lista_inteiros){
    exibir_lista(l, lista_inteiros);
    for(int i = 0; i < 10; i++){
        printf("Valor posicao %d = %d\n", i, lista_inteiros[i]);
    }
}


int main()
{
    Lista l;
    Lista l_2;
    l = cria_lista();
    l_2 = cria_lista();

    int lista[10] = {4,8,-1,19,2,7,8,5,9,22};
    int lista_inteiros[10];

    while(1){
        int escolha = menu();
        switch(escolha){
            case 1:
                insere_elem_in_not_ord(l, lista);
                exibicao_lista(l, lista_inteiros);
                break;
            case 2:
                insere_elem_in_ord(l_2, lista);
                exibicao_lista(l_2, lista_inteiros);
                break;
            case 3:
                remover_elemento(l, escolha);
                exibicao_lista(l, lista_inteiros);
                break;
            case 4:
                remover_elemento(l_2, escolha);
                exibicao_lista(l_2, lista_inteiros);
                break;
            case 5:
                break;
            default:
                break;
        }
        if(escolha == 5)
            break;
    }

    return 0;
}
