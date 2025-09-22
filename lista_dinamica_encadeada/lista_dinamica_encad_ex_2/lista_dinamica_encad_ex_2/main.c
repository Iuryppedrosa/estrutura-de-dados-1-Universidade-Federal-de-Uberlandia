#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica_encad_ex_2.h"

int main() {
    Lista lista = NULL;
    int opcao, coef, expo, pos;
    char var;
    Termo *termo;

    do {
        printf("\nMenu:\n");
        printf("1. Criar lista\n");
        printf("2. Inserir termo\n");
        printf("3. Remover termo\n");
        printf("4. Obter termo por posicao\n");
        printf("5. Esvaziar lista\n");
        printf("6. Apagar lista\n");
        printf("7. Imprimir lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (lista != NULL) {
                    printf("Lista ja criada. Apague primeiro para criar uma nova.\n");
                } else {
                    lista = cria_lista();
                    if (lista == NULL) {
                        printf("Falha ao criar lista.\n");
                    } else {
                        printf("Lista criada com sucesso.\n");
                    }
                }
                break;

            case 2:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                printf("Digite coeficiente, variavel e expoente (ex: 5 x 2): ");
                scanf("%d %c %d", &coef, &var, &expo);
                termo = (Termo *)malloc(sizeof(Termo));
                if (termo == NULL) {
                    printf("Falha ao alocar termo.\n");
                    break;
                }
                termo->coeficiente = coef;
                termo->parte_desconhecida = var;
                termo->expoente = expo;
                if (insere_polinomio_ord(&lista, termo)) {
                    printf("Termo inserido com sucesso.\n");
                } else {
                    printf("Falha ao inserir termo.\n");
                    free(termo);
                }
                break;

            case 3:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                printf("Digite coeficiente do termo a remover: ");
                scanf("%d", &coef);
                termo = (Termo *)malloc(sizeof(Termo));
                if (termo == NULL) {
                    printf("Falha ao alocar termo.\n");
                    break;
                }
                termo->coeficiente = coef;
                if (remove_polinomio_ord(&lista, termo)) {
                    printf("Termo removido com sucesso.\n");
                } else {
                    printf("Termo nao encontrado ou falha ao remover.\n");
                    free(termo);
                }
                break;

            case 4:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                printf("Digite a posicao do termo: ");
                scanf("%d", &pos);
                if (get_elem_pos(lista, pos, &termo)) {
                    printf("Termo na posicao %d: %d%c^%d\n", pos, termo->coeficiente, termo->parte_desconhecida, termo->expoente);
                } else {
                    printf("Posicao invalida ou termo nao encontrado.\n");
                }
                break;

            case 5:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                esvazia_lista(lista);
                printf("Lista esvaziada com sucesso.\n");
                break;

            case 6:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                apaga_lista(&lista);
                printf("Lista apagada com sucesso.\n");
                break;

            case 7:
                if (lista == NULL) {
                    printf("Crie uma lista primeiro.\n");
                    break;
                }
                imprime_lista(lista);
                break;

            case 8:
                if (lista != NULL) {
                    apaga_lista(&lista);
                }
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 8);

    return 0;
}
