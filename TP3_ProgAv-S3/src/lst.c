//
// Created by brice on 15/10/2021.
//

#include "lst.h"


/* ***** ***** DIFINITION DES FONCTIONS ASSOCIÉES ***** ***** */

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

    struct lst_elm_t *E;
    E = new_lst_elm(v);
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

/** @brief La fonction prend trois arguments :
 * La liste "L" est modifiée par l’insertion de la valeur entière "value" après l’emplacement désigné par "place". */
void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place) {
    if (place == NULL)
        cons(L, value);
    else {
        struct lst_elm_t *newElm;
        newElm = new_lst_elm(value);
        assert(newElm);

        newElm->suc = place->suc;
        place->suc = newElm;
        L->numelm++;

        if (place == L->tail)
            L->tail = newElm;
    }
}

/** @brief La fonction insère dans l’ordre croissant la valeur entière value dans la liste L. */
void insert_ordered(struct lst_t *L, const int value) {

}