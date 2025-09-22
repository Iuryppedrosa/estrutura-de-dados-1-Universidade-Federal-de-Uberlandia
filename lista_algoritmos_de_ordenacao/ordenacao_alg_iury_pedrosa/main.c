#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_NOME 40
#define MAX_ALUNOS 2300

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    int nota1, nota2, nota3;
} Aluno;

void bubbleSort(Aluno vetor[], int n, int *comparacoes, int *trocas);
void selectionSort(Aluno vetor[], int n, int *comparacoes, int *trocas);
void insertionSort(Aluno vetor[], int n, int *comparacoes, int *trocas);
void quickSort(Aluno vetor[], int inicio, int fim, int *comparacoes, int *trocas);
void mergeSort(Aluno vetor[], int inicio, int fim, int *comparacoes, int *trocas);
void intercala(Aluno vetor[], int inicio, int meio, int fim, int *comparacoes, int *trocas);


void bubbleSort(Aluno vetor[], int n, int *comparacoes, int *trocas) {
    int i, iteracao;
    Aluno aux;
    int troca_ocorreu;
    for (iteracao = n - 1; iteracao > 0; iteracao--) {
        troca_ocorreu = 0;
        for (i = 0; i < iteracao; i++) {
            (*comparacoes)++;
            if (vetor[i].matricula > vetor[i+1].matricula) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca_ocorreu = 1;
                (*trocas)++;
            }
        }
        if (troca_ocorreu == 0) {
            break;
        }
    }
}

void selectionSort(Aluno vetor[], int n, int *comparacoes, int *trocas) {
    int i, iteracao, menor;
    Aluno aux;
    for (iteracao = 0; iteracao < n - 1; iteracao++) {
        menor = iteracao;
        for (i = iteracao + 1; i < n; i++) {
            (*comparacoes)++;
            if (vetor[i].matricula < vetor[menor].matricula) {
                menor = i;
            }
        }
        if (iteracao != menor) {
            aux = vetor[iteracao];
            vetor[iteracao] = vetor[menor];
            vetor[menor] = aux;
            (*trocas)++;
        }
    }
}

void insertionSort(Aluno vetor[], int n, int *comparacoes, int *trocas) {
    int i, iteracao;
    Aluno elem;
    for (iteracao = 1; iteracao < n; iteracao++) {
        elem = vetor[iteracao];
        i = iteracao - 1;
        (*comparacoes)++;
        while (i >= 0 && vetor[i].matricula > elem.matricula) {
            vetor[i+1] = vetor[i];
            i--;
            (*trocas)++;
            if (i >= 0) (*comparacoes)++;
        }
        vetor[i+1] = elem;
        (*trocas)++;
    }
}

void quickSort(Aluno vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int i = inicio, j = fim;
        Aluno pivo = vetor[(inicio + fim) / 2];
        Aluno aux;

        while (i <= j) {
            (*comparacoes)++;
            while (vetor[i].matricula < pivo.matricula) {
                i++;
                (*comparacoes)++;
            }
            (*comparacoes)++;
            while (vetor[j].matricula > pivo.matricula) {
                j--;
                (*comparacoes)++;
            }
            if (i <= j) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
                (*trocas)++;
            }
        }
        if (inicio < j) {
            quickSort(vetor, inicio, j, comparacoes, trocas);
        }
        if (i < fim) {
            quickSort(vetor, i, fim, comparacoes, trocas);
        }
    }
}


void mergeSort(Aluno vetor[], int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int meio = floor((inicio + fim) / 2);
        mergeSort(vetor, inicio, meio, comparacoes, trocas);
        mergeSort(vetor, meio + 1, fim, comparacoes, trocas);
        intercala(vetor, inicio, meio, fim, comparacoes, trocas);
    }
}

void intercala(Aluno vetor[], int inicio, int meio, int fim, int *comparacoes, int *trocas) {
    int i = inicio, j = meio + 1, k = 0;
    Aluno *temp = (Aluno *) malloc(sizeof(Aluno) * (fim - inicio + 1));

    while (i <= meio && j <= fim) {
        (*comparacoes)++;
        if (vetor[i].matricula <= vetor[j].matricula) {
            temp[k] = vetor[i];
            i++;
        } else {
            temp[k] = vetor[j];
            j++;
        }
        k++;
        (*trocas)++;
    }

    while (i <= meio) {
        temp[k] = vetor[i];
        k++;
        i++;
        (*trocas)++;
    }

    while (j <= fim) {
        temp[k] = vetor[j];
        k++;
        j++;
        (*trocas)++;
    }
    for (k = inicio, i = 0; k <= fim; k++, i++) {
        vetor[k] = temp[i];
        (*trocas)++;
    }

    free(temp);
}


