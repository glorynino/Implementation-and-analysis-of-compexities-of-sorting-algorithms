#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    char mot[100];
    struct list* svt; // Correction : 'list' doit être précédé de 'struct' si non défini par typedef
} list;

// Fonction d'affichage pour un tableau d'entiers
void afficher(int *T, int n)
{
    printf("---------- Après une itération -----------\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Élément %zu : %d\n", i, T[i]);  // Utiliser %zu pour le type size_t
    }
}

// Fonction d'affichage pour une liste chaînée de chaînes de caractères
void afficherlist(list* L)
{
    list *p = L;  // Utilisation de p pour parcourir la liste chaînée
    int i = 1;    // Initialisation de l'index pour l'affichage des éléments

    printf("---------- Après une itération -----------\n");
    while (p != NULL)  // Parcours de la liste tant qu'on n'est pas à la fin
    {
        printf("Élément numéro %d : %s\n", i, p->mot); // Affiche l'élément et son contenu
        p = p->svt;  // Passe au prochain élément de la liste
        i++;          // Incrémente le compteur
    }
}
