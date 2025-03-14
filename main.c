
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terrain.h"
#include "interaction.h"
#include "jeu.h"

//  *********************************************
//  Declarations des fonctions autres que le main
//  *********************************************

/**
 * @brief Excute la boucle principale du jeu
 * @name jeu_executer
 * @param terrain la terrain sur lequel le joueur evolue
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param joueur_carburant la quantite de carburant du joueur
 * @param destination_ligne la ligne de la case a atteindre
 * @param destination_colonne la colonne de la case a atteindre
 */
//  Ecrire le prototype de la fonction 'jeu_executer' ici
void jeu_executer(t_terrain terrain, int joueur_ligne, int joueur_colonne, int *joueur_carburant, int destination_ligne, int destination_colonne);

//  ******************************
//  Definition de la fonction main
//  ******************************
int main(void) {
    srand(time(NULL));// Initialisation du générateur de nombres aléatoires


    //  Les donnees du jeu : terrain, joueur, case de sortie
    t_terrain terrain;
    int joueur_ligne, joueur_colonne, joueur_carburant; //  le joueur
    int destination_ligne, destination_colonne; //  la case de destination

    //  initialisation du jeu
    jeu_init(terrain, &joueur_ligne, &joueur_colonne, &joueur_carburant, &destination_ligne, &destination_colonne);

    //  Presentation du jeu
    interaction_presenter_jeu();

    //  Boucle principale du jeu
    //jeu_executer(terrain, joueur_ligne, joueur_colonne, joueur_carburant, destination_ligne, destination_colonne);
    jeu_executer(terrain, joueur_ligne, joueur_colonne, &joueur_carburant, destination_ligne, destination_colonne);

    return 0;
}

//  ********************************************
//  Definitions des fonctions autres que le main
//  ********************************************
// Definir la fonction 'jeu_executer' ici
void jeu_executer(t_terrain terrain, int joueur_ligne, int joueur_colonne, int *joueur_carburant, int destination_ligne, int destination_colonne) {
    t_action action;
    t_direction direction;

    while (1) {
        // Afficher le terrain avec la position du joueur et la destination
        terrain_afficher(terrain, joueur_ligne, joueur_colonne, destination_ligne, destination_colonne);

        // Afficher les options disponibles
        interaction_afficher_options(*joueur_carburant);

        // Demander une action au joueur
        action = interaction_demander_action(*joueur_carburant);

        // Vérifier si l'action est valide
        action = interaction_verifier_choix_action(action, *joueur_carburant);

        if (action == ACTION_INVALIDE) {
            printf("Action invalide. Veuillez réessayer.\n");
            continue;
        }

        if (action == ACTION_QUITTER) {
            printf("Vous avez choisi de quitter le jeu. Au revoir!\n");
            break;
        }

        if (action == ACTION_ACHETER_BONUS) {
            if (*joueur_carburant >= 10) {
                *joueur_carburant -= 10;
                printf("Bonus de déplacement acheté! Vous avez maintenant %d litres de carburant.\n", *joueur_carburant);
                // Ici, vous pouvez ajouter la logique pour le bonus de déplacement (4 cases d'affilée)
            } else {
                printf("Carburant insuffisant pour acheter le bonus.\n");
            }
            continue;
        }

        if (action == ACTION_DEPLACER) {
            // Demander une direction de déplacement
            direction = interaction_demander_direction_deplacement();

            if (direction == DIRECTION_ERRONEE) {
                printf("Direction invalide. Veuillez réessayer.\n");
                continue;
            }

            // Calculer la nouvelle position
            int nouvelle_ligne = joueur_ligne;
            int nouvelle_colonne = joueur_colonne;

            switch (direction) {
                case DIRECTION_HAUT:
                    nouvelle_ligne--;
                    break;
                case DIRECTION_BAS:
                    nouvelle_ligne++;
                    break;
                case DIRECTION_GAUCHE:
                    nouvelle_colonne--;
                    break;
                case DIRECTION_DROITE:
                    nouvelle_colonne++;
                    break;
                default:
                    break;
            }

            // Vérifier si la nouvelle position est valide
            if (!terrain_contient(nouvelle_ligne, nouvelle_colonne)) {
                printf("Déplacement impossible. Vous êtes au bord du terrain.\n");
                continue;
            }

            // Mettre à jour la position et le carburant
            *joueur_carburant -= 1;  // Consommation de carburant
            int carburant_case = terrain_get_carburant(terrain, nouvelle_ligne, nouvelle_colonne);
            *joueur_carburant += carburant_case;  // Ajouter le carburant de la nouvelle case
            terrain_set_carburant(terrain, nouvelle_ligne, nouvelle_colonne, 0);  // Réinitialiser la case

            joueur_ligne = nouvelle_ligne;
            joueur_colonne = nouvelle_colonne;

            // Vérifier si le joueur a atteint la sortie
            if (joueur_ligne == destination_ligne && joueur_colonne == destination_colonne) {
                interaction_afficher_victoire(*joueur_carburant);
                break;
            }

            // Vérifier si le joueur a épuisé son carburant
            if (*joueur_carburant <= 0) {
                interaction_afficher_echec();
                break;
            }
        }
    }
}