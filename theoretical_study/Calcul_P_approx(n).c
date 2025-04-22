#include <stdio.h>
#include <stdlib.h>
#include " probability_of_hand_empiric.h"

void hist_loi_empirique_C4(int n)
{
    FILE *f = fopen("P_approx_1.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    fprintf(f," C¹_1,C¹_2,P_approx_1(n)\n"); // Ligne pour les titres des colonnes
    int *tab = P_approx_1(n); //stock les valeurs de P_approx_1(n)
    int i =0;
    while(tab[i][2]!=NULL)
    {
        fprintf(f,"%d,%d,%d",C¹_1,C¹_2, tab[i][2] );
        i++;
    }
    fclose(f);
}

void hist_loi_theorique_C4()
{
    FILE *f = fopen("loi_theorique.csv","w"); // ouverture/créée fichier en mode écriture
    if(f == NULL) // vérifie que le fichier s'eest bien ouvert
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    fprintf(f," C¹_1,C¹_2,P(C¹_1,C¹_2)\n"); // Ligne pour les titres des colonnes
    for(int j=1; j<4; j++)
    {
        for (int i=1; i<=j; i++)
        {
            fprintf(f, "%d,%d,%d\n", i,j,P(i,j));
        }
    }
    fclose(f);
}

int main()
{
    int n = 1000;
    hist_loi_empirique_C4(n);
    hist_loi_theorique_C4();
}