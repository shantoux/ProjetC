#include "initialisation.h"


//------------------------------||:FONCTION:||---------------------------------||

void initialisation(Bonhomme **soignant, Bonhomme **lambda, Coordonnees **virus,
  int * cpt_lambda, int * cpt_virus, int * cpt_soignant, int nrow, int ncol, Case
  emplacement[nrow][ncol], int vie_virus[])
{
    //ok donc maintenant que les structures et les listes sont mises en place, y'a plus qu'à.
    //1. on initialise une première grille de N par M cases. Il faut faire le tour de chaque case et faire poper les soigneurs, les virus et les civils.
    //2. à chaque fois qu'un soigneur ou un civil apparait, il faut l'introduire dans Bonhomme/soigneur ou civil pour l'ajouter aux listes.
    //Ne pas oublier d'initialiser chaque bonhomme.

    Bonhomme * tempS; //tableaux temporaires pour les realloc
    Bonhomme * tempL; //tableau temporaire pour les realloc
    Coordonnees * tempV;

    //Allocation dynamique pour les tableaux soignants et lambda

    *soignant = (Bonhomme*) malloc (*cpt_soignant * sizeof(Bonhomme));
    if( *soignant == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      free(*soignant);
      exit(EXIT_FAILURE);
    }

    *lambda = (Bonhomme*) malloc (*cpt_lambda * sizeof(Bonhomme));
    if( *lambda == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      free(*lambda);
      exit(EXIT_FAILURE);
    }

    *virus = (Coordonnees*) malloc (*cpt_virus * sizeof(Coordonnees));
    if (*virus == NULL)
    {
      fprintf(stderr,"Allocation impossible");
      free(*virus);
      exit(EXIT_FAILURE);
    }

    // INITIALISATION
    int i, j;
    int nbrAlea;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
      {
        int resultat = probabilite(PROB_V, PROB_L, PROB_S); //si resultat == 4, alors la case reste vide.

        if (resultat == 1)
        {
        //alors présence d'un virus
            emplacement[i][j].PV_virus = vie_virus[4];//initialisation du compteur de vie du virus pour cette case
            (*virus)[*cpt_virus].y = i;
            (*virus)[*cpt_virus].x = j;
            *cpt_virus += 1;

            //realloc puisqu'on ajoute un élément au tableau virus
            tempV = realloc (*virus, (*cpt_virus+1) * sizeof(Coordonnees));
            if (tempV == NULL)
            {
              fprintf(stderr,"Reallocation impossible");
              free(*virus);
              *virus = NULL;
              exit(EXIT_FAILURE);
            }
            else
            {
              *virus = tempV;
            }
        }
        else if (resultat == 2)
        {
            //alors presence d'un lambda
            emplacement[i][j].occupee = 1;
            emplacement[i][j].presence_lambda = 1;
            (*lambda)[*cpt_lambda].localisation.y = i;
            (*lambda)[*cpt_lambda].localisation.x = j;
            attribution_direction(*lambda, *cpt_lambda);
            *cpt_lambda += 1;

            //realloc puisqu'on ajoute un élément au tableau lambda
            tempL = realloc (*lambda, (*cpt_lambda+1) * sizeof(Bonhomme));
            if (tempL == NULL)
            {
                fprintf(stderr,"Reallocation impossible");
                free(*lambda);
                *lambda = NULL;
                exit(EXIT_FAILURE);
            }
            else
            {
                *lambda = tempL;
            }
        }
        else if (resultat == 3)
        {   //presence d'un soignant
            emplacement[i][j].occupee = 1;
            emplacement[i][j].presence_soignant = 1;
            (*soignant)[*cpt_soignant].localisation.y = i;
            (*soignant)[*cpt_soignant].localisation.x = j;
            (*soignant)[*cpt_soignant].vocation = 1;
            attribution_direction(*soignant, *cpt_soignant);
            *cpt_soignant += 1;

            //realloc puisqu'on ajoute un élément au tableau soignant
            tempS = realloc (*soignant, (*cpt_soignant+1) * sizeof(Bonhomme));
            if ( tempS == NULL )
            {
                fprintf(stderr,"Reallocation impossible");
                free(*soignant);
                *soignant = NULL;
                exit(EXIT_FAILURE);
            }
            else
            {
                *soignant = tempS;
            }
        }

        //printf("virus : %d, lambda : %d, soignant : %d\n", *cpt_virus, *cpt_lambda, *cpt_soignant);
       }
     }

     printf("1/soigneur x:%d y:%d\n", (*soignant)[0].localisation.x, (*soignant)[0].localisation.y);
     printf("2/soigneur x:%d y:%d\n", (*soignant)[1].localisation.x, (*soignant)[1].localisation.y);
     printf("3/soigneur x:%d y:%d\n", (*soignant)[2].localisation.x, (*soignant)[2].localisation.y);
     printf("2/soigneur x:%d y:%d\n", (*soignant)[10].localisation.x, (*soignant)[10].localisation.y);
     printf("1/lambda x:%d y:%d\n", (*lambda)[0].localisation.x, (*lambda)[0].localisation.y);
     printf("2/lambda x:%d y:%d\n", (*lambda)[1].localisation.x, (*lambda)[1].localisation.y);
     printf("3/lambda x:%d y:%d\n", (*lambda)[2].localisation.x, (*lambda)[2].localisation.y);
     printf("2/lambda x:%d y:%d\n", (*lambda)[10].localisation.x, (*lambda)[10].localisation.y);
}


//-------------------------------||:IMPLEMENTATION DES FONCTIONS:||----------------------------------||

void attribution_direction(Bonhomme *entite, int indice) //attribue une direction parmi les 8 possibles
{
  int a;
  a = pioche(1,8);
  entite[indice].direction = a;
}
