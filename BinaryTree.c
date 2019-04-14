#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

TAB *inicializa(){
    return NULL;
}
//Cria um node
TAB *cria(TAB *e, TAB *d, int info){
    TAB *novo = (TAB *) malloc(sizeof(TAB));
    novo->dir = d;
    novo->esq = e;
    novo->info = info;
    return novo;
}
//Cria uma Binary tree apartir de um vetor
TAB *Vet2BT(int *vet, int n){
    if(n <= 0)
        return NULL;
    return cria(Vet2BT(vet, n/2), Vet2BT(&vet[n/2 + 1], n - n/2 - 1), vet[n/2]);
}

TAB *busca(TAB *arv, int elem){
    if((!arv) ||(arv->info == elem))
        return arv;
    TAB *esq = busca(arv->esq, elem);
    if(esq)
        return esq;
    return busca(arv->dir, elem);
}

//Pre-ordem
void imp_pre(TAB *arv){
    if(arv){
        printf("%d", arv->info);
        imp_pre(arv->esq);
        imp_pre(arv->dir);
    }
}
//Pos-ordem
void imp_pos(TAB *arv){
    if(arv){
        imp_pos(arv->esq);
        imp_pos(arv->dir);
        printf("%d", arv->info);
    }
}
//Simetrica
void imp_sim(TAB *arv){
    if(arv){
        imp_sim(arv->esq);
        printf("[%d]\n", arv->info);
        imp_sim(arv->dir);
    }
}

static void libera_TAB(TAB *arv){
    if(arv){
        libera(arv->esq);
        libera(arv->dir);
        free(arv);
    }
}

