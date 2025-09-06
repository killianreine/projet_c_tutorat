#ifndef TRAITER_FICHIER_H
#define TRAITER_FICHIER_H

#include "etudiant.h"

typedef char* string;

// Opération sur un fichier
string* rechercher_motif(string); 
int etudiant_existant(Etudiant);

// Opération étudiant
int ajouter_etudiant(Etudiant);
int supprimer_etudiant(Etudiant*);


#endif