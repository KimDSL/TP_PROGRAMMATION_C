#include "etudiant.h"

// Définition de la fonction pour initialiser la structure de gestion
void initialiserGestion(GestionEtudiants *gestion, int capacite){

    gestion->capacite = capacite;
    gestion->nombre = 0;
    gestion->liste = (Etudiant *)malloc(sizeof(Etudiant) * capacite);

    if (gestion->liste == NULL){
        fprintf(stderr, "Erreur d'allocation memoire\n");
        exit(EXIT_FAILURE);
    }
}
// Définition de la fonction pour libérer la mémoire allouée pour la gestion
void libererGestion(GestionEtudiants *gestion){
    free(gestion->liste);
    gestion->liste = NULL;
    gestion->nombre = 0;
    gestion->capacite = 0;
}

// Définition de la fonction pour augmenter la capacite du tableau quand il est plein
int redimensionnerGestion(GestionEtudiants *gestion){
    int nouvelleCapacite = gestion->capacite * 2;
    Etudiant *nouvelleListe = (Etudiant *)realloc(gestion->liste, sizeof(Etudiant) * nouvelleCapacite);

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
    printf("Date de naissance : %02d/%02d/%04d\n", etudiant.dateNaissance.jour, etudiant.dateNaissance.mois, etudiant.dateNaissance.annee);
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

// Définition des fonctions pour le menu
void afficherMenu(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+========================================+\n");
    printf("|   SYSTEME DE GESTION DES ETUDIANTS     |\n");
    printf("+========================================+\n\n");

    printf("1. Inscrire un étudiant\n");
    printf("2. Modifier les informations\n");
    printf("3. Rechercher (par matricule)\n");
    printf("4. Supprimer un étudiant\n");
    printf("5. Trier par ordre alphabetique (nom)\n");
    printf("6. Recherche dichotomique\n");
    printf("7. Calculer l'age de l'étudiant\n");
    printf("8. Trier par option\n");
    printf("9. Trier par département\n");
    printf("10. Trier par niveau\n");
    printf("11. Afficher tous les étudiants\n");
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
            printf("Appuyez sur Entrée pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+==============================+\n");
            printf("|              ERREUR          |\n");
            printf("+==============================+\n");
            printf("Aucun étudiant à trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entrée pour continuer...");
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
            printf("Appuyez sur Entrée pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+===============================+\n");
            printf("|              ERREUR           |\n");
            printf("+===============================+\n");
            printf("Aucun étudiant à trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entrée pour continuer...");
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
            printf("Etudiants tries par département!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entrée pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+====================================+\n");
            printf("|              ERREUR                |\n");
            printf("+====================================+\n");
            printf("Aucun étudiant à trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entrée pour continuer...");
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
            printf("Appuyez sur Entrée pour continuer...");
            getchar();
            afficherListeEtudiants(gestion);
        }
        else
        {
            printf("\n");
            printf("+====================================+\n");
            printf("|              ERREUR                |\n");
            printf("+====================================+\n");
            printf("Aucun étudiant à trier!\n");
            printf("\n------------------------------------------------------------------------\n\n");
            printf("Appuyez sur Entrée pour continuer...");
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
    printf("Entrez les informations de l'étudiant :\n\n");

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

    printf("Département                    : ");
    fgets(nouvelEtudiant.departement, sizeof(nouvelEtudiant.departement), stdin);
    nouvelEtudiant.departement[strcspn(nouvelEtudiant.departement, "\n")] = '\0';

    printf("Option                         : ");
    fgets(nouvelEtudiant.option, sizeof(nouvelEtudiant.option), stdin);
    nouvelEtudiant.option[strcspn(nouvelEtudiant.option, "\n")] = '\0';

    printf("Région d'origine               : ");
    fgets(nouvelEtudiant.regionOrigine, sizeof(nouvelEtudiant.regionOrigine), stdin);
    nouvelEtudiant.regionOrigine[strcspn(nouvelEtudiant.regionOrigine, "\n")] = '\0';

    printf("Niveau d'étude (1, 2, 3...)    : ");
    scanf("%d", &nouvelEtudiant.niveau);
    while (getchar() != '\n')
        ;

    if (ajouterEtudiant(gestion, nouvelEtudiant))
    {
        printf("\n");
        printf("+======================================+\n");
        printf("|         INSCRIPTION REUSSIE          |\n");
        printf("+======================================+\n");
        printf("L'étudiant a été ajouté avec succes!\n");
        printf("Total étudiants: %d/%d\n", gestion->nombre, gestion->capacite);
    }
    else
    {
        printf("\n");
        printf("+==================================+\n");
        printf("|         ECHEC INSCRIPTION        |\n");
        printf("+==================================+\n");
        printf("Impossible d'ajouter l'étudiant.\n");
    }

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
    afficherMenu(gestion);
}

void afficherEtudiantTrouve(Etudiant *étudiant)
{
    printf("\n");
    printf("+==========================================+\n");
    printf("|              ETUDIANT TROUVE             |\n");
    printf("+==========================================+\n\n");

    printf("  Matricule          : %s\n", étudiant->matricule);
    printf("  Nom                : %s\n", étudiant->nom);
    printf("  Prenom             : %s\n", étudiant->prenom);
    printf("  Date de naissance  : %02d/%02d/%04d\n",
           étudiant->dateNaissance.jour,
           étudiant->dateNaissance.mois,
           étudiant->dateNaissance.annee);
    printf("  Genre              : %c\n", étudiant->genre);
    printf("  Departement        : %s\n", étudiant->departement);
    printf("  Option             : %s\n", étudiant->option);
    printf("  Region d'origine   : %s\n", étudiant->regionOrigine);
    printf("  Niveau             : %d\n", étudiant->niveau);

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entrée pour continuer...");
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
        printf("Aucun étudiant dans la base.\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();
        afficherMenu(gestion);
        return;
    }

    char matricule[50];
    printf("Entrer le matricule de l'étudiant :\n");
    printf("___________\r");
    fgets(matricule, sizeof(matricule), stdin);
    matricule[strcspn(matricule, "\n")] = '\0';

    printf("\nRecherche de l'étudiant %s en cours...\n", matricule);

    Etudiant trouve = obtenirEtudiant(gestion, matricule);

    if (strlen(trouve.matricule) > 0)
    {
        afficherEtudiantTrouve(&trouve);
    }
    else
    {
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entrée pour continuer...");
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
        printf("Aucun étudiant dans la base.\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entrée pour continuer...");
        getchar();
        afficherMenu(gestion);
        return;
    }

    qsort(gestion->liste, gestion->nombre, sizeof(Etudiant), comparerEtudiantsParNom);
    printf("[INFO] Liste triée par nom pour recherche dichotomique\n\n");

    char nom[50];
    printf("Entrer le nom de l'étudiant :\n");
    printf("___________\r");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';

    printf("\nRecherche dichotomique en cours...\n");

    int index = rechercheDichotomique(gestion->liste, gestion->nombre, nom);

    if (index != -1)
    {
        printf("Etudiant trouvé à l'index %d\n", index);
        afficherEtudiantTrouve(&gestion->liste[index]);
    }
    else
    {
        printf("Aucun étudiant trouvé avec le nom '%s'\n", nom);
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entrée pour continuer...");
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
    printf("6. Département\n");
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
        printf("Appuyez sur Entrée pour continuer...");
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

void afficherMenuSupprimerEtudiant(GestionEtudiants *gestion, int index) //L000000
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
    printf("+=======================================+\n");
    printf("|          SUPPRESSION ETUDIANT         |\n");
    printf("+=======================================+\n");
    printf("Etes-vous sur de vouloir supprimer cet etudiant?\n\n");

    Etudiant *e = &gestion->liste[index];
    printf("  Matricule : [%s]\n", e->matricule);
    printf("  Nom       : [%s]\n", e->nom);
    printf("  Prenom    : [%s]\n", e->prenom);
    printf("  Niveau    : [%d]\n\n", e->niveau);

    printf("1. Oui, supprimer\n");
    printf("0. Non, annuler\n");

    printf("\n------------------------------------------------------------------------\n");
    printf("\nVotre choix: ");

    int choix = obtenirChoix();
    if (choix == 1)
    {
        supprimerEtudiant(gestion, index);
        printf("\n");
        printf("+=======================================+\n");
        printf("|            SUPPRESSION                |\n");
        printf("+=======================================+\n");
        printf("Etudiant supprime avec succes!\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
    }

    afficherMenu(gestion);
}

void afficherListeEtudiants(GestionEtudiants *gestion)
{
    printf("\n");
    printf("+========================================================+\n");
    printf("| LISTE DES ETUDIANTS (%d etudiant(s))%-20s|\n", gestion->nombre, "");
    printf("+========================================================+\n\n");

    if (gestion->nombre == 0)
    {
        printf("Aucun etudiant dans la base.\n");
        printf("\n------------------------------------------------------------------------\n\n");
        printf("Appuyez sur Entree pour continuer...");
        getchar();
        afficherMenu(gestion);
        return;
    }

    printf("+-----+------------------+---------------------+---------------------+-------+------------+-------+---------------------+------------------+--------------------+\n");
    printf("| No  | Matricule        | Nom                 | Prenom              | Genre | Naissance  | Niveau| Option              | Departement      |  Region d'origine  |\n");
    printf("+-----+------------------+---------------------+---------------------+-------+------------+-------+---------------------+------------------+--------------------+\n");

    for (int i = 0; i < gestion->nombre; i++)
    {
        printf("| %-3d | %-16s | %-19s | %-19s | %-5c | %02d/%02d/%04d | %-5d | %-19s | %-16s | %-18s |\n",
               i + 1,
               gestion->liste[i].matricule,
               gestion->liste[i].nom,
               gestion->liste[i].prenom,
               gestion->liste[i].genre,
               gestion->liste[i].dateNaissance.jour,
               gestion->liste[i].dateNaissance.mois,
               gestion->liste[i].dateNaissance.annee,
               gestion->liste[i].niveau,
               gestion->liste[i].option,
               gestion->liste[i].departement,
               gestion->liste[i].regionOrigine);
    }

    printf("+-----+------------------+---------------------+---------------------+-------+------------+-------+---------------------+------------------+--------------------+\n");
    printf("\nTotal: %d etudiant(s)\n", gestion->nombre);

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entree pour continuer...");
    getchar();
    afficherMenu(gestion);
}

void afficherMenuCalculerAge(GestionEtudiants *gestion, int index)
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
    printf("+=========================================+\n");
    printf("|      CALCULER L'AGE DE L'ETUDIANT       |\n");
    printf("+=========================================+\n\n");

    Etudiant *e = &gestion->liste[index];
    printf("Matricule de l'etudiant : %s\n\n", e->matricule);

    printf("------------------------------------------------------------------------\n\n");

    printf("Etudiant : %s %s\n", e->nom, e->prenom);
    printf("Date de naissance : %02d/%02d/%04d\n",
           e->dateNaissance.jour,
           e->dateNaissance.mois,
           e->dateNaissance.annee);

    int age = 2026 - e->dateNaissance.annee;
    printf("\nAge approximatif : %d ans\n", age);

    printf("\n------------------------------------------------------------------------\n\n");
    printf("Appuyez sur Entree pour continuer...");
    getchar();
    afficherMenu(gestion);
}

int obtenirChoix(void)
{
    int choix;
    int resultat = scanf("%d", &choix);

    while (getchar() != '\n')
        ;

    if (resultat != 1)
        return -1;

    return choix;
}