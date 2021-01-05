#ifndef DEPLACEMENT
#define DEPLACEMENT

  //------------------------------------||:INCLUDE & DEFINE:||-------------------------------------||

  #include "utils.h"
  #define PROB_ELSE 25
  #define PROB_SAME 75
  #define PROB_DEPLACEMENT 70
  #define PROB_ARRET 30
  #define PROB_VIVRE 90
  #define PROB_MOURIR 10
  #define PROB_MALADE 33
  #define PROB_ASYMPTO 67

  //-------------------------------||:PROTOTYPES DES FONCTIONS:||----------------------------------||
  /*fonction principale de déplacement. Considère les déplacements et
  les conséquences de chacun en fonction de son état, de son statut et de son environnement*/
  void deplacement(Bonhomme **soignant, Bonhomme **lambda, &cpt_lambda, &cpt_virus, &cpt_soignant, int MAX_S, int MAX_L, int MAX_V);

  void quel_chemin(Bonhomme *bonhomme, int i, int N, int M, Case emplacement[N][M]);//permet de choisir d'avancer (même direction ou autre) ou de s'arrêter. Gère les collisions.
  void colision(int direction_temp); //fonction appelée par la fonction [quel_chemin] dans un cas de collision. Change de direction ou s'arrête. (gère les collisions multiples).
  void contamination(Case * choix); //cas de dépot d'un virus du fait d'un asymptotique autour de sa case ou sur celle-ci.
  int infection(Bonhomme ** bonhomme); //determine si un bonhomme devient asymptotique ou malade.
  void Changement_coordonnees(Bonhomme entite[], Dir nouvelle, int Long, int Larg);
  void liberation_case(int i, int j, Case place[i][j]);
  void nouvelle_case(int i, int j, Case place[i][j], Bonhomme entite[]);
  Dir pioche_nouvelle(Dir ancienne);
  int obstacle_lambda(Dir nouvelle, int Long, int Larg, Case matrice[Long][Larg], Coordonnees *anciennes);
  Dir fonction_gradient(Case *place, Bonhomme *entite, int indice, Coordonnees *anciennes);





  //void zone_gradient(); ??? ==> zone créée par le malade.
  //void sens(gradient); ??? ==> pour un soigneur, est attiré, pour un lambda, est repoussé, par un malade.
  //void match(); ??? ==> quand un soigneur se colle à un malade, les deux ne bougent plus et le malade guérit après deux tours s'il survit.

//---------------------------------------------------------------------------------------------------

#endif
