#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

void libera(TAVL *arv){
    if(arv){
        libera(arv->esq);
        libera(arv->dir);
        free(arv);
    }
}

TAVL *busca_TAVL(int elem, TAVL* arv){
    if(!arv)
        return NULL;
    if(elem < arv->info)
        return busca(elem, arv->esq);
    if(elem > arv->info)
        return busca(elem, arv->dir);
    return arv;
}

TAVL *insere_TAVL(int elem, TAVL *arv){
    if(!arv){
        arv = (TAVL *)malloc(sizeof(TAVL));
        arv->info = elem;
        arv->esq = NULL;
        arv->dir = NULL;
        arv->alt = 0;
    }
    else if(elem < arv->info){
        arv->esq = insere_TAVL(elem, arv->esq);
        if(altura(arv->esq) - altura(arv->dir) == 2 )
            if(elem < arv->esq->info)
                arv = RSE(arv);
            else
                arv = RED(arv);
    }
    else if(elem > arv->info){
        arv->dir = insere_TAVL(elem, arv->dir);
        if(altura(arv->dir) - altura(arv->esq) == 2 )
            if(elem > arv->dir->info)
                arv = RSD(arv);
            else
                arv = RDE(arv);
    }
    arv->alt = altura(arv);
    return arv;
}

//Altura dos nós
int altura(TAVL *arv){
    if(!arv)
        return -1;
    return 1 + maximo(altura(arv->esq), altura(arv->dir));
}
int maximo(int x, int y){
    if(x >= y)
        return x;
    return y;
}
//

TAVL *RSE(TAVL *arv){ //Rotação Simples Esquerda
    TAVL *aux = NULL;
    aux = arv->esq;
    arv->esq = aux->dir;
    aux->dir = arv;
    arv->alt = altura(arv);
    aux->alt = altura(aux);
    return aux; //Nova Raiz
}

TAVL *RSD(TAVL *arv){ //Rotação Simples Direita
    TAVL *aux = NULL;
    aux = arv->dir;
    arv->dir = aux->esq;
    aux->esq = arv;
    arv->alt = altura(arv);
    aux->alt = altura(aux);
    return aux;
}

TAVL *RDE(TAVL *arv){ //Rotação Direita-Esquerda
    arv->dir = RSD(arv->dir);
    return RSE(arv);
}

TAVL *RED(TAVL *arv){ //Rotação Esquerda-Direita
    arv->esq = RSE(arv->esq);
    return RSD(arv);
}

int calc_alt_retira(TAVL *arv){
    int esq_alt, dir_alt;
    if(!arv)
        return(0);
    if(!arv->esq)
        esq_alt = 0;
    else
        esq_alt = 1 + arv->esq->alt;
    if(!arv->dir)
        dir_alt = 0;
    else
        dir_alt = 1 + arv->dir->alt;
    if(esq_alt > dir_alt)
        return(esq_alt);
    return(dir_alt);
}

int FB(TAVL *arv){ //Fator de Balanceamento
    int esq_alt, dir_alt;
    if(!arv)
        return(0);
    if(!arv->esq)
        esq_alt = 0;
    else
        esq_alt = 1 + arv->esq->alt;
    if(!arv->dir)
        dir_alt = 0;
    else
        dir_alt = 1 + arv->dir->alt;
    return(esq_alt - dir_alt);
}

void imprime_aux(TAVL *arv, int andar){
    if(arv){
        register int j;
        imprime_aux(arv->esq,andar+1);
        for(j=0; j<=andar; j++) printf("   ");
        printf("%d\n", arv->info);
        imprime_aux(arv->dir, andar+1);
  }
}

void imprime(TAVL *arv){
    imprime_aux(arv, 1);
}

TAVL *retira_TAVL(int elem, TAVL *arv){
    if(!arv)
        return NULL;
    else
        if(elem > arv->info){
            arv->dir = retira_TAVL(elem, arv->dir);
            if(FB(arv) == 2){
                if(FB(arv->esq) >= 0)
                    arv = RSE(arv);
                else
                    arv = RED(arv);
            }
        }
        else
            if(elem < arv->info){
                    arv->esq = retira_TAVL(elem, arv->esq);
                    if(FB(arv) == -2){
                        if(FB(arv->dir) <= 0)
                            arv = RSD(arv);
                        else
                            arv = RDE(arv);
                    }
            }
            else{ //Encontrado o elemento
                if(arv->esq){
                    TAVL *p;
                    p = arv->esq;
                    while(p->dir)
                        p = p->dir;
                    arv->info = p->info;
                    arv->esq = retira_TAVL(p->info, arv->esq);
                    if(FB(arv) == -2){
                        if(FB(arv->dir) <= 0)
                            arv = RSD(arv);
                        else
                            arv = RDE(arv);
                    }
                  }
                  else{
                      TAVL *x = arv;
                      arv = arv->dir;
                      free(x);
                      return(arv);
                  }
            }
    arv->alt = calc_alt_retira(arv);
    return(arv);
}


