//
// Created by stephane on 09/01/25.
//

#include <stdio.h>
#include "interaction.h"

//  ***********************************
//  Definitions des fonctions publiques
//  ***********************************

// Definir la fonction 'interaction_presenter_jeu' ici
void interaction_presenter_jeu() {
    printf("Bienvenue dans le jeu de déplacement de véhicule!\n");
    printf("Le but du jeu est de déplacer votre véhicule (X) sur le terrain pour atteindre la sortie (s).\n");
    printf("Vous devez gérer votre carburant pour ne pas tomber à sec avant d'atteindre la destination.\n");
    printf("Bonne chance!\n");
}

// Definir la fonction 'interaction_afficher_options' ici
void interaction_afficher_options(int carburant) {
    printf("\nOptions disponibles :\n");
    printf("1. Se déplacer\n");
    if (carburant >= 10) {
        printf("2. Acheter un bonus de déplacement (10 litres)\n");
    } else {
        printf("2. Acheter un bonus de déplacement (10 litres) - Option grisée (carburant insuffisant)\n");
    }
    printf("3. Quitter le jeu\n");
}

// Definir la fonction 'interaction_demander_action' ici
t_action interaction_demander_action(int carburant) {
    int choix;
    printf("Choisissez une action (1-3): ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            return ACTION_DEPLACER;
        case 2:
            if (carburant >= 10) {
                return ACTION_ACHETER_BONUS;
            } else {
                return ACTION_INVALIDE;
            }
        case 3:
            return ACTION_QUITTER;
        default:
            return ACTION_INVALIDE;
    }
}

// Definir la fonction 'interaction_demander_direction_deplacement' ici
t_direction interaction_demander_direction_deplacement() {
    char direction;
    printf("Choisissez une direction (h: haut, b: bas, g: gauche, d: droite): ");
    scanf(" %c", &direction);

    switch (direction) {
        case 'h':
            return DIRECTION_HAUT;
        case 'b':
            return DIRECTION_BAS;
        case 'g':
            return DIRECTION_GAUCHE;
        case 'd':
            return DIRECTION_DROITE;
        default:
            return DIRECTION_ERRONEE;
    }
}
// Definir la fonction 'interaction_afficher_echec' ici
void interaction_afficher_echec() {
    printf("Vous avez épuisé votre carburant avant d'atteindre la destination. Mission échouée!\n");
}

// Definir la fonction 'interaction_afficher_victoire' ici
void interaction_afficher_victoire(int carburant) {
    printf("Félicitations! Vous avez atteint la destination avec %d litres de carburant restants.\n", carburant);
}

// Definir la fonction 'interaction_verifier_choix_action' ici
t_action interaction_verifier_choix_action(t_action action, int carburant) {
    if (action == ACTION_ACHETER_BONUS && carburant < 10) {
        return ACTION_INVALIDE;
    }
    return action;
}