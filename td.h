#ifndef TD_H
#define TD_H

typedef struct Etudiant Etudiant; 

typedef struct{
    char* nomTD;
    Etudiant* etudiants;
} TD;

// Création
TD creer_td(char*);

// Opérations de base
int ajouter_etudiant(TD, Etudiant);
int ajouter_liste_etudiant(TD, Etudiant**);
int supprimer_etudiant(TD, Etudiant);

Etudiant rechercher_etudiant(TD, Etudiant);

#endif