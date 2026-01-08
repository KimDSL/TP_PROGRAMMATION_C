#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"
#include "operations.h"
#include "affichage.h"
//contenu de fonctios
void afficherMenu(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+========================================+\n");
    printf("|   SYSTEME DE GESTION DES ETUDIANTS     |\n");
    printf("+========================================+\n\n");

    printf("1. Inscrire un etudiant\n");
    printf("2. Modifier les informations\n");
    printf("3. Rechercher (par matricule)\n");
    printf("4. Supprimer un etudiant\n");
    printf("5. Trier par ordre alphabetique (nom)\n");
    printf("6. Recherche dichotomique\n");
    printf("7. Calculer l'age de l'etudiant\n");
    printf("8. Trier par option\n");
    printf("9. Trier par departement\n");
    printf("10. Trier par niveau\n");
    printf("11. Afficher tous les etudiants\n");
    printf("0. Quitter\n");

    printf("\nVotre choix: ");
    int choix = obtenirChoix();
    int index;

    switch (choix)
    {
    case 1:
        afficherFormulaireInscrire(gestion);
        break;
    case 2:
        index = selectionnerEtudiant(gestion);
        if (index != -1)
            afficherMenuModifierEtudiant(gestion, index);
        else
            afficherMenu(gestion);
        break;
    case 3:
        afficherMenuRechercherEtudiant(gestion);
        break;
    case 4:
        index = selectionnerEtudiant(gestion);
        if (index != -1)
            afficherMenuSupprimerEtudiant(gestion, index);
        else
            afficherMenu(gestion);
        break;
    case 5:
        if (gestion->nombre > 0)
        {
            qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParNom);
            printf("\n");
            printf("+==============================+\n");
            printf("|           TRI REUSSI         |\n");
            printf("+==============================+\n");
            printf("Etudiants tries par ordre alphabetique!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+==============================+\n");
            printf("|              ERREUR          |\n");
            printf("+==============================+\n");
            printf("Aucun etudiant a trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherMenu(gestion);
        }
        break;
    case 6:
        afficherMenuRechercheDichotomique(gestion);
        break;
    case 7:
        index = selectionnerEtudiant(gestion);
        if (index != -1)
            afficherMenuCalculerAge(gestion, index);
        else
            afficherMenu(gestion);
        break;
    case 8:
        if (gestion->nombre > 0)
        {
            qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParOption);
            printf("\n");
            printf("+==============================+\n");
            printf("|           TRI REUSSI         |\n");
            printf("+==============================+\n");
            printf("Etudiants tries par option!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+===============================+\n");
            printf("|              ERREUR           |\n");
            printf("+===============================+\n");
            printf("Aucun etudiant a trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherMenu(gestion);
        }
        break;
    case 9:
        if (gestion->nombre > 0)
        {
            qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParDepartement);
            printf("\n");
            printf("+==============================+\n");
            printf("|           TRI REUSSI         |\n");
            printf("+==============================+\n");
            printf("Etudiants tries par departement!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+====================================+\n");
            printf("|              ERREUR                |\n");
            printf("+====================================+\n");
            printf("Aucun etudiant a trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherMenu(gestion);
        }
        break;
    case 10:
        if (gestion->nombre > 0)
        {
            qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParNiveau);
            printf("\n");
            printf("+====================================+\n");
            printf("|           TRI REUSSI               |\n");
            printf("+====================================+\n");
            printf("Etudiants tries par niveau!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+====================================+\n");
            printf("|              ERREUR                |\n");
            printf("+====================================+\n");
            printf("Aucun etudiant a trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entree pour continuer...");
            getchar();
            afficherMenu(gestion);
        }
        break;
    case 11:
        afficherListeEtudiants(gestion);
        break;
    case 0:
        printf("\nVoulez-vous vraiment quitter?\n");
        printf("1. Oui\n");
        printf("0. Non\n");
        printf("Votre choix: ");

        int confirmation = obtenirChoix();
        if (confirmation == 1)
        {
            printf("\nAu revoir!\n");
            libererGestion(gestion);
            exit(0);
        }
        else
        {
            afficherMenu(gestion);
        }
        break;
    default:
        printf("Choix invalide.\n");
        afficherMenu(gestion);
    }
}

