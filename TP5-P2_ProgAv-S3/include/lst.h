#ifndef _LST_
#define _LST_

#include "elm.h"

struct lst {
    struct elm *head;
    struct elm *tail;
    int num_elm;
};

/** @brief Créer une liste */
struct lst *new_lst();

/** @brief Libérer une liste */
void del_lst(struct lst *L, void (*ptrF)());

/** @brief Est ce que la liste est vide ? */
bool empty_lst(struct lst *L);

/** @brief Donner la tête */
struct elm *get_head(struct lst *L);

/** @brief Donner la queue */
struct elm *get_tail(struct lst *L);

/** @brief Ajouter en tête */
void cons(struct lst *L, void *data);

/** @brief Ajouter en queue */
void queue(struct lst *L, void *data);

/** @brief Insert à la place pointé ptrF */
void insert_ord(struct lst *L, void *data, bool (*ptrF)());

/** @brief Afficher la liste */
void view_lst(struct lst *L, void (*ptrF)());

#endif