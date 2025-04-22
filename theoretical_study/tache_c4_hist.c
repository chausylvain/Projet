#include <stdio.h>
#include <stdlib.h>
#include "tache_c3.h"

void hist_loi_empirique_C4(int n)
{
    FILE *f = fopen("P_approx_1.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'est bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f," C¹_1,C¹_2,P_approx_1(n)\n"); // Ligne pour les titres des colonnes
    double *tab = P_approx_1(n); //stock les valeurs de P_approx_1(n)
    int k =0;
    while(tab[k]<6)
    {
        for (int i=0; i<4; i++)
        {
            for(int j=i; j<4; j++)
            {
                fprintf(f,"%d,%d,%f",i,j, tab[k] );
                k++;
            }
        }
    }
    fclose(f);
}

void hist_loi_theorique_C4()
{
    FILE *f = fopen("loi_theorique.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
    }
    fprintf(f," C¹_1,C¹_2,P(C¹_1,C¹_2)\n"); // Ligne pour les titres des colonnes
    for(int j=1; j<4; j++)
    {
        for (int i=1; i<=j; i++)
        {
            tirage t = {i,j};
            fprintf(f, "%d,%d,%f\n", i,j,P(t));
        }
    }
    fclose(f);
}
