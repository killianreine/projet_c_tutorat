#include "etudiant.h" // Printf par exemple
#include <stdlib.h> // NULL, Malloc, calloc, free, realloc, ...
#include <stdio.h>
#include <string.h>

/**
 * Fonction permettant de créer un étudiant sans informations
 * @param
 * @return
 *      Etudiant >>> l'étudiant qui vient d'être créé
 */
Etudiant creer_etudiant_vide(){
    Etudiant etu;
    Etudiant* ptrEtu = &etu; // Accès via pointeur

    // Initialisation des infos
    ptrEtu -> numeroEtu = -1;
    ptrEtu -> prenom = NULL;
    ptrEtu -> nom = NULL;
    ptrEtu -> promo = NULL;
    ptrEtu -> td = NULL;

    return etu;
}

/**
 * Fonction permettant de creer un étudiant avec ses informations
 * @param
 *      int         nEtu    >>> numéro de l'étudiant (identifiant)
 *      char*       nom     >>> nom de l'étudiant
 *      char*       prenom  >>> prénom de l'étudiant
 *      char*       promo   >>> promotion d'affectation de l'étudiant
 * @return
 *      Etudiant            >>> l'étudiant créé
 */
Etudiant creer_etudiant(int nEtu, char* nom, char* prenom, char* promo){
    Etudiant etu;
    Etudiant* ptrEtu = &etu; // Accès via pointeur

    // Initialisation des infos
    ptrEtu -> numeroEtu = nEtu;

    // Déclaration des tableaux dynamique des chmaps
    ptrEtu -> prenom = malloc(strlen(nom));
    ptrEtu -> nom = malloc(strlen(prenom));
    ptrEtu -> promo = malloc(strlen(promo));

    // Initialisation des champs
    strcpy(ptrEtu -> prenom, prenom);
    strcpy(ptrEtu -> nom, nom);
    strcpy(ptrEtu -> promo, promo);
    ptrEtu -> td = NULL;

    return etu;
}

/**
 * Fonction permettant de modifier le numéro d'un étudiant
 * @param
 *      Etudiant    etu             >>> l'étudiant
 *      int         _numeroEtu      >>> le nouveau numéro a associé à etu
 * @return
 *      int         (booléen)       >>> 1=succès ; 0=échec
 */
int modifier_numero_etudiant(Etudiant* ptrEtu, int _numeroEtu){
    // TODO : Regarder si un étudiant enrengistré possède déjà la numéro
    // REQUIRE : Gestion du fichier de stockage des étudiants
    ptrEtu -> numeroEtu = _numeroEtu;
    return 1; 
}

/**
 * Fonction permettant de modifier le prénom d'un étudiant
 * @param
 *      Etudiant*   ptrEtu          >>> Le pointeur vers l'étudiant
 *      char*       _prenomEtu      >>> Le nouveau prénom de l'étudiant
 * @return
 *      int         (booléen)       >>> 1=succès ; 0=échec
 */
int modifier_prenom_etudiant(Etudiant* ptrEtu, char* _prenomEtu){
    // Nouveau tableau dynamique temporaire pour le nouveau prénom
    char* temp = malloc(strlen(_prenomEtu)+1);
    if(!temp){
        // Une erreur
        return 0;
    }
    free(ptrEtu->prenom);
    ptrEtu->prenom=temp;
    strcpy(ptrEtu->prenom, _prenomEtu);
    return 1;
}

/**
 * Fonction permettant de modifier le nom d'un étudiant
 * @param
 *      Etudiant*   ptrEtu          >>> Le pointeur vers l'étudiant
 *      char*       _nomEtu      >>> Le nouveau nom de l'étudiant
 * @return
 *      int         (booléen)       >>> 1=succès ; 0=échec
 */
int modifier_nom_etudiant(Etudiant* ptrEtu, char* _nomEtu){
    // Nouveau tableau dynamique temporaire pour le nouveau nom
    char* temp = malloc(strlen(_nomEtu)+1);
    if(!temp){
        // Une erreur
        return 0;
    }
    free(ptrEtu->nom);
    ptrEtu->nom=temp;
    strcpy(ptrEtu->nom, _nomEtu);
    return 1;
}

/**
 * Fonction permettant de modifier la promotion d'un étudiant
 * @param
 *      Etudiant*   ptrEtu          >>> Le pointeur vers l'étudiant
 *      char*       _promoEtu      >>> La nouvelle promotion de l'étudiant
 * @return
 *      int         (booléen)       >>> 1=succès ; 0=échec
 */
int modifier_promo_etudiant(Etudiant* ptrEtu, char* _promoEtu){
    // Nouveau tableau dynamique temporaire pour la nouvelle promo
    char* temp = malloc(strlen(_promoEtu)+1);
    if(!temp){
        // Une erreur
        return 0;
    }
    free(ptrEtu->promo);
    ptrEtu->promo=temp;
    strcpy(ptrEtu->promo, _promoEtu);
    return 1;
}

char* creer_enregistrement(Etudiant etu){
    size_t taille = sizeof(etu.prenom)+sizeof(etu.promo)+sizeof(etu.nom)+30;
    char* enregistrement = malloc(taille);
    if(!enregistrement){
        perror("Erreur dans le malloc");
        exit(EXIT_FAILURE);
    }
    sprintf(enregistrement, "%d;%s;%s;%s\n", etu.numeroEtu, etu.nom, etu.prenom, etu.promo);
    return enregistrement;
}