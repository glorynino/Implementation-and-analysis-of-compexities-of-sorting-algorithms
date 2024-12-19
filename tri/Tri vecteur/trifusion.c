#include <stdio.h>
#include <stdlib.h>
#include "tri_fusion.h"

// Définition des compteurs en global
int compteurComparaisons = 0;
int compteurPermutations = 0;

void fusion(int tableau[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;
    
    int* gaucheArr = (int*)malloc(n1 * sizeof(int));
    int* droiteArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) gaucheArr[i] = tableau[gauche + i];
    for (int j = 0; j < n2; j++) droiteArr[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;

    // Fusion des deux sous-tableaux
    while (i < n1 && j < n2) {
        compteurComparaisons++;  // Incrémente à chaque comparaison
        if (gaucheArr[i] <= droiteArr[j]) {
            tableau[k++] = gaucheArr[i++];
            compteurPermutations++;  // Incrémente à chaque permutation
        } else {
            tableau[k++] = droiteArr[j++];
            compteurPermutations++;  // Incrémente à chaque permutation
        }
    }

    // Si des éléments restent dans le tableau de gauche
    while (i < n1) {
        tableau[k++] = gaucheArr[i++];
        compteurPermutations++;  // Incrémente à chaque permutation
    }

    // Si des éléments restent dans le tableau de droite
    while (j < n2) {
        tableau[k++] = droiteArr[j++];
        compteurPermutations++;  // Incrémente à chaque permutation
    }

    free(gaucheArr);
    free(droiteArr);
}

void triFusion(int tableau[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        fusion(tableau, gauche, milieu, droite);
    }
}

void afficherCompteurs() {
    printf("Nombre de comparaisons : %d\n", compteurComparaisons);
    printf("Nombre de permutations : %d\n", compteurPermutations);
}
