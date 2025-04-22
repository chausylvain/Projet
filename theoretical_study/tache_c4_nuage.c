#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"

void nuage_points_C4()
{
    FILE *f = fopen("nuage_C4.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
  
    }
    fprintf(f,"n,P_approx_1(i,j,n)\n"); // Ligne pour les titres des colonnes
    for(int n=10; n<100000; n++)
    {
        fprintf(f, "%d,%f\n",n,P_approx_1_main(1,2,n));
    }
    fclose(f);
   
}

void droite_C4()
{
    FILE *f = fopen("droite_C4.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        
    }
    tirage t = {1,2};
    fprintf(f,"y\n"); // Ligne pour les titres de la colonne
    fprintf(f, "%f\n",P(t));
    fclose(f);
   
}
