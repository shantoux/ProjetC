Tableau de bord Projet C

!! en resume !!

//2. gerer les conteurs de sorte à retourner le vainqueur

3. gérer les fonctions match() et sens() //et zone_gradient
match() peut être pas besoin d'une fonction à part entière  -> utiliser "tmp_infection" && .etat = MALADE et décrémenter tmp_infection.
sens() pour les lambda c'est gérer dans "obstacle_bonhomme()" du déplacement donc pas la peine
       pour les soignants ->  *si il n'est pas déjà sur un gradient* il faudrait faire une fonction "scan" de la presence d'un gradient à 1 autour de lui pour se diriger vers le lui, sinon c'est gérer dans "obstacle_bonhomme" normalement


4. voir si le code tel qu'il est fonctionne...
//faire la mise à jour de la fonction d'affichage. --> fait
6. regler correctement les differents arguments et types de chaque fonction (tous les pointeurs sont-ils correctement placés ?)
//7. definir la valeur de chaque constante.
// 8. mettre les fonctions probabilite et pioche au bon endroit (rajout d'un "static" ? "extern"). --> je les ai mis dans le utils.c, qui sert justement aux fonctions qu'on utilise partout
10. voir pour les bords de case en fonction des déplacements de bonhommes. --> j'ai rajouté des modulos pour qu'il y ait un déplacement périodique (ils rentrent par là, sortent de l'autre côté), il faudra aussi modifier CONTAMINATION et ZONE GRADIENT pour prendre ça en compte.
11. terminer de gérer les tableaux soignant et virus
12. faire les fonctions un2moins et un2plus 
