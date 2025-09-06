#include <stdio.h>
#include "etudiant.h"

int main(){
    Etudiant rk230026 = creer_etudiant_vide();
    Etudiant ml230027 = creer_etudiant(230027, "Martin", "Laurent", "ST-L3 INFORMATIQUE");
    printf("Informations personnelles\n|- Numero etu : %d\n|- Nom Prénom : %s %s\n|- Promo : %s\n\n",rk230026.numeroEtu, rk230026.nom, rk230026.prenom, rk230026.promo);
    printf("Informations personnelles\n|- Numero etu : %d\n|- Nom Prénom : %s %s\n|- Promo : %s\n\n ---- \n\n",ml230027.numeroEtu, ml230027.nom, ml230027.prenom, ml230027.promo);
    
    modifier_numero_etudiant(&ml230027, 230026);
    modifier_prenom_etudiant(&ml230027, "Anne-Sophie");
    printf("Informations personnelles\n|- Numero etu : %d\n|- Nom Prénom : %s %s\n|- Promo : %s\n\n",ml230027.numeroEtu, ml230027.nom, ml230027.prenom, ml230027.promo);

    modifier_numero_etudiant(&rk230026, 230026);
    modifier_prenom_etudiant(&rk230026, "Killian");
    modifier_nom_etudiant(&rk230026, "Reine");
    modifier_promo_etudiant(&rk230026, "ST L3 INFORMATIQUE");
    printf("Informations personnelles\n|- Numero etu : %d\n|- Nom Prénom : %s %s\n|- Promo : %s\n",rk230026.numeroEtu, rk230026.nom, rk230026.prenom, rk230026.promo);

    printf("FIN...\n");
    return 0;
}