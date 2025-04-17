#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probabiliste.h"
#include "../../include/player.h"
#include "../../include/board.h"
#include "../../include/card.h"
#include "../../include/interface.h"

int main()
{
    FILE *fd = fopen("resultats1.csv", "w");

    if (!fd)
    {
        perror("Erreur ouverture fichier resultats1.csv");
        return 1;
    }
    
    // Initialiser le générateur de nombres aléatoires une seule fois
    srand(time(NULL));
    
    fprintf(fd, "ième partie,n_tours,temps_ms,scores[0],scores[1],victoires\n");
    
    /*on crée 60 parties */
    for (int i = 0; i < 60; i++)
    {
        /*la partie se joue en n tours avec n compris entre 3 et 20*/
        srand(time(NULL) + i); // Different seed for each iteration
        int n = (rand() % 50); // Changer le nombre de tours ici ------------------------------------------
        printf("Valeur de n : %d\n", n);
        
        clock_t debut = clock();
        printf("Début de la partie n°%d ... ", i + 1);
        int* scores = probabiliste(n); /*on lance une partie avec la fonction probabiliste*/
        printf("fin de la partie n°%d\n", i + 1);
        clock_t fin = clock();
        
        if (scores == NULL) {
            fprintf(stderr, "Erreur: probabiliste a retourné NULL\n");
            continue;
        }
        
        printf("Scores (agressive, probabiliste) : %d, %d\n", scores[0], scores[1]);
        double temps_ms = ((double)(fin - debut)) * 1000.0 / CLOCKS_PER_SEC;
        
        // Déterminer le vainqueur
        int victoires = (scores[1] > scores[0]) ? 1 : (scores[0] > scores[1]) ? 0 : -1;
        
        fprintf(fd, "%d,%d,%.2f,%d,%d,%d\n", i + 1, n, temps_ms, scores[0], scores[1], victoires);
        
        // Libérer la mémoire allouée par probabiliste
        free(scores);
        printf("\n");
    }
    
    fclose(fd);
    return 0;
}
