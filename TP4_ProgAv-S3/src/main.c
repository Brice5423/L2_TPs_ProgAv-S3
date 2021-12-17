#include"pair.h"

int main() {
    int a;
    bool peutAdd;
    bool peutMult;

    a = 0;
    peutAdd = false;
    peutMult = false;

    struct matrix *A = matrixInput("data/A.txt");
    struct matrix *B = matrixInput("data/B.txt");

    viewMatrix(A, "A");
    viewMatrix(B, "B");

    // vérifie si on peut faire une addition
    if (A->m == B->m && A->n == B->n) {
        peutAdd = true;
    }
    // vérifie si on peut faire une multiplication
    if (A->n == B->m) {
        peutMult = true;
    }

    if (peutAdd && peutMult) { // si peutAdd et peutMult sont vrais
        printf("\nQue voulez-vous faire de ces matrices ?\n\t1 : additionner\n\t2 : multiplier\n\t3 : additionner et multiplier\n");
        scanf("%d", &a);

    } else if (peutAdd) { // sinon si peutAdd est vrai
        printf("\nLa seul opération possible est l'addition\n");
        a = 1;

    } else { // sinon si peutMult est vrai
        printf("\nLa seul opération possible est la multiplication\n");
        a = 2;
    }

    if (a == 1 || a == 3) {
        viewMatrix(addMatrix(A, B), "A+B");
    }

    if (a == 2 || a == 3) {
        viewMatrix(multMatrix(A, B), "A*B");
        viewMatrix(multMatrix(B, A), "B*A");
    }

    return EXIT_SUCCESS;
}