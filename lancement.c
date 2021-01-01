#include "lancement.h"

//------------------------------//:FONCTION:\\---------------------------------\\

void lancement(Bonhomme lambda[], Bonhomme soigneur[], Case emplacement[][])
{
    int vie_virus[5] = {0,1,2,3,4}; //Tableau vers lequel pointe cpt_virus
    Case emplacement[N][M]={0}; //initialisation de l'environnement avec des valeurs à 0

    //Allocation dynamique pour les tableaux soignants et lambda
    Bonhomme * soignant;
    Bonhomme * lambda;

    int cpt_lambda;
    int cpt_virus;
    int cpt_soignant;
    int cpt_infecté;

    initialisation(Bonhomme soignant[], Bonhomme lambda[], &cpt_lambda, &cpt_virus, &cpt_soignant);
    affichage(Bonhomme soignant[], Bonhomme lambda[], int nrow, int ncol, Case matrice[nrow][ncol]);

    while ( (((cpt_lambda + cpt_soignant) > 0) && (cpt_virus > 0)) || ((cpt_infecté > 0) && (cpt_virus == 0)) )
    {
        deplacement(Bonhomme soignant[], Bonhomme lambda[], &cpt_lambda, &cpt_virus, &cpt_soignant, &cpt_infecté);
        affichage(Bonhomme soignant[], Bonhomme lambda[], int nrow, int ncol, Case matrice[nrow][ncol]);
    }
}
