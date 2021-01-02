#include "lancement.h"

//------------------------------//:FONCTION:\\---------------------------------\\

void lancement(Bonhomme lambda[], Bonhomme soigneur[], Case emplacement[][])
{
    initialisation(Bonhomme soignant[], Bonhomme lambda[], &cpt_lambda, &cpt_virus, &cpt_soignant);
    affichage(Bonhomme soignant[], Bonhomme lambda[], int nrow, int ncol, Case matrice[nrow][ncol]);

    while ( (((cpt_lambda + cpt_soignant) > 0) && (cpt_virus > 0)) || ((cpt_infecté > 0) && (cpt_virus == 0)) )
    {
        deplacement(Bonhomme soignant[], Bonhomme lambda[], &cpt_lambda, &cpt_virus, &cpt_soignant, &cpt_infecté);
        affichage(Bonhomme soignant[], Bonhomme lambda[], int nrow, int ncol, Case matrice[nrow][ncol]);
    }
}
