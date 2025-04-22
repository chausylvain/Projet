#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 
 \brief :  simule la distribution des cartes à J2 en prenant en argument la main (i,j) de J1
 \param : i et j entiers, cartes de J1
 \return : rien
*/

int* main_J2(int i, int j);

/** 
 \brief : retourne a proportion de mains (i',j') obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j)
 \param : 
 \return : 
*/

int P_approx_2_1_main(int i_prim, int j_prim, int i, int j, int n);

/** 
 \brief : retourne pour chaque main (i',j'), la proportion de telles mains obtenues par J2 lors de n distributions indépendantes de la main de J2, conditionnellement à (C^1_1,C^1_2)=(i,j).
 \param: 
 \return : 
*/

int* P_approx_2_1(int i, int j ,int n);

