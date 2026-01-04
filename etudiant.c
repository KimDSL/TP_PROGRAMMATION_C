#include "etudiant.h"

// Définition de la fonction pour initialiser la structure de gestion
void initialiserGestion(GestionEtudiants *gestion, int capacite)
{
    /* Allouer la memoire pour le tableau d'etudiants */
    gestion->liste = (Etudiant *)malloc(sizeof(Etudiant) * capacite);

    /* Verifier si l'allocation a reussi */
    if (gestion->liste == NULL)
    {
        fprintf(stderr, "Erreur : Echec de l'allocation memoire\n");
        exit(EXIT_FAILURE);
    }

    gestion->nombre = 0;
    gestion->capacite = capacite;
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
    // Calcul de la nouvelle capacité
    int nouvelleCapacite = gestion->capacite * 2;

    // Reallocation de la memoire avec la nouvelle capacite 
    Etudiant *nouvelleListe = (Etudiant *)realloc(gestion->liste,
                                                  sizeof(Etudiant) * nouvelleCapacite);

    // Verification de si la reallocation a reussi
    if (nouvelleListe == NULL)
    {
        fprintf(stderr, "Erreur : Echec de la reallocation memoire\n");
        return 0;
    }

    gestion->liste = nouvelleListe;
    gestion->capacite = nouvelleCapacite;
    printf("Info : Capacite augmentee a %d\n", nouvelleCapacite);
    return 1;
}



// Définition de la fonction pour comparer deux etudiants par niveau pour le tri par niveau
int comparerEtudiantsParNiveau(const void *a, const void *b)
{
    const Etudiant *etudiantA = (const Etudiant *)a;
    const Etudiant *etudiantB = (const Etudiant *)b;
    return etudiantA->niveau - etudiantB->niveau;
}