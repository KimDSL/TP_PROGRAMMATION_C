#ifndef __MY_MATH_LIB_H
#define __MY_MATH_LIB_H

// Définition de la structure Date
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

// Définition de la structure Etudiant
typedef struct
{
    char matricule[20];
    char nom[30];
    char prenom[30];
    Date dateNaissance;
    char departement[30];
    char filiere[30];
    int niveau;
    char sexe[10];
    char region[30];
} Etudiant;

// Définition de la fonction pour récupérer la date actuelle
void dateActuelle(Date *date);

// Défiinition de la fonction pour calculer l'âge
int calculerAge(Date dateNaissance, Date dateActuelle);

// Définition de la fonction pour ajouter un étudiant
void ajouterEtudiant(Etudiant **tab, int *n);

// Définition de la fonction pour modifier un étudiant
void modifierEtudiant(Etudiant *tab, int n, const char *matricule);

// Définition de la fonction pour supprimer un étudiant
void supprimerEtudiant(Etudiant **tab, int *n, const char *matricule);

// Définition de la fonction pour afficher les étudiants
void afficherEtudiants(const Etudiant *tab, int n);

// Définition de la fonction pour rechercher un étudiant par matricule
Etudiant* rechercherEtudiantParMatricule(const Etudiant *tab, int n, const char *matricule);

// Définition de la fonction pour trier les étudiants par nom
void trierEtudiantsParNom(Etudiant *tab, int n);

// Défininition de la fonction pour une reccherche dichotomique par nom
Etudiant* rechercheDichotomiqueParNom(const Etudiant *tab, int n, const char *nom);

// Définition de la fonction pour trier par filiere
void trierEtudiantsParFiliere(Etudiant *tab, int n);

#endif 
