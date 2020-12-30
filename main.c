// Version 1 : on veut obtenir une petite matrice ou peut se retrouver
// dans chaque case avec une certaine probabilite un virus, un civil OU un soigneur

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "main.h"
#define N 5
#define M 5
#define PROB_V 20
#define PROB_C 30
#define PROB_S 25

//structures
typedef enum Danger Danger; //permet d'indiquer la charge virale d'une case
enum Danger
{
  ABSENT, FAIBLE, FORT
};

typedef struct Coordonnees Coordonnees; //les coordonnees determine une case precise au sein de l'environnement.
struct Coordonnees
{
  int x;
  int y;
};

typedef struct Environnement Environnement; //utiliser un pointeur pour le décompte des virus.
struct Environnement
{
  bool presente[3] = {0}; //indique la présence d'une des trois entités possibles
  Danger charge_virale = {ABSENT}; //indique le niveau de charge virale (dû à un civil malade)
  int cpt_virus = {0}; //indique le "temps de vie" restant à un virus sur la case
  int soigneur* = NULL; //intêret de pointer vers les S et C ?
  int civil* = NULL;
};

typedef struct Bonhomme Bonhomme;
struct Bonhomme
{
  bool vocation = false; //indique si le bonhomme est un soigneur (1) ou simple civil (0)
  int direction = NULL ; //donne la direction du Bonhomme
  bool malade = false; // indique si le bonhomme est sain(0) ou malade(1). ??????
  bool mort = false ; //peut-être inutile. A voir durant le dvl !!!
  Coordonnees localisation; //A voir comment les gerer de manière pertinente. Pointeur ? localisation.x = "N" et localisation.y = "M"
  int atchoum[a][b] = NULL; //seulement pour les civils. Garder dans la structure ? Pointeur vers les vraies cases ?
  Element* suivantS = NULL; //raccorde à la liste des soigneurs (si nécéssaire)
  Element* suivantC = NULL; //raccorde à la liste des civils (si nécéssaire)
};

struct Bonhomme soigneur; //il faudra les rajouter dans le fichier nécéssaire. Surement le main ou l'initialisation
struct Bonhomme civil; //idem

typedef struct ListeS ListeS; //liste chainee pour les soigneurs
struct ListeS
{
  Bonhomme *numberOne;
};

typedef struct ListeC ListeC; //liste chainee pour les civils
struct ListeC
{
  Bonhomme *theFirst; //pas la même constante que l'autre liste histoire de les différencier
};


//fonction principale
int pioche();

int main()
{
    //ok donc maintenant que les structures et les listes sont mises en place, y'a plus qu'à.
    //1. on initialise une première grille de N par M cases. Il faut faire le tour de chaque case et faire poper les soigneurs, les virus et les civils.
    //2. à chaque fois qu'un soigneur ou un civil apparait, il faut l'introduire dans Bonhomme/soigneur ou civil pour l'ajouter aux listes.
    //Ne pas oublier d'initialiser chaque bonhomme.

    Environnement case[N][M];
    int i, j;

    /////////////////////////////
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
      {
        int nbrAlea = pioche();
        printf("%d\n", nbrAlea);
        if (nbrAlea < 5) ;
          //alors présence d'un virus
        else if (nbrAlea >= 5 && nbrAlea < 20) ;
          //alors presence d'un civils
        else if (nbrAlea >= 20 && nbrAlea < 30) ; //presence d'un soigneur
        else // aucune entitee sur cette case
       }
     }
    ////////////////////////////
}

int pioche(); //pioche un chiffre entre un et cent. création d'une valeur quasi-aléatoire (dépend du temps)
{
  srand(time(NULL);
  double nbrAlea = (rand() %100 +1);
  return nbrAlea;
}
