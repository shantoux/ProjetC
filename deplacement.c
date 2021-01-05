#include "deplacement.h"

//------------------------------||:FONCTION:||---------------------------------|

void deplacement(Bonhomme **soignant, int MAX_S, Bonhomme **lambda, int MAX_L, int cpt_lambda,
        int *cpt_virus, int cpt_soignant, int nrow, int ncol, Case emplacement[nrow][ncol],
        int vie_virus[], int MAX_V)
{
    int i;
    int cpt_infecte = 0; //hum pas au bon endroit ?

    // [Lecture tableau lambda]

    for (i = 0; i < MAX_L; i++) //il faudra récupérer le nombre maximum de soignant, virus et lambda après l'initialisation
    {
        if ((*lambda[i]).etat != MALADE && (*lambda[i]).etat != MORT)
        //if (*soignant)[i].malade < 2) COMPRENDS PAS
        {
            if (emplacement[(*lambda)[i].localisation.y][(*lambda)[i].localisation.i].gradient > 0)
            //si je suis sur un gradient : je vais dans la direction opposée
            {

                inverse_gradient(); //pas créé.
            }
            else //sinon j'avance ou je reste à l'arrêt (la fonction s'adapte également à la collision)
            {
                quel_chemin((*lambda)[i]);
            }
        }

        if (emplacement[(*lambda)[i].localisation.y][(*lambda)[i].localisation.x].PV_virus != 0 && (*lambda)[i].etat == SAIN)
        //si je suis sur une case virus et pas infecté : j'ai P chance de tomber malade et L chance de devenir asymptomatique !
        {
            un2moins();
            *cpt_virus--;
            infection();
        }

        if ((*lambda)[i].etat == ASYMPTO) //si je suis asymptomatique :
        {
            (*lambda)[i].tmp_infection -= 1;
            if ((*lambda)[i].tmp_infection == 0)     //si tmp_infection tombe à 0, il redevient sain
            {
                (*lambda)[i].etat = SAIN;
                cpt_infecte--;
            }
            else
            {
                contamination(*lambda[i]); //P chance de contaminer une des cases autour de l'asymptomatique.
                //Retourne la case en question et :
                if ((*choix).occupe != 0 &&) //(*choix).malade == 0)?????? //si case occupée, infection du bonhomme s'il est sain
                {
                  if ((*choix).vocation == 0)
                  {
                      infection(&lambda);
                  }
                  else //le soignant a une immunité unique par virus... comment faire ?
                  {
                    un2plus(); //un virus de plus
                    *cpt_virus++;//???
                  }
                }
                else if ((*choix).occupe == 0)
                {
                  un2plus(); //un virus de plus
                  *cpt_virus++;
                }
            }
        }

        if ((*lambda)[i].malade == 2) //si je suis malade : j'ai P chance de mourir et L chance de survivre
        {
              int mortel = probabilite(PROB_MOURIR, PROB_VIVRE, NULL);
              if (mortel == 1)
              {
                  zone_gradient(emplacement, 2); //
                  (*lambda)[i].malade = 3;
                  cpt_infecte--;
                  emplacement[(*lambda)[i].localisation.x][(*lambda)[i].localisation.y].occupee = 0;
                  emplacement[(*lambda)[i].localisation.x][(*lambda)[i].localisation.y].presence_lambda = 0;
                  emplacement[(*lambda)[i].localisation.x][(*lambda)[i].localisation.y].pv_virus = 4;
                  (*lambda)[i].localisation.x = NULL;
                  (*lambda)[i].localisation.y = NULL;
                  un2plus();
                  *cpt_virus++;
              }
              if (mortel == 2) //bonhomme dégage une zone avec gradient indiquant qu'il est dangereux
              {
                  zone_gradient(emplacement, 1); //
              }
              if () //si un soignant me tient compagnie : un décompte se fait... idem comment faire ?
              {
                  match(); //meme probleme que pour asymptotique (ligne juste après contamination);
                  if (???)
                  {
                      tour_match++;
                  }
                  if (tour_match == 2)
                  {
                      (*lambda)[i].malade = 0; //guérison
                  }
              }
        }
    }




    // [Lecture tableau soigneur]

    for (i = 0; i < MAX_S; i++)
    {
        if ((*soignant)[i].malade < 2)
        {
            if ((*soignant)[i].malade == 0 && ) //si [fonction match] est activée... comment faire ?
            {
                match();
                /*if (???)
                {
                    tour_match++;
                }
                if (tour_match == 2)
                {
                    //guérison
                }*/
            }
            else
            {
                if((*soignant)[i].malade == 0 && ) //si je suis sur un gradient : je vais dans la direction de celui-ci... comment faire ?
                {
                    sens();
                }
                else //j'avance
                {
                    quel_chemin();
                }
            }
        }


        if (emplacement[(*soignant)[i].localisation.x][(*soignant)[i].localisation.y].pv_virus != 0 && (*soignant)[i].malade == 0) //si je suis sur une case virus et pas infecté
        {
            un2moins();
            *cpt_virus--;
            infection(&soignant);
        }
        if ((*soignant)[i].malade == 1) //si je suis asymptomatique :
        {
            (*soignant)[i].tmp_infection--;
            if ((*soignant)[i].tmp_infection == 0)     //si tmp_infection tombe à 0, il redevient sain
            {
                (*soignant)[i].malade = 0;
                cpt_infecte--;
            }
            else
            {
              Case *choix;
              contamination(&choix); //P chance de contaminer une des cases autour de l'asymptomatique.
              //Retourne la case en question et :
              if ((*choix).occupe != 0 && ...) //(*choix).malade == 0)???? //si case occupée, infection du bonhomme s'il est sain (A MODIFIER!!!!!!)
              {
                if ((*choix).vocation == 0 )
                {
                    infection(&lambda);
                }
                else //le soigneur a une immunité unique par virus... comment faire ?
                {
                  un2plus(); //un virus de plus
                  *cpt_virus++;
                }
              }
              else if ((*choix).occupe == 0)
              {
                un2plus(); //un virus de plus
                *cpt_virus++;
              }
            }
        }

        if (*soignant)[i].malade == 2) //si je suis malade : j'ai P chance de mourir et L chance de survivre
        {
              int mortel = probabilite(PROB_MOURIR, PROB_VIVRE, NULL);
              if (mortel == 1)
              {
                  zone_gradient(emplacement, 0);
                  (*lambda)[i].malade = 3;
                  cpt_infecte--;
                  emplacement[(*soignant)[i].localisation.x][(*soignant)[i].localisation.y].occupee = 0;
                  emplacement[(*soignant)[i].localisation.x][(*soignant)[i].localisation.y].presence_soignant = 0;
                  emplacement[(*soignant)[i].localisation.x][(*soignant)[i].localisation.y].pv_virus = 4;
                  (*soignant)[i].localisation.x = NULL;
                  (*soignant)[i].localisation.y = NULL;
                  un2plus();
                  *cpt_virus++;
              }
              if (mortel == 2) //bonhomme dégage une zone avec gradient indiquant que je suis dangereux
              {
                  zone_gradient(emplacement, 1);
              }
              if () //si un malade me tient compagnie : un décompte se fait... ????????????
              {
                  match();
                  if (???)
                  {
                      tour_match++;
                  }
                  if (tour_match == 2)
                  {
                      (*soignant)[i].malade = 0;//guérison
                  }
              }
        }
    }

    //Lecture tableau virus : prototype

    for (i = 0; i < MAX_V ; i++)
    {
        if (pv == 0)
        {
            un2moins();
            cpt_virus--;
        }
    }

}

  //----------------------------||:FONCTIONS:||--------------------------------||


