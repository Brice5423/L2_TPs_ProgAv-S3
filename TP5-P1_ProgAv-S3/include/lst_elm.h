#ifndef _LST_ELM_T_
#define _LST_ELM_T_

#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> // librairie d'assertions

struct lst_elm_t {
    void *datum;
    struct lst_elm_t *suc;
};

/* @brief Créer un élément de liste et y ranger la donnée */
struct lst_elm_t *new_lst_elm(void *datum);

/* @brief Supprimer un élément de liste et mettre son pointeur à NULL */
void del_lst_elm(struct lst_elm_t **ptrE);

/* @brief Renvoyer la donnée de l'élément */
void *getDatum(struct lst_elm_t *E);

/* @brief Renvoyer le pointeur sur le successeur de l'élément */
struct lst_elm_t *getSuc(struct lst_elm_t *E);

/* @brief Modifier la donnée de l'élément */
void setDatum(struct lst_elm_t *E, void *datum);

/* @brief Modifier le pointeur sur le successeur de l'élément */
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);

#endif