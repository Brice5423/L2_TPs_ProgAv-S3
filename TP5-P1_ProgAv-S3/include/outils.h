#ifndef _OUTILS_
#define _OUTILS_

#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions

/** D'affichage d'une valeur entière. */
void printInteger(int *i);

/** De suppression d'une mémoire de type entier. */
void rmInteger(int *i);

/** De comparaison de 2 entiers. */
bool cmpInteger(int *i, int *j);

/** D'affichage d'une valeur réelle. */
void printDouble(double *d);

/** De suppression d'une mémoire de type réel. */
void rmDouble(double *d);

/** De comparaison de 2 réels. */
bool cmpDouble(double *u, double *v);

#endif // _OUTILS_
