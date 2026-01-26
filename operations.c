#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

// Ajouter un nouvel étudiant à la liste de gestion
int ajouterEtudiant(GestionEtudiants *gestion, Etudiant etudiant)
{
    if (gestion == NULL)
        return 0;

    if (gestion->nombre >= gestion->capacite)
    {
        if (redimensionnerGestion(gestion) == 0)
            return 0;
    }

    gestion->liste[gestion->nombre] = etudiant;
    gestion->nombre++;
    return 1;
}

// Obtenir un étudiant par son matricule
Etudiant obtenirEtudiant(GestionEtudiants *gestion, const char *matricule)
{
    Etudiant etudiantVide;
    memset(&etudiantVide, 0, sizeof(Etudiant));
    strcpy(etudiantVide.matricule, "");

    if (gestion == NULL || gestion->liste == NULL || matricule == NULL)
        return etudiantVide;
    if (gestion->nombre == 0)
    {
        printf("Aucun étudiant dans la base.");
        return etudiantVide;
    }

    for (int i = 0; i < gestion->nombre; i++)
    {
        if (strcmp(gestion->liste[i].matricule, matricule) == 0)
            return gestion->liste[i];
    }

    printf("Aucun étudiant trouve avec le matricule '%s'\n", matricule);
    return etudiantVide;
}

// Selectionner un étudiant de maniere interactive
int selectionnerEtudiant(GestionEtudiants *gestion)
{
    if (gestion == NULL || gestion->liste == NULL || gestion->nombre == 0)
    {
        printf("Erreur : Aucun étudiant dans la base !\n");
        return -1;
    }
    // Demande le matricule à l'utilisateur
    char matricule[20];
    printf("\n=== SELECTION D'UN ETUDIANT ===\n");
    printf("Entrez le matricule de l'étudiant: ");
    fgets(matricule, sizeof(matricule), stdin);
    matricule[strcspn(matricule, "\n")] = '\0';

    // Rechercher l'étudiant dans la liste
    for (int i = 0; i < gestion->nombre; i++)
    {
        if (strcmp(gestion->liste[i].matricule, matricule) == 0)
        {
            printf("\nEtudiant trouve a l'index %d :\n", i);
            printf("===== Informations de l'étudiant =====\n");
            printf("Matricule     : %s\n", gestion->liste[i].matricule);
            printf("Nom           : %s\n", gestion->liste[i].nom);
            printf("Prenom        : %s\n", gestion->liste[i].prenom);
            printf("Date naissance: %02d/%02d/%04d\n", gestion->liste[i].dateNaissance.jour, gestion->liste[i].dateNaissance.mois, gestion->liste[i].dateNaissance.annee);
            printf("Genre         : %c\n", gestion->liste[i].genre);
            printf("Departement   : %s\n", gestion->liste[i].departement);
            printf("Option        : %s\n", gestion->liste[i].option);
            printf("Region origin : %s\n", gestion->liste[i].regionOrigine);
            printf("Niveau        : %d\n", gestion->liste[i].niveau);
            printf("============================================================================\n");
            return i;
        }
    }
    // Etudiant non trouvé
    printf("\nAucun étudiant trouve avec le matricule '%s'\n", matricule);
    return -1;
}

