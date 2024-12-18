#include <stdio.h>
#include <stdlib.h>
#include "tri_fusion.h"

void fusion(int tableau[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int* gaucheArr = (int*)malloc(n1 * sizeof(int));
    int* droiteArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) gaucheArr[i] = tableau[gauche + i];
    for (int j = 0; j < n2; j++) droiteArr[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;

    while (i < n1 && j < n2) {
        if (gaucheArr[i] <= droiteArr[j]) {
            tableau[k++] = gaucheArr[i++];
        } else {
            tableau[k++] = droiteArr[j++];
        }
    }

    while (i < n1) tableau[k++] = gaucheArr[i++];
    while (j < n2) tableau[k++] = droiteArr[j++];

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
