#include "utils.h"

////////////////////////////////////IMPLEMENTATION FONCTIONS////////////////////////////////////////////


int pioche(int min, int max) //pioche un chiffre entre un minimum et maximum. création d'une valeur quasi-aléatoire (dépend du temps)
{
  int a;
  a = ((rand()%max)+min);
  return a;
}

int probabilite(int PROBA1, int PROBA2, int PROBA3)
{
    int nbrAlea = pioche(1,100);//nbrAlea pioché entre 1 et PROBA1 + PROBA2+ PROBA3
    printf("%d\n", nbrAlea);
    if (nbrAlea < PROBA1)
    {
        return 1;
    }
    else if (nbrAlea > PROBA1)
    {
        if (PROBA3 == NULL)
        {
            return 2;
        }
        else
        {
            if (nbrAlea > PROBA1+PROBA2)
            {
                if (nbrAlea > PROBA1+PROBA2+PROBA3)
                {
                    return 4;
                }
                else
                {
                    return 3;
                }
            }
            else
            {
                return 2;
            }
        }

    }
}
