// Supprimer un etudiant de la liste a un index donne
int supprimerEtudiant(GestionEtudiants *gestion, int index)
{
    if (gestion == NULL || gestion->liste == NULL || gestion->nombre == 0)
        return 0;

    if (index < 0 || index >= gestion->nombre)
        return 0;

    printf("\nSuppression de l'etudiant :\n");
    printf("   Matricule : %s\n", gestion->liste[index].matricule);
    printf("   Nom : %s %s\n", gestion->liste[index].nom, gestion->liste[index].prenom);

    // decallage
    for (int i = index; i < gestion->nombre - 1; i++)
    {
        gestion->liste[i] = gestion->liste[i + 1];
    }
    // reduction du nombre d'etudiant
    gestion->nombre--;

    // Optimiser la memoire si necessaire
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

// Fonction de recherche dichotomique pour trouver un etudiant par matricule
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