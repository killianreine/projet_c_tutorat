#include "traiter_fichier.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int ajouter_etudiant(Etudiant etu){
    FILE* fichier = fopen("src/etudiant.txt", "a");
    if(!fichier){
        printf("Erreur d'ouverture de fichier");
        return -1;
    }
    char* enregistrement = creer_enregistrement(etu);
    fputs(enregistrement, fichier);
    
    free(enregistrement);
    fclose(fichier);

    printf("Etudiant ajouté avec succès\n");
    return 1;
}