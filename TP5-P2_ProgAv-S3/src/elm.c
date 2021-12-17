#include "elm.h"

struct elm *new_elm(void *data) {
    struct elm *E;

    E = (struct elm *) calloc(1, sizeof(struct elm));
    E->data = data;
    E->pred = NULL;
    E->suc = NULL;

    return E;
}

void del_elm(struct elm *E, void (*ptrF)()) {
    ptrF(E);
}

struct elm *get_suc(struct elm *E) {
    return E->suc;
}

struct elm *get_pred(struct elm *E) {
    return E->pred;
}

void *get_data(struct elm *E) {
    return E->data;
}

void set_suc(struct elm *E, struct elm *S) {
    E->suc = S;
}

void set_pred(struct elm *E, struct elm *P) {
    E->pred = P;
}

void set_data(struct elm *E, void *data) {
    E->data = data;
}

void view_elm(struct elm *E, void (*ptrF)()) {
    ptrF(E);
}