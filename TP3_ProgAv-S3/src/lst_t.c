//
// Created by brice on 15/10/2021.
//

#include "lst_t.h"

/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L) {
    assert(L);
    return L->numelm == 0;
}

/** @brief Construire une liste vide */
struct lst_t *new_lst() {
    /** @note : calloc fonctionne de manière identique à malloc
    	et de surcroît met à NULL(0) tous les octets alloués */
    struct lst_t *L = (struct lst_t *) calloc(1, sizeof(struct lst_t));
    assert(L);
    return L;
}

/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t *L, int v) {
    assert(L);
    struct lst_elm_t *E = new_lst_elm(v);
    assert(E);
    E->suc = L->head;
    L->head = E;
    if (L->numelm == 0)
        L->tail = E;
    L->numelm++;
}

/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t *L) {
    printf("[ ");
    for (struct lst_elm_t *E = L->head; E; E = E->suc) {
        printf("%d ", E->x);
    }
    printf("]\n\n");
}

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL) {
    assert(ptrL && *ptrL);
    free(*ptrL);
    *ptrL = NULL;
}
