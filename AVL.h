#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct avl{
    int info;
    struct avl *esq, *dir;
    int alt;
}TAVL;

void libera(TAVL *arv);
TAVL *busca_TAVL(int elem, TAVL *arv);
int altura(TAVL *arv);
int maximo(int x, int y);
TAVL *insere_TAVL();
TAVL *retirada_TAVL();
TAVL *RSE(TAVL *arv); //ROTACAO SIMPLES ESQUERDA
TAVL *RSD(TAVL *arv); //ROTACAO SIMPLES DIREITA
TAVL *RDE(TAVL *arv); //ROTACAO DUPLA DIRETA-ESQUERDA
TAVL *RED(TAVL *arv); //ROTACAO DUPLA ESQUERDA-DIREITA
int FB(TAVL *arv);
int calc_alt_retira(TAVL *arv);
void imprime(TAVL *arv);
void imprime_aux(TAVL *arv, int andar);


#endif // AVL_H_INCLUDED
