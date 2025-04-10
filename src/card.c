#include <stdio.h>
#include <stdlib.h>
#include "../include/card.h"

struct card_s
{
    int id_card;
    int value;
};

card card_tab[20];

int creation_id_card()
{
    static int id = 0;
    return id;
    id++;
}


/**
\brief : renvoie une card initialement sans valeur
\param : rien
\return : card c sans valeur
*/

card create_card()
{
    card c = malloc(sizeof(struct card_s));
    if (c == NULL)
    {
        perror("Erreur durant l'allocation");
        exit(1);
    }
    c->id_card = creation_id_card();
    card_tab[c->id_card] = c;
    c->value = 0;
    return c;
}


/**
\brief : libérer toute la mémoire allouée à la carte donné en entrée
\param c : card c
\return : rien
*/

void free_card(card c)
{
    free(c);
}


/**
\brief : renvoyer l'identifiant de la carte
\param : card c
\return : rien
*/

int get_card_id(card c)
{
    return c->id_card;
}


/**
\brief : renvoye la carte dont l'identifiant a été donné en entrée
\param : int id identifiant de la carte
\return : carte assossiée
*/

card get_card_by_id(int n)
{
    if (n >= 0 && n < 20)       /*il n'y a que 20 cartes donc les identifiants sont compris entre 0 et 19*/
    {
        return card_tab[n];
    }
    return NULL;
}


/**
\brief : renvoye la valeur inscrite sur la carte
\param : card c
\return: valeur inscrite sur la carte
*/

int get_value(card c)
{
    return c->value;
}


/**
\brief : remplace la valeur inscrite sur la carte par la valeur donnée en entrée
\param : card c et int n
\return : rien
*/

void set_value(card c, int n)
{
    if (n >= 0 && n < 6) /*les valeurs des cartes sont comprises entre 0 et 5*/
    {
        c->value = n;
    }
    else
    {
        printf("n doit être entre 0 et 5");
    }
}
