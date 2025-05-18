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
void display_board(board b) {
    printf("Il y a %d équipes\n\n", get_number_of_teams(b));

    team teams[2] = { b->team1, b->team2 };

    for (int t = 0; t < 2; t++) {
        printf("Dans l'équipe %d il y a %d joueuses\n\n", t + 1, get_number_of_players_in_team(b, teams[t].team_id));

        for (int p = 0; p < 2; p++) {
            player pl = get_player(b, teams[t].team_id, p);

            printf("L'identifiant de la %s joueuse est %d\n", p == 0 ? "première" : "deuxième", get_player_id(pl));
            printf("Cette joueuse a %d cartes dans sa main.\n", get_size_of_hand(pl));
            printf("Les valeurs des cartes de sa main sont : \n");
            // for (int i = 0; i < get_size_of_hand(pl); i++) {
            //     card c = get_card_in_hand(pl, i);
            //     printf(
            //         "┌─────────────┐\n"
            //         "│ %d           │\n"
            //         "│             │\n"
            //         "│     %c       │\n"
            //         "│             │\n"
            //         "│          %d  │\n"
            //         "└─────────────┘\n", get_value(c), get_card_colour(c), get_value(c));
            // }
            int hand_size = get_size_of_hand(pl);

            // Print top border
            for (int i = 0; i < hand_size; i++) {
                printf("┌─────────────┐ ");
            }
            printf("\n");

            // Line 1: Card value (top left)
            for (int i = 0; i < hand_size; i++) {
                card c = get_card_in_hand(pl, i);
                printf("│ %-11d │ ", get_value(c));
            }
            printf("\n");

            // Line 2: Empty
            for (int i = 0; i < hand_size; i++) {
                printf("│             │ ");
            }
            printf("\n");

            // Line 3: Card color (centered)
            for (int i = 0; i < hand_size; i++) {
                card c = get_card_in_hand(pl, i);
                printf("│     %c       │ ", get_card_colour(c));
            }
            printf("\n");

            // Line 4: Empty
            for (int i = 0; i < hand_size; i++) {
                printf("│             │ ");
            }
            printf("\n");

            // Line 5: Card value (bottom right)
            for (int i = 0; i < hand_size; i++) {
                card c = get_card_in_hand(pl, i);
                printf("│          %-2d │ ", get_value(c));
            }
            printf("\n");

            // Bottom border
            for (int i = 0; i < hand_size; i++) {
                printf("└─────────────┘ ");
            }
            printf("\n");


            printf("\nElle a joué %d cartes jusque-là\n", get_number_of_played_cards(pl));
            printf("Les valeurs des cartes qu'elle a jouées sont : ");
            for (int k = 0; k < get_number_of_played_cards(pl); k++) {
                card c = get_played_card(pl, k);
                printf("%d %c, ", get_value(c), get_card_colour(c));
            }

            int slate = get_slate(pl);
            if (slate != -1) {
                printf("\nSon pari était %s", slate == 0 ? "défaite" : "victoire");
            }
            printf("\n\n");
        }

        printf("Le score de l'équipe %d est %d\n\n", t + 1, get_score_of_team(b, teams[t].team_id));
    }

    printf("Le nombre de cartes mises de côté est %d\n", get_number_of_out_of_game_cards(b));
    printf("Les valeurs des cartes mises de côté sont : ");
    for (int j = 0; j < get_number_of_out_of_game_cards(b); j++) {
        card c = get_out_of_game_card(b, j);
        printf("%d %c, ", get_value(c), get_card_colour(c));
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
        if (fgets(reponse, sizeof(reponse), stdin) == NULL) // utilisation de fgets pour lire un a un les caractères de la réponse
        {
            fprintf(stderr, "Erreur dans la lecture de la réponse\n");
            exit(1);
        }
        //printf("Réponse invalide, réessayez : "); // enlevé car cause une gêne
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
    int reponse = -1; // pour stocker la réponse; 1 chiffre car les joueuses ont NB_PLAYERS_TEAM*NB_TEAMS cartes max dans les mains
    scanf("%d", &reponse);
    while (reponse < 0 || reponse > get_size_of_hand(p)) // utilisation de scanf pour lire la réponse

    {
        printf("Joueuse %d, veuillez entrer un nombre entre 1 et %d", get_player_id(p), get_size_of_hand(p));
        scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    }
    
    return reponse;
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
        printf("Indice invalide. Veuillez entrer un indice entre 0 et %d ", get_size_of_hand(p)-1);
        scanf("%d",&reponse); // utilisation de scanf pour lire la réponse
    }
    
    //used_indices[reponse] = 1;

    return get_card_in_hand(p, reponse); // on récupère la carte à l'indice donné par la joueuse
}

/** 
\brief : demande à la joueuse une couleur qu'elle souhaite jouer et renvoit cette couleur
\return : char couleur que la joueuse souhaite jouer
*/
char ask_colour() {
    char reponse = 'a';
    printf("Entrez la couleur que vous voulez jouer : " );
    scanf(" %c", &reponse); // utilisation de scanf pour lire la réponse
    while (reponse != 'r' && reponse != 'n' && reponse != 'm') // tant que la réponse n'est pas valide
    {
        printf("Réponse invalide. Veuillez entrer 'r', 'n' ou 'm' : ");
        scanf(" %c", &reponse); // utilisation de scanf pour lire la réponse
    }
    return reponse;
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
        printf("L'équipe victorieuse est l'équie 1\n");
    }
    if(get_score_of_team(b,team1.team_id)<get_score_of_team(b,team2.team_id)) // cas ou le score de l'équipe 2 est supérieur
    {
        printf("L'équipe victorieuse est l'équie 2\n");
    }
    else // cas d'égalité
    {
        printf("Egalité entre les équipes\n");
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