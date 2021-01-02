#ifndef INITIALISATION
#define INITIALISATION

//------------------------------------//:INCLUDE & DEFINE:\\-------------------------------------\\

#include "utils.h"
#define PROB_V 5
#define PROB_L 20
#define PROB_S 10

//-------------------------------//:PROTOTYPES DES FONCTIONS:\\----------------------------------\\

void initialisation(Bonhomme **soignant, Bonhomme **lambda, int * cpt_lambda, int * cpt_virus, int * cpt_soignant, int nrow, int ncol, Case emplacement[nrow][ncol], int vie_virus[]);
int pioche(int min, int max);

//---------------------------------------------------------------------------------------------------

#endif