void afficherFormulaireInscrire(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+========================================================+\n");
    printf("|        INSCRIRE UN NOUVEL ETUDIANT                     |\n");
    printf("+========================================================+\n");
    printf("Entrez les informations de l'etudiant :\n\n");

    Etudiant nouvelEtudiant;
    memset(&nouvelEtudiant, 0, sizeof(Etudiant));

    printf("Matricule (ex: 23ENSPM0443)    : ");
    fgets(nouvelEtudiant.matricule, sizeof(nouvelEtudiant.matricule), stdin);
    nouvelEtudiant.matricule[strcspn(nouvelEtudiant.matricule, "\n")] = '\0';

    printf("Nom                            : ");
    fgets(nouvelEtudiant.nom, sizeof(nouvelEtudiant.nom), stdin);
    nouvelEtudiant.nom[strcspn(nouvelEtudiant.nom, "\n")] = '\0';

    printf("Prenom                         : ");
    fgets(nouvelEtudiant.prenom, sizeof(nouvelEtudiant.prenom), stdin);
    nouvelEtudiant.prenom[strcspn(nouvelEtudiant.prenom, "\n")] = '\0';

    printf("Date de naissance (jj/mm/aaaa) : ");
    scanf("%d/%d/%d", &nouvelEtudiant.dateNaissance.jour,
          &nouvelEtudiant.dateNaissance.mois,
          &nouvelEtudiant.dateNaissance.annee);
    while (getchar() != '\n')
        ;

    printf("Genre (M/F)                    : ");
    scanf(" %c", &nouvelEtudiant.genre);
    while (getchar() != '\n')
        ;

    printf("Departement                    : ");
    fgets(nouvelEtudiant.departement, sizeof(nouvelEtudiant.departement), stdin);
    nouvelEtudiant.departement[strcspn(nouvelEtudiant.departement, "\n")] = '\0';

    printf("Option                         : ");
    fgets(nouvelEtudiant.option, sizeof(nouvelEtudiant.option), stdin);
    nouvelEtudiant.option[strcspn(nouvelEtudiant.option, "\n")] = '\0';

    printf("Region d'origine               : ");
    fgets(nouvelEtudiant.regionOrigine, sizeof(nouvelEtudiant.regionOrigine), stdin);
    nouvelEtudiant.regionOrigine[strcspn(nouvelEtudiant.regionOrigine, "\n")] = '\0';

    printf("Niveau d'etude (1, 2, 3...)    : ");
    scanf("%d", &nouvelEtudiant.niveau);
    while (getchar() != '\n')
        ;

    if (ajouterEtudiant(gestion, nouvelEtudiant))
    {
        printf("\n");
        printf("+======================================+\n");
        printf("|         INSCRIPTION REUSSIE          |\n");
        printf("+======================================+\n");
        printf("L'etudiant a ete ajoute avec succes!\n");
        printf("Total etudiants: %d/%d\n", gestion->nombre, gestion->capacite);
    }
    else
    {
        printf("\n");
        printf("+==================================+\n");
        printf("|         ECHEC INSCRIPTION        |\n");
        printf("+==================================+\n");
        printf("Impossible d'ajouter l'etudiant.\n");
    }

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entree pour continuer...");
    getchar();
    afficherMenu(gestion);
}

void afficherEtudiantTrouve(Etudiant *etudiant)
{
    printf("\n");
    printf("+==========================================+\n");
    printf("|              ETUDIANT TROUVE             |\n");
    printf("+==========================================+\n\n");

    printf("  Matricule          : %s\n", etudiant->matricule);
    printf("  Nom                : %s\n", etudiant->nom);
    printf("  Prenom             : %s\n", etudiant->prenom);
    printf("  Date de naissance  : %02d/%02d/%04d\n",
           etudiant->dateNaissance.jour,
           etudiant->dateNaissance.mois,
           etudiant->dateNaissance.annee);
    printf("  Genre              : %c\n", etudiant->genre);
    printf("  Departement        : %s\n", etudiant->departement);
    printf("  Option             : %s\n", etudiant->option);
    printf("  Region d'origine   : %s\n", etudiant->regionOrigine);
    printf("  Niveau             : %d\n", etudiant->niveau);

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entree pour continuer...");
    getchar();
}