int menu(){
    int user_choice;
    printf("Selecione uma opcao abaixo:\n");
    printf("1 - bubble sort\n");
    printf("2 - select sort\n");
    printf("3 - insert sort\n");
    printf("4 - quiz sort\n");
    printf("5 - merge sort\n");
    printf("6 - Exibir lista de alunos\n");
    printf("0 - sair\n");
    printf("Opcao: ");
    scanf("%d", &user_choice);
    return user_choice;
}

void show_studants(Aluno *lista_de_alunos, int quantidade){
    printf("--- Exibindo dados de %d alunos ---\n\n", quantidade);
    for (int i = 0; i < quantidade; i++) {
        printf("Matricula: %d\n", lista_de_alunos[i].matricula);
        printf("Nome: %s\n", lista_de_alunos[i].nome);
        printf("Notas: %d, %d, %d\n", lista_de_alunos[i].nota1, lista_de_alunos[i].nota2, lista_de_alunos[i].nota3);
        printf("----------------------------------\n");
    }
}

int open_file(FILE **file, char *f_name){
    *file = fopen(f_name, "r");
    if(*file == NULL){
        return 0;
    }
    return 1;
}

int read_file(Aluno *estrutura_aluno, char *f_name, int *qtd_lidos){
    FILE *file;
    if(open_file(&file, f_name) == 1){
        *qtd_lidos = populate_struct(estrutura_aluno, file);
        fclose(file);
        return 1;
    }
    return 0;
}

int populate_struct(Aluno *estrutura_aluno, FILE *file){
    int qtd = 0;
    while(fscanf(file, "%d %s %d %d %d",
                &estrutura_aluno[qtd].matricula,
                estrutura_aluno[qtd].nome,
                &estrutura_aluno[qtd].nota1,
                &estrutura_aluno[qtd].nota2,
                &estrutura_aluno[qtd].nota3) == 5)
    {
        qtd++;
    }
    return qtd;
}

int main()
{
    Aluno alunos[MAX_ALUNOS];
    Aluno alunos_copia[MAX_ALUNOS];
    Aluno *p_alunos = alunos;
    char nome_arquivo[40] = "Lista_Alunos.txt";
    int qtd_lidos;
    if(read_file(p_alunos, nome_arquivo, &qtd_lidos) == 1){
        printf("Arquivo lido com sucesso. Total de alunos: %d\n", qtd_lidos);
    }else{
        printf("Erro ao ler o arquivo %s\n", nome_arquivo);
    }
    int user_choice;
    do {
        memcpy(alunos_copia, alunos, sizeof(Aluno) * qtd_lidos);

        user_choice = menu();

        long long int comparacoes = 0;
        long long int trocas = 0;
        clock_t inicio, fim;
        double tempo_gasto;

        switch(user_choice){
            case 1:
                printf("\n--- Executando Bubble Sort ---\n");
                inicio = clock();
                bubbleSort(alunos_copia, qtd_lidos, &comparacoes, &trocas);
                fim = clock();
                break;
            case 2:
                printf("\n--- Executando Selection Sort ---\n");
                inicio = clock();
                selectionSort(alunos_copia, qtd_lidos, &comparacoes, &trocas);
                fim = clock();
                break;
            case 3:
                printf("\n--- Executando Insertion Sort ---\n");
                inicio = clock();
                insertionSort(alunos_copia, qtd_lidos, &comparacoes, &trocas);
                fim = clock();
                break;
            case 4:
                printf("\n--- Executando Quick Sort ---\n");
                inicio = clock();
                quickSort(alunos_copia, 0, qtd_lidos - 1, &comparacoes, &trocas);
                fim = clock();
                break;
            case 5:
                printf("\n--- Executando Merge Sort ---\n");
                inicio = clock();
                mergeSort(alunos_copia, 0, qtd_lidos - 1, &comparacoes, &trocas);
                fim = clock();
                break;
            case 6:
                printf("\nExibindo lista atual (original ou a ultima ordenada):\n");
                show_studants(alunos_copia, qtd_lidos);
                continue;
            case 0:
                printf("Encerrando o programa.\n");
                continue;
            default:
                printf("Opcao invalida!\n");
                continue;
        }

        if (user_choice >= 1 && user_choice <= 5) {
            tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0;
            printf("Resultados:\n");
            printf("-> Comparacoes: %lld\n", comparacoes);
            printf("-> Trocas: %lld\n", trocas);
            printf("-> Tempo de execucao: %lf milissegundos\n", tempo_gasto);
        }

    } while(user_choice != 0);
    return 0;
}
