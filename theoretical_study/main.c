#include <stdio.h>
#include <stdlib.h>
#include "tache_c10.h"

int main(){
    FILE *file = fopen("p_approx_alter_data.csv", "w");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    int n = 1000;
    // Écrire des lignes de données
    for(int i = 0; i < n; i++){
        fprintf(file,"%f\n", P_approx_2_alter(i));
    }

    // Fermer le fichier
    fclose(file);

    printf("Données écrites avec succès dans data.csv !\n");
    return 0;
}


