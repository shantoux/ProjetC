#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define L 80
#define C 30

static char grille[C][L];


static void quadrillage(void) //Afficher l'environnement dans lequel se développe l'ecosysteme
{
    int colonne;
    int ligne;

    putchar('\n');
    putchar('+');

    for (colonne = 1; colonne <= C; ++colonne)
        printf("--+");

    putchar('\n');

    for (ligne = 0; ligne < L; ++ligne)
    {
        putchar('|');

        for (colonne = 0; colonne < L; ++colonne)
            if (isalpha(grille[colonne][ligne]))
                printf(" %c |", grille[colonne][ligne]);
            else
                printf("%c |", ' ');

        putchar('\n');
        putchar('+');

        for (colonne = 1; colonne <= C; ++colonne)
            printf("--+");

        putchar('\n');
    }
}


int main()
{
  affiche_grille();
  return 0;
}
