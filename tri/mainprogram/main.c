#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list
{
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
void afficherlist(list *L)
{
    list *p = L; // Utilisation de p pour parcourir la liste chaînée
    int i = 1;   // Initialisation de l'index pour l'affichage des éléments

    printf("---------- Après une itération -----------\n");
    while (p != NULL) // Parcours de la liste tant qu'on n'est pas à la fin
    {
        printf("Élément numéro %d : %s\n", i, p->mot); // Affiche l'élément et son contenu
        p = p->svt;                                    // Passe au prochain élément de la liste
        i++;                                           // Incrémente le compteur
    }
}
// tri avec les list
// tri par bulle

void bullelist(list *L)
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
    int nbPerm = 0;
    int verification = 1;
    while (verification)
    {
        p = L;
        nbComp++;
        verification = 0;
        while (p->svt != NULL)
        {
            p2 = p->svt;
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
    printf("le nombre de comparaison:%d", nbComp);
    printf("le nombre de permutation:%d", nbPerm);
}
// tri par insertion
void insertionlist(list *L)
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
    printf("le nombre de comparaison:%d", nbComp);
    printf("le nombre de permutation:%d", nbPerm);
}
// fin des tri de liste
list *creerNoeud(const char *mot)
{
    list *nouveau = (list *)malloc(sizeof(list));
    if (nouveau == NULL)
    {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    strcpy(nouveau->mot, mot);
    nouveau->svt = NULL;
    return nouveau;
}

// Fonction pour ajouter un nœud à la fin de la liste
void ajouterFin(list **L, const char *mot)
{
    list *nouveau = creerNoeud(mot);
    if (*L == NULL)
    {
        *L = nouveau; // La liste est vide, le nouveau devient le premier élément
    }
    else
    {
        list *temp = *L;
        while (temp->svt != NULL)
        {
            temp = temp->svt;
        }
        temp->svt = nouveau;
    }
}

// Fonction pour libérer la mémoire de la liste
void libererListe(list *L)
{
    list *temp;
    while (L != NULL)
    {
        temp = L;
        L = L->svt;
        free(temp);
    }
    printf("Mémoire libérée.\n");
}

// tri de vecteur
// TRI PEINGNE
void peingne(int *T, int taille)
{
    int nbComp = 0;
    int nbPerm = 0;
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
    printf("le nombre de permutation : %d", nbPerm);
    printf("le nombre de comparaison : %d", nbComp);
}
// FIN DU TRI PEINGNE

// tri rapide
//  Fonction pour échanger deux éléments
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
// fin du tri rapide */
// tri fusion
int compteurComparaisons = 0;
int compteurPermutations = 0;

void fusion(int tableau[], int gauche, int milieu, int droite)
{
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int *gaucheArr = (int *)malloc(n1 * sizeof(int));
    int *droiteArr = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        gaucheArr[i] = tableau[gauche + i];
    for (int j = 0; j < n2; j++)
        droiteArr[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;

    // Fusion des deux sous-tableaux
    while (i < n1 && j < n2)
    {
        compteurComparaisons++; // Incrémente à chaque comparaison
        if (gaucheArr[i] <= droiteArr[j])
        {
            tableau[k++] = gaucheArr[i++];
            compteurPermutations++; // Incrémente à chaque permutation
        }
        else
        {
            tableau[k++] = droiteArr[j++];
            compteurPermutations++; // Incrémente à chaque permutation
        }
    }

    // Si des éléments restent dans le tableau de gauche
    while (i < n1)
    {
        tableau[k++] = gaucheArr[i++];
        compteurPermutations++; // Incrémente à chaque permutation
    }

    // Si des éléments restent dans le tableau de droite
    while (j < n2)
    {
        tableau[k++] = droiteArr[j++];
        compteurPermutations++; // Incrémente à chaque permutation
    }

    free(gaucheArr);
    free(droiteArr);
}

void triFusion(int tableau[], int gauche, int droite)
{
    if (gauche < droite)
    {
        int milieu = gauche + (droite - gauche) / 2;

        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        fusion(tableau, gauche, milieu, droite);
    }
}
// fin du tri fusion

void afficherCompteurs()
{
    printf("Nombre de comparaisons : %d\n", compteurComparaisons);
    printf("Nombre de permutations : %d\n", compteurPermutations);
}

// fin du tri de vecteur
int main()
{
    int *T;
    int n;
    int i;
    int ncmp = 0;
    int nperm = 0;
    printf("cher utilisateur tu choisis de pratiquer les operation de tri su qu'elle structure  \n");
    printf("1- vecteur \n");
    printf("2- liste \n");
    printf("3- matrice \n");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        printf("vous avez choisi de pratiquer les operation de tri sur un vecteur \n");
        printf("Combien d'éléments voulez-vous ajouter au tableau ?\n");
        scanf("%d", &n);
        T = (int *)malloc(n * sizeof(int));
        if (T == NULL)
        {
            printf("Erreur d'allocation mémoire !\n");
            exit(1);
        }
        for (int i = 0; i < n; i++)
        {
            printf("Entrez l'élément numéro %d : ", i + 1);
            scanf("%d", &T[i]);
        }
        printf("qu'elle methode de tri voulez vous utiliser  1 pour peingne , 2 pour rapide , 3 pour fusion \n");
        scanf("%d", &i);

        // le choix des tr
        switch (i)
        {
        case 1:
            printf("1- Tri Peingne\n");
            break;
        case 2:
            printf("2- Tri rapide\n");
            triRapide(T, 0, n - 1, &ncmp, &nperm, n);
            printf("le nombre de permutation : %d\n", nperm);
            printf("le nombre de comparaison : %d\n", ncmp);
            break;
        case 3:
            printf("3- Tri Fusion\n");
            triFusion(T, 0, n - 1);
            afficherCompteurs();
            break;

        default:
            print("choisis un numero entre 1 et 6 ! ");
            break;
        }

        free(T);
        break;
    case 2:
        printf("vous avez choisi de pratiquer les operation de tri sur une liste \n");

        printf("Combien de mots voulez-vous ajouter à la liste ?\n");
        scanf("%d", &n);
        list *maListe = NULL;
        for (int i = 0; i < n; i++)
        {
            char mot[100];
            printf("Entrez le mot numéro %d : ", i + 1);
            scanf("%s", mot);
            ajouterFin(&maListe, mot);
        }
        printf("qu'elle methode de tri voulez vous utiliser  1 pour bulle , 2 pour insertion \n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("1- Tri par bulle\n");
            bullelist(maListe);
            break;
        case 2:
            printf("2- Tri par insertion\n");
            insertionlist(maListe);

        default:
            printf("choisis un numero entre 1 et 2 !");
            break;
        }

        libererListe(maListe);
    case 3:
        printf("vous avez choisi de pratiquer les operation de tri sur une matrice \n");

        break;
    default:

        printf("ta pas choisis un nombre demander ");
        break;
    }

    return 0;
}
