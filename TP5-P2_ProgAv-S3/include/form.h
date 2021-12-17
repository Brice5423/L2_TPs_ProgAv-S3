#ifndef _FORM_
#define _FORM_

#include "db.h"
#include "outils.h"

#define len_max 20

struct form {
    char product[len_max];
    int stock;
    double pbt;
};

/** @brief Supprimer un formulaire */
void del_form(struct form *F);

/** @brief Lire un formulaire dans un fichier */
struct form *read_form(FILE *fd, enum mode m);

/** @brief Écrire un formulaire dans un fichier */
void write_form(struct form *F, enum mode m, FILE *fd);

/** @brief Donner le nom dans le formulaire */
char *get_product(struct form *F);

/** @brief Donner le stock dans le formulaire */
int get_stock(struct form *F);

/** @brief Donner le prix dans le formulaire */
double get_price(struct form *F);

/** @brief Afficher le formulaire */
void view_form(struct form *F);

/** @brief Est ce que le nom de F1 est plus petit ou égal au nom de F2 */
bool pg_form(struct form *F1, struct form *F2);

#endif