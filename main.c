
//-------------------------------||:FICHIER PRINCIPAL:||----------------------------------||

#include "utils.h"
//#include "lancement.h"
#include "initialisation.h"
#include "deplacement.h"
#include "affichage.h"

int main(int argc, char* argv[])
{
    //Déclaration des variables qui seront visibles dans tout le programme (plus simple que extern tout ça)
    int vie_virus[5] = {0,1,2,3,4}; //Tableau vers lequel pointe cpt_virus
    Case emplacement[N][M]={0}; //initialisation de l'environnement avec des valeurs à 0
    int cpt_lambda=0;
    int cpt_virus=0;
    int cpt_soignant=0;
    int cpt_infecte=0;
    int tours_simulation_max = 0;

    //Déclaration des tableaux pour Bonhommes soignant, lambda et virus
    Bonhomme * soignant;
    Bonhomme * lambda;
    Coordonnees * virus;

    printf("Veuillez entrer le nombre de tours de simulation que vous souhaitez réaliser : \n");
    scanf("%d", &tours_simulation_max);

    initialisation(&soignant, &lambda, &virus, &cpt_lambda, &cpt_virus,
                   &cpt_soignant, N, M, emplacement, vie_virus);

    //Affiche la grille initiale
    afficher(N, M, emplacement);

    int MAX_S = cpt_soignant;
    int MAX_L = cpt_lambda;
    int MAX_V = cpt_virus;

    //BOUCLE DE SIMULATION
    int i;
    for (i = 0, i < tours_simulation_max, i++)
    //while ( ( ( (cpt_lambda + cpt_soignant) > 0) && (cpt_virus > 0) ) || ( (cpt_infecté > 0) && (cpt_virus == 0) ) )
    {
      deplacement(&soignant, &lambda, &cpt_lambda, &cpt_virus, &cpt_soignant, &cpt_infecté, MAX_S, MAX_L);
      afficher(N, M, emplacement);
    }

    free(lambda);
    lambda = NULL;
    free(soignant);
    soignant = NULL;
    //lancement(); //lance le programme
    //printf("Les %c ont gagné", vainqueur); //indique entre la population humaine et le virus celui qui a erradiqué l'autre
    return 0;
}
