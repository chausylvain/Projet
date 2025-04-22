#include <stdio.h>
#include <stdlib.h>
#include "probability_of_hand_empiric.h"


int hist_empirique_C7(int n){
    FILE *file =fopen("data1.csv", "w");
    if (file==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(file, "freq, (i,j)"); 
    for (int i=1; i<4; i++){
        for (int j=i; j<4; j++){
            fprintf(file, "%f, (%d,%d)", P_approx_2_1(1,2,n), i, j);
        }
    }
    fclose(file);
    return 0;
} 


int hist_tehorique_C7(int n){
    FILE *fd =fopen("data2.csv", "w");
    if (fd==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(fd,"resultat, (i,j)" );
    for (int i=1; i<4; i++){
        for(int j=i; j<4; j++){
           fprintf(fd, "%f\n", P_cond((i,j,1,2)));
        }
    }
    fclose(fd);
    return 0;
}

int nuage_C7(){
    FILE *f =fopen("data3.csv", "w");
    if (f==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprintf(f, "N, P_approx_2_1_main(2,3,1,2,n)");
    for (int i=1; i<100001; i++){
        fprintf(f, "%d, %f\n", i, P_approx_2_1(2,3,1,2,i));
    }
    fclose(f);
    return 0;
}

int droite (){
    FILE *fdd =fopen("data4.csv", "w");
    if (fdd==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fprint(fdd, "y\n");
    fprintf(fdd, "%f\n", P_cond(2,3, 1,2));
    fclose(fdd);
}

int main(){
    hist_empirique_C7(1000);
    hist_tehorique_C7(1000);
    nuage_C7();

}