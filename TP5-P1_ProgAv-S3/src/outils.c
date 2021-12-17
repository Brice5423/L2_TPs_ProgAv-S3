#include "outils.h"

void printInteger(int *i) {
    assert(i);
    printf("La valeur est entière et vaut : %d\n", (*i));
}

void rmInteger(int *i) {
    assert(i);
    free(i);
}

bool cmpInteger(int *i, int *j) {
    assert(i);
    assert(j);
    return (*i) < (*j);
}

void printDouble(double *d) {
    assert(d);
    printf("La valeur est réelle et vaut : %.2lf\n", (*d));
}

void rmDouble(double *d) {
    assert(d);
    free(d);
}

bool cmpDouble(double *u, double *v) {
    assert(u);
    assert(v);
    return (*u) < (*v);
}