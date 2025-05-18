#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"

#ifndef _INTERFACE_
#define _INTERFACE_

/** 
\brief : affiche toutes les infos du jeu (plateau, joueuses, équipes, scores, mains, paris, ...)
\param b: board b défini dans board.h et board.c
\return : rien
*/
 void display_board(board b);


/**
\brief : demande à la joueuse de donner son pari et renvoyer un entier encodant ce pari 
\param p : player p défini dans player.h et player.c
\return : entier i encodant le pari
*/

int ask_gamble(player p);


/**
\brief : demande à la joueuse combien de cartes elle souhaite poser sur la table et renvoyer ce nombre
\param p : player p défini dans player.h et player.c
\return : entier i renvoyant le nombre sur la carte
*/
int ask_number_of_played_cards(player p);


/** 
\brief : demande à la joueuse une carte de sa main qu'elle souhaite jouer et renvoyer cette carte 
\param p : player p défini dans player.h et player.c
\return : carte c que la joueuse souhaite jouer
*/
card ask_card(player p);

/** 
\brief : NOUVELLE FONCTION TÂCHE E, demande à la joueuse une couleur qu'elle souhaite jouer et renvoit cette couleur
\return : char couleur que la joueuse souhaite jouer
*/
char ask_colour();

/* 
\brief : affiche un message de fin de jeu avec les informations associées 
\param b : board b défini dans board.h et board.c
\return : rien
*/
void display_end_game(board b);

/*/
\brief : affiche le message donné en entrée 
\param c : char* c message à renvoyer
\return : rien
*/
void display_message(char* c);

#endif