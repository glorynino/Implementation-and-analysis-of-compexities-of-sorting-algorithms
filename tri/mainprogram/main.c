#include <stdio.h>
#include <stdlib.h>
#include "tri_fusion.h"
#include "insertionlist.h"
#include "tri/lesfichierH/affichage.h"

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;
// TRI PEINGNE
void peingne(int *T, int taille)
{
    int gap = taille;
    gap = (int)(gap / 1.3);
    if (gap < 1)
        gap = 1;

    while (gap != 1)
    {
        int j = gap;
        int i = 0;
        while (j < taille)
        {
            if (T[i] > T[j])
            {
                int swap = T[i];
                T[i] = T[j];
                T[j] = swap;
            }
            i++;
            j++;
        }
        gap = (int)(gap / 1.3);
    }
}
// FIN DU TRI PEINGNE
//la fonction qui suit est utiliser pour afficher l'etat du vecteur a chaque etiration 
void afficher(int *T, int n)
{
    printf("---------- Après une itération -----------\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Élément %d : %d\n", (int)i, T[i]);
    }
}

// Fonction pour échanger deux éléments
void echanger(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitionnement pour le tri rapide
int partition(int tableau[], int debut, int fin, int *nbComp, int *nbPerm)
{
    int pivot = tableau[fin];
    int i = debut - 1;

    for (int j = debut; j < fin; j++)
    {
        (*nbComp)++; // Incrémenter le compteur de comparaisons
        if (tableau[j] <= pivot)
        {
            i++;
            echanger(&tableau[i], &tableau[j]);
            (*nbPerm)++; // Incrémenter le compteur de permutations
        }
    }
    echanger(&tableau[i + 1], &tableau[fin]);
    (*nbPerm)++; // Incrémenter le compteur pour l'échange final
    return i + 1;
}

// Tri rapide avec affichage à chaque étape
void triRapide(int tableau[], int debut, int fin, int *nbComp, int *nbPerm, int n)
{
    if (debut < fin)
    {
        int indicePivot = partition(tableau, debut, fin, nbComp, nbPerm);

        // Afficher le tableau après chaque partition
        afficher(tableau, n);

        // Tri des sous-tableaux
        triRapide(tableau, debut, indicePivot - 1, nbComp, nbPerm, n);
        triRapide(tableau, indicePivot + 1, fin, nbComp, nbPerm, n);
    }
}

int main()
{
    int *T;
    int n;

    printf("Nombre d'éléments : \n");
    do
    {
        scanf("%d", &n);
    } while (n < 0);

    T = malloc(n * sizeof(int));
    if (T == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("Élément %d : \n", (int)i);
        scanf("%d", &T[i]);
    }

    int nbComp = 0; // Compteur de comparaisons
    int nbPerm = 0; // Compteur de permutations

    printf("----------- Tri rapide ---------------\n");
    triRapide(T, 0, n - 1, &nbComp, &nbPerm, n);

    printf("----------- Résultat final ---------------\n");
    afficher(T, n);

    printf("Nombre de comparaisons : %d\n", nbComp);
    printf("Nombre de permutations : %d\n", nbPerm);

    free(T); // Libérer la mémoire allouée
    return 0;
}



/*
    printf("-----exemple de tri de peigne ------\n");
    peingne(T, n);
    afficher(T, n);

    printf("-------exemple de tri de fusion ------");
    free(T);
*/
