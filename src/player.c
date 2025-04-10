#include <stdio.h>
#include <stdlib.h>
#include "../include/player.h"
#include "../include/card.h"

struct player_s
{
    card *cards_in_hand;        /*les cartes en main*/
    int hand;                   /*le nombre de cartes en main*/
    card *cards_on_table;       /*les cartes sur la table*/
    int table;                  /*le nombre de cartes sur la table*/
    int ardoise; /*1 =la joueuse a parié victoire et 0=la joueuse a parié défaite */
    int id;                     /*l'identifiant de la joueuse*/
    int team_id;                /*l'identifiant de son équipe*/
};

int creation_id_bis()       /*creer un identifiant id unique qui commence à 0 pour la première joueuse*/
{
    static int id = 0;
    return id++;
}

player player_tab[4];       /*on créer un tableau de joueuses*/


/**
 *  \brief Renvoie un player sans carte en main initialement sans carte en main, sans carte posée sur la table et avec une ardoise vide 
 *  \detail La joueuse a un identifiant unique
 *  \param La fonction ne prend rien en entrée
 *  \return un player
 */

player create_player()
{
    player p = malloc(sizeof(struct player_s));
    if (p == NULL)
    {
        perror("Erreur durant l'allocation");       
        exit(1);
    }
    p->cards_in_hand = malloc(6 * sizeof(card));        
    p->hand = 0;
    p->cards_on_table = malloc (5 * sizeof(card));
    p->table = 0;
    p->ardoise = 0;
    p->id = creation_id_bis();
    player_tab[p->id] = p;      /*l'identifiant de la joueuse est sa place dans le tableau des joueuses*/
    return p;
};


/** 
 * \brief libére la mémoire allouée à la joueuse
 * \param p player
 */

void free_player(player p)
{
    free(p->cards_in_hand);
    free(p->cards_on_table);
    free(p);
}


/**
 * \brief Renvoie l'identifiant de la joueuse
 * \param p player
 * \return un entier
 */
 
int get_player_id(player p)
{
    return p->id;
}


/**
 * \brief Renvoie une joueuse 
 * \param n entier
 * \return player
 */

player get_player_by_id(int n)
{
    if (n >= 0 && n < 4) /*il ny a que 4 joueurs donc les identifiants sont compris entre 0 et 4*/
    {
        return player_tab[n];
    }
    return NULL;
}


/**
 * \brief Ajoute la carte à la main de la joueuse
 * \param p player et c card
 * \return La fonction ne renvoie rien
 */

void add_card_to_hand(player p, card c)
{
    p->cards_in_hand[p->hand] = c;
    p->hand++;          /*le nombre de cartes en main augmente de 1*/
}


/**
 * \brief Renvoie le nombre de cartes dans la main de la joueuse
 * \param p player
 * \return un entier
 */

int get_size_of_hand(player p)
{
    return p->hand;
}


/**
 * \brief Renvoie la carte de la main de la joueuse 
 * \param p player et card_index entier
 * \return une carte 
 */


card get_card_in_hand(player p, int card_index)
{
    return p->cards_in_hand[card_index];
}


/**
 * \brief Supprime la carte de la main de la joueuse 
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

void remove_card_from_hand(player p, card c)
{
    int id_card = get_card_id(c);
    int j = -1;
    for (int i = 0; i < p->hand; i++)
    {
        if (get_card_id(p->cards_in_hand[i]) == id_card)
        {
            free(p->cards_in_hand[i]);
            j = i;          
            break;
        }
    }
    if (j != -1)            /*si j=-1 alors la carte n'est pas en main*/
    {
        for (int i = j; i < p->hand - 1; i++)
        {
            p->cards_in_hand[i] = p->cards_in_hand[i + 1];
        }
        p->hand--;
    }
}


/**
 * \brief Ajoute la carte aux cartes jouées sur la table par la joueuse 
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

void play_card(player p, card c)
{
    p->cards_on_table[p->table] = c;
    p->table = p->table + 1;
}


/**
 * \brief Renvoie le nombre de cartes jouées posées sur la table de la joueuse
 * \param p player
 * \return un entier
 */

int get_number_of_played_cards(player p)
{
    return p->table;
}


/**
 * \brief Renvoie la carte jouée et posée sur la table par la joueuse dont l'indice est card_index
 * \param p player et card_index une carte
 * \return une carte
 */

card get_played_card(player p, int card_index)
{
    return p->cards_on_table[card_index];
}


/**
 * \brief Supprimer la carte de la table de la joueuse
 * \param p player et c une carte
 * \return La fonction ne renvoie rien
 */

void remove_played_card(player p, card c)
{
    int id_card = get_card_id(c);
    int j = -1;
    for (int i = 0; i < p->table; i++)
    {
        if (get_card_id(p->cards_on_table[i]) == id_card)
        {
            free(p->cards_on_table[i]);
            j = i;
            break;
        }
    }
    if (j != -1)        /*si j=-1 alors la carte n'est pas sur la table*/
    {
        for (int i = j; i < p->table - 1; i++)
        {
            p->cards_on_table[i] = p->cards_on_table[i + 1];
        }
        p->table--;
    }
}


/**
 * \brief Renvoie le pari de la joueuse écrit sur son ardoise, codé avec un entier
 * \param p player
 * \return un entier
 */

int get_slate(player p)
{
    return p->ardoise;
}


/**
 * \brief Remplace le pari de la joueuse par le pari codé avec l'entier donné en entrée
 * \param p player, n entier
 * \return La fonction ne renvoie rien
 */

void set_slate(player p, int n)
{
    if (n == 0 || n == 1)
    {
        p->ardoise = n;
    }
    else
    {
        printf("n doit être entre 0 et 1");
    }
}
