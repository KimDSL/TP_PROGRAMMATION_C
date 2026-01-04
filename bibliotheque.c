#include "bibliotheque.h"
#include <time.h>
// Définition de la fonction pour récupérer la date actuelle
void dateActuelle(Date *date)
{
    // Utilisation de la bibliothèque time.h pour obtenir la date actuelle
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    date->jour = tm.tm_mday;
    date->mois = tm.tm_mon + 1; // Les mois sont indexés à partir de 0
    date->annee = tm.tm_year + 1900; // Année depuis 1900
}
// Défiinition de la fonction pour calculer l'âge
int calculerAge(Date dateNaissance, Date dateActuelle)
{
    int age = dateActuelle.annee - dateNaissance.annee;

    // Vérifier si l'anniversaire de cette année est déjà passé
    if (dateActuelle.mois < dateNaissance.mois || 
       (dateActuelle.mois == dateNaissance.mois && dateActuelle.jour < dateNaissance.jour))
    {
        age--;
    }

    return age;
}