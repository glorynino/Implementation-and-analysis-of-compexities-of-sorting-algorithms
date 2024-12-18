#include <stdio.h>
        
void peingne(int *T, int taille)
{  int nbComp = 0;
   int nbPerm = 0;
   int gap = taille;
     gap = (int)(gap / 1.3);
    if (gap < 1)
        gap = 1;

    while (gap != 1)
    {
        int j = gap;
        int i = 0;
        while (j != taille)
        {    nbComp++;
            if (T[i] > T[j])
            {   nbPerm++;
                int swap = T[i];
                T[i] = T[j];
                T[j] = swap;
            }
            i++;
            j++;
        }
        gap = (int)(gap / 1.3);
    }
   printf("le nombre de permutation : %d",nbPerm);
   printf("le nombre de comparaison : %d",nbComp);


}