#ifndef _OUTILS_
#define _OUTILS_

#include <string.h>
#include <stdbool.h>

/** @brief Est ce que *a est plus grand que *b */
bool pg_int(int *a, int *b);

/** @brief Est ce que *x est plus grand que *y */
bool pg_double(double *x, double *y);

/** @brief Est ce que *s1 est plus grand que *s2 */
bool pg_string(char *s1, char *s2);

/** @brief Est ce que *a est plus petit que *b */
bool pp_int(int *a, int *b);

/** @brief Est ce que *x est plus petit que *y */
bool pp_double(double *x, double *y);

/** @brief Est ce que *s1 est plus petit que *s2 */
bool pp_string(char *s1, char *s2);

#endif