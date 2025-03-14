//
// Created by stephane on 08/01/25.
//
#include "jeu.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'jeu_maj_carburant_joueur' ici
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant, int terrain[][NB_DIRECTIONS])
{
  // Annule la quantité de carburant sur la case du joueur
  if (terrain[joueur_ligne][joueur_colonne] > 0)
  {
    *joueur_carburant += terrain[joueur_ligne][joueur_colonne];
    terrain[joueur_ligne][joueur_colonne] = 0;
  }
  // Décrémente le carburant du joueur après un déplacement
  *joueur_carburant -= COUT_DEPLACEMENT_VOISIN;
}
// Definir la fonction 'jeu_deplacer_joueur' ici
bool jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, t_direction direction)
{
  int nouvelle_ligne = *joueur_ligne;
  int nouvelle_colonne = *joueur_colonne;

  switch (direction)
  {
  case DIRECTION_DROITE:
    nouvelle_colonne++;
    break;
  case DIRECTION_BAS:
    nouvelle_ligne++;
    break;
  case DIRECTION_HAUT:
    nouvelle_ligne--;
    break;
  case DIRECTION_GAUCHE:
    nouvelle_colonne--;
    break;
  default:
    return false;
  }

  // Vérifie si le déplacement est dans les limites du terrain
  if (nouvelle_ligne >= 0 && nouvelle_colonne >= 0)
  {
    *joueur_ligne = nouvelle_ligne;
    *joueur_colonne = nouvelle_colonne;
    return true;
  }
  return false;
}
// Definir la fonction 'jeu_init' ici

void jeu_init(int terrain[][NB_DIRECTIONS], int *joueur_ligne, int *joueur_colonne, int *joueur_carburant, int *destination_ligne, int *destination_colonne)
{
  // Initialisation du terrain avec des stations de gas
  for (int i = 0; i < NB_DIRECTIONS; i++)
  {
    for (int j = 0; j < NB_DIRECTIONS; j++)
    {
      terrain[i][j] = 0;
    }
  }

  // Position initiale du joueur
  *joueur_ligne = 0;
  *joueur_colonne = 0;

  // Quantité initiale de carburant
  *joueur_carburant = JOUEUR_CARBURANT_INITIAL;

  // Position de destination
  *destination_ligne = NB_DIRECTIONS - 1;
  *destination_colonne = NB_DIRECTIONS - 1;
}
// Definir la fonction 'jeu_afficher_direction' ici
void jeu_afficher_direction(t_direction direction)
{
  switch (direction)
  {
  case DIRECTION_DROITE:
    printf("Droite\n");
    break;
  case DIRECTION_BAS:
    printf("Bas\n");
    break;
  case DIRECTION_HAUT:
    printf("Haut\n");
    break;
  case DIRECTION_GAUCHE:
    printf("Gauche\n");
    break;
  default:
    printf("Direction erronée\n");
    break;
  }
}
// Definir la fonction 'jeu_verifier_choix_deplacement' ici
t_direction jeu_verifier_choix_deplacement(const char *choix)
{
  if (strcmp(choix, "droite") == 0)
  {
    return DIRECTION_DROITE;
  }
  else if (strcmp(choix, "bas") == 0)
  {
    return DIRECTION_BAS;
  }
  else if (strcmp(choix, "haut") == 0)
  {
    return DIRECTION_HAUT;
  }
  else if (strcmp(choix, "gauche") == 0)
  {
    return DIRECTION_GAUCHE;
  }
  else
  {
    return DIRECTION_ERRONEE;
  }
}
// Definir la fonction 'jeu_calculer_voisin' ici
void jeu_calculer_voisin(int case_ligne, int case_colonne, t_direction direction, int *voisin_ligne, int *voisin_colonne)
{
  *voisin_ligne = case_ligne;
  *voisin_colonne = case_colonne;

  switch (direction)
  {
  case DIRECTION_DROITE:
    (*voisin_colonne)++;
    break;
  case DIRECTION_BAS:
    (*voisin_ligne)++;
    break;
  case DIRECTION_HAUT:
    (*voisin_ligne)--;
    break;
  case DIRECTION_GAUCHE:
    (*voisin_colonne)--;
    break;
  default:
    break;
  }
}
// Definir la fonction 'jeu_verifier_fin' ici
t_jeu_etat jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant, int destination_ligne, int destination_colonne)
{
  if (joueur_ligne == destination_ligne && joueur_colonne == destination_colonne)
  {
    return JEU_ETAT_VICTOIRE;
  }
  else if (joueur_carburant <= 0)
  {
    return JEU_ETAT_ECHEC;
  }
  else
  {
    return JEU_ETAT_EN_COURS;
  }
}