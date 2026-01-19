#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "etudiant.h"

// Définition des fonctions pour le menu
void afficherMenu(GestionEtudiants *gestion);
void afficherFormulaireInscrire(GestionEtudiants *gestion);
void afficherEtudiantTrouve(Etudiant *etudiant);
void afficherMenuRechercherEtudiant(GestionEtudiants *gestion);
void afficherMenuRechercheDichotomique(GestionEtudiants *gestion);
void afficherMenuModifierEtudiant(GestionEtudiants *gestion, int index);