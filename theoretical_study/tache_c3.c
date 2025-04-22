#include "tache_c3.h"

typedef struct {
    int first;
    int second;
} tirage;

/**
 * \brief computes the size of a list the is made of 1, 2 and 3
 * \param array an array of integers with a sentinel value
 * \return the size of this array
 */
int size_list(int* array) {
    int i = 0;
    while (array[i] == 1 || array[i] == 2 || array[i] == 3) { //Assuming 1, 2 and 3 are the values of the cards
        i++;
    }
    return i;
}

/**
 * \brief tire deux cartes parmi la pioche uniformément
 * \param pioche une liste d'entiers
 * \return un tirage de deux entiers
 */
tirage distrib(int* pioche) {
    int size = size_list(pioche);
    tirage t = {0, 0}; // Initialize with default values
    
    if (size < 2) {
        printf("Erreur : La pioche doit contenir au moins deux cartes.\n");
        return t;
    }
    
    int choice1 = rand() % size;
    t.first = pioche[choice1];
    
    int choice2 = rand() % size;
    while (choice2 == choice1) {
        choice2 = rand() % size;
    }
    t.second = pioche[choice2];
    
    return t;
}

/**
 * \brief Calcule la probabilité de tirer deux cartes de même couleur.
 * \param t un couple de cartes
 * \return la probabilité d'obtenir ce couple de cartes
 */
double P(tirage t) {
    if ((t.first == 1 && t.second == 1) || 
        (t.first == 2 && t.second == 2) || 
        (t.first == 3 && t.second == 3)) {
        return 1.0 / 15.0;
    } 
    else if ((t.first == 1 && t.second == 2) || 
             (t.first == 1 && t.second == 3) || 
             (t.first == 2 && t.second == 3)) {
        return 4.0 / 15.0;
    } 
    else {
        printf("Erreur : couple de cartes non défini.\n");
        return 0.0;
    }
}

/**
 * \brief Crée une pioche de cartes
 * \param
 * \return une pioche de cartes (dynamically allocated)
 */
int * def_pioche() {
    int * pioche = (int *) malloc(7 * sizeof(int));
    
    pioche[0] = 1;
    pioche[1] = 1;
    pioche[2] = 2;
    pioche[3] = 2;
    pioche[4] = 3;
    pioche[5] = 3;
    pioche[6] = -1; // The end of the list
    
    return pioche;
}

/**
 * \brief Tire deux cartes de la pioche du jeu
 * \param
 * \return un tirage
 */
tirage main_J1 () {
    int * pioche = def_pioche();
    tirage t = distrib(pioche);
    free(pioche);
    return t;
}

/**
 * \brief Calcule la probabilité d'obtenir un couple de cartes donné
 * \param i la première carte
 * \param j la seconde carte qui est supérieure à la première
 * \param n le nombre de tirages
 * \return la probabilité d'obtenir ce couple de cartes
 */
double P_approx_1_main(int i, int j, int n) {
    int * pioche = def_pioche();
    int proportion_i_j = 0;
    for (int k = 0 ; k < n ; k++) {
        tirage t = distrib(pioche);
        if ((t.first == i && t.second == j) || (t.first == j && t.second == i)) {
            proportion_i_j++;
        }
    }
    free(pioche);
    return (double)proportion_i_j / n; // Cast proportion_i_j to double for division so it doesn't truncate
}

/**
 * \brief Calcule la probabilité d'obtenir tous les couples de cartes
 * \param n le nombre de tirages
 * \return une liste, qui est la probabilité d'obtenir tous les couples de cartes
 */
double * P_approx_1(int n) {
    double * proportion = (double *) calloc(6, sizeof(double));
    proportion[0] = P_approx_1_main(1,1,n);
    proportion[1] = P_approx_1_main(1,2,n);
    proportion[2] = P_approx_1_main(1,3,n);
    proportion[3] = P_approx_1_main(2,2,n);
    proportion[4] = P_approx_1_main(2,3,n);
    proportion[5] = P_approx_1_main(3,3,n);
    if (proportion[0] + proportion[1] + proportion[2] + proportion[3] + proportion[4] + proportion[5] != 1) {
        printf("Erreur : la somme des probabilités n'est pas égale à 1.\n");
    }
    return proportion;
}