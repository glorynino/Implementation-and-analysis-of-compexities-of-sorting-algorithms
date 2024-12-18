#ifndef INSERTION
#define INSERTION

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

void insertionSort(Node** head);



#endif