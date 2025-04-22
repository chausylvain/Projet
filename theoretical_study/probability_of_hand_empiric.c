typedef struct {
    int first;
    int second;
} tirage;

/**
 * \brief computes the size of a linked list
 * \param linked_list a linked list
 * \return the size of this list
 */
int size_list(int * linked_list) {
    int i = 0;
    while (linked_list[i] != "\0") {
        i++;
    }
    return i;
}

/**
 * \brief tire deux cartes parmi la pioche
 * \param pioche une linked list
 * \return un tirage
 */
tirage distrib(int * pioche) {
    int size = size_list(pioche);
    if (size < 2) {
        printf("Erreur : La pioche doit contenir au moins deux cartes.\n");
    }
    tirage t;
    int choice1, choice2;
    choice1 = rand() % size;
    t.first = pioche[choice1];
    choice2 = rand() % size;
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
    }
}

/**
 * \brief Crée une pioche de cartes
 * \param
 * \return une pioche de cartes
 */
int * def_pioche(){
    int * pioche = (int *) malloc(6 * sizeof(int));
    pioche[0] = 1;
    pioche[1] = 1;
    pioche[2] = 2;
    pioche[3] = 2;
    pioche[4] = 3;
    pioche[5] = 3;
    return pioche;
}

/**
 * \brief Tire deux cartes de la pioche du jeu
 * \param
 * \return un tirage
 */
tirage mainJ1 () {
    int * pioche = def_pioche();
    tirage t = distrib(pioche);
    return t;
}

/**
 * \brief Calcule la probabilité d'obtenir un couple de cartes donné
 * \param i la première carte
 * \param j la seconde carte qui est supérieure à la première
 * \param n le nombre de tirages
 * \return la probabilité d'obtenir ce couple de cartes
 */
double P_approx_1(int i,int j, int n) {
    int * pioche = def_pioche();
    int proportion_i_j;
    for (int k = 0 ; k < n ; k++) {
        tirage t = distrib(pioche);
        if (t.first == i && t.second == j) {
            proportion_i_j++;
        }
    }
    return proportion_i_j / n;
}

/**
 * \brief Calcule la probabilité d'obtenir tous les couples de cartes
 * \param n le nombre de tirages
 * \return une liste, qui est la probabilité d'obtenir tous les couples de cartes
 */
double * P_approx_1(int n) {
    int * proportion = (int *) calloc(6 * sizeof(tirage));
    proportion[0] = P_approx_1(1,1,n);
    proportion[1] = P_approx_1(1,2,n);
    proportion[2] = P_approx_1(1,3,n);
    proportion[3] = P_approx_1(2,2,n);
    proportion[4] = P_approx_1(2,3,n);
    proportion[5] = P_approx_1(3,3,n);
    return proportion;
}