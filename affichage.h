#ifndef AFFICHAGE
#define AFFICHAGE


//------------------------------------||:INCLUDE & DEFINE:||-------------------------------------||

#include "utils.h"
#define clrscr() printf("\033[H\033[2J") // la fonction clrscr(); effacera l'écran
#define couleur(param) printf("\033[%sm",param) //paramétrage de l'affichage en couleur

//-------------------------------||:PROTOTYPES DES FONCTIONS:||----------------------------------||

void afficher(int nrow, int ncol, Case matrice[nrow][ncol]);
void affichage_direction(Dir direction);

//--------------------------------------------------------------------------------------------------

#endif
