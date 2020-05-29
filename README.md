# :capital_abcd: Word Search
A word search puzzle solver

## Comment utiliser le programme
- make mm15 			: compile le projet
- ./mm15          : executer
- make ind FILE=toto.c	: indente le fichier toto.c
- make clean			: efface les fichiers inutiles
- make purge			: efface l'executable

## Les options du programme
- l : lire nouvelle grille 15x15
- r : recherche un mot dans la grille courante
- s : resoudre le jeu courant
- b : creer une grille 15x15
- x : choisir un jeu entre 1, 2 ou 3
- q : terminer

## Explication des fonctionnalités
- 1/ Lecture et affichage du jeu :
Pour pouvoir lire et afficher le jeu à partir des entrées données par l’utilisateur (choix « l » dans le menu principal), il y a deux options possibles. On peut soit lire les mots à partir d’un fichier (option « f »), soit entrer la grille et les mots au clavier (option « c »). Il y a aussi une option supplémentaire (option « e ») qui permet d’enregistrer la grille du jeu courant dans un fichier.
On a testé la lecture par un fichier (option « f ») grâce à un fichier « file.txt » inclus dans le projet rendu. Dans la suite, ce fichier « file.txt » est  remplie avec les mots de words1 qui sera utilisé pour la suite du projet.

- 2/ Recherche d’un mot dans une grille :
La recherche d’un mot dans la grille s’effectue par le choix « r »  , qui nous affiche la ligne, la colonne et la direction du mot trouvé. Pour optimiser la taille du code, on a utilisé deux variables, i_step (le pas de la ligne) , j_step (le pas de la colonne) que l’on incrémente par « 0 », « 1 », « -1 » en fonction de la direction. Cela nous permet de faire une recherche circulaire dans toute les directions, et ainsi nous donner la ligne, la position et la direction du mot à partir d’une lettre dans la grille.
On a testé la fonction de recherche d’un mot dans une grille grâce à aux grilles grid1, grid2 et grid3.

- 3/ Résolution du jeu :
Le choix « s » dans le menu principal permet de résoudre le jeu courant. Il y a alors deux options possibles dans le sous menu du choix  « s ». L’option « 1 » permet une recherche par mots, et l’option  « 2 » permet une recherche par grille.
On a testé la résolution du jeux avec les grilles grid1, grid2, grid3 et on compare les résultats des deux options. Nous avons observé une différence par rapport aux nombre de mots trouvés, ou la première option trouve 41 mots et la deuxième option trouve 42 mots en comptant deux fois un mot (pour grid1). On observe aussi ce même problème avec la grille grid 2 et grid 3.
Pour palier à ce problème nous avons créé une condition dans l'option 2 (recherche par grille) qui indique que si un mot à déjà été trouvé, il ne peut pas être compté plusieurs fois.

- 4/ Remplissage de la grille par les choix 1, 2, 3 :
Ici, le programme fonctionne correctement, en sélectionnant le choix « x », on peut entrer au clavier soit « 1 », « 2 », « 3 » qui permettent d’afficher des grilles déjà remplie. 5/ Remplissage de la grille par des mots (génération de la grille en partant d’une liste de mot)
On lit les mots à partir d’un fichier, puis on trie les indexes des mots du plus petit mot au plus grand. Ensuite la grille est remplie ligne par ligne. On commence par le mot de plus grande taille. Puis on complète les cases manquantes de la ligne par le mot de plus petite taille, et si il reste des cases vides, on les complète par des lettres aléatoires. Cela est fait pour chaque ligne. Enfin on renvoie le nombre de mot qui ont pu être placés dans la grille.
On a testé le remplissage de la grille par les mots du fichier « file.txt ».