void quel_chemin(Bonhomme *bonhomme, int i, int N, int M, Case emplacement[N][M]) //en fonction de la direction de départ, utilise probabilité() et choisi une nouvelle direction
{
    int resultat = probabilite(PROB_ARRET, PROB_DEPLACEMENT); //ARRET 30%, DEPLACEMENT 70%
    int direction_temp = NULL; //on stock la nouvelle direction de manière temporaire si jamais il y a un obstacle.
    if (resultat == 2) //le Bonhomme se déplace
    {
          resultat = probabilite(PROB_ELSE, PROB_SAME);
          if (resultat == 2)
          {
            direction_temp = bonhomme[i].direction;
          }
          else
          {
            srand(time(NULL));
            direction_temp = pioche_nouvelle(bonhomme[i].direction);
          }
          if (obstacle_lambda(direction_temp, N, M, emplacement, bonhomme[i].localisation) != 1)
          {
              liberation_case(bonhomme[i].localisation.y, bonhomme[i].localisation.x, emplacement);
              Changement_coordonnees(bonhomme[i].localisation, direction_temp);
              bonhomme[i].direction = direction_temp;
              nouvelle_case(bonhomme[i].localisation.y, bonhomme[i].localisation.x, emplacement, bonhomme[i]);
          }
          else
          {
              colision(direction_temp, N, M, emplacement, bonhomme[i]);
          }
    }
}





