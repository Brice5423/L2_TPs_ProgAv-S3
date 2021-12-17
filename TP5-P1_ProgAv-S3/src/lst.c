#include "lst.h"

struct lst_t *new_lst() {
    struct lst_t *L;

    L = (struct lst_t *) calloc(1, sizeof(struct lst_t));
    assert(L);

    return L;
}

void del_lst(struct lst_t **ptrL, void(*ptrFct)()) {
    struct lst_elm_t *E;

    E = (*ptrL)->head;
    while (E != NULL) {
        struct lst_elm_t *suc;

        suc = E->suc;
        free(E);
        E = suc;
    }

    free(*ptrL);
    *ptrL = NULL;
}

bool empty_lst(const struct lst_t *L) {
    assert(L);
    return L->numelm == 0;
}

void cons(struct lst_t *L, void *datum) {
    struct lst_elm_t *elm;

    elm = new_lst_elm(datum);

    if (L->numelm == 0) {
        L->tail = elm;
    }

    elm->suc = L->head;
    L->numelm++;
    L->head = elm;
}

void queue(struct lst_t *L, void *datum) {
    struct lst_elm_t *elm;

    elm = new_lst_elm(datum);

    if (L->numelm == 0) {
        L->head = elm;
    }

    L->tail->suc = elm;
    L->numelm++;
    L->tail = elm;
}

void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct)()) {
    if (empty_lst(L) || L->head->datum > datum) {
        cons(L, datum);

    } else if (datum >= L->tail->datum) {
        queue(L, datum);

    } else {
        struct lst_elm_t *look;
        struct lst_elm_t *elm;

        look = L->head;
        elm = new_lst_elm(datum);

        while ((*ptrFct)(look->suc->datum, datum)) {
            look = look->suc;
        }

        elm->suc = look->suc;
        look->suc = elm;
        L->numelm++;
    }
}

struct lst_elm_t *getHead(struct lst_t *L) {
    return L->head;
}

struct lst_elm_t *getTail(struct lst_t *L) {
    return L->tail;
}

int getNumelm(struct lst_t *L) {
    return L->numelm;
}

void setNumelm(struct lst_t *L, int numElm) {
    L->numelm = numElm;
}

void print_lst(struct lst_t *L, void (*ptrFct)()) {
    printf("[\n");
    for (struct lst_elm_t *E = L->head; E != NULL; E = E->suc) {
        (*ptrFct)(E->datum);
    }
    printf("]\n\n");
}
