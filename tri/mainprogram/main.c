//
// Created by yacai on 20/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list {
    char mot[100];
    struct list* svt;
} list;
void afficher(int* T, int n)
{
    printf("---------- Apres une iteration -----------\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Element %d : %d\n", (int)i, T[i]);
    }
}
// Fonction d'affichage pour une liste chaînée de chaînes de caractères
void afficherlist(list* L)
{
    list* p = L;  // Utilisation de p pour parcourir la liste chaînée
    int i = 1;    // Initialisation de l'index pour l'affichage des éléments

    printf("---------- Après une iteration -----------\n");
    while (p != NULL)  // Parcours de la liste tant qu'on n'est pas à la fin
    {
        printf("Element numéro %d : %s\n", i, p->mot); // Affiche l'élément et son contenu
        p = p->svt;  // Passe au prochain élément de la liste
        i++;          // Incrémente le compteur
    }
}
// tri avec les list
// tri par bulle

void bullelist(list* L)
{
    char swap[100];
    list* p;
    list* p2;
    if (L == NULL)
    {
        printf("la list est vide");
        return;
    }

    int nbComp = 0;
    int  nbPerm = 0;
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
    printf("le nombre de comparaison: %d\n ", nbComp);
    printf("le nombre de permutation: %d\n ", nbPerm);

}
// tri par insertion
void insertionlist(list* L)
{
    list* p = L;
    list* p2;
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
    printf("le nombre de comparaison: %d\n", nbComp);
    printf("le nombre de permutation: %d\n", nbPerm);
}
//fin des tri de liste
list* creerNoeud(const char* mot) {
    list* nouveau = (list*)malloc(sizeof(list));
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire !\n");
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
    }
    else {
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
    printf("Memoire libere.\n");
}

// tri de vecteur

void tri_par_selection(int* A, int taille) {
    int i, j, min, minindex;
    int nbComp = 0, nbPerm = 0;

    for (i = 0; i < taille - 1; i++) {  // Il n'est pas nécessaire de continuer jusqu'à la dernière case
        min = A[i];
        minindex = i;

        for (j = i + 1; j < taille; j++) {  // Commence à j = i + 1 pour ne pas comparer l'élément actuel
            nbComp++;
            if (A[j] < min) {
                min = A[j];
                minindex = j;
            }
        }

        // Si minindex est différent de i, effectue l'échange
        if (minindex != i) {
            int temp = A[i];
            A[i] = A[minindex];
            A[minindex] = temp;
            nbPerm++;
            afficher(A, taille);  // Affichage après l'échange
        }
    }

    printf("Le tableau est trie par selection, nombre de comparaisons : %d , nombre de permutations : %d\n", nbComp, nbPerm);
}


void tri_par_bulle(int* A, int taille) {
    int temp;
    int nbComp = 0, nbPerm = 0;
    for (int i = 0; i < taille - 1; i++) {

        for (int j = 0; j < taille - i - 1; j++) {
            afficher(A, taille);
            if (A[j] > A[j + 1]) {
                nbPerm++;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            nbComp++;
        }

    }
    printf("Le Tabeau est trier par bulle, nombre de comparaison %d , nombre de permutation %d \n", nbComp, nbPerm);
}

void tri_par_insertion(int A[], int taille) {
    int nbComp = 0, nbPerm = 0;
    for (int i = 1; i < taille; i++) {

        int valeur = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > valeur) {
            nbComp++;
            A[j + 1] = A[j];
            j--;
            nbPerm++;
        }
        A[j + 1] = valeur;
        afficher(A, taille);
    }

    printf("Le Tabeau est trier par insertion, nombre de comparaison %d , nombre de permutation %d \n", nbComp, nbPerm);
}
// TRI PEINGNE
void peigne(int* T, int taille)
{
    int nbComp = 0; // Compteur de comparaisons
    int nbPerm = 0; // Compteur de permutations
    int gap = taille; // Écart initial
    int swapped = 1; // Indicateur de permutation

    while (gap > 1 || swapped)
    {
        gap = (int)(gap / 1.3); // Réduction de l'écart
        if (gap < 1)
            gap = 1; // L'écart minimal est 1

        swapped = 0; // Réinitialisation de l'indicateur de permutation

        for (int i = 0; i + gap < taille; i++)
        {
            nbComp++;
            if (T[i] > T[i + gap])
            {
                // Permutation des éléments
                int swap = T[i];
                T[i] = T[i + gap];
                T[i + gap] = swap;

                nbPerm++;
                swapped = 1; // Indiquer qu'une permutation a eu lieu
            }
        }
        afficher(T, taille); // Affichage intermédiaire après chaque passe
    }

    printf("Le nombre de permutations : %d\n", nbPerm);
    printf("Le nombre de comparaisons : %d\n", nbComp);
}

