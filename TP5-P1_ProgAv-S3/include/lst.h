#ifndef _LST_T_
#define _LST_T_

#include "lst_elm.h"

#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions

struct lst_t {
    struct lst_elm_t *head;
    struct lst_elm_t *tail;
    int numelm;
};

/** Construire une liste vide */
struct lst_t *new_lst();

/** Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL, void (*ptrFct)());

/** Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L);

/** Ajouter en tête de la liste L la donnée */
void cons(struct lst_t *L, void *datum);

/** Ajouter en queue de la liste L la donnée */
void queue(struct lst_t *L, void *datum);

/** Insérer dans la liste L la donnée suivent l'ordre donné par la fonction pointée par ptrFct */
void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct)());

/** Consulter la tête de la liste */
struct lst_elm_t *getHead(struct lst_t *L);

/** Consulter la queue de la liste */
struct lst_elm_t *getTail(struct lst_t *L);

/** Consulter le nombre d'éléments rangés dans la liste */
int getNumelm(struct lst_t *L);

/** Modifier le nombre d'éléments rangés dans la liste */
void setNumelm(struct lst_t *L, int numElm);

/** Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void print_lst(struct lst_t *L, void (*ptrFct)());

#endif