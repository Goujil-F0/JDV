//
// Created by stephane on 08/01/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terrain.h"

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************
// Definir la fonction 'terrain_generer_position_sortie' ici
void terrain_generer_position_sortie(int *sortie_ligne, int *sortie_colonne) {
    *sortie_ligne = rand() % NB_LIGNES;
    *sortie_colonne = rand() % NB_COLONNES;
}

// Definir la fonction 'terrain_generer_position_depart' ici
void terrain_generer_position_depart(int destination_ligne, int destination_colonne, int *depart_ligne, int *depart_colonne) {
    int distance;
    do {
        *depart_ligne = rand() % NB_LIGNES;
        *depart_colonne = rand() % NB_COLONNES;
        distance = abs(*depart_ligne - destination_ligne) + abs(*depart_colonne - destination_colonne);
    } while (distance <= 10);
}

// Definir la fonction 'terrain_contient' ici
bool terrain_contient(int position_ligne, int position_colonne) {
    return position_ligne >= 0 && position_ligne < NB_LIGNES && position_colonne >= 0 && position_colonne < NB_COLONNES;
}

// Definir la fonction 'terrain_get_carburant' ici
int terrain_get_carburant(t_terrain terrain, int position_ligne, int position_colonne) {
    if (terrain_contient(position_ligne, position_colonne)) {
        return terrain[position_ligne][position_colonne];
    }
    return 0;
}

// Definir la fonction 'terrain_set_carburant' ici
void terrain_set_carburant(t_terrain terrain, int position_ligne, int position_colonne, int carburant) {
    if (terrain_contient(position_ligne, position_colonne)) {
        terrain[position_ligne][position_colonne] = carburant;
    }
}

// Definir la fonction 'terrain_init' ici
void terrain_init(t_terrain terrain) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            terrain[i][j] = 0;
        }
    }
}

// Definir la fonction 'terrain_creer_stations_carburant' ici
void terrain_creer_stations_carburant(t_terrain terrain, int quantite_globale) {
    srand(time(NULL));
    while (quantite_globale > 0) {
        int ligne = rand() % NB_LIGNES;
        int colonne = rand() % NB_COLONNES;
        int carburant = rand() % (STATION_MAX_CARBURANT + 1);
        if (carburant > quantite_globale) {
            carburant = quantite_globale;
        }
        terrain_set_carburant(terrain, ligne, colonne, carburant);
        quantite_globale -= carburant;
    }
}

// Definir la fonction 'terrain_afficher' ici
void terrain_afficher(t_terrain terrain, int courante_ligne, int courante_colonne, int destination_ligne, int destination_colonne) {
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (i == courante_ligne && j == courante_colonne) {
                printf("[X] ");  // Case courante
            } else if (i == destination_ligne && j == destination_colonne) {
                printf("[S] ");  // Case de sortie
            } else {
                printf("[%d] ", terrain[i][j]);  // Case normale
            }
        }
        printf("\n");
    }
}


