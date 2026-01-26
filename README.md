# TP_PROGRAMMATION_C
 Mini appli console en C pour la gestion efficace des étudiants. 

## Membres du groupe
- BIONDI BIONDI KEDENG EMMANUEL
- BROU KOUASSI JEAN CEDRIC
- DIDDI KOULSOUMI
- DINAMOU SOUBOURDA LARISSA
- DJAFRI JUSTIN

## objectif
L'objectif de ce projet est de créer une structure de données en langage C pour gérer la gestion des étudiants.

## Description du projet
Ce projet consiste à développer une application console en langage C pour gérer les informations des étudiants. L'application permet de stocker, afficher, modifier et supprimer les données des étudiants, ainsi que de trier et rechercher des étudiants en fonction de différents critères.

## Architecture du projet
TP_PROGRAMMATION_C
├── main.c          → Point d'entrée
├── etudiant.c/h    → Structures de données
├── operations.c/h  → Logique métier (CRUD)
└── affichage.c/h   → Interface utilisateur

## Données gerées
Chaque étudiant est représenté par une structure contenant les informations suivantes :
- Matricule (identifiant unique pour chaque étudiant)
- Nom  
- Prénom 
- Date de naissance (jj/mm/aaaa)
- Département
- Option
- Niveau (année d'étude)
_ Région d'origine

## Techniques utilisées
- Langage de programmation C
- Tableau dynamique pour stocker les étudiants
- Structures de données
- Fonction pour calculer l'âge à partir de la date de naissance
- Fonctions pour les opérations: Créer, Lire, Mettre à jour, Supprimer
- Tri et recherche dans les tableaux

## Fonctionnalités
- Ajouter un étudiant
- Supprimer un étudiant
- Mettre à jour les informations d'un étudiant
- Afficher la liste des étudiants
- Rechercher un étudiant par son matricule
- Tri par ordre alphabétique des noms
- Recherche par dichotomie
- Tri par option
- Tri par département
- Tri par niveau
- Calcul de l'âge des étudiants

## Menu principal
L'application propose un menu principal avec les options suivantes :
1. Inscrire un étudiant
2. Modifier les informations
3. Rechercher (par matricule)
4. Supprimer un etudiant5. 
5. Trier par ordre alphabetique (nom)5. Rechercher un étudiant par son matricule
6. Recherche dichotomique
7. Calculer l'age de l'etudiant
8. Trier par option
9. Trier par departement
10. Trier par niveau
11. Afficher tous les etudiants
0. Quitter

## Compilation
gcc main.c etudiant.c operations.c affichage.c -o programme

## Exécution
./programme