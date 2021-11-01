//
// Created by brice on 15/10/2021.
//

#include "lst_elm.h"
#include "lst.h"

int main() {
    int v;
    struct lst_t *L = new_lst();

    printf("Donnée une valeur < à 0 pour mettre fin.\n");
    scanf("%d", &v);
    while (v > 0) {
        cons(L, v);
        scanf("%d", &v);
    }
    print_lst(L);

    insert_after(L, 666, L->head->suc);
    print_lst(L);

    del_lst(&L);
    return EXIT_SUCCESS;
}