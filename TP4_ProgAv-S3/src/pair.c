#include "pair.h"

struct pair *consPair(int l, int c) {
    struct pair *P = (struct pair *) calloc(1, sizeof(struct pair));

    P->c = c;
    P->l = l;

    return P;
}

struct pair *cpyPair(struct pair *P) {
    return consPair(P->l, P->c);
}

void freePair(struct pair *P) {
    free(P);
    P = NULL;
}

int pair2ind(struct pair *p, struct matrix *M) {
    return ((p->l) * (M->n) + (p->c));
}

struct pair *ind2pair(int k, struct matrix *M) {
    return consPair((k / M->n), (k % M->n));
}