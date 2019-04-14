#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main(){
    TAVL *arvore = NULL;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%i", &num);
        if(num == -9){
            scanf("%d", &from);
            arvore = retira_TAVL(from, arvore);
            imprime(arvore);
        }

        else if(num == -1){
            printf("\n");
            imprime(arvore);
            libera(arvore);
            return 0;
            }
        else if(!num){
            printf("\n");
            imprime(arvore);
        }
        else
            arvore = insere_TAVL(num, arvore);
        printf("\n\n");
    }
    return 0;
}
