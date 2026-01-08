#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"

int ajouterEtudiant(GestionEtudiants *gestion, Etudiant etudiant);
Etudiant obtenirEtudiant(GestionEtudiants *gestion, const char *matricule);
int selectionnerEtudiant(GestionEtudiants *gestion);
void modifierEtudiant(GestionEtudiants *gestion, int index);