///////////////////////////////////////////////////////////////////////////////

void colision(int direction_temp, int N, int M, Case emplacement[N][M], Bonhomme bonhomme[i]) //si sur la case de déplacement se trouve quelqu'un, on ne peut pas y deplacer le bonhomme. dans ce cas 50-50 de s'arrêter ou de changer de direction
{ //CAS OU TOUTES LES CASES AUTOUR SONT BLOQUEES.
    int libre = obstacle_lambda(direction_temp, N, M, emplacement, bonhomme[i].localisation);
    Dir new_temp;
    while libre < 1
    {
        int resultat = pioche(1,2);
        if (resultat = 1) //le perso s'arrête
        {
            //(*bonhomme)[i].direction = 0;
            libre = 2;
        }
        else
        {
            new_temp = pioche_nouvelle(direction_temp);
            libre = obstacle_lambda(new_temp, N, M, emplacement, bonhomme[i].localisation);
        }
    }
    if (libre == 1)
    {
      liberation_case(bonhomme[i].localisation.y, bonhomme[i].localisation.x, emplacement);
      Changement_coordonnees(bonhomme[i].localisation, direction_temp);
      bonhomme[i].direction = direction_temp;
      nouvelle_case(bonhomme[i].localisation.y, bonhomme[i].localisation.x, emplacement, bonhomme[i]);
    }
  }


///////////////////////////////////////////////////////////////////////////////

void contamination(&choix)
{
  int resultat = pioche(1,9);
  switch (resultat)
  {
  case 1 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)-1][((*bonhomme)[i].localisation.y)+1]; //case au sud-ouest
      break;
  case 2 :
      *choix = emplacement[(*bonhomme)[i].localisation.x][((*bonhomme)[i].localisation.y)+1]; //case au sud
      break;
  case 3 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)+1][((*lambda)[i].localisation.y)+1]; //case au sud-est
      break;
  case 4 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)-1][(*bonhomme)[i].localisation.y]; //case à l'ouest
      break;
  case 5 :
      *choix = emplacement[(*bonhomme)[i].localisation.x][(*bonhomme)[i].localisation.y]; //case de l'asymptomatique
      break;
  case 6 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)+1][(*bonhomme)[i].localisation.y]; //case à l'est
      break;
  case 7 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)-1][((*bonhomme)[i].localisation.y)-1]; //case au nord-ouest
      break;
  case 8 :
      *choix = emplacement[(*bonhomme)[i].localisation.x][((*bonhomme)[i].localisation.y)-1]; //case au nord
      break;
  case 9 :
      *choix = emplacement[((*bonhomme)[i].localisation.x)+1][((*bonhomme)[i].localisation.y)-1]; //case au nord-est
      break;
  default :
    printf("la contamination de l'asymptomatique ne fonctionne pas");
      exit(EXIT_FAILURE);
  }
}

///////////////////////////////////////////////////////////////////////////////

int infection()
{
  int resultat = probabilite(PROB_MALADE, PROB_ASYMPTO, NULL);
  switch (resultat)
  {
  case 1 : //tombe malade
      (*bonhomme)[i].malade = 2;
      cpt_infecte++;
      return 1;
  case 2 : //asymptomatique
      (*bonhomme)[i].malade = 1;
      (*bonhomme)[i].tmp_infection = 7;
      cpt_infecte++;
      return 2;
  default :
      printf("l'infection ne marche pas correctement (ERREUR 44)");
      exit(EXIT_FAILURE);
  }
}


///////////////////////////////////////////////////////////////////////////////

