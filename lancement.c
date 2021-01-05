#include "lancement.h"

//------------------------------||:FONCTION:||---------------------------------||

void lancement(Bonhomme lambda[], Bonhomme soigneur[], Case emplacement[][])
{
  printf("compteur lambda : %d\ncompteur virus : %d\ncompteur soignant : %d\n", cpt_lambda, cpt_virus, cpt_soignant);


  while ( ( ( (cpt_lambda + cpt_soignant) > 0) && (cpt_virus > 0) ) || ( (cpt_infecté > 0) && (cpt_virus == 0) ) )
  {
  deplacement(&soignant, &lambda, &cpt_lambda, &cpt_virus, &cpt_soignant, &cpt_infecté, MAX_S, MAX_L);
  afficher(N, M, emplacement);
  }
}
