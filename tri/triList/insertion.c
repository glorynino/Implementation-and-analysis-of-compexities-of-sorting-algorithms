#include <string.h>
#include <stdlib.h>
#include <stdio.h>  // Pour afficher les compteurs

typedef struct Node
{
    char word[100];
    struct Node *next;
} Node;

void triParInsertion(Node **tete)
{
    if (*tete == NULL || (*tete)->next == NULL)
        return; // Rien à trier si la liste est vide ou contient un seul élément

    Node *trie = NULL;  // Liste triée (initialement vide)
    Node *actuel = *tete; // Liste originale (non triée)
    
    int comparisons = 0;  // Compteur de comparaisons
    int permutations = 0; // Compteur de permutations

    while (actuel != NULL)
    {
        Node *suivant = actuel->next; // Sauvegarder le noeud suivant
        actuel->next = NULL;         // Déconnecter "actuel" de la liste originale

        // Insertion dans la liste triée
        if (trie == NULL || strcmp(actuel->word, trie->word) < 0)
        {
            // Comparaison
            comparisons++;
            // Insertion en tête de la liste triée
            actuel->next = trie;
            trie = actuel;
            // Permutation
            permutations++;
        }
        else
        {
            Node *temp = trie;
            while (temp->next != NULL && strcmp(temp->next->word, actuel->word) < 0)
            {
                // Comparaison dans la boucle while
                comparisons++;
                temp = temp->next;
            }

            // Une dernière comparaison avant insertion
            comparisons++;
            
            // Insérer "actuel" après le noeud trouvé
            actuel->next = temp->next;
            temp->next = actuel;
            // Permutation
            permutations++;
        }

        // Passer au noeud suivant
        
        actuel = suivant;
    }

    *tete = trie; // Mettre à jour la tête pour pointer vers la liste triée

    // Afficher les résultats
    printf("Comparaisons : %d\n", comparisons);
    printf("Permutations : %d\n", permutations);
}
