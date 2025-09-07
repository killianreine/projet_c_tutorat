#include <stdio.h>
#include "traiter_fichier.h"

int main(){
    Etudiant ml230027 = creer_etudiant(230027, "Martin", "Laurent", "ST-L3 INFORMATIQUE");
    Etudiant rk230026 = creer_etudiant(230026, "Reine", "Killian", "ST-L3 INFORMATIQUE");
    ajouter_etudiant_liste("src/L3-INFO.txt", ml230027);
    //ajouter_etudiant_liste("src/L3-INFO.txt", rk230026);

    Etudiant* etu = select_etudiant_by_num("src/L3-INFO.txt", 230026);
    
    printf("L'étudiant : %s", (etu)?"a été trouvé.\n":"n'a pas été trouvé.\n");

    printf("FIN...\n");
    return 0;
}