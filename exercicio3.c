#include <stdio.h>

int main(){

    int soma = 0, k = 1, indice = 12;

    while(k < indice){
        k = k +1;
        soma = soma + k;
    }

    printf("%d",soma);

    return 0;
}