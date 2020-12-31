#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#define clrscr() printf("\033[H\033[2J") // la fonction clrscr(); effacera l'écran
#define couleur(param) printf("\033[%sm",param) //paramétrage de l'affichage en couleur
#define N 20
#define M 20
#define PROB_V 5
#define PROB_L 20
#define PROB_S 10

//----------------------STRUCTURES------------------------------------------------

typedef struct Coordonnees Coordonnees; //les coordonnees determine une kase precise au sein de l'environnement.
struct Coordonnees
{
  int x;
  int y;
};

typedef struct Bonhomme Bonhomme;
struct Bonhomme
{
  bool vocation; //indique si le bonhomme est un soigneur (1) ou simple civil (0)
  int direction; //donne la dernière direction du Bonhomme
  bool malade; // indique si le bonhomme est sain(0) ou malade(1). ??????
  bool mort; //peut-être inutile. A voir durant le dvl !!!
  Coordonnees localisation; //A voir comment les gerer de manière pertinente. Pointeur ? localisation.x = "N" et localisation.y = "M"
  int atchoum; //seulement pour les civils. Garder dans la structure ? Pointeur vers les vraies kases ?
};

typedef struct Environnement Environnement; //utiliser un pointeur pour le décompte des virus.
struct Environnement
{
  bool occupee; //indique la présence d'une des trois entités possibles
  int gradient; //indique le niveau de charge virale (dû à un malade)
  int  cpt_virus; //indique le "temps de vie" restant à un virus sur la kase
  bool presence_lambda; //j'ai pas réussi à utiliser les pointeurs ici, il faudra voir si c'est handicapant pour la suite
  bool presence_soignant;//ici non plus
};



//----------------------PROTOTYPES FONCTIONS ------------------------------------------------
int pioche(int min, int max);
void affiche_grille(int nrow, int ncol, Environnement matrice[nrow][ncol]);

//----------------------FONCTION PRINCIPALE ------------------------------------------------

int main(int argc, char *argv[])
{
    //ok donc maintenant que les structures et les listes sont mises en place, y'a plus qu'à.
    //1. on initialise une première grille de N par M kases. Il faut faire le tour de chaque kase et faire poper les soigneurs, les virus et les civils.
    //2. à chaque fois qu'un soigneur ou un civil apparait, il faut l'introduire dans Bonhomme/soigneur ou civil pour l'ajouter aux listes.
    //Ne pas oublier d'initialiser chaque bonhomme.
    int vie_virus[5] = {0,1,2,3,4}; //Tableau vers lequel pointe cpt_virus
    Environnement kase[N][M]={0}; //initialisation de l'environnement avec des valeurs à 0


    //Allocation dynamique pour les tableaux soignants et lambda
    Bonhomme * soignant;
    Bonhomme * lambda;
    Bonhomme * tempS; //tableaux temporaires pour les realloc
    Bonhomme * tempL; //tableau temporaire pour les reallo

    soignant = malloc (sizeof(Bonhomme));

    if( soignant == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      exit(EXIT_FAILURE);
    }

    lambda = malloc (sizeof(Bonhomme));
    if( lambda == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      exit(EXIT_FAILURE);
    }



    // INITIALISATION
    int i, j, cpt_lambda = 0, cpt_soignant = 0, compteur_virus=0;
    int nbrAlea;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
      {
        nbrAlea = pioche(1,100);//nbrAlea pioché entre 1 et 100
        printf("%d\n", nbrAlea);
        if (nbrAlea <= PROB_V)
        {
        //alors présence d'un virus
          kase[i][j].cpt_virus = vie_virus[4];//initialisation du compteur de vie du virus pour cette case
          compteur_virus += 1;
        }
        else if (nbrAlea > PROB_V && nbrAlea <= PROB_V+PROB_L)
        {
          //alors presence d'un lambda
          kase[i][j].occupee = 1;
          kase[i][j].presence_lambda = 1;
          lambda[cpt_lambda].localisation.x = i;
          lambda[cpt_lambda].localisation.y = j;
          cpt_lambda += 1;

          //realloc puisqu'on ajoute un élément au tableau lambda
          tempL = realloc (lambda, (cpt_lambda+1) * sizeof(Bonhomme));
          if ( tempL == NULL )
          {
            fprintf(stderr,"Reallocation impossible");
            free(lambda);
            exit(EXIT_FAILURE);
          }
          else
          {
            lambda = tempL;
          }
        }
        else if (nbrAlea > PROB_V+PROB_L && nbrAlea <= PROB_V+PROB_L+PROB_S)
        {   //presence d'un soignant
          kase[i][j].occupee = 1;
          kase[i][j].presence_soignant = 1;
          soignant[cpt_soignant].localisation.x = i;
          soignant[cpt_soignant].localisation.y = j;
          soignant[cpt_soignant].vocation = 1;
          cpt_soignant += 1;

          //realloc puisqu'on ajoute un élément au tableau soignant
          tempS = realloc (soignant, (cpt_soignant+1) * sizeof(Bonhomme));
          if ( tempS == NULL )
          {
            fprintf(stderr,"Reallocation impossible");
            free(soignant);
            exit(EXIT_FAILURE);
          }
          else
          {
            soignant = tempS;
          }
        }
        printf("virus : %d, lambda : %d, soignant : %d\n", compteur_virus, cpt_lambda, cpt_soignant);

       }
     }
     affiche_grille(N, M, kase);
     free(lambda);
     lambda = NULL;
     free(soignant);
     soignant = NULL;
     return 0;
}


//----------------------IMPLEMENTATION DES FONCTIONS  ------------------------------------------------

int pioche(int min, int max) //pioche un chiffre entre un minimum et maximum. création d'une valeur quasi-aléatoire (dépend du temps)
{
  int a;
  a = ((rand()%max)+min);
  return a;
}

void affiche_grille(int nrow, int ncol, Environnement matrice[nrow][ncol])
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
        else if (matrice[i][j].cpt_virus != 0)
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
