#ifndef AFFICHAGE
#define AFFICHAGE

#include <stdio.h>
typedef struct list
{
    char mot[100];
    list* svt;
}list;
void afficher(int *T, int n);
void afficherlist(list* L);


#endif