// FIN DU TRI PEINGNE

//tri rapide
// Fonction pour échanger deux éléments
void echanger(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partitionnement pour le tri rapide
int partition(int tableau[], int debut, int fin, int* nbComp, int* nbPerm)
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
void triRapide(int tableau[], int debut, int fin, int* nbComp, int* nbPerm, int n)
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
//tri fusion
int compteurComparaisons = 0;
int compteurPermutations = 0;

void fusion(int tableau[], int gauche, int milieu, int droite) {
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int* gaucheArr = (int*)malloc(n1 * sizeof(int));
    int* droiteArr = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) gaucheArr[i] = tableau[gauche + i];
    for (int j = 0; j < n2; j++) droiteArr[j] = tableau[milieu + 1 + j];

    int i = 0, j = 0, k = gauche;

    // Fusion des deux sous-tableaux
    while (i < n1 && j < n2) {
        compteurComparaisons++;  // Incrémente à chaque comparaison
        if (gaucheArr[i] <= droiteArr[j]) {
            tableau[k++] = gaucheArr[i++];
            compteurPermutations++;  // Incrémente à chaque permutation
        }
        else {
            tableau[k++] = droiteArr[j++];
            compteurPermutations++;  // Incrémente à chaque permutation
        }
    }

    // Si des éléments restent dans le tableau de gauche
    while (i < n1) {
        tableau[k++] = gaucheArr[i++];
        compteurPermutations++;  // Incrémente à chaque permutation
    }

    // Si des éléments restent dans le tableau de droite
    while (j < n2) {
        tableau[k++] = droiteArr[j++];
        compteurPermutations++;  // Incrémente à chaque permutation
    }

    free(gaucheArr);
    free(droiteArr);
}

void triFusion(int tableau[], int gauche, int droite) {
    if (gauche < droite) {

        int milieu = gauche + (droite - gauche) / 2;

        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        fusion(tableau, gauche, milieu, droite);
    }
    afficher(tableau,droite+1);
}
//fin du tri fusion

// part 2 tri matrice par insertion

void AffichageMAt(char **mat, int taille) {
    int i;
    printf("apres une iteration\n");
    for (i = 0; i < taille; i++) {
        printf("%s\t", mat[i]);
    }
    printf("\n");
}


