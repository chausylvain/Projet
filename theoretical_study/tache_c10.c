#include <stdio.h>
#include <stdlib.h>

/* Tâche C.10 */

/**
 * Retourne la proportion des mains obtenues par J2
 */

double P_approx_2_1_alter(int i_prim, int j_prim, int n){
    double P_B = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P_B += P_approx_1(i,j,n) * P_approx_2_1(i_prim,j_prim,i,j,n);
        }
    }
    return P_B;
}

double P_approx_2_alter(int n){
    double P_B = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P_B += P_approx_2_1(i,i,n);
        }
    }
    return P_B;
}

