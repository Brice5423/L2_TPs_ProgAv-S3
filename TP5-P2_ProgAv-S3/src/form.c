#include "form.h"

void del_form(struct form *F) {
    free(F);
    F = NULL;
}

struct form *read_form(FILE *fd, enum mode m) {
    struct form *F;

    F = (struct form *) calloc(1, sizeof(struct form));

    if (m == TEXT) {
        fscanf(fd, " %s", F->product);
        F->product[len_max - 1] = '\0';
        fscanf(fd, " %d", &(F->stock));
        fscanf(fd, " %lf", &(F->pbt));

    } else {
        fread(F, sizeof(struct form), 1, fd);
    }

    return F;
}

void write_form(struct form *F, enum mode m, FILE *fd) {
    if (m == TEXT) {
        fprintf(fd, "%s\n", F->product);
        fprintf(fd, "%d\n", F->stock);
        fprintf(fd, "%lf\n", F->pbt);

    } else {
        fwrite(F, sizeof(struct form), 1, fd);
    }
}

char *get_product(struct form *F) {
    return F->product;
}

int get_stock(struct form *F) {
    return F->stock;
}

double get_price(struct form *F) {
    return F->pbt;
}

void view_form(struct form *F) {
    printf("%s\n", F->product);
    printf("%d\n", F->stock);
    printf("%lf\n", F->pbt);
}

bool pg_form(struct form *F1, struct form *F2) {
    return (!(pg_string(F1->product, F2->product)));
}
