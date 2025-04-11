#include "../include/board.h"
#include "../include/card.h"
#include "../include/player.h"


board create_board() {
    board b = malloc(sizeof(*b));
    b->team1.team_id = -1;
    b->team2.team_id = -1;
    b->team1.score = 0;
    b->team2.score = 0;
    b->team1.player1 = NULL;
    b->team1.player2 = NULL;
    b->team2.player1 = NULL;
    b->team2.player2 = NULL;
    for (int i = 0; i < NB_CARDS; i++) {
        b->out_of_game_cards[i] = 0;
    }
    return b;
}

void free_board(board b) {
    free(b);
}

void add_team(board b) {
    if (b->team1.team_id == -1) {
        b->team1.team_id = 0;
    }

    else if (b->team2.team_id == -1) {
        b->team2.team_id = 1;
    }
    else {
        printf("Error: too many teams\n");
    }
}

int get_number_of_teams(board b) {
    int count = 0;
    if (b->team1.team_id != -1) {
        count++;
    }
    if (b->team2.team_id != -1) {
        count++;
    }
    return count;
}

void add_player_to_team(board b, int team_id, player player) {
    if (b->team1.team_id == team_id) {
        if (b->team1.player1 == NULL) {
            b->team1.player1 = player;
        }
        else if (b->team1.player2 == NULL) {
            b->team1.player2 = player;
        }
        else {
            printf("Error: too many players\n");
        }
    }
    
    if (b->team2.team_id == team_id) {
        if (b->team2.player1 == NULL) {
            b->team2.player1 = player;
        }
        else if (b->team2.player2 == NULL) {
            b->team2.player2 = player;
        }
        else {
            printf("Error: too many players\n");
        }
    }

    if(!(b->team1.team_id == team_id) && !(b->team2.team_id == team_id)) {
        printf("Error: wrong team id\n");
    }

}

int get_number_of_players_in_team(board b, int team_id) {
    int count = 0;
    if (b->team1.team_id == team_id) {
        if (b->team1.player1 != NULL) {
            count++;
        }
        if (b->team1.player2 != NULL) {
            count++;
        }
    }
    else if (b->team2.team_id == team_id) {
        if (b->team2.player1 != NULL) {
            count++;
        }
        if (b->team2.player2 != NULL) {
            count++;
        }
    }
    return count;
}

player get_player(board b, int team_id, int player_index) {
    if (b->team1.team_id == team_id) {
        if (player_index == 0) {
            return b->team1.player1;
        }
        else if (player_index == 1) {
            return b->team1.player2;
        }
        else {
            printf("Error: wrong player index\n");
        }
    }
    else if (b->team2.team_id == team_id) {
        if (player_index == 0) {
            return b->team2.player1;
        }
        else if (player_index == 1) {
            return b->team2.player2;
        }
        else {
            printf("Error: wrong player index\n");
        }
    }
    else {
        printf("Error: wrong team id\n");
    }
    printf("Unknown error in get_player\n");
    return NULL;
}

int get_score_of_team(board b, int team_id) {
    if (b->team1.team_id == team_id) {
        return b->team1.score;
    }
    else if (b->team2.team_id == team_id) {
        return b->team2.score;
    }
    else {
        printf("Error: wrong team id\n");
        return -1;
    }
    printf("Unknown error in get_score_of_team\n");
    return -1;
}

void set_score_of_team(board b, int team_id, int score) {
    if (b->team1.team_id == team_id) {
        b->team1.score = score;
    }
    else if (b->team2.team_id == team_id) {
        b->team2.score = score;
    }
    else {
        printf("Error: wrong team id\n");
        return;
    }
}

void add_out_of_game_card(board b, card c) {
    // On récupère le nombre actuel de cartes hors jeu
    int count = get_number_of_out_of_game_cards(b);
    
    // On vérifie si le tableau n'est pas plein
    if (count < NB_CARDS) {
        b->out_of_game_cards[count] = c;
    }
    else {
        printf("Error: out of game cards array is full\n");
    }
}

int get_number_of_out_of_game_cards(board b) {
    int count = 0;
    
    // On parcourt le tableau jusqu'à trouver une carte nulle (0)
    // ou jusqu'à atteindre la fin du tableau
    while (count < NB_CARDS && b->out_of_game_cards[count] != 0) {
        count++;
    }
    
    return count;
}

card get_out_of_game_card(board b, int card_index) {
    if (b->out_of_game_cards[card_index] == 0) {
        printf("Error: no card at this index\n");
        return NULL;
    }
    return b->out_of_game_cards[card_index];
}

void remove_out_of_game_card(board b, card c) {
    int i = 0;
    while (b->out_of_game_cards[i] != c) {
        i++;
        if (i >= NB_CARDS) {
            printf("Error: card not found\n");
            return;
        }
    }
    b->out_of_game_cards[i] = 0;
}