void tri_matrix_insertion(char **matrix, int taille) {
    int i;
    int nbComp = 0, nbPerm = 0;
    for (i = 1; i < taille; i++) {
        char mot[100];
        strcpy(mot, matrix[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(matrix[j], mot) > 0) {
            nbComp++; nbPerm++;
            strcpy(matrix[j + 1], matrix[j]);
            j--;
        }

        strcpy(matrix[j + 1], mot);
        nbPerm++;
        AffichageMAt(matrix, taille);
    }
    printf("La Matrice est trier par insertion, nombre de comparaison %d , nombre de permutation %d \n", nbComp, nbPerm);
}

// tri rapide pour les matrice
void echanger_matrice(char a[], char b[]) {
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition_matrice(char **mat, int debut, int fin) {
    char pivot[100];
    strcpy(pivot, mat[fin]); // Dernier élément comme pivot
    int i = debut - 1;

    for (int j = debut; j < fin; j++) {
        if (strcmp(mat[j], pivot) < 0) {
            i++;
            echanger_matrice(mat[i], mat[j]);
        }
    }
    echanger_matrice(mat[i + 1], mat[fin]);
    return i + 1;
}

void triRapide_matrice(char **mat, int debut, int fin) {

    if (debut < fin) {
        int pIndex = partition_matrice(mat, debut, fin);
        AffichageMAt(mat, fin+1);
        triRapide_matrice(mat, debut, pIndex - 1);
        triRapide_matrice(mat, pIndex + 1, fin);
    }
}

void afficherCompteurs() {
    printf("Nombre de comparaisons : %d\n", compteurComparaisons);
    printf("Nombre de permutations : %d\n", compteurPermutations);
}

//fin du tri de vecteur
int main()
{
    int* T;
    int n;
    int choixTypeATrier;
    int ChoixTri;
    int ncmp = 0;
    int nperm = 0;
    printf("cher utilisateur tu choisis de pratiquer les operation de tri su qu'elle structure  \n");
    printf("1- vecteur \n");
    printf("2- liste \n");
    printf("3- matrice \n");
    scanf("%d", &choixTypeATrier);
    switch (choixTypeATrier)
    {
    case 1:
        printf("vous avez choisi de pratiquer les operation de tri sur un vecteur \n");
        printf("Combien d'éléments voulez-vous ajouter au tableau ?\n");
        scanf("%d", &n);
        T = (int*)malloc(n * sizeof(int));
        if (T == NULL)
        {
            printf("Erreur d'allocation memoire !\n");
            exit(1);
        }
        for (int i = 0; i < n; i++)
        {
            printf("Entrez l'element numero %d : ", i + 1);
            scanf("%d", &T[i]);
        }
        printf("qu'elle methode de tri voulez vous utiliser  \n1 pour peingne  \n2 pour rapide \n3 pour fusion \n4 tri par selection \n5 tri bulle \n6 tri par insertion \n");
        scanf("%d", &ChoixTri);

        // le choix des tri
        switch (ChoixTri)
        {
        case 1:
            printf("1- Tri Peingne\n");
            peigne(T,n);
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
        case 4:
            printf("4- tri par selection \n");
            tri_par_selection(T,n);
            break;
        case 5:
            printf("5- tri par bulle \n");
            tri_par_bulle(T,n);
            break;
        case 6:
            printf("6- tri par insertion \n");
            tri_par_insertion(T,n);
            break;
        default:

            break;
        }

        free(T);
        break;
    case 2:
        printf("vous avez choisi de pratiquer les operation de tri sur une liste \n");

        printf("Combien de mot voulez-vous ajouter à la liste ?\n");
        scanf("%d", &n);
        list* maListe = NULL;
        for (int i = 0; i < n; i++)
        {
            char mot[100];
            printf("Entrez le mot numero %d : ", i + 1);
            scanf("%s", mot);
            ajouterFin(&maListe, mot);
        }
        printf("qu'elle methode de tri voulez vous utiliser  1 pour bulle , 2 pour insertion \n");
        scanf("%d", &ChoixTri);
        switch (ChoixTri)
        {
        case 1:
            printf("1- Tri par bulle\n");
            bullelist(maListe);
            break;
        case 2:
            printf("2- Tri par insertion\n");
            insertionlist(maListe);
            break;
        default:
            printf("choisis un numero entre 1 et 2 !");
            break;
        }

        libererListe(maListe);
        break;

    case 3:
        printf("vous avez choisi de pratiquer les operation de tri sur une matrice \n");
        printf("Combien de mot voulez-vous ajouter dans la matrice ?\n");
        scanf("%d", &n);
        char** matrice = (char**)malloc(n * sizeof(char*));
        if (matrice == NULL) {
            perror("Erreur d'allocation memoire");
            return 1;
        }
        // Allocation dynamique pour chaque chaîne
        for (int i = 0; i < n; i++) {
            matrice[i] = (char*)malloc(100 * sizeof(char)); // Allocation pour une chaîne de 100 caractères
            if (matrice[i] == NULL) {
                perror("Erreur d'allocation memoire");
                return 1;
            }
        }
        // Lecture des chaînes
        printf("Entrez %d chaines :\n", n);
        for (int i = 0; i < n; i++) {
            printf("Chaine %d : ", i + 1);
            scanf(" %99[^\n]", matrice[i]); // Lecture de la chaîne avec protection contre le débordement
        }
        int choixAlgoTri = -1;
        printf("choisissez un algo un tri 1-tri par insertion 2-tri rapide\n");
        scanf("%d", &choixAlgoTri);
        switch (choixAlgoTri) {
            case 1:
                tri_matrix_insertion(matrice, n);

                break;
            case 2:
                triRapide_matrice(matrice,0,n-1);
                break;
        }

        for (int i = 0; i < n; i++) {
            free(matrice[i]);
        }
        free(matrice);

        break;
    default:

        printf("ta pas choisis un nombre demander ");
        break;
    }

    return 0;
}



