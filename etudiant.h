#ifndef EDTUDIANT_H
#define ETUDIANT_H

typedef struct TD TD; 

typedef struct{
    int numeroEtu;
    char* nom;
    char* prenom;
    char* promo;
    TD* td;
} Etudiant;

// Création d'un étudiant
Etudiant creer_etudiant_vide();
Etudiant creer_etudiant(int, char*, char*, char*);

// Opérations de bases sur un étudiant
int modifier_numero_etudiant(Etudiant*, int);
int modifier_nom_etudiant(Etudiant*, char*);
int modifier_prenom_etudiant(Etudiant*, char*);
int modifier_promo_etudiant(Etudiant*, char*);

// Affichage de l'étudiant
void afficher_etudiant(Etudiant);
void afficher_td_etudiant(Etudiant);

// Opérations avancées sur un étudiant
int est_dans_td(Etudiant, TD);
int supprimer_td(Etudiant, TD);
int ajouter_td(Etudiant, TD);

// Création de l'enregistrement donné à la bdd
char* creer_enregistrement(Etudiant);

// Supprimer détruire l'étudiant
int liberer_etudiant(Etudiant);

#endif