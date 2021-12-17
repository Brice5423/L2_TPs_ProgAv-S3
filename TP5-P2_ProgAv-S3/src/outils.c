#include "outils.h"

bool pg_int(int *a, int *b) {
    return a > b;
}

bool pg_double(double *x, double *y) {
    return x > y;
}

bool pg_string(char *s1, char *s2) {
    return strcmp(s1, s2) > 0;
}

bool pp_int(int *a, int *b) {
    return a < b;
}

bool pp_double(double *x, double *y) {
    return x < y;
}

bool pp_string(char *s1, char *s2) {
    return strcmp(s1, s2) < 0;
}