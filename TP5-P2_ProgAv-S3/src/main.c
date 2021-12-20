#include "form.h" // fait appel de : outils.h & (db.h -> lst.h -> elm.h)

int main() {
    // formulaire lu à partir du pointeur de fonction de fichier
    struct form *(*ptr_read)(FILE *, enum mode) = &read_form;
    // pointeur de fonction de vue de formulaire
    void (*ptr_view)(struct form *) = &view_form;
    // forme écrire dans le fichier pointeur de fonction
    void (*ptr_write)(struct form *, enum mode, FILE *) = &write_form;
    // pointeur de fonction de suppression de formulaire
    void (*ptr_del)(struct form *) = &del_form;

    // créer une liste de formulaires à partir d'un fichier texte/binaire
    struct lst *L = read_lst(TEXT, (void *(*)()) ptr_read, ptr_del);

    // voir la liste des formulaires
    view_lst(L, ptr_view);
    // écrire la liste de formulaires dans un fichier texte/binaire
    write_lst(L, BINARY, ptr_write);
    // supprimer la liste des formulaires
    del_lst(L, ptr_del);

    // créer une liste de formulaires à partir d'un fichier texte/binaire
    L = read_lst(BINARY, (void *(*)()) ptr_read, ptr_del);
    // voir la liste des formulaires
    view_lst(L, ptr_view);

    // supprimer la liste des formulaires
    del_lst(L, ptr_del);

    return EXIT_SUCCESS;
}