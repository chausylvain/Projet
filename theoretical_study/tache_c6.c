#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 
\brief :  simule la distribution des cartes à J2 en prenant en argument la main (i,j) de J1
\param : i et j entiers, cartes de J1
\return : rien
*/

int* main_J2(int i, int j)
{
    int cartes[4]; // préparation d'un tableau pour stocker les cartes qu'il rest dans le jeu
    int n1 = 2; // initialisation à 2 des entiers qui représentent le nombre de chaque cartes restantes
    int n2 = 2;
    int n3 = 2;
    if (i == 1) // si i = 1 alors n1 décroit car J2 ne pourra pas avoir cette carte
    {
        n1 = n1-1;
    }
    if ( i == 2)
    {
        n2 = n2-1;
    }
    if (i == 3)
    {
        n3 = n3-1;
    }
    if (j == 1)
    {
        n1=n1-1;
    }
    if (j == 2)
    {
        n2 = n2-1;
    }
    if (j == 3)
    {
        n3 = n3-1;
    }
    if(n1+n2+n3 != 4) // vérification qu'il ya bien 4 cartes dans le jeu
    {
        perror("erreur dans le comptage des cartes de J1");
        exit(1);
    }
    int index = 0;
    for (int k1=0; k1<n1; k1++)
    {
        cartes[index++]= 1;
    }
    for (int k2=0; k2<n2; k2++)
    {
        cartes[index++]= 2;
    }
    for (int k3=0; k3<n3; k3++)
    {
        cartes[index++]= 3;
    }
    int* tab_main_J2 = malloc(2 * sizeof(int));
    if (tab_main_J2 == NULL) 
    {
        perror("Échec malloc");
        return NULL;
    }
    srand(time(NULL));
    for (int m = 0; m<2; m++)
    {
        int index2 = rand() % 4;
        tab_main_J2[m] = cartes[index2];
    }
    if(tab_main_J2[0] > tab_main_J2[1]) // ou les valeurs ne son pas rangées dans l'ordre croissant
    {
        int tmp = tab_main_J2[0];
        tab_main_J2[0] = tab_main_J2[1];
        tab_main_J2[1] = tmp;
    }
    return tab_main_J2;
}

/** 
\brief : retourne a proportion de mains (i',j') obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j)
\param : 
\return : 
*/
int P_approx_2_1_main(int i_prim, int j_prim, int i, int j, int n)
{
    int p = 0;
    for ( int k =0; k<n; k++)
    {
        int* t_main_J2 = main_J2(i, j);
        if (t_main_J2[0]==i_prim && t_main_J2[1]==j_prim)
        {
            p++;
        }
    }
    int proportion = p/n ;
    return proportion;
}

/** 
\brief : retourne pour chaque main (i',j'), la proportion de telles mains obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j).
\param: 
\return : 
*/
int* P_approx_2_1(int i, int j ,int n)
{
    int* tab = malloc(6*sizeof(int)); // il y a 6 couples de cartes 
    int index=0;
    for(int k=1; k<4; k++)
    {
        for (int m =k; m<4; m++)
        {
            int p = P_approx_2_1_main(k, m, i, j, n);
            printf("La proportion de (%d,%d) est %d", i, j ,p);
            tab[index] = p;
            index++;

        }
    }
    return tab;
}