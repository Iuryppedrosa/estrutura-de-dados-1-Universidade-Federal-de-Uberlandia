#include "lista.h"
#include <stdlib.h>
#define MAX 10

struct lista {
    int inteiro[MAX];
    int fim;
};

// mesmo sendo o conceito de lista estática, a lista é criada via malloc dinamicamente
// para obedecer o conceito de TAD(n saber quantas listas a aplicacao necessita);
Lista cria_lista(){
    Lista l = (Lista) malloc(sizeof(struct lista));
    if(l != NULL){
        l->fim = 0;//lista vazia
    }
    return l;
}

// campo fim deve ser zero.
int lista_vazia(Lista l){
    if(l->fim != 0){
        return 0; // nao esta vazia
    }
    return 1;
}
// campo fim deve ser igual ao valor de max
int lista_cheia(Lista l){
    if(l->fim != MAX){
        return 0;
    }
    return 1;
}

//lista nao ordenada
//insere no final da lista (posicao fim[indica a posicao disponivel)
int insere_elem(Lista l, int elem){
    if(lista_cheia(l) != 0 || l == NULL){
        return 0;
    }
    l->inteiro[l->fim] = elem;
    l->fim++;
    return 1;
}

//lista ordenada
int insere_elem_ord(Lista l, int elem){
    if(lista_cheia(l) == 1 || l == NULL){
        return 0;
    }
    // lista vazia ou elemento MAIOR > ou igual ao ultimo elemento
    // caso em que sendo, n precisa de deslocamento, basta inserir no fim(que é o começo, se lista vazia)
    // lista-> fim - 1; indica a ultima posicao, visto que fim mostra smp a posicao disponivel
    if(lista_vazia(l) == 1 || elem >= l->inteiro[l->fim - 1]){
        l->inteiro[l->fim] = elem;
    }else{
        int i = 0;
        int aux = 0; // acusa qual posicao o elemento encontra o seu par
        // esse while tambem trata a hipotese do elemento ser o menor de todos
        // caso em que o while n entra, o elemento sera inserido na primeira posicao
        // e o for fara o incremento de todos.
        while(elem >= l->inteiro[aux]){ // percorre a lista para encontrar a ordem que o item deve estar
            aux++;
        };
        for(i = l->fim; i > aux; i--){ // reordenando, abrindo espaço, jogando os elementos para a direita
            l->inteiro[i] = l->inteiro[i - 1];
        }
        l->inteiro[aux] = elem;
    };
    l->fim++;
    return 1;
/*
    while
    elemento = 5
    1,2,3,4,*5*,5,6,7,8,9,10
    sim, sim, sim, sim, sim, nao
    aux = 5;


    for
    elemento 5
    aux 5
    i = 10
    sim
    elemento na posicao 10 recebe o elemento na posicao 9
    i = 9
    sim
    elemento na posicao 9 recebe o elemento na posicao 8
    i = 8
    sim
    elemento na posicao 8, recebe o elemento na posicao 7
    i = 7
    sim
    elemento na posicao 7, recebe o elemento na posicao 6
    i = 6
    sim
    elemento na posicao 6, recebe o elemento da posicao 5
    i = 5
    nao
    elemento da posicao 5, recebe o elemeto que queremos inserir

*/
}

int remove_elem(Lista l, int elem){
    if(lista_vazia(l) == 1){
        return 0;
    }
    int aux = 0;
    int i = 0;
    while(aux < l->fim && l->inteiro[aux] != elem){
        aux++;
        if(aux == l->fim){
            return 0;
        }
    }
    // aux + 1 é o sucessor do que será removido
    for(i = aux+1; i < l->fim; i++){
        // l->inteiro[i - 1] é a posicao que sera substituida removida, recebendo o proximo
        l->inteiro[i - 1] =  l->inteiro[i];
    }
    l->fim--;
    return 1;
}

int remove_elem_ord(Lista l, int elem){
    // lista vazia
    // lista nula
    // elemento nao está na lista, pois é menor que o primeiro ou maior que o ultimo
    if(lista_vazia(l) == 1 || l == NULL || elem < l->inteiro[0] || elem > l->inteiro[l->fim - 1]){
        return 0;
    }
    int aux = 0;

    //verifica se o elemento está pra frente, comparando ele com o ultimo.
    while(aux < l->fim && l->inteiro[aux] < elem){
        aux++;
    }
    int i = 0;
    if(aux == l->fim || l->inteiro[aux] > elem){
        return 0;
    }
    //i = aux + 1 = sucessor do achado
    //l->inteiro[i - 1] o achado
    for(i = aux + 1; i < l->fim; i++){
        l->inteiro[i - 1] = l->inteiro[i];
    }
    l->fim--;
    return 1;
}

void exibir_lista(Lista l, int *vetor_exibicao){
    for(int i = 0; i < l->fim; i++){
        vetor_exibicao[i] = l->inteiro[i];
    }
}
