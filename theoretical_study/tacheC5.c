#include <stdio.h>

/** 
\brief :  retourne les valeurs calculées de la tache C5
\param : i et j entiers, cartes de J1, i', j' cartes de J2
\return :  proba que J2 obtienne i', j' sachant que J1 a obtenu i,j
*/
double P_cond(int i_prim, int j_prim, int i, int j)
{
    if((i == j && i_prim==i) || (i == j && j_prim == i))
    {
        return (double)0;
    }
    if((i_prim == i && j_prim == j) || i_prim == j_prim )
    {
        return (double)1/6;
    }
    if(i_prim == i || j_prim == i || i_prim == j || j_prim ==j)
    {
        return (double)2/6;
    }
    else
    {
        return (double)4/6;
    }
}