void zone_gradient(Case emplacement, bool etat) //marque autour du bonhomme la zone de signal avec un gradient en fonction de la proximité.
{
  if (etat == 1) //cas le malade est vivant
  {
    for (u = 0 ; u < 3 ; u++)
      {
          for (k = 0 ; k < 3 ; k++)
          {
              if(u+k > 0)
              {
                  if (u == 2 || k == 2)
                  {
                      emplacement[((*lambda)[i].localisation.x)-u][((*lambda)[i].localisation.y)+k].gradient = 1;
                      emplacement[((*lambda)[i].localisation.x)+u][((*lambda)[i].localisation.y)-k].gradient = 1;
                  }
                  else
                  {
                      emplacement[((*lambda)[i].localisation.x)-u][((*lambda)[i].localisation.y)+k].gradient = 2;
                      emplacement[((*lambda)[i].localisation.x)+u][((*lambda)[i].localisation.y)-k].gradient = 2;
                  }
              }
          }
      }
  }
  if (etat == 2) //cas ou le malade vient de mourir
  {
    for (u = 0 ; u < 3 ; u++)
      {
          for (k = 0 ; k < 3 ; k++)
          {
          emplacement[((*lambda)[i].localisation.x)-u][((*lambda)[i].localisation.y)+k].gradient = 0;
          emplacement[((*lambda)[i].localisation.x)+u][((*lambda)[i].localisation.y)-k].gradient = 0;
          }
      }
  }
}

///////////////////////////////////////////////////////////////////////////////:

void Changement_coordonnees(Coordonnees *anciennes, Dir nouvelle)
{
  if (nouvelle == NORD)
  {
    *(anciennes).y = (*(anciennes).y -1 + Long)%Long;
  }
  else if (nouvelle == SUD)
  {
    *(anciennes).y = (*(anciennes).y +1)%Long;

  }
  else if (nouvelle == EST)
  {
    *(anciennes).x = (*(anciennes).x +1)%Larg;

  }
  else if (nouvelle == OUEST)
  {
    *(anciennes).x = (*(anciennes).x -1 + Larg)%Larg;
  }
  else if (nouvelle == NO)
  {
    *(anciennes).y = (*(anciennes).y -1 + Long)%Long;
    *(anciennes).x = (*(anciennes).x -1 + Larg)%Larg;
  }
  else if (nouvelle == NE)
  {
    *(anciennes).y = (*(anciennes).y -1 + Long)%Long;
    *(anciennes).x = (*(anciennes).x +1)%Larg;
  }
  else if (nouvelle == S0)
  {
    *(anciennes).y = (*(anciennes).y +1)%Long;
    *(anciennes).x = (*(anciennes).x -1 + Larg)%Larg;
  }
  else if (nouvelle == SE)
  {
    *(anciennes).y = (*(anciennes).y +1)%Long;
    *(anciennes).x = (*(anciennes).x +1)%Larg;
  }
}

void liberation_case(int i, int j, Case place[i][j])
{
  place[i][j].occupee = 0;
  place[i][j].presence_lambda = 0;
  place[i][j].presence_soignant = 0;
}

void nouvelle_case(int i, int j, Case place[i][j], Bonhomme entite[])
{
  place[i][j].occupee = 1;
  if (entite.vocation == 1)
  {
    place[i][j].presence_soignant = 0;
  }
  else
  {
    place[i][j].presence_lambda = 0;
  }
}

Dir pioche_nouvelle(Dir ancienne)
{
  Dir tab[8] = {NORD, SUD, EST, OUEST, NO, NE, SO, SE};
  int a;
  do
  {
    a = pioche(1,8);
  }
  while tab[a] == ancienne;
  return tab[a];
}

int obstacle_lambda(Dir nouvelle, int Long, int Larg, Case matrice[Long][Larg], Coordonnees *anciennes)
{
  Coordonnees tampon;
  tampon = *anciennes;
  Changement_coordonnees(&tampon, nouvelle);
  if (matrice[tampon.y][tampon.x].occupee == 1 || matrice[tampon.y][tampon.x].gradient != 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void fonction_gradient(int i, int j, Case place[i][j], Bonhomme entite[indice])
{
  if (entite[indice].vocation == 1)
  {
    for (i = (entite[indice].localisation.y - 1+N)%N, )
  }
}
