#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/board.h"
#include "../include/player.h"
#include "../include/interface.h"
 
/** 
\brief : affiche toutes les infos du jeu (plateau, joueuses, équipes, scores, mains, paris, ...)
\param b: board b défini dans board.h et board.c
\return : rien
*/
 void display_board(board b){
    /* J'utilise les 2 fonctions suivantes mais dans le sujet, le jeu est fixé à 2 équipes de 2 joueuses donc je vais directement utiliser ce fait*/
    printf("Il y a %d équipes\n\n",get_number_of_teams(b)); 
 
    /* Pour la première équipe */
    team team1 = b->team1;
    printf("Dans l'équipe team1 il y a %d joueuses\n\n", get_number_of_players_in_team(b, team1.team_id)); 
    player player1_1 = get_player(b, team1.team_id, 0);
    player player1_2 = get_player(b, team1.team_id, 1);
 
    /* Pour la première joueuse */
    printf("L'identifiant de la première joueuse est %d\n",get_player_id (player1_1) );
    printf("Cette joueuse a %d cartes dans sa main.\n", get_size_of_hand(player1_1) );
    printf("Les valeurs des cartes de sa main sont : ");
    for(int i=0; i<get_size_of_hand(player1_1); i++)
    {
        card c1 = get_card_in_hand(player1_1, i); // Il faut récupérer l'id de la carte
        printf("%d",get_value(c1));
 
        if(i < get_size_of_hand(player1_1)-1){
            printf(", ");
        }
 
    }
    printf("\nElle a joué %d cartes jusque-là\n", get_number_of_played_cards(player1_1) );
    printf("Les valeurs des cartes qu'elle a joué sont: ");
    for(int k=0; k<get_number_of_played_cards(player1_1);k++)
    {
        card c2 = get_played_card(player1_1, k);
        printf("%d",get_value(c2)) ;
 
    }
    printf("\nSon pari est %d, pourquoi print ça ici \n", get_slate(player1_1) );
 
    /* Pour la deuxième joueuse */
    printf("\n");
 
    printf("L'identifiant de la deuxième joueuse est %d\n",get_player_id (player1_2) );
    printf("Cette joueuse a %d cartes dans sa main.\n", get_size_of_hand(player1_2) );
    printf("Les valeurs des cartes de sa main sont : ");
    for(int i=0; i<get_size_of_hand(player1_2); i++)
    {
        card c1 = get_card_in_hand (player1_2, i);
        printf("%d",get_value(c1));
 
        if(i < get_size_of_hand(player1_2)-1){
            printf(", ");
        }
    }
    printf("\nElle a joué %d cartes jusque-là\n", get_number_of_played_cards(player1_2) );
    printf("Les valeurs des cartes qu'elle a joué sont: ");
    for(int k=0; k<get_number_of_played_cards(player1_2);k++)
    {
        card c2 = get_played_card(player1_2, k);
        printf("%d\n",get_value(c2));
 
    }
    printf("\nSon pari est %d, pourquoi print ça ici \n", get_slate(player1_2) );
 
    printf("\nLe score de l'équipe 1 est %d\n\n", get_score_of_team(b, team1.team_id));
 
   /* Pour la deuxième équipe */
    team team2 = b->team2;
    printf("Dans l'équipe team2 il y a %d joueuses\n", get_number_of_players_in_team(b, team2.team_id));
    player player2_1 = get_player(b, team2.team_id, 0);
    player player2_2 = get_player(b, team2.team_id, 1);
 
    /* Pour la première joueuse */
    printf("\n");
 
    printf("L'indentifiant de la première joueuse est %d\n",get_player_id (player2_1) );
    printf("Cette joueuse a %d cartes dans sa main \n", get_size_of_hand(player2_1) );
    printf("Les valeurs des cartes de sa main sont : ");
    for(int i=0; i<get_size_of_hand(player2_1); i++)
    {
        card c1 = get_card_in_hand (player2_1, i);
        printf("%d",get_value(c1));
 
        if(i < get_size_of_hand(player2_1)-1){
            printf(", ");
        }
 
    }
    printf("\nElle a joué %d cartes jusque-là\n", get_number_of_played_cards(player2_1) );
    printf("Les valeurs des cartes qu'elle a joué sont:");
    for(int k=0; k<get_number_of_played_cards(player2_1);k++)
    {
        card c2 = get_played_card(player2_1, k);
        printf("%d",get_value(c2));
 
    }
    printf("\nSon pari est %d, pourquoi print ça ici \n", get_slate(player2_1) );
 
    /* Pour la deuxième joueuse */
 
    printf("\n");
 
    printf("L'indentifiant de la deuxième joueuse est %d\n",get_player_id (player2_2) );
    printf("Cette joueuse a %d cartes dans sa main\n", get_size_of_hand(player2_2) );
    printf("Les valeurs des cartes de sa main sont :");
    for(int i=0; i<get_size_of_hand(player2_2); i++)
    {
        // Il faut récupérer l'id de la carte
        card c1 = get_card_in_hand (player2_2, i);
        printf("%d",get_value(c1));
 
        if(i < get_size_of_hand(player2_2)-1){
            printf(", ");
        }
 
    }
    printf("\nElle a joué %d cartes jusque-là\n", get_number_of_played_cards(player2_2) );
    printf("Les valeurs des cartes qu'elle a joué sont: ");
    for(int k=0; k<get_number_of_played_cards(player2_2);k++)
    {
        card c2 = get_played_card(player2_2, k);
        printf("%d,",get_value(c2));
 
    }
    printf("\nSon pari est %d, pourquoi print ça ici \n\n", get_slate(player2_2) );
 
    printf("Le score de l'équipe 2 est %d\n\n", get_score_of_team(b, team2.team_id));
 
    printf("Le nombre de cartes mises de côté est %d\n\n", get_number_of_out_of_game_cards(b));
    printf("Les valeurs des cartes mises des coté sont:\n");
    for(int j=0; j<get_number_of_out_of_game_cards(b); j++)
    {
        card c3 = get_out_of_game_card(b, j);
        printf("%d\n",get_value(c3));
    }
 
 }
 
