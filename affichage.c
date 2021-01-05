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
        if ((matrice[i][j].lambda_present).malade)
        {
          couleur("31");
          printf("%2c ", 'M');
          couleur("0");
          printf("|");
        }
        else

          if (matrice[i][j].lambda_present != 0)
          {
            if (matrice[i][j].PV_virus > 0 && !(matrice[i][j].lambda_present -> malade))
            {
              couleur("33");
              printf("%2c ", 'L');
              couleur("0");
              printf("|");
            }
            else if (*(matrice[i][j].lambda_present).malade)
            {
              couleur("31");
              printf("%2c ", 'M');
              couleur("0");
              printf("|");
            }
            else
            {
              printf("%2c |", 'L');
            }
          }
          else if (matrice[i][j].presence_soignant != 0)
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
