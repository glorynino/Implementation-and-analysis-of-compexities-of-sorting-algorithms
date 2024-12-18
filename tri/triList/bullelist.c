#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "affichage.h"

void bullelist(list L, )
{
    char swap[100];
    list *p;
    list *p2;
    if (L == NULL)
    {
        printf("la list est vide");
        return;
    }

    int nbComp = 0;
     int  nbPerm = 0;
    int verification = 1;
    while (verification)
    {    p = L;
         nbComp++;
        verification = 0;
        while (p->svt!= NULL)
        {   p2 = p->svt;
            nbComp++;
            if (strcmp(p->mot, p2->mot) > 0)
            {
                verification = 1;
                strcpy(swap, p->mot);
                strcpy(p->mot, p2->mot);
                strcpy(p2->mot, swap);
                afficherlist(L);
                nbPerm++;
            }
            p = p->svt;
        }
    }
   printf("le nombre de comparaison:%d",nbComp);
   printf("le nombre de permutation:%d",nbPerm);

}