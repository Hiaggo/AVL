#ifndef ARVOREBUSCABINARIA_H_INCLUDED
#define ARVOREBUSCABINARIA_H_INCLUDED

typedef struct tabb{
    int info;
    struct tabb *esq, *dir;
}TABB;

TABB *busca_tabb(TABB *arv, int elem);
TABB *insere(TABB *arv, int elem);
TABB *retirada(TABB *arv, int elem);
static void libera_TABB(TABB *arv);

#endif // ARVOREBUSCABINARIA_H_INCLUDED
