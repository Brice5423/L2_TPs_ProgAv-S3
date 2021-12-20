#ifndef _DB_
#define _DB_

#include "lst.h"

/** @brief Type de fichier : texte ou binaire */
enum mode {
    TEXT, BINARY
};

/** @brief Ecrire une liste lst dans un fichier texte ou binaire selon le mode */
void write_lst(struct lst *L, enum mode m, void (*ptrF)());

/** @brief Transcrire en liste d'un fichier texte ou binaire selon le mode */
struct lst *read_lst(enum mode m, void *(*ptrF)(), void (ptr_del)());

#endif