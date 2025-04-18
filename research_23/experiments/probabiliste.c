// Pour la facilité d'implémentation, le code reprend des bouts de code du main.c, qui malheureusement ne pouvait pas être modulaire selon les consignes, afin de recréer le déroulement du jeu

#include "probabiliste.h"
#include "../../include/board.h"
#include "../../include/card.h"
#include "../../include/player.h"
#include <time.h>
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>

// HERE is where the main is modified

int * agressive_probabiliste_method(int team_id_agressive_method, int team_id_probabiliste_method, int NB_ROUNDS) {

    // HERE
    if (team_id_agressive_method !=0 && team_id_probabiliste_method != 1) {
        printf("Error: team_id_agressive_method and team_id_probabiliste_method must be 0 and 1 respectively\n");
        return NULL;
    }
    else if (team_id_probabiliste_method != 0 && team_id_probabiliste_method != 1) {
        printf("Error: team_id_agressive_method and team_id_probabiliste_method must be 0 and 1 respectively\n");
        return NULL;
    }

    /* Initialisation du plateau */
    board b = create_board();
    
    /* Ajout des équipes et des joueuses */
    int count = 0;
    
    card* card_tot = malloc(NB_CARDS * sizeof(card));
    if (card_tot == NULL) {
        printf("Error: memory allocation failed for card_tot\n");
        free_board(b);
        return NULL;
    }

    for (int i = 0; i < NB_TEAMS; i++) {
        add_team(b);
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = create_player();
            add_player_to_team(b, i, p);

            /* Distribution des cartes */
            for (int k = 0; k < (NB_CARDS/(NB_TEAMS*NB_PLAYERS_TEAM)); k++) { // CHANGE THAT IN LOT B FOR GENERALIZATION-----------------------------------------------------------------------
                card c = create_card();
                set_value(c, (k + 1)%6); // %6 PERMET DE FIXER LA VALUE MAX -------------------------------------- 
                card_tot[count] = c;
                count++;
            }
        }
    }
    /* Distribution des cartes */
    int index[NB_CARDS];
    
    for (int i = 0; i < NB_CARDS; i++) {
        index[i] = i;
    }

    for (int i = NB_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = index[i];
        index[i] = index[j];
        index[j] = temp;
    }

    count = 0;

    for (int i = 0; i < NB_TEAMS; i++) {
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            for (int k = 0; k < (NB_CARDS/(NB_TEAMS*NB_PLAYERS_TEAM)); k++) { // CHANGE THAT IN LOT B FOR GENERALIZATION ---------------------------------------------------------------------------
                player p = get_player(b, i, j); 
                card c = card_tot[index[count]];
                add_card_to_hand(p, c);
                count++;
            }
        }
    }

    /* Déroulement des tours */

    for (int round = 0; round < NB_ROUNDS; round++) {
        /* Phase de pari */
        
        // HERE
        int gamble_type = 0;

        for (int i = 0; i < NB_TEAMS; i++) {
            // HERE
            // si l'id de l'équipe est celui de la méthode agressive, on parie en utilisant la méthode agressive, sinon, on utilise la méthode probabiliste
            if (i == team_id_agressive_method) {
                for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                    player p = get_player(b, i, j);
                    card smallest_card = get_card_in_hand(p, 0);
                    card highest_card = get_card_in_hand(p, 0);
                    for (int k = 1; k < get_size_of_hand(p); k++) {
                        card current_card = get_card_in_hand(p, k);
                        if (get_value(current_card) > get_value(highest_card)) {
                            highest_card = current_card;
                        }
                        if (get_value(current_card) < get_value(smallest_card)) {
                            smallest_card = current_card;
                        }
                    }
                    int value_of_smallest_card = get_value(smallest_card);
                    int value_of_highest_card = get_value(highest_card);
                    int gamble;
                    if (value_of_smallest_card - 1 >= 5 - value_of_highest_card) {
                        gamble = 1; // Victoire
                    }
                    else {
                        gamble = 0; // Défaite
                    }

                    set_slate(p, gamble);
                    gamble_type = 4;
                }
            }
            else {
                for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                    player p = get_player(b, i, j);
                    // HERE
                    // calcule la moyenne de de la valeurs des autres joueurs moins les cartes déjà jouées (c'est une même moyenne)
                    int total_value_of_all_cards = NB_PLAYERS_TEAM*NB_TEAMS*5+NB_PLAYERS_TEAM*NB_TEAMS*4+NB_PLAYERS_TEAM*NB_TEAMS*3+NB_PLAYERS_TEAM*NB_TEAMS*2+NB_PLAYERS_TEAM*NB_TEAMS*1;
                    int total_value_of_played_cards = 0;
                    for (int k = 0; k < NB_TEAMS; k++) {
                        for (int l = 0; l < NB_PLAYERS_TEAM; l++) {
                            player other_player = get_player(b, k, l);
                            if (other_player != p) {
                                for (int m = 0; m < get_size_of_hand(other_player); m++) {
                                    card current_card = get_card_in_hand(other_player, m);
                                    total_value_of_played_cards += get_value(current_card);
                                }
                            }
                        }
                    }
                    //int average_value_of_played_cards = total_value_of_played_cards / (NB_TEAMS*NB_PLAYERS_TEAM - 1);
                    int average_value_of_remaining_cards = (total_value_of_all_cards - total_value_of_played_cards) / (NB_TEAMS*NB_PLAYERS_TEAM - 1);
                    // cherche si une ou deux cartes du joueur courant sont plus fortes que la moyenne
                    for (int k = 0; k < get_size_of_hand(p); k++) {
                        card current_card = get_card_in_hand(p, k);
                        if (get_value(current_card) > average_value_of_remaining_cards) {
                            // si une carte est plus forte que la moyenne, le joueur parie
                            set_slate(p, 1);
                            gamble_type = 1;
                            break;
                        }
                    }
                    // si aucune des cartes n'est plus forte que la moyenne, on teste avec deux cartes
                    if (get_slate(p) == 0) {
                        for (int k = 0; k < get_size_of_hand(p); k++) {
                            for (int l = k + 1; l < get_size_of_hand(p); l++) {
                                card current_card_1 = get_card_in_hand(p, k);
                                card current_card_2 = get_card_in_hand(p, l);
                                if (get_value(current_card_1) + get_value(current_card_2) > average_value_of_remaining_cards) {
                                    // si deux cartes sont plus fortes que la moyenne, le joueur parie
                                    set_slate(p, 1);
                                    gamble_type = 2;
                                    break;
                                }
                            }
                        }
                    }
                    // si aucune des cartes n'est plus forte que la moyenne, le joueur parie sa plus faible carte et la défaite
                    if (get_slate(p) == 0) {
                        // on cherche la plus faible carte du joueur
                        gamble_type = 3;
                        card smallest_card = get_card_in_hand(p, 0);
                        for (int k = 1; k < get_size_of_hand(p); k++) {
                            card current_card = get_card_in_hand(p, k);
                            if (get_value(current_card) < get_value(smallest_card)) {
                                smallest_card = current_card;
                            }
                        }
                        set_slate(p, 0);
                    }
                }
            }
        }

        /* Phase de jeu */

        int team_scores[NB_TEAMS] = {0, 0};

        for (int i = 0; i < NB_TEAMS; i++) {
            if (i == team_id_agressive_method) {
                for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                    player p = get_player(b, i, j);

                    // HERE
                    int gamble = get_slate(p);
                    if (gamble == 1) {
                        // Play the two highest cards if there are two cards left or else play the only card
                        if (get_size_of_hand(p) == 2) {
                            card highest_card_1 = get_card_in_hand(p, 0);
                            card highest_card_2 = get_card_in_hand(p, 1);

                            for (int k = 2; k < get_size_of_hand(p); k++) {
                                card current_card = get_card_in_hand(p, k);
                                if (get_value(current_card) > get_value(highest_card_1)) {
                                    highest_card_2 = highest_card_1;
                                    highest_card_1 = current_card;
                                } else if (get_value(current_card) > get_value(highest_card_2)) {
                                    highest_card_2 = current_card;
                                }
                            }
                            play_card(p, highest_card_1);
                            remove_card_from_hand(p, highest_card_1);
                            play_card(p, highest_card_2);
                            remove_card_from_hand(p, highest_card_2);
                            team_scores[i] += get_value(highest_card_1) + get_value(highest_card_2);
                        } else if (get_size_of_hand(p) == 1) {
                            card only_card = get_card_in_hand(p, 0);
                            play_card(p, only_card);
                            remove_card_from_hand(p, only_card);
                            team_scores[i] += get_value(only_card);
                        }
                    } else {
                        // Play the lowest card
                        card smallest_card = get_card_in_hand(p, 0);
                        for (int k = 1; k < get_size_of_hand(p); k++) {
                            card current_card = get_card_in_hand(p, k);
                            if (get_value(current_card) < get_value(smallest_card)) {
                                smallest_card = current_card;
                            }
                        }
                        play_card(p, smallest_card);
                        remove_card_from_hand(p, smallest_card);
                        team_scores[i] += get_value(smallest_card);
                    }
                }
            }
            else {
                for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                    player p = get_player(b, i, j);
    
                    // HERE
                    //int gamble = get_slate(p);
                    if (gamble_type == 0) {
                        printf("This should not happen\n");
                    }
                    if (gamble_type == 1) {
                        // Play the two highest cards, careful if the hand only contains one card (it should have been checked before)
                        if (get_size_of_hand(p) == 2) {
                            card highest_card_1 = get_card_in_hand(p, 0);
                            card highest_card_2 = get_card_in_hand(p, 1);
    
                            for (int k = 2; k < get_size_of_hand(p); k++) {
                                card current_card = get_card_in_hand(p, k);
                                if (get_value(current_card) > get_value(highest_card_1)) {
                                    highest_card_2 = highest_card_1;
                                    highest_card_1 = current_card;
                                } else if (get_value(current_card) > get_value(highest_card_2)) {
                                    highest_card_2 = current_card;
                                }
                            }
                            play_card(p, highest_card_1);
                            remove_card_from_hand(p, highest_card_1);
                            play_card(p, highest_card_2);
                            remove_card_from_hand(p, highest_card_2);
                            team_scores[i] += get_value(highest_card_1) + get_value(highest_card_2);
                        } else if (get_size_of_hand(p) == 1) {
                            card only_card = get_card_in_hand(p, 0);
                            play_card(p, only_card);
                            remove_card_from_hand(p, only_card);
                            team_scores[i] += get_value(only_card);
                        }
    
                    } 
                    else if (gamble_type == 2) {
                        // Play the one highest card
                        card highest_card_1 = get_card_in_hand(p, 0);
                        for (int k = 1; k < get_size_of_hand(p); k++) {
                            card current_card = get_card_in_hand(p, k);
                            if (get_value(current_card) > get_value(highest_card_1)) {
                                highest_card_1 = current_card;
                            }
                        }
                        play_card(p, highest_card_1);
                        remove_card_from_hand(p, highest_card_1);
                        team_scores[i] += get_value(highest_card_1);
                    }
                    else {
                        // Play the lowest card
                        card smallest_card = get_card_in_hand(p, 0);
                        for (int k = 1; k < get_size_of_hand(p); k++) {
                            card current_card = get_card_in_hand(p, k);
                            if (get_value(current_card) < get_value(smallest_card)) {
                                smallest_card = current_card;
                            }
                        }
                        play_card(p, smallest_card);
                        remove_card_from_hand(p, smallest_card);
                        team_scores[i] += get_value(smallest_card);
                    }
                }
            }
        }

        /* Détermination du gagnant du tour */

        int max_score = 0;
        int winning_team = 1;

        for (int i = 0; i < NB_TEAMS; i++) {
            if (team_scores[i] > max_score) {
                max_score = team_scores[i];
                winning_team = i;
            }
        }
        // Regarde s'il y a égalité en toutes les équipes
        int draw = 1; // Suppose égalité au départ

        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = i + 1; j < NB_TEAMS; j++) { // j = i + 1 pour éviter i == j
                if (team_scores[i] != team_scores[j]) {
                    draw = 0; // Pas d'égalité
                    break;
                }
            }
            if (!draw) break; // Sortir aussi de la boucle extérieure
        }
        
        if (draw) {
            winning_team = -1;
        }
            
        /* Attribution des points */
    
        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                int gamble = get_slate(p);
                if (winning_team == i && gamble == 1) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                } 
                else if (winning_team != i && gamble == 0) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                }
                else if (winning_team == -1) {
                    set_score_of_team(b, i, get_score_of_team(b, i) + 1);
                } // si égalité, toute le monde gagne
            }
        }
    }
        
    /* Fin du jeu */
    
    /* Copier les scores avant de libérer la mémoire */
    int * scores = malloc(NB_TEAMS * sizeof(int));
    if (scores == NULL) {
        printf("Error: memory allocation failed for scores\n");
        
        // Nettoyer la mémoire avant de quitter
        free(card_tot);
        for (int i = 0; i < NB_TEAMS; i++) {
            for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
                player p = get_player(b, i, j);
                free_player(p);
            }
        }
        free_board(b);
        return NULL;
    }
    
    for (int i = 0; i < NB_TEAMS; i++) {
        scores[i] = get_score_of_team(b, i);
    }
    
    // Before freeing card_tot
    for (int i = 0; i < NB_CARDS; i++) {
        free_card(card_tot[i]);
    }
    free(card_tot);
    
    for (int i = 0; i < NB_TEAMS; i++) {
        for (int j = 0; j < NB_PLAYERS_TEAM; j++) {
            player p = get_player(b, i, j);
            free_player(p);
        }
    }
    
    free_board(b);
    
    return scores;
}

int * probabiliste(/*int * distrib, int nb_teams, int nb_card_each_turn*/ int number_of_rounds) {
    // One team must play one method and the other team must use the other method
    int team_id_agressive_method = 0;
    int team_id_probabiliste_method = 1;
    int *result = agressive_probabiliste_method(team_id_agressive_method, team_id_probabiliste_method, number_of_rounds);
    
    // Reset global state after each call
    reset_player_id_counter();
    reset_card_id_counter();
    reset_global_array1();
    reset_global_array2();
    
    return result;
}