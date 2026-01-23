#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "etudiant.h"

// Définitions des fonctions pour le menu
void afficherMenu(GestionEtudiants *gestion);
/// @paramétre gestion 
void afficherFormulaireInscrire(GestionEtudiants *gestion);
/// @paramétre étudiant 
void afficherEtudiantTrouve(Etudiant *etudiant);
/// @paramétre gestion 
void afficherMenuRechercherEtudiant(GestionEtudiants *gestion);
/// @paramétre gestion 
void afficherMenuRechercheDichotomique(GestionEtudiants *gestion);
/// @paramétre gestion et index
void afficherMenuModifierEtudiant(GestionEtudiants *gestion, int index);