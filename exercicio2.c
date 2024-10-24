#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    char *texto = NULL;
    size_t tamanho = 0;
    
    printf("Digite uma string: ");
    getline(&texto, &tamanho, stdin);

    int contador = 0;
    for (int i = 0; texto[i] != '\0'; i++){
        if(tolower(texto[i] == 'a')){
            contador++;
        }
    }

    printf("A letra 'a' aparece %d vez(es) nesse texto!\n", contador);

    free(texto);
    
    return 0;
}