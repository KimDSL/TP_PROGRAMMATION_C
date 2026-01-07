#include "etudiant.h"

// Définition de la fonction pour initialiser la structure de gestion
void initialiserGestion(GestionEtudiants *gestion, int capacite){
    
    gestion->liste =  malloc(sizeof(Etudiant) * capacite);

    if(gestion->liste == NULL){
        fprintf(stderr, "Erreur d'allocation memoire\n");
        exit(EXIT_FAILURE); 
    }
}
// Définition de la fonction pour libérer la mémoire allouée pour la gestion
void libererGestion(GestionEtudiants *gestion)
{
    free(gestion->liste);
    gestion->liste = NULL;
    gestion->nombre = 0;
    gestion->capacite = 0;
}

// Définition de la fonction pour augmenter la capacite du tableau quand il est plein
int redimensionnerGestion(GestionEtudiants *gestion)
{
    int nouvelleCapacite = gestion->capacite * 2;
    Etudiant *nouvelleListe = realloc(gestion->liste, sizeof(Etudiant) * nouvelleCapacite);

    if (nouvelleListe == NULL){
        fprintf(stderr, "Erreur : Echec de la reallocation memoire\n");
        return 0;
    }

    gestion->liste = nouvelleListe;
    gestion->capacite = nouvelleCapacite;
    printf("Info : Capacite augmentee a %d\n", nouvelleCapacite);
    return 1;
}

// Définition de la fonction pour afficher les details d'un etudiant
void afficherEtudiant(Etudiant etudiant, int index){
    printf("Etudiant %d\n", index);
    printf("Matricule : %s\n", etudiant.matricule);
    printf("Nom : %s %s\n", etudiant.nom, etudiant.prenom);
    printf("Date de naissance : %02d/%02d/%04d\n",etudiant.dateNaissance.jour,etudiant.dateNaissance.mois,etudiant.dateNaissance.annee);
    printf("Genre : %c\n", etudiant.genre);
    printf("Departement : %s\n", etudiant.departement);
    printf("Option : %s\n", etudiant.option);
    printf("Region d'origine : %s\n", etudiant.regionOrigine);
    printf("Niveau : %d\n", etudiant.niveau);
}

// Définition de la fonction pour afficher tous les etudiants stockés
void afficherTousLesEtudiants(GestionEtudiants *gestion){
    for (int i = 0; i < gestion->nombre; i++){
        afficherEtudiant(gestion->liste[i], i);
        printf("----------------------\n");
    }
}

// Définition de la fonction pour comparer deux etudiants par matricule pour la recherche dichotomique
int comparerEtudiantsParMatricule(const void *a, const void *b){
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return strcmp(etudiantA->matricule, etudiantB->matricule);
}

// Définition de la fonction pour comparer deux etudiants par nom pour le tri par ordre alphabetique
int comparerEtudiantsParNom(const void *a, const void *b){
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return strcmp(etudiantA->nom, etudiantB->nom);
}

// Définition de la fonction pour comparer deux etudiants par option pour le tri par option
int comparerEtudiantsParOption(const void *a, const void *b){
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return strcmp(etudiantA->option, etudiantB->option);
}

// Définition de la fonction pour comparer deux etudiants par departement pour le tri par departement
int comparerEtudiantsParDepartement(const void *a, const void *b){
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return strcmp(etudiantA->departement, etudiantB->departement);
}

// Définition de la fonction pour comparer deux etudiants par niveau pour le tri par niveau
int comparerEtudiantsParNiveau(const void *a, const void *b){
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return etudiantA->niveau - etudiantB->niveau;
}