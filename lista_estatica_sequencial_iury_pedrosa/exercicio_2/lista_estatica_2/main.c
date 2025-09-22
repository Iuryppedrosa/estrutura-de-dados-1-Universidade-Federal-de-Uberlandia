#include "lista_bebidas.h"
#include <stdio.h>
#include <string.h>

int main() {
    Lista l = NULL;
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Criar lista\n");
        printf("2. Inserir bebida\n");
        printf("3. Remover bebida por nome\n");
        printf("4. Buscar bebida por posição\n");
        printf("5. Esvaziar lista\n");
        printf("6. Apagar lista\n");
        printf("7. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (l == NULL) {
                    l = cria_lista();
                    if (l)
                        printf("Lista criada com sucesso.\n");
                    else
                        printf("Erro ao criar lista.\n");
                } else {
                    printf("Lista já foi criada.\n");
                }
                break;

            case 2:
                if (l != NULL) {
                    Bebida b;
                    printf("Nome: ");
                    fgets(b.nome, sizeof(b.nome), stdin);
                    b.nome[strcspn(b.nome, "\n")] = '\0';
                    printf("Volume (ml): ");
                    scanf("%d", &b.volume);
                    printf("Preço: ");
                    scanf("%f", &b.preco);
                    getchar(); // limpa \n
                    if (insere_ord(l, b))
                        printf("Bebida inserida com sucesso.\n");
                    else
                        printf("Erro: lista cheia ou falha na inserção.\n");
                } else {
                    printf("Crie a lista primeiro.\n");
                }
                break;

            case 3:
                if (l != NULL) {
                    char nome[20];
                    printf("Nome da bebida a remover: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    if (remove_ord(l, nome))
                        printf("Bebida removida.\n");
                    else
                        printf("Bebida não encontrada.\n");
                } else {
                    printf("Crie a lista primeiro.\n");
                }
                break;

            case 4:
                if (l != NULL) {
                    int pos;
                    printf("Digite a posição (iniciando em 0): ");
                    scanf("%d", &pos);
                    getchar();
                    Bebida b;
                    if (get_elem_pos(l, pos, &b)) {
                        printf("Nome: %s | Volume: %dml | Preço: R$%.2f\n",
                               b.nome, b.volume, b.preco);
                    } else {
                        printf("Posição inválida.\n");
                    }
                } else {
                    printf("Crie a lista primeiro.\n");
                }
                break;

            case 5:
                if (l != NULL) {
                    esvazia_lista(l);
                    printf("Lista esvaziada.\n");
                } else {
                    printf("Crie a lista primeiro.\n");
                }
                break;

            case 6:
                if (l != NULL) {
                    apaga_lista(&l);
                    printf("Lista apagada.\n");
                } else {
                    printf("Lista já está apagada.\n");
                }
                break;

            case 7:
                imprime_lista(l);
                break;

            case 0:
                if (l != NULL)
                    apaga_lista(&l);
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
