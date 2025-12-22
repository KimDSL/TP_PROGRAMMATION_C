#ifndef A15AB512_86CF_41FA_BF40_2DCD39B874EB
#define A15AB512_86CF_41FA_BF40_2DCD39B874EB


#endif /* A15AB512_86CF_41FA_BF40_2DCD39B874EB */
#include <stdio.h>

// Fonction principale
int main(void)
{
    int choix;

    printf("=================================\n");
    printf("   TEST D'UN PROJET EN LANGAGE C  \n");
    printf("=================================\n");

    printf("1. Dire bonjour\n");
    printf("2. Tester un calcul\n");
    printf("3. Quitter\n");
    printf("Choisissez une option : ");
    scanf("%d", &choix);

    switch (choix)
    {
        case 1:
            printf("Bonjour ! Votre projet C fonctionne correctement.\n");
            break;

        case 2:
        {
            int a, b;
            printf("Entrez deux nombres : ");
            scanf("%d %d", &a, &b);
            printf("Somme = %d\n", a + b);
            break;
        }

        case 3:
            printf("Fin du programme. Au revoir !\n");
            break;

        default:
            printf("Choix invalide.\n");
    }

    return 0;
}