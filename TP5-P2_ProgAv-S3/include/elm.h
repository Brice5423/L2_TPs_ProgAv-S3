#ifndef _ELM_
#define _ELM_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct elm {
    void *data;
    struct elm *suc;
    struct elm *pred;
};

/** @brief Créer un élément avec sa data de dans */
struct elm *new_elm(void *data);

/** @brief Supprimer un élément */
void del_elm(struct elm *E, void (*ptrF)());

/** @brief Donner le successeur de l'élément */
struct elm *get_suc(struct elm *E);

/** @brief Donner le prédécesseur */
struct elm *get_pred(struct elm *E);

/** @brief Donner la data */
void *get_data(struct elm *E);

/** @brief Changer le successeur */
void set_suc(struct elm *E, struct elm *S);

/** @brief Changer le prédécesseur */
void set_pred(struct elm *E, struct elm *P);

/** @brief Changer la data */
void set_data(struct elm *E, void *data);

/** @brief Afficher l'élément
 * 2ème paramètre : fonction a 1 paramètre (prend E) */
void view_elm(struct elm *E, void (*ptrF)());

#endif