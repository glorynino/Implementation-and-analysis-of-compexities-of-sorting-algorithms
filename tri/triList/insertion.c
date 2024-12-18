#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char word[100];
    struct Node *next;
} Node;

void insertionSort(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node *sorted = NULL; // Liste triée
    Node *current = *head;

    while (current != NULL)
    {
        Node *next = current->next;

        // Insertion dans la liste triée
        if (sorted == NULL || strcmp(current->word, sorted->word) < 0)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->word, current->word) < 0)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}
