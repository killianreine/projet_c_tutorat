#include <stdio.h>
#include "traiter_fichier.h"

int main(){
    Etudiant ml230027 = creer_etudiant(230027, "Martin", "Laurent", "ST-L3 INFORMATIQUE");
    Etudiant rk230026 = creer_etudiant(230026, "Reine", "Killian", "ST-L3 INFORMATIQUE");
    //ajouter_etudiant(ml230027);
    ajouter_etudiant(rk230026);
    printf("FIN...\n");
    return 0;
}