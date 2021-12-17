#ifndef _PAIR_
#define _PAIR_

#include "matrix.h"

struct pair {
    int l;
    int c;
};

struct pair *consPair(int l, int c);

struct pair *cpyPair(struct pair *P);

void freePair(struct pair *P);

/**
 * renvoie l’indice dans le vecteur values correspondant
 * au couple de coordonnées référencé par p
 * */
int pair2ind(struct pair *p, struct matrix *M);

/**
 * renvoie une paire (l, c) correspondant à l’indice k
 * */
struct pair *ind2pair(int k, struct matrix *M);

#endif