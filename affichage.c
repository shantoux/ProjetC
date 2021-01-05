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
        if (matrice[i][j].lambda_present->etat == MALADE || matrice[i][j].soignant_present -> etat == MALADE)
        {
          couleur("31");
          printf("%2c ", 'M');
          couleur("0");
          printf("|");
        }
        else if (matrice[i][j].lambda_present != NULL)
        {
            if (matrice[i][j].lambda_present -> etat == SAIN))
            {
              affichage_direction(matrice[i][j].lambda_present -> direction)
              printf("|");
            }
            else if (matrice[i][j].lambda_present -> etat == ASYMPTO)
            {
              couleur("33");
              affichage_direction(matrice[i][j].lambda_present -> direction)
              couleur("0");
              printf("|");
            }
          }
          else if (matrice[i][j].presence_soignant != NULL)
          {
            if (matrice[i][j].presence_soignant -> etat == SAIN)
            { couleur("32;1");
              printf("%2c ", 'S');
              couleur("0");
              printf("|");
            }
            else if (matrice[i][j].presence_soignant -> etat == ASYMPTO)
            {
              couleur("33;1");
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




void affichage_direction(Dir direction)
{
  if (direction == NORD) { printf("%2c ", '∧');}
  else if (direction == SUD) { printf("%2c ", '∨');}
  else if (direction == EST) { printf("%2c ", '>');}
  else if (direction == OUEST) { printf("%2c ", '<');}
  else if (direction == NE) { printf("%2c ", '/');}
  else if (direction == SO) { printf("%2c ", '/');}
  else if (direction == NO) { printf("%2c ", '\\');}
  else if (direction == SE) { printf("%2c ", '\\');}
}
