#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBuscaBinaria.h"
#include "BinaryTree.h"

TABB *busca_tabb(TABB *arv, int elem){
    if((!arv)||(arv->info == elem))
        return arv;
    if(elem > arv->info)
        return busca_tabb(arv->dir, elem);
    return busca_tabb(arv->esq, elem);
}

TABB *insere(TABB *arv, int elem){
    if(!arv){
        arv = cria(NULL, NULL, elem);
        return arv;
    }
    if(elem < arv->info)
        arv->esq = insere(arv->esq, elem);
    else if(elem > arv->info)
        arv->dir = insere(arv->dir, elem);
    return arv;
}
TABB *retirada(TABB *arv, int elem){
    if(!arv)
        return arv;
    if(arv->info < elem)
        arv->dir = retirada(arv->dir, elem);
    else if(arv->info > elem)
        arv->esq = retirada(arv->esq, elem);
    else{ // ACHOU O ELEMENTO
        if((!arv->esq)&&(!arv->dir)){ //FOLHA
            free(arv);
            return NULL;
        }
        if((!arv->esq)||(!arv->dir)){ //1 FILHO
            TABB *aux = arv;
            if(arv->esq)
                arv = arv->esq;
            else
                arv = arv->dir;
            free(aux);
        }
        else{ //2 FILHOS
            TABB *aux = arv->esq;
            while(aux->dir)
                aux = aux->dir;
            arv->info = aux->info;
            aux->info = elem;
            arv->esq = retirada(arv->esq, elem);
        }
    }
}

static void libera_TABB(TABB *arv){
    if(arv){
        libera(arv->esq);
        libera(arv->dir);
        free(arv);
    }
}