// Modifier les informations d'un étudiant à un index donné
void modifierEtudiant(GestionEtudiants *gestion, int index)
{
    if (gestion == NULL || gestion->liste == NULL || index < 0 || index >= gestion->nombre)
    {
        printf("Index invalide !\n");
        return;
    }

    Etudiant *e = &gestion->liste[index];

    // infos actuelles
    printf("\n========================================\n");
    printf("        ETUDIANT A MODIFIER\n");
    printf("========================================\n");
    printf("Matricule    : %s\n", e->matricule);
    printf("Nom          : %s\n", e->nom);
    printf("Prenom       : %s\n", e->prenom);
    printf("Date naissance: %02d/%02d/%04d\n", e->dateNaissance.jour, e->dateNaissance.mois, e->dateNaissance.annee);
    printf("Genre        : %c\n", e->genre);
    printf("Departement  : %s\n", e->departement);
    printf("Option       : %s\n", e->option);
    printf("Region origin: %s\n", e->regionOrigine);
    printf("Niveau       : %d\n", e->niveau);
    printf("========================================\n");
    printf("Confirmer votre choix: ");

    int choix;
    scanf("%d", &choix);
    while (getchar() != '\n')
        ;

    /* Traiter le choix */
    switch (choix)
    {
    case 1:
        printf("Nouveau matricule: ");
        fgets(e->matricule, sizeof(e->matricule), stdin);
        e->matricule[strcspn(e->matricule, "\n")] = '\0';
        printf("Matricule modifié !\n");
        break;
    case 2:
        printf("Nouveau nom: ");
        fgets(e->nom, sizeof(e->nom), stdin);
        e->nom[strcspn(e->nom, "\n")] = '\0';
        printf("Nom modifié !\n");
        break;
    case 3:
        printf("Nouveau prenom: ");
        fgets(e->prenom, sizeof(e->prenom), stdin);
        e->prenom[strcspn(e->prenom, "\n")] = '\0';
        printf("Prenom modifié !\n");
        break;
    case 4:
        printf("Nouvelle date (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &e->dateNaissance.jour, &e->dateNaissance.mois, &e->dateNaissance.annee);
        while (getchar() != '\n')
            ;
        printf("Date modifiée !\n");
        break;
    case 5:
        printf("Nouveau genre (M/F): ");
        scanf(" %c", &e->genre);
        while (getchar() != '\n')
            ;
        printf("Genre modifié !\n");
        break;
    case 6:
        printf("Nouveau departement: ");
        fgets(e->departement, sizeof(e->departement), stdin);
        e->departement[strcspn(e->departement, "\n")] = '\0';
        printf("Departement modifié !\n");
        break;
    case 7:
        printf("Nouvelle option: ");
        fgets(e->option, sizeof(e->option), stdin);
        e->option[strcspn(e->option, "\n")] = '\0';
        printf("Option modifiée !\n");
        break;
    case 8:
        printf("Nouvelle region: ");
        fgets(e->regionOrigine, sizeof(e->regionOrigine), stdin);
        e->regionOrigine[strcspn(e->regionOrigine, "\n")] = '\0';
        printf("Region modifiée !\n");
        break;
    case 9:
        printf("Nouveau niveau: ");
        scanf("%d", &e->niveau);
        while (getchar() != '\n')
            ;
        printf("Niveau modifié !\n");
        break;
    case 0:
        printf("Modification annulée.\n");
        break;
    default:
        printf("Choix invalide !\n");
    }
}

// Supprimer un étudiant de la liste a un index donne
int supprimerEtudiant(GestionEtudiants *gestion, int index)
{
    if (gestion == NULL || gestion->liste == NULL || gestion->nombre == 0)
        return 0;

    if (index < 0 || index >= gestion->nombre)
        return 0;

    printf("\nSuppression de l'étudiant :\n");
    printf("   Matricule : %s\n", gestion->liste[index].matricule);
    printf("   Nom : %s %s\n", gestion->liste[index].nom, gestion->liste[index].prenom);

    // décallage
    for (int i = index; i < gestion->nombre - 1; i++)
    {
        gestion->liste[i] = gestion->liste[i + 1];
    }
    // reduction du nombre d'étudiant
    gestion->nombre--;

    // Optimiser la mémoire si necessaire
    if (gestion->nombre > 0 && gestion->nombre < gestion->capacite / 2 && gestion->capacite > 10)
    {
        int nouvelleCapacite = gestion->capacite / 2;
        Etudiant *nouvelleListe = realloc(gestion->liste, nouvelleCapacite * sizeof(Etudiant));

        if (nouvelleListe != NULL)
        {
            gestion->liste = nouvelleListe;
            gestion->capacite = nouvelleCapacite;
            printf("Memoire optimisee : capacite reduite a %d\n", nouvelleCapacite);
        }
    }

    printf("Etudiant supprime !\n");
    printf("Etudiants restants : %d/%d\n", gestion->nombre, gestion->capacite);

    return 1;
}

// Fonction de recherche dichotomique pour trouver un étudiant par matricule
int rechercheDichotomique(Etudiant *liste, int nombre, const char *nom)
{
    int gauche = 0;
    int droite = nombre - 1;

    while (gauche <= droite)
    {
        int milieu = (gauche + droite) / 2;
        int comparaison = strcmp(liste[milieu].nom, nom);
        if (comparaison == 0)
        {
            return milieu;
        }
        else if (comparaison < 0)
        {
            gauche = milieu + 1;
        }
        else
        {
            droite = milieu - 1;
        }
    }
    return -1;
}