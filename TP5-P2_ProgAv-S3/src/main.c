#include "form.h" // fait appel de : outils.h & (db.h -> lst.h -> elm.h)

int main() {
    struct form *(*ptr_read)(FILE *, enum mode) =&read_form;
    void (*ptr_view)(struct form *) =&view_form;
    void (*ptr_write)(struct form *, enum mode, FILE *) =&write_form;
    void (*ptr_del)(struct form *) =&del_form;
    struct lst *L = read_lst(TEXT, (void *(*)()) ptr_read, ptr_del);

    view_lst(L, ptr_view);
    write_lst(L, BINARY, ptr_write);
    del_lst(L, ptr_del);

    L = read_lst(BINARY, (void *(*)()) ptr_read, ptr_del);
    view_lst(L, ptr_view);
    del_lst(L, ptr_del);

    return EXIT_SUCCESS;
}