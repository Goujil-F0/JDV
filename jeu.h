//
// Created by stephane on 08/01/25.
//

#ifndef CODE_JEU_H
#define CODE_JEU_H

#define JOUEUR_CARBURANT_INITIAL 2
#define COUT_DEPLACEMENT_VOISIN 1
#define BONUS_CARBURANT 5
#define TOTAL_CARBURANT_NIVEAU_1 100

//  *****************************
//  Definitions des types publics
//  *****************************

typedef enum
{
    DIRECTION_ERRONEE = -1,
    DIRECTION_DROITE,
    DIRECTION_BAS,
    DIRECTION_HAUT,
    DIRECTION_GAUCHE
} t_direction;
#define NB_DIRECTIONS 4

typedef enum
{
    JEU_ETAT_ECHEC = 1,
    JEU_ETAT_VICTOIRE,
    JEU_ETAT_EN_COURS
} t_jeu_etat;

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Met a jour la quantite de carburant du joueur apres un deplacement. Annule la quantite de carburant sur la case du joueur.
 * @name jeu_maj_carburant_joueur
 * @param joueur_ligne la ligne ou se trouve maintenant le joueur
 * @param joueur_colonne la colonne ou se trouve maintenant le joueur
 * @param joueur_carburant l'adresse ou placer la nouvelle quantite de carburant du joueur apres deplacement
 * @param terrain le terrain sur lequel le joueur s'est deplace
 */
//  Ecrire le prototype de la fonction 'jeu_maj_carburant_joueur' ici
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int *joueur_carburant, int terrain[][NB_DIRECTIONS]);
/**
 * @brief Deplace le joueur dans une dircetion donnee.
 * @name jeu_deplacer_joueur
 * @param joueur_ligne l'adresse de la ligne ou se trouve le joueur avant le deplacement et qui sera mise a jour
 * @param joueur_colonne l'adresse de la colonne ou se trouve le joueur avant le deplacement et qui sera mise a jour
 * @param direction la direction dans laquelle on veut deplacer le joueur
 * @return true si le deplacement a pu se faire dans les lilmites du terrain, false sinon
 */
//  Ecrire le prototype de la fonction 'jeu_deplacer_joueur' ici
bool jeu_deplacer_joueur(int *joueur_ligne, int *joueur_colonne, t_direction direction);
/**
 * @brief Initialise le terrain de jeu avec les stations de gas.
 * Initialise la position de destination ainsi que la position initiale du joueur et sa quantite de carburant.
 * @name jeu_init
 * @param terrain le terrain sur lequel seront placees les stations de gas
 * @param joueur_ligne l'adresse de la ligne ou positionner le joueur
 * @param joueur_colonne l'adresse de la colonne ou positionner le joueur
 * @param joueur_carburant l'adresse ou placer la quantite de carburant du joueur
 * @param destination_ligne l'adresse de la ligne de la case a atteindre
 * @param destination_colonne l'adresse de la colonne de la case a atteindre
 */
//  Ecrire le prototype de la fonction 'jeu_init' ici
void jeu_init(int terrain[][NB_DIRECTIONS], int *joueur_ligne, int *joueur_colonne, int *joueur_carburant, int *destination_ligne, int *destination_colonne);
/**
 * @brief Affiche une direction en toutes lettres
 * @name jeu_afficher_direction
 * @param direction la direction a afficher
 */
//  Ecrire le prototype de la fonction 'jeu_afficher_direction' ici
void jeu_afficher_direction(t_direction direction);
/**
 * @brief Recupere une direction saisie sous la forme d'une chaine de caracteres,
 * s'assure qu'elle est valide et retourne la constante correspondante.
 * @ame jeu_verifier_choix_deplacement
 * @param choix une chaine de caractere constituant un choix de direction du joueur
 * @return DIRECTION_ERRONEE si la chaine ne correspond pas a l'une des 4 directions.
 * Sinon, retourne DIRECTION_HAUT ou DIRECTION_BAS ou DIRECTION_DROITE ou DIRECTION_GAUCHE selon la direction choisie
 */
//  Ecrire le prototype de la fonction 'jeu_verifier_choix_deplacement' ici
t_direction jeu_verifier_choix_deplacement(const char *choix);
/**
 * @brief Calcule la position d'un voisin dans une direction donnee.
 * @name jeu_calculer_voisin
 * @param case_ligne la ligne de la case de depart
 * @param case_colonne la colonne de la case de depart
 * @param direction la direction dans laquelle se trouve le voisin
 * @param voisin_ligne l'adresse ou placer la ligne du voisin selon la direction
 * @param voisin_colonne l'adresse ou placer la colonne du voisin selon la direction
 */
//  Ecrire le prototype de la fonction 'jeu_calculer_voisin' ici
void jeu_calculer_voisin(int case_ligne, int case_colonne, t_direction direction, int *voisin_ligne, int *voisin_colonne);
/**
 * @brief Verifie si le jeu est termine ou non.
 * @name jeu_verifier_fin
 * @param joueur_ligne la ligne ou se trouve le joueur
 * @param joueur_colonne la colonne ou se trouve le joueur
 * @param joueur_carburant la quantite de carburant actuel du joueur
 * @param destination_ligne la ligne de la destination
 * @param destination_colonne la colonne de la destination
 * @return JEU_ETAT_VICTOIRE si le joueur a atteint la case d'arrivee.
 * JEU_ETAT_ECHEC si le joueur n'a plus de carburant.
 * JEU_ETAT_EN_COURS si la partie est en cours.
 */
//  Ecrire le prototype de la fonction 'jeu_verifier_fin' ici
t_jeu_etat jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant, int destination_ligne, int destination_colonne);
#endif // CODE_JEU_H
