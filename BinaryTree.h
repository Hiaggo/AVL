#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef struct arvbin{
    int info;
    struct arvbin *esq, *dir;
}TAB;

TAB *inicializa();
TAB *cria(TAB *e, TAB *d, int info);
TAB *Vet2BT(int *v, int n);
TAB *busca(TAB *arv, int elem);
void imp_pre(TAB *arv);
void imp_pos(TAB *arv);
void imp_sim(TAB *arv);
static void libera_TAB(TAB *arv);

#endif // BINARY_TREE_H_INCLUDED
