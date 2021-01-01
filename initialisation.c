#include "initialisation.h"

//------------------------------//:FONCTION:\\---------------------------------\\

int initialisation()
{
    //ok donc maintenant que les structures et les listes sont mises en place, y'a plus qu'à.
    //1. on initialise une première grille de N par M cases. Il faut faire le tour de chaque case et faire poper les soigneurs, les virus et les civils.
    //2. à chaque fois qu'un soigneur ou un civil apparait, il faut l'introduire dans Bonhomme/soigneur ou civil pour l'ajouter aux listes.
    //Ne pas oublier d'initialiser chaque bonhomme.

    Bonhomme * tempS; //tableaux temporaires pour les realloc
    Bonhomme * tempL; //tableau temporaire pour les realloc

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
          emplacement[i][j].PV_virus = vie_virus[4];//initialisation du compteur de vie du virus pour cette case
          compteur_virus += 1;
        }
        else if (nbrAlea > PROB_V && nbrAlea <= PROB_V+PROB_L)
        {
          //alors presence d'un lambda
          emplacement[i][j].occupee = 1;
          emplacement[i][j].presence_lambda = 1;
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
          emplacement[i][j].occupee = 1;
          emplacement[i][j].presence_soignant = 1;
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
     affiche_grille(N, M, emplacement);
     free(lambda);
     lambda = NULL;
     free(soignant);
     soignant = NULL;
     return EXIT_SUCCESS;
}


//-------------------------------//:IMPLEMENTATION DES FONCTIONS:\\----------------------------------\\

int pioche(int min, int max) //pioche un chiffre entre un minimum et maximum. création d'une valeur quasi-aléatoire (dépend du temps)
{
  int a;
  a = ((rand()%max)+min);
  return a;
}
