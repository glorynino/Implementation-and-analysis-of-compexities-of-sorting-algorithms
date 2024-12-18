#include <stdio.h>
#include "trierapide.h"

void echanger(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int tableau[], int debut, int fin,int *nbComp,int *nbPerm)
{   
    int pivot = tableau[fin];
    int i = debut - 1;

    for (int j = debut; j < fin; j++)
    {    nbComp++;
        if (tableau[j] <= pivot)
        {
            i++;
            nbPerm ++;
            echanger(&tableau[i], &tableau[j]);
        }
    }
    echanger(&tableau[i + 1], &tableau[fin]);
    return i + 1;
}


void triRapide(int tableau[], int debut, int fin ,int* nbComp , int* nbPerm )
{    
    if (debut < fin)
    {
        int indicePivot = partition(tableau, debut, fin , nbComp , nbPerm);

        // Tri des sous-tableaux
        triRapide(tableau, debut, indicePivot - 1, nbComp ,  nbPerm);
        triRapide(tableau, indicePivot + 1, fin, nbComp , nbPerm);
    }
}