#include <stdio.h>
#include <stdlib.h>
#include "lista_seq_string.h"

int menu(){
    int escolha;
    while(1){
        printf("0 Criar a lista de 10 nomes\n");
        printf("1 Inserir nome na lista.\n");
        printf("2 Apagar nome na lista.\n");
        printf("3 Imprimir toda a lista.\n");
        printf("4 Apagar toda a lista.\n");
        printf("5 Esvaziar a lista.\n");
        printf("6 Sair.\n");
        scanf("%d", &escolha);
        return escolha;
        if(escolha == 6){
            break;
        }
    }
    return escolha;
}

int main()
{
    Lista l;
    String inserir_nome;
    String apagar_nome;
    String lista[10];
    int fim_lista;
    while(1){
        int escolha = menu();
        switch(escolha){
            case 0:
                l = cria_lista();
            break;
            case 1:
                printf("Qual nome quer inserir? ");
                scanf("%s", &inserir_nome);
                if(insere_elemento(l, inserir_nome) != 1){
                    printf("Erro ao inserir elemento!");
                }else{
                    printf("Nao foi possivel inserir, lista n existe!");
                }
                break;
            case 2:
                printf("Qual nome quer apagar? ");
                scanf("%s", &apagar_nome);
                if(remove_elemento(l, apagar_nome) != 1){
                    printf("Erro ao inserir elemento!");
                }
                else{
                    printf("Nao foi possivel remover, lista n existe!");
                }
                break;
            case 3:
                fim_lista = imprimir_lista(l, lista);
                if(fim_lista == 0){
                    printf("Lista Vazia! Ou nao existe!\n");
                }
                for(int i = 0; i < fim_lista; i++){
                    printf("Nome %d: %s\n", i, lista[i]);
                }
                break;
            case 4:
                apagar(&l);
                break;
            case 5:
                esvaziar_lista(l);
                break;
            case 6:
                break;
        }
        if(escolha == 6){
            break;
        }
    }

    return 0;
}
