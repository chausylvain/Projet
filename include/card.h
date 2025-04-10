#include <stdio.h>
#include <stdlib.h>

#ifndef _CARD_
#define _CARD_

/**
\brief : type abstrait card permettant d'accéder à toutes les infos d'une carte
d'après le sujet : paquet de 20 cartes, numérotées de 1 à 5. Il y a 4 cartes de chaque type */
typedef struct card_s *card;
;

/**
\brief : renvoie une card initialement sans valeur
\param : rien
\return : card c sans valeur
*/
card create_card();

/**
\brief : libérer toute la mémoire allouée à la carte donné en entrée
\param c : card c
\return : rien
*/
void free_card(card c);

/**
\brief : renvoyer l'identifiant de la carte
\param : card c
\return : rien
*/
int get_card_id(card c);

/**
\brief : renvoye la carte dont l'identifiant a été donné en entrée
\param : int id identifiant de la carte
\return : carte assossiée
*/
card get_card_by_id(int id);

/**
\brief : renvoye la valeur inscrite sur la carte
\param : card c
\return: valeur inscrite sur la carte
*/
int get_value(card c);

/**
\brief : remplace la valeur inscrite sur la carte par la valeur donnée en entrée
\param : card c et int n
\return : rien
*/
void set_value(card c, int n);

#endif
