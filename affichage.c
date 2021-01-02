#include "affichage.h"

//modifier pour ajouter les cas "affectés".

//------------------------------||:FONCTION:||---------------------------------|

void afficher(int nrow, int ncol, Case matrice[nrow][ncol])
{
  int i, j;

  putchar('\n');
  putchar('+');

  for (j = 1; j <= ncol; j++)
      printf("---+");

  putchar('\n');

  for (i = 0; i < nrow; i++)
  {
      putchar('|');

      for (j = 0; j < ncol; j++)
      {
        if (matrice[i][j].occupee)
        {
          if (matrice[i][j].presence_lambda)
          {
            printf("%2c |", 'L');
          }
          else if (matrice[i][j].presence_soignant)
          {
            couleur("32;1");
            printf("%2c ", 'S');
            couleur("0");
            printf("|");
          }
        }
        else if (matrice[i][j].PV_virus > 0)
        {
          couleur("41");
          printf("   ");
          couleur("0");
          printf("|");
        }
        else
        {
          printf("   |");
        }
      }
      putchar('\n');
      putchar('+');

      for (j = 1; j <= ncol; j++)
        {
          printf("---+");
        }

      putchar('\n');
  }
}
