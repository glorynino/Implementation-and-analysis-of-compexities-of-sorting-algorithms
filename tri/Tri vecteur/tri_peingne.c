#include <stdio.h>

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
        while (j != taille)
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