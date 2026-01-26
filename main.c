#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"
#include "etudiant.h"
#include "operations.h"

GestionEtudiants gestion;

int main()
{
    system("chcp 65001 > nul");

    initialiserGestion(&gestion, 1);

    printf("\n");
    printf("+========================================+\n");
    printf("|   SYSTEME DE GESTION DES ETUDIANTS     |\n");
    printf("+========================================+\n\n");

    printf("Base de donnees initialisee\n");
    //printf("   Capacite : %d etudiants\n", gestion.capacite);
    printf("   Nombre actuel : %d etudiant(s)\n\n", gestion.nombre);

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entree pour continuer...");
    getchar();
    printf("\n");

    afficherMenu(&gestion);

    return 0;
}
