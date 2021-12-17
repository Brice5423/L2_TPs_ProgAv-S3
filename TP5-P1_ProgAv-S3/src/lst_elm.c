#include "lst_elm.h"


struct lst_elm_t *new_lst_elm(void *datum) {
    struct lst_elm_t *elm;

    elm = (struct lst_elm_t *) calloc(1, sizeof(struct lst_elm_t));
    elm->datum = datum;
    elm->suc = NULL;

    return elm;
}

void del_lst_elm(struct lst_elm_t **ptrE) {
    free(*ptrE);
    *ptrE = NULL;
}

void *getDatum(struct lst_elm_t *E) {
    return E->datum;
}

struct lst_elm_t *getSuc(struct lst_elm_t *E) {
    return E->suc;
}

void setDatum(struct lst_elm_t *E, void *datum) {
    E->datum = datum;
}

void setSuc(struct lst_elm_t *E, struct lst_elm_t *S) {
    E->suc = S;
}