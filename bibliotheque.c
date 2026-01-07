#include "bibliotheque.h"
#include <string.h>
#include <stdio.h>

// Fonction pour trier les étudiants par nom (ordre alphabétique)
void trierEtudiantsParNom(Etudiant *tab, int n)
{
    Etudiant temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(tab[i].nom, tab[j].nom) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    printf("\nLes étudiants triés par nom sont :\n");
    afficherEtudiants(tab, n);
}

// Fonction pour trier les étudiants par filière (ordre alphabétique)
void trierEtudiantsParFiliere(Etudiant *tab, int n)
{
    Etudiant temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(tab[i].filiere, tab[j].filiere) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    printf("\nLes étudiants triés par filière sont :\n");
    afficherEtudiants(tab, n);
}

// Fonction pour afficher la liste des étudiants
void afficherEtudiants(Etudiant *tab, int n)
{
    int i;
    printf("\n=== LISTE DES ÉTUDIANTS ===\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. %s %s | Matricule: %s | Filière: %s\n",
               i + 1,
               tab[i].prenom,
               tab[i].nom,
               tab[i].matricule,
               tab[i].filiere);
    }
}
