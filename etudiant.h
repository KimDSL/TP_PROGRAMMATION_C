#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker la date de naissance
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour stocker les informations d'un etudiant
typedef struct {
    char matricule[20];     
    char nom[50];          
    char prenom[50];        
    Date dateNaissance;     
    char genre;             
    char departement[50];   
    char option[50];        
    char regionOrigine[50]; 
    int niveau;             
} Etudiant;

// Structure pour la gestion d'un tableau dynamique d'etudiants
typedef struct {
    Etudiant *liste; // Tableau dynamique d'etudiants 
    int nombre;      // Nombre actuel d'etudiants 
    int capacite;    // Capacite maximale du tableau
} GestionEtudiants;

// Définition de la fonction pour initialiser la structure de gestion
void initialiserGestion(GestionEtudiants *gestion, int capacite);

// Définition de la fonction pour libérer la mémoire allouée pour la gestion
void libererGestion(GestionEtudiants *gestion);

// Définition de la fonction pour augmenter la capacite du tableau quand il est plein
int redimensionnerGestion(GestionEtudiants *gestion);

// Définition de la fonction pour afficher les details d'un etudiant
void afficherEtudiant(Etudiant etudiant, int index);

// Définition de la fonction pour afficher tous les etudiants stockés
void afficherTousLesEtudiants(GestionEtudiants *gestion);

// Définition de la fonction pour comparer deux etudiants par matricule pour la recherche dichotomique
int comparerEtudiantsParMatricule(const void *a, const void *b);

// Définition de la fonction pour comparer deux etudiants par nom pour le tri par ordre alphabetique
int comparerEtudiantsParNom(const void *a, const void *b);

// Définition de la fonction pour comparer deux etudiants par option pour le tri par option
int comparerEtudiantsParOption(const void *a, const void *b);

// Définition de la fonction pour comparer deux etudiants par departement pour le tri par departement
int comparerEtudiantsParDepartement(const void *a, const void *b);

// Définition de la fonction pour comparer deux etudiants par niveau pour le tri par niveau
int comparerEtudiantsParNiveau(const void *a, const void *b);
#endif