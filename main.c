#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bibliotheque.h"

int main(void)
{
    Etudiant *tab = NULL;
    int choix = 0;

    do
    {
        printf("\n\nBIENVENUE DANS L'APPLICATION DE GESTION DES ETUDIANTS DE L'ENSPM\n\n");
        printf("1. Enregistrer un etudiant\n");
        printf("2. Modifier un etudiant\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Rechercher un etudiant\n");
        printf("5. Trier par ordre alphabétique les etudiants\n");
        printf("6. Recherche dichotomique par nom\n");
        printf("7. Trier par filiere les etudiants\n");
        printf("8. Afficher la liste des etudiants\n");
        printf("0. Quitter l'application\n");


        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
        {
            
            break;
        }
        case 2:
        {
            
            break;
        }
        case 3:
        {
            
            break;
        }
        case 4:
        {
            
            break;
        }
        case 5:
        {
            
            break;
        }
        case 6:
        {
            
            break;
        }
        case 0:
            break;
        default:
            printf("\nRetry...\n\n");
        }
    } while (choix != 0);

    return EXIT_SUCCESS;
}