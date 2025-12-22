#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int matricule;
    char nom[30];
    char prenom[30];
    char sexe[10];
    int age;
} Etudiant;


int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    int n = 0;
    int choix, matricule;

    do {
        printf("\n1. Ajouter\n2. Modifier\n3. Supprimer\n0. Quitter\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, &n);
                break;
            case 2:
                printf("Matricule a modifier : ");
                scanf("%d", &matricule);
                modifierEtudiant(etudiants, n, matricule);
                break;
            case 3:
                printf("Matricule a supprimer : ");
                scanf("%d", &matricule);
                supprimerEtudiant(etudiants, &n, matricule);
                break;
        }
    } while (choix != 0);

    return 0;
}