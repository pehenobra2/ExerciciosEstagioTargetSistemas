#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct celula {
    int numero;
    struct celula *prox;
    struct celula *ant;
} Celula;

Celula *criarCelula (int numero){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->numero = numero;
    nova->prox = NULL;
    nova->ant = NULL;
    return nova;
}

bool pertenceFibonacci(int numero){
    if (numero < 0) return true;
    if (numero == 0 || numero == 1) return true;

    Celula *inicio = criarCelula(0);
    Celula *segundo = criarCelula(1);
    inicio->prox = segundo;
    segundo->ant = inicio;

    Celula *atual = segundo;
    while (atual->numero < numero) {
        int novoNumero = atual->numero + atual->ant->numero;
        Celula *novaCelula = criarCelula(novoNumero);
        atual->prox = novaCelula;
        novaCelula->ant = atual;
        atual = novaCelula;
    }

    if(atual->numero == numero){
        while (inicio != NULL) {
            Celula *temp = inicio;
            inicio = inicio->prox;
            free(temp);
        }
        return true;
    }else{
        while (inicio != NULL) {
            Celula *temp = inicio;
            inicio = inicio->prox;
            free(temp);
        }
        return false;
    }
}

int main(){

    int numero;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    if(pertenceFibonacci(numero)){
        printf("Esse numero pertence a sequencia de Fibonacci!\n");
    }else{
        printf("Esse numero nao pertence a sequencia de Fibonacci!\n");
    }

    return 0;
}