/**
\brief : demande à la joueuse de donner son pari et renvoyer un entier encodant ce pari 
\param p : player p défini dans player.h et player.c
\return : entier i encodant le pari
*/
int ask_gamble(player p){
    int gamble = -1; // initialisation de la variable gamble
    printf("Joueuse %d, quel est votre pari ? ", get_player_id(p));
    char reponse[11]; // 8 caractères dans "Victoire" et 7 dans "Défaite" + "\n" et "\0"
    if (fgets(reponse, sizeof(reponse), stdin) == NULL) // utilisation de fgets pour lire un a un les caractères de la réponse
    {
        fprintf(stderr, "Erreur dans la lecture de la réponse\n");
        exit(1);
    } 
 
    while (strstr(reponse, "v") == NULL && strstr(reponse, "d") == NULL) // tant que la réponse ne contient pas "Victoire" ou "Defaite"
    {
        printf("Réponse invalide. Veuillez entrer 'Victoire' ou 'Defaite'.\n");
        if (fgets(reponse, sizeof(reponse), stdin) == NULL) // utilisation de fgets pour lire un a un les caractères de la réponse
        {
            fprintf(stderr, "Erreur dans la lecture de la réponse\n");
            exit(1);
        } 
    }
    {
        /* code */
    }
 
 
    if(strstr(reponse, "v") != NULL) // si la réponse contient "Victoire"
    {
        gamble = 1; // pari de victoire
    }
    else if(strstr(reponse, "d") != NULL) // si la réponse contient "Defaite"
    {
        gamble = 0; // pari de défaite
    }
 
    return gamble; // valeur par défaut si la réponse n'est pas reconnue
}
 
 
/**
\brief : demande à la joueuse combien de cartes elle souhaite poser sur la table et renvoyer ce nombre
\param p : player p défini dans player.h et player.c
\return : entier i renvoyant le nombre sur la carte
*/
int ask_number_of_played_cards(player p){
    printf("Joueuse %d, combien de cartes souhaitez-vous poser ? ", get_player_id(p));
    int reponse; // pour stocker la réponse; 1 chiffre car les joueuses ont 5 cartes max dans les mains
    if (scanf("%d",&reponse)==1) // utilisation de scanf pour lire la réponse
    {
        return reponse;
    }
    else 
    {
        fprintf(stderr, "Erreur dans la lecture de la réponse\n");
        exit(1);
    }
    
    /*
    printf("Joueuse %d, combien de cartes souhaitez-vous poser ? ", get_player_id(p));
    int reponse = 0; // pour stocker la réponse; 1 chiffre car les joueuses ont 5 cartes max dans les mains
    scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    while (reponse < 0 || reponse > get_size_of_hand(p)) // utilisation de scanf pour lire la réponse
    {
        printf("Joueuse %d, veuillez entrer un nombre entre 1 et %d ", get_player_id(p), get_size_of_hand(p));
        scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    }
    
    return reponse;
    */
}
 
 
/** 
\brief : demande à la joueuse une carte de sa main qu'elle souhaite jouer et renvoyer cette carte 
\param p : player p défini dans player.h et player.c
\return : carte c que la joueuse souhaite jouer
*/
card ask_card(player p){
    int reponse = 0;
    //static int used_indices[5] = {0}; 
    printf("Entrez l'indice de la carte que vous voulez jouer (0 à %d) ", get_size_of_hand(p)-1); // on demande à la joueuse de choisir une carte
    scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    //printf("test\n");
    while (reponse < 0 || reponse >= get_size_of_hand(p) /*|| used_indices[reponse]*/)
    {/*
        if(used_indices[reponse]) // si la carte a déjà été jouée
        {
            printf("Cette carte a déjà été jouée. Veuillez en choisir un autre indice.\n");
        }
        else // si l'indice est hors limites
        {
            printf("Indice invalide. Veuillez entrer un indice entre 0 et %d.\n", get_size_of_hand(p)-1);
        }
        */
        printf("Indice invalide. Veuillez entrer un indice entre 0 et %d.\n", get_size_of_hand(p)-1);
        scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    }
    
    //used_indices[reponse] = 1;

    return get_card_in_hand(p, reponse); // on récupère la carte à l'indice donné par la joueuse
}
 
 
/* 
\brief : affiche un message de fin de jeu avec les informations associées 
\param b : board b défini dans board.h et board.c
\return : rien
*/
void display_end_game(board b)
{
    printf("Fin du jeu !\n");
    team team1= b->team1;
    team team2= b->team2;
    if(get_score_of_team(b,team1.team_id)>get_score_of_team(b,team2.team_id)) // cas ou le score de l'équipe 1 est supérieur
    {
        printf("l'équipe victorieuse est l'équie team1 ");
    }
    if(get_score_of_team(b,team1.team_id)<get_score_of_team(b,team2.team_id)) // cas ou le score de l'équipe 2 est supérieur
    {
        printf("l'équipe victorieuse est l'équie team2 ");
    }
    else // cas d'égalité
    {
        printf("Egalité entre les équipes");
    }
}
 
/*/
\brief : affiche le message donné en entrée 
\param c : char* c message à renvoyer
\return : rien
*/
void display_message(char* c)
{
    if (c!= NULL)
    {
        printf("%s\n", c);
    }
 
}