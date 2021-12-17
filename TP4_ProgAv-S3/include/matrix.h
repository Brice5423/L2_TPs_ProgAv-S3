#ifndef _MATRIX_
#define _MATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>

struct matrix {
    double *values;
    int n;
    int m;
};

/**
 * Alloue la mémoire et initialise les champs m et n.
 */
struct matrix *consMatrix(int n, int m);

/**
 * Créer une copie exacte de la matrice M.
 */
struct matrix *cpyMatrix(struct matrix *M);

/**
 * Libère toute la mémoire occupée par *M et mais celle-ci à NULL.
 */
void freeMatrix(struct matrix **M);

/**
 * Visualise la matrice M après avoir affiché son entête.
 */
void viewMatrix(struct matrix *M, char *enTete);

/**
 * Saisit au clavier les données.
 */
struct matrix *scanMatrix();

struct matrix *addMatrix(struct matrix *A, struct matrix *B);

struct matrix *multMatrix(struct matrix *A, struct matrix *B);

/**
 * La structures FILE * (cf. fichier stdio.h et les exemples sur Arche)
 * Les opérateurs des fichiers textes (de la librairie stdio.h)
 */
struct matrix *matrixInput(char *fileName);

#endif