#include "traiter_fichier.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Fonctionnalité : SELECT * FROM Etudiant WHERE numeroEtu = _numeroEtu
 * @param
 *      char*       path            >>> Le chemin du fichier dans lequel on recherche l'étudiant
 *      int         _numeroEtu      >>> Le numéro de l'étudiant a à sélectionner
 * @return
 *      Etudiant                    >>> L'étudiant trouvé (ou NULL dans le cas échéant)
 */
Etudiant* select_etudiant_by_num(char* path, int _numeroEtu){
    FILE* fichier = fopen(path, "r");
    if(!fichier){
        perror("Erreur d'ouverture de fichier");
        exit(EXIT_FAILURE);
    }
    char ligne[256];
    while(fgets(ligne, sizeof(ligne), fichier)){
        ligne[strcspn(ligne, "\n")]='\0';

        char* token = strtok(ligne, ";");
        if(!token) continue;

        int numero = atoi(token);
        char* nom = strtok(NULL, ";");
        char* prenom = strtok(NULL, ";");
        char* promo = strtok(NULL, ";");

        if(numero==_numeroEtu){
            Etudiant* e = malloc(sizeof(Etudiant));
            if(!e){
                perror("erreur dans le malloc");
                exit(EXIT_FAILURE);
            }
            e->numeroEtu = _numeroEtu;
            e->prenom = prenom;
            e->nom = nom;
            e->promo = promo;
            
            fclose(fichier);

            return e;
        }
    }
    fclose(fichier);
    return NULL;
}

/**
 * Fonctionalité : Ajout d'un étudiant dans la base de données etudiant.txt
 * @param
 *      char*       path        >>> Le chemin du fichier
 *      Etudiant    etu         >>> L'étudiant à ajouter
 * @return
 *      int         (boolean)   >>> L'étudiant a t-il été ajouté
 */
int ajouter_etudiant_liste(char* path, Etudiant etu){
    // Si l'étudiant est déjà dans la liste, on l'ajoute pas
    if(select_etudiant_by_num(path, etu.numeroEtu)){
        printf("L'étudiant est déjà dans la liste\n");
        return -1;
    }

    FILE* fichier = fopen(path, "a");
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