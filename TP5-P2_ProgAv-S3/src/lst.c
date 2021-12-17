#include "lst.h"


struct lst *new_lst() {
    struct lst *L;

    L = (struct lst *) calloc(1, sizeof(struct lst));
    assert(L);
    L->head = NULL;
    L->tail = NULL;
    L->num_elm = 0;

    return L;
}

void del_lst(struct lst *L, void (*ptrF)()) {
    struct elm *E;

    E = L->head;

    while (E != NULL) {
        struct elm *suc;

        suc = E->suc;
        free(E);
        E = suc;
    }

    free(L);
    L = NULL;
}

bool empty_lst(struct lst *L) {
    assert(L);
    return L->num_elm == 0;
}

struct elm *get_head(struct lst *L) {
    return L->head;
}

struct elm *get_tail(struct lst *L) {
    return L->tail;
}

void cons(struct lst *L, void *data) {
    struct elm *E;

    E = new_elm(data);

    if (empty_lst(L)) {
        L->tail = E;
    } else {
        L->head->pred = E;
    }

    E->suc = L->head;
    L->num_elm++;
    L->head = E;
}

void queue(struct lst *L, void *data) {
    struct elm *E;

    E = new_elm(data);

    if (empty_lst(L)) {
        L->head = E;
    } else {
        L->tail->suc = E;
    }

    E->pred = L->tail;
    L->num_elm++;
    L->tail = E;
}

void insert_ord(struct lst *L, void *data, bool (*ptrF)()) {
    if (empty_lst(L) || (*ptrF)(L->head->data, data)) {
        cons(L, data);

    } else if ((*ptrF)(data, L->tail->data)) {
        queue(L, data);

    } else {
        struct elm *look;
        struct elm *E;

        look = L->head;
        E = new_elm(data);

        while ((*ptrF)(look->suc->data, data)) {
            look = look->suc;
        }

        E->suc = look->suc;
        look->suc = E;
        L->num_elm++;
    }
}

void view_lst(struct lst *L, void (*ptrF)()) {
    printf("\n");
    for (struct elm *E = L->head; E != NULL; E = E->suc) {
        (*ptrF)(E->data);
        printf("\n");
    }
    printf("\n");
}