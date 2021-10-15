//
// Created by brice on 15/10/2021.
//

#include "lst_elm_t.h"
#include "lst_t.h"

int main() {
    int v;
    struct lst_t *L = new_lst();
    scanf("%d", &v);
    while (v > 0) {
        cons(L, v);
        scanf("%d", &v);
    }
    print_lst(L);
    del_lst(&L);
    return EXIT_SUCCESS;
}