#include "db.h"

void write_lst(struct lst *L, enum mode m, void(*ptrF)()) {
    FILE *fd;
    char fname[20];

    if (m == TEXT) {
        printf("\tÉcrire une liste dans un fichier texte (.txt)\n\t\tNom du fichier : ");
        scanf("%s", fname);
        fd = fopen(fname, "wt");

    } else {
        printf("\tÉcrire une liste dans un fichier binaire (.bin)\n\t\tNom du fichier : ");
        scanf("%s", fname);
        fd = fopen(fname, "wb");
    }
    assert(fd);

    for (struct elm *look = L->head; look != NULL; look = look->suc) {
        ptrF(look->data, m, fd);
    }
    fclose(fd);
}

struct lst *read_lst(enum mode m, void *(*ptrF)(), void (ptr_del)()) {
    FILE *fd;
    char fname[20];

    if (m == TEXT) {
        printf("\tLire une liste dans un fichier texte (.txt)\n\t\tNom du fichier : ");
        scanf("%s", fname);
        fd = fopen(fname, "rt");

    } else {
        printf("\tLire une liste dans un fichier binaire (.bin)\n\t\tNom du fichier : ");
        scanf("%s", fname);
        fd = fopen(fname, "rb");
    }

    assert(fd);
    struct lst *L = new_lst();

    while (!feof(fd)) {
        queue(L, ptrF(fd, m));
    }

    struct elm *E = get_tail(L);
    struct elm *T = get_pred(E);

    set_suc(T, NULL);
    L->tail = T;
    del_elm(E, ptr_del);

    fclose(fd);
    return L;
}
