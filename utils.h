//-------------------------------//:INCLUDE & DEFINE:\\----------------------------------\\

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> //???
#define N 20
#define M 20

//-------------------------------//:STRUCTURES:\\----------------------------------\\

typedef struct Coordonnees Coordonnees; //les coordonnees determinent une case précise dans la matrice.
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
    bool mort; //
    Coordonnees localisation; //A voir comment les gerer de manière pertinente. Pointeur ? localisation.x = "N" et localisation.y = "M"
    int atchoum; //seulement pour les civils. Garder dans la structure ? Pointeur vers les vraies cases ?
};

typedef struct Case Case; //utiliser un pointeur pour le décompte des virus.
struct Case
{
    bool occupee; //indique la présence d'une des trois entités possibles
    int gradient; //indique le niveau de charge virale (dû à un malade)
    int  PV_virus; //indique le "temps de vie" restant à un virus sur la case
    bool presence_lambda; //j'ai pas réussi à utiliser les pointeurs ici, il faudra voir si c'est handicapant pour la suite
    bool presence_soignant;//ici non plus
};
