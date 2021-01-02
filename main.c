
//-------------------------------//:FICHIER PRINCIPAL:\\----------------------------------\\

#include "utils.h"
//#include "lancement.h"
#include "initialisation.h"
//#include "deplacement.h"
#include "affichage.h"

int main(int argc, char* argv[])
{
    int vie_virus[5] = {0,1,2,3,4}; //Tableau vers lequel pointe cpt_virus
    Case emplacement[N][M]={0}; //initialisation de l'environnement avec des valeurs à 0
    int cpt_lambda=0;
    int cpt_virus=0;
    int cpt_soignant=0;
    int cpt_infecté=0;

    //Allocation dynamique pour les tableaux soignants et lambda
    Bonhomme * soignant;
    Bonhomme * lambda;

    soignant = (Bonhomme*) malloc (cpt_soignant * sizeof(Bonhomme));

    if( soignant == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      free(soignant);
      exit(EXIT_FAILURE);
    }

    lambda = (Bonhomme*) malloc (cpt_lambda * sizeof(Bonhomme));
    if( lambda == NULL )
    {
      fprintf(stderr,"Allocation impossible");
      free(lambda);
      exit(EXIT_FAILURE);
    }


    initialisation(&soignant, &lambda, &cpt_lambda, &cpt_virus, &cpt_soignant, N, M, emplacement, vie_virus);
    afficher(N, M, emplacement);
    printf("compteur lambda : %d\ncompteur virus : %d\ncompteur soignant : %d\n", cpt_lambda, cpt_virus, cpt_soignant);
    free(lambda);
    lambda = NULL;
    free(soignant);
    soignant = NULL;
    //lancement(); //lance le programme
    //printf("Les %c ont gagné", vainqueur); //indique entre la population humaine et le virus celui qui a erradiqué l'autre
    return 0;
}
