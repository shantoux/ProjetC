
UE MiNi Info II 
Projet C

Compte-Rendu

« Simulation d’une invasion virale dans une population »

supervisé par Stéphanie Chevalier

auteur : Shanti Pijeaud — Boutard Anthony



Principe de la simulation

	Ce projet a pour objectif la matérialisation d’un environnement virtuel où évoluent un virus dans une population dynamique de bonhommes, et où les bonhommes peuvent être de deux types (lambda ou soignant). Globalement, le programme mis en place a pour consigne de demander à l'utilisateur le nombre de tour qu'il veut simuler, puis de lancer la simulation jusqu'à ce que le nombre de tour possible soit atteint.

	Le projet est segmenté en plusieurs fichiers qui permettent de gérer les diverses fonctions nécessaires au programme : 

	(1) main.c
	(2) utils.c
	(3) utils.h
	(4) initialisation.c
	(5) initialisation.h
	(6) deplacement.c
	(7) deplacement.h
	(8) affichage.c
	(9) affichage.h

	Pour réaliser ce programme, nous avons décidé de créer l'environnement à partir d'une matrice[ ][ ], et de gérer les trois entités (virus, lambda, soignant) par trois tableaux[ ] distincts. Initialement, nous avions défini ces trois tableaux de manière dynamique par le biais de la fonction "malloc", et avons travaillé la quasi-totalité à partir de ces tableaux dynamiques, ce qui nous a fait perdre un temps énorme, car nous n'arrivions pas à les gérer. La version finale du programme ne comporte donc que des tableaux à dimensions fixes. 

	Au fil des tours de la simulation, la fonction "affichage" qui se trouve dans le fichier affichage.c/h, permet sur le terminal (i) la matérialisation de l'environnement virtuel, (ii) l'affichage des différentes entités qui y évoluent et (iii) l'état des bonhommes (malade, asymptomatique ou sain) de manière dynamique au fil des tours de la simulation. Elle est une première fois utilisée à la fin de l'initialisation, puis à nouveau appelée après chaque tour pour mettre à jour la matrice. Elle exploite la fonction "msleep" (utils.c/h) qui instaure une brève pause sur le terminal entre l'affichage de deux tours afin de rendre compte plus facilement de l'évolution de la matrice.Paramètres préliminaires (main.c, utils.c, utils.h)

	Les structures de l'ensemble des acteurs du programme sont définies dans utils.h, et considèrent :
	
	— "Coordonnees" : elle permet de définir l'emplacement [y = ligne][x = colonne] d'une entité. 
	— "Bonhomme" : elle intègre les particularités d'un bonhomme donné, à savoir sa vocation (si c'est un lambda ou un soignant), sa direction définie par l'enum "Dir", son état par rapport au virus et défini par l'enum "Statut", sa localisation dans l'environnement, et le temps qu'il lui reste à être infecté si ce bonhomme est asymptomatique ou en train d'être soigné par un autre bonhomme soignant. 
	— "Case" : elle représente tout ce qu'une case de l'environnement virtuel peut contenir (une entité ou non, la vie d'un virus qui s'y trouve, un pointeur vers un bonhomme s'il y en a un et le niveau de gradient si un malade est proche de cette case).

	Le fichier utils.h possèdent également les prototypes des fonctions "pioche" (choisi  aléatoirement un nombre entre un minimum et un maximum) et "probabilite" (sélectionne l'une des actions possibles en fonction de sa probabilité à l'aide d'un nombre choisi par "pioche" entre 1 et 100) implémentées dans utils.c. 

	Dans le main.c, la matrice "emplacement" et le tableau "vie_virus" (contenant les différents états de la vie du virus) sont déclarées. Ensuite, plusieurs variables sont définis afin d'établir le nombre initial de virus, de lambda et de soignant à la fin de l'initialisation par des compteurs. Ils sont incrémentés dans initialisation.c à chaque apparition de l'une des entités jusqu'à la fin de la lecture de la matrice afin d'obtenir dans chaque tableau associé, l'ensemble des trois entités apparues au cours de l'initialisation. La variable "tours_simulation_max" permet quant-à-elle de garder le nombre de tour que l'utilisateur désirera simuler par une fonction "scanf" établi un peu après.

	Sont ensuite déclarés les trois tableaux d'entités, en sachant que le tableau virus ne contient que des coordonnées.


Initialisation de la matrice et apparition des entités aléatoirement (initialisation.c)

	Une fois les paramètres préliminaires au lancement du programme déclarés, le main appelle la fonction "initialisation" qui se trouve dans initialisation.c en prenant comme notamment comme paramètres des pointeurs sur les compteurs de lambda, virus et soignant, mais également sur la matrice "emplacement" et sur les trois tableaux des entités. 

	L'objectif de cette fonction est de définir les valeurs par défaut (absence d'entité) de chaque case de "emplacement", puis de faire apparaître (selon une certaine probabilité inhérente à chaque entité), un virus, un lambda, un soignant (probabilités définies par des constantes de préprocesseur) ou de laisser la case vide à défaut. A chaque fois qu'une entité apparait, elle est répertoriée au sein de son tableau par un ajout dans la case d'indice n (égal au compteur associé) où ses caractéristiques seront alors initialisées. Cela est fait par le biais d'un tableau temporaire qui ait associé au tableau de l'entité en question. Dans le cas où un bonhomme apparait, la fonction "attribution_direction" lui donne une direction virtuelle aléatoire par le biais de la fonction "pioche". 
Gestion des déplacement pour chaque tour jusqu'au dernier (deplacement.c)

	En premier lieu, il est important de comprendre comment le programme procède pour modifier la position d'un bonhomme d'une case à une autre s'il est amené a bouger. Pour ce faire, les trois fonctions "liberation_case", "changement_coordonnees" et "nouvelle_case" sont appelées.

	La fonction "deplacement" se trouve dans deplacement.c se distingue en trois étapes :

	A. Déplacement des bonhommes lambdas :

	Cette première boucle for parcourt le tableau "lambda" et s'articule en quatre conditions. Nous avons décidé que les conséquences (hors affichage) de l'infection d'un bonhomme ne se verra qu'au tour n+1. Pour gérer la périodicité des déplacements (un lambda sur un bord de la matrice pourra se déplacer de l'autre côté), un modulo a été réalisé. Dans le cas où la valeur est négative, la longueur de la colonne ou de la ligne a été ajoutée avant de réaliser le modulo. Il faut aussi remarquer qu'un bonhomme, s'il en a la possibilité, ne peut se déplacer que d'une case par tour à la fois.

	(1) si le lambda n'est pas malade : une action de déplacement est possible

Dans cette condition, la fonction analyse d'abord les gradients en priorité. Si la case sur lequel le lambda se trouve possède un gradient égal à 2, le lambda doit s'enfuir dans la direction opposée. La fonction "attraction" est appelée. Elle permet au lambda d'être "attiré" vers un gradient égal à 1 si cela est possible afin de fuir le malade. 

Autrement, la fonction "repulsion" est automatiquement appelée. Ainsi, si la case sur lequel le lambda se trouve possède un gradient égal à 1, le lambda analyse son environnement et cherche alors à s'enfuir dans la direction opposée au sens du gradient (vers un gradient égal à 0) si cela est possible. 

Si la case du lambda possède un gradient égal à 0, "repulsion" analyse si un gradient égal à 1 se trouve autour du bonhomme, auquel cas celui-ci se rend directement dans le sens opposé (vers un gradient 0) si cela est possible.

Finalement, si "repulsion" n'a trouvé aucun gradient égal à 0 autour du bonhomme, la fonction "quel_chemin" est appelée. C'est la fonction par défaut de déplacement dans l'environnement virtuel. Elle demande tout d'abord à la fonction "probabilite" de décider si le bonhomme reste à l'arrêt ou se déplace. Si le bonhomme choisi de se déplacer, il a de nouveau la possibilité, par le biais de "probabilite", soit de garder sa direction initiale, soit d'en changer (fonction "pioche_nouvelle") et conserve temporairement son choix dans la variable "direction_temp". Si, après analyse par l'appelle de la fonction "obstacle_bonhomme", la case correspondant à cette nouvelle direction n'est pas occupée, le bonhomme change de case. Sinon, la fonction "collision" est appelée et lui permet de choisir entre s'arrêter ou changer encore de direction jusqu'à ce que cela soit possible (à l'aide d'une boucle while vérifiant la condition que la case de la nouvelle direction ne soit pas occupée).

	(2) si le lambda est malade : il se fait soigner à proximité d'un soignant et à une chance de mourir à chaque tour. Il crée une zone de gradient autour de lui qui indique aux autres sa position

Quand un lambda est malade, la fonction "soin" est appelée. Celle-ci analyse l'environnement, et se contente de décrémenter de 1 la variable "tmp_infection" et d'annuler le gradient de lambda (appel de la fonction "zone_gradient") si un soignant est sur une case voisine. Ensuite, si le malade n'est toujours pas guérit, la fonction "probabilite" permet ici de décider si le malade meurt ou non à ce tour. S'il meurt, il est supprimé de la case, et sinon, il matérialise sa zone de gradient (sauf en présence d'un soignant). 

	(3) si un lambda sain est sur une case virus : infection

Si, en général après un déplacement, le lambda se retrouve sur une case virus et qu'il est sain, il va se voir infecter par le virus (qui sera supprimé de la case) par l'appel de la fonction "infection". Cette fonction décide si le lambda devient malade ou asymptomatique. 

	(4) si le lambda est asymptomatique : possibilité de lâcher un virus à proximité de sa position

Dans le cas où le lambda est asymptomatique, sa variable "tmp_infection" décrémente de 1 directement. Si elle devient égale à 0, le lambda redevient sain. Autrement, la fonction "contamination" est appelée. Cette fonction permet à l'asymptomatique de pouvoir contaminer sa case ou l'une des cases voisines de la sienne avec un certain pourcentage de chance. Il peut également ne contaminer aucune case. Si une case est contaminée et qu'elle est occupée par un lambda, celui-ci sera immédiatement infecté. Si c'est un soignant, il sera immunisé mais un virus sera placé sur sa case (s'il ne bouge pas au prochain tour, la condition "présence d'un virus" s'activera, l'infectant alors). Enfin, si la case est vide, un virus y sera également placé. 

	B. Déplacement des bonhommes soignants :

	La lecture du tableau des soignants respecte sensiblement l'architecture en quatre conditions du tableau des lambdas. Seulement, certaines choses changent également, et nous ne détaillerons pas à nouveau ce qui n'a pas été modifié entre la lecture des deux tableaux. 

	(1) si le soignant n'est pas malade : une action de déplacement est possible
	
Tout comme un lambda, la fonction regarde les gradients en priorité. Pour un soignant, s'il se trouve sur un gradient égal à 2, il ne bougera pas et se contentera de rester passif (la fonction "soin" sera alors activée à la lecture du tableau des lambdas au prochain tour). Si le gradient est de 1, un appel de la fonction "attraction" attire alors le soignant vers une case de gradient égal à 2, et si le gradient est de 0, vers une case de gradient égal à 1 (si elle existe autour de lui). 

	Le reste des conditions s'applique comme celles à la lecture du tableau lambda. Il est cependant à noter qu'un soignant asymptomatique continue d'être attiré et de soigner les malades, à l'inverse des soignants malades qui perdent leurs fonctions de soin. 


	C. Analyse des virus

	La lecture du tableau virus se contente de décrémenter la variable "PV_virus" de "emplacement" pour chaque virus existent, et de supprimer un virus du tableau quand il n'existe plus.  

	
