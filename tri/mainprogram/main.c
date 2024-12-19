#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct list {
    char mot[100];
    struct list *svt;
} list;
void afficher(int *T, int n)
{
    printf("---------- Après une itération -----------\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Élément %d : %d\n", (int)i, T[i]);
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
// tri avec les list 
// tri par bulle
void bullelist(list* L)
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
// tri par insertion
void insertionlist(list* L)
{
    list *p = L;
    list *p2;
    char swap[100];
    int nbComp = 0;
    int nbPerm = 0;
    while (p != NULL)
    {
        p2 = p;
        while (p2->svt != NULL)
        {
            nbComp++;
            if (strcmp(p->mot, p2->svt->mot) > 0)
            {
                strcpy(swap, p->mot);
                strcpy(p->mot, p2->svt->mot);
                strcpy(p2->svt->mot, swap);
                afficherlist(L);
                nbPerm++;
            }
            p2 = p2->svt;
        }
        p = p->svt;
    }
    printf("le nombre de comparaison:%d",nbComp);
    printf("le nombre de permutation:%d",nbPerm);
}   










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

//tri rapide
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
//fin du tri rapide */ 
list* creerNoeud(const char* mot) {
    list* nouveau = (list*)malloc(sizeof(list));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    strcpy(nouveau->mot, mot);
    nouveau->svt = NULL;
    return nouveau;
}

// Fonction pour ajouter un nœud à la fin de la liste
void ajouterFin(list** L, const char* mot) {
    list* nouveau = creerNoeud(mot);
    if (*L == NULL) {
        *L = nouveau; // La liste est vide, le nouveau devient le premier élément
    } else {
        list* temp = *L;
        while (temp->svt != NULL) {
            temp = temp->svt;
        }
        temp->svt = nouveau;
    }
}

// Fonction pour libérer la mémoire de la liste
void libererListe(list* L) {
    list* temp;
    while (L != NULL) {
        temp = L;
        L = L->svt;
        free(temp);
    }
    printf("Mémoire libérée.\n");
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

     list* maListe = NULL;

    // Ajout d'éléments à la liste
    ajouterFin(&maListe, "B");
    ajouterFin(&maListe, "Z");
    ajouterFin(&maListe, "J");
    ajouterFin(&maListe, "A");

   insertionlist(maListe);

    /* T = malloc(n * sizeof(int));
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
    */
   libererListe(maListe);   
    return 0;
}



/*
    printf("-----exemple de tri de peigne ------\n");
    peingne(T, n);
    afficher(T, n);

    printf("-------exemple de tri de fusion ------");
    free(T);
*/
