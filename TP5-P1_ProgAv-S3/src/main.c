#include "lst.h"
#include "outils.h"

void listeHomoReelle();

void listeHomoEntiere();

int main() {
    int cmpt;
    int a;
    int b;
    int *ptra;
    int *ptrb;

    double x;
    double y;
    double *ptrx;
    double *ptry;

    struct lst_t *L;
    struct lst_elm_t *E;

    /* donne les valeurs aux différentes variables */
    a = 8;
    b = 4;
    ptra = &a;
    ptrb = &b;

    x = 5.4;
    y = 3.14;
    ptrx = &x;
    ptry = &y;

    L = new_lst();

    /* Création de liste entière */
    cons(L, ptra);
    cons(L, ptrb);

    /* Création de liste réelle */
    cons(L, ptrx);
    cons(L, ptry);

    /* La liste vaut [3.14 ; 5.4 ; 4 ; 8 ] */
    for (cmpt = 0, E = getHead(L); cmpt < getNumelm(L); cmpt += 1, E = getSuc(E)) {
        if (cmpt < 2) {
            double *d;
            d = (double *) getDatum(E);
            printDouble(d);

        } else {
            int *d;
            d = (int *) getDatum(E);
            printInteger(d);
        }
    }

    /* ***** ***** Test : listeHomoReelle() & listeHomoEntiere() ***** ***** */
    printf("\n\t- - - - - listeHomoReelle - - - - -\n");
    listeHomoReelle();
    printf("\n\t- - - - - ListeHomeEntiere - - - - -\n");
    listeHomoEntiere();

    return EXIT_SUCCESS;
}

void listeHomoReelle() {
    struct lst_t *L;
    double *v;
    double u;

    L = new_lst();

    do {
        printf("Entrez un réel (O pour s'arrêter): ");
        scanf("%lf", &u);
        if (u == 0) {
            break;
        }

        v = (double *) calloc(1, sizeof(double));
        *v = u;

        insert_ordered(L, v, &cmpDouble);
    } while (true);

    print_lst(L, &printDouble);
    del_lst(&L, &rmDouble);
}

void listeHomoEntiere() {
    struct lst_t *L;
    int *v;
    int u;

    L = new_lst();

    do {
        printf("Entrez un entier (O pour s'arrêter): ");
        scanf("%d", &u);
        if (u == 0) {
            break;
        }

        v = (int *) calloc(1, sizeof(int));
        *v = u;

        insert_ordered(L, v, &cmpInteger);
    } while (true);

    print_lst(L, &printInteger);
    del_lst(&L, &rmInteger);
}