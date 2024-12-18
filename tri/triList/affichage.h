#ifndef AFFICHAGE_H
#define AFFICHAGE_H

// Définition de la structure list
typedef struct list {
    char mot[100];
    struct list *svt;
} list;

// Déclaration de la fonction afficherlist qui attend un argument de type list*
void afficher(int *T, int n);
void afficherlist(list *L);

#endif
