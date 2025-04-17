#include <stdio.h>
#include <stdlib.h>
#include "card.h"

#ifndef _PLAYER_
#define _PLAYER_

/** 
 * \brief Créer un type abstrait player
 */
typedef struct player_s *player;

void reset_player_id_counter();

void reset_global_array1();

/**
 *  \brief Renvoie un player sans carte en main initialement sans carte en main, sans carte posée sur la table et avec une ardoise vide 
 *  \detail La joueuse a un identifiant unique
 *  \param La fonction ne prend rien en entrée
 *  \return un player
 */

player create_player();


/** 
 * \brief libére la mémoire allouée à la joueuse
 * \param p player
 */

void free_player(player p);


/**
 * \brief Renvoie l'identifiant de la joueuse
 * \param p player
 * \return un entier
 */
 
int get_player_id (player p);
 

/**
 * \brief Renvoie une joueuse joueuse
 * \param n entier
 * \return player
 */

 player get_player_by_id(int n);


/**
 * \brief Ajoute la carte à la main de la joueuse
 * \param p player et c card
 * \return La fonction ne renvoie rien
 */

 void add_card_to_hand(player p, card c);


/**
 * \brief Renvoie le nombre de cartes dans la main de la joueuse
 * \param p player
 * \return un entier
 */

  int get_size_of_hand(player p);


/**
 * \brief Renvoie la carte de la main de la joueuse 
 * \param p player et card_index entier
 * \return une carte 
 */

 card get_card_in_hand (player p, int card_index);


/**
 * \brief Supprime la carte de la main de la joueuse 
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

 void remove_card_from_hand(player p, card c);


/**
 * \brief Ajoute la carte aux cartes jouées sur la table par la joueuse 
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

 void play_card(player p, card c);


/**
 * \brief Renvoie le nombre de cartes jouées posées sur la table de la joueuse
 * \param p player
 * \return un entier
 */

 int get_number_of_played_cards(player p);


/**
 * \brief Renvoie la carte jouée et posée sur la table par la joueuse dont l'indice est card_index
 * \param p player et card_index une carte
 * \return une carte
 */

 card get_played_card(player p, int card_index);


/**
 * \brief Supprimer la carte de la table de la joueuse
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

 void remove_played_card(player p, card c);


/**
 * \brief Renvoie le pari de la joueuse écrit sur son ardoise, codé avec un entier
 * \param p player
 * \return un entier
 */

 int get_slate(player p);

 
/**
 * \brief Remplace le pari de la joueuse par le pari codé avec l'entier donné en entrée
 * \param p player, n entier
 * \return La fonction ne renvoie rien
 */

 void set_slate(player p, int n);
 
#endif