void afficherMenuRechercherEtudiant(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+==========================================+\n");
    printf("|            RECHERCHE ETUDIANT            |\n");
    printf("+==========================================+\n\n");

    if (gestion->nombre == 0)
    {
        printf("Aucun etudiant dans la base.\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
        afficherMenu(gestion);
        return;
    }

    char matricule[50];
    printf("Entrer le matricule de l'etudiant :\n");
    printf("___________\r");
    fgets(matricule, sizeof(matricule), stdin);
    matricule[strcspn(matricule, "\n")] = '\0';

    printf("\nRecherche de l'etudiant %s en cours...\n", matricule);

    Etudiant trouve = obtenirEtudiant(gestion, matricule);

    if (strlen(trouve.matricule) > 0)
    {
        afficherEtudiantTrouve(&trouve);
    }
    else
    {
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
    }

    afficherMenu(gestion);
}

void afficherMenuRechercheDichotomique(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+======================================+\n");
    printf("|         RECHERCHE DICHOTOMIQUE       |\n");
    printf("+======================================+\n\n");

    if (gestion->nombre == 0)
    {
        printf("Aucun etudiant dans la base.\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
        afficherMenu(gestion);
        return;
    }

    qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParNom);
    printf("[INFO] Liste triee par nom pour recherche dichotomique\n\n");

    char nom[50];
    printf("Entrer le nom de l'etudiant :\n");
    printf("___________\r");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';

    printf("\nRecherche dichotomique en cours...\n");

    int index = rechercheDichotomique(gestion->liste, gestion->nombre, nom);

    if (index != -1)
    {
        printf("Etudiant trouve a l'index %d\n", index);
        afficherEtudiantTrouve(&gestion->liste[index]);
    }
    else
    {
        printf("Aucun etudiant trouve avec le nom '%s'\n", nom);
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
    }

    afficherMenu(gestion);
}

void afficherMenuModifierEtudiant(GestionEtudiants *gestion, int index)
{
    if (index < 0 || index >= gestion->nombre)
    {
        printf("\n");
        printf("+==================================+\n");
        printf("|              ERREUR              |\n");
        printf("+==================================+\n");
        printf("Index invalide!\n");
        afficherMenu(gestion);
        return;
    }

    printf("\n");
    printf("+==========================================+\n");
    printf("|       MODIFIER INFORMATIONS ETUDIANT     |\n");
    printf("+==========================================+\n\n");

    Etudiant *e = &gestion->liste[index];
    printf("Etudiant actuel : [%s] - [%s] [%s] - Niveau: %d\n\n",
           e->matricule, e->nom, e->prenom, e->niveau);

    printf("Quel champ souhaitez-vous modifier ?\n\n");

    printf("1. Matricule\n");
    printf("2. Nom\n");
    printf("3. Prenom\n");
    printf("4. Date de naissance\n");
    printf("5. Genre\n");
    printf("6. Departement\n");
    printf("7. Option\n");
    printf("8. Region d'origine\n");
    printf("9. Niveau\n");
    printf("10. Enregistrer et retourner\n");
    printf("0. Annuler\n");
    printf("Votre choix: ");

    int choix = obtenirChoix();

    if (choix >= 1 && choix <= 9)
    {
        modifierEtudiant(gestion, index);
        afficherMenuModifierEtudiant(gestion, index);
    }
    else if (choix == 10)
    {
        printf("\n");
        printf("+=======================================+\n");
        printf("|              SAUVEGARDE               |\n");
        printf("+=======================================+\n");
        printf("Modifications enregistrees!\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
        afficherMenu(gestion);
    }
    else if (choix == 0)
    {
        afficherMenu(gestion);
    }
    else
    {
        printf("Choix invalide.\n");
        afficherMenuModifierEtudiant(gestion, index);
    }
}
