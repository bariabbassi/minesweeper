/**
 * Fonctions de lecture/ecriture pour le jeu
 * 'mots meles" avec grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"
#include <stdio.h>

/**
 * Jeux
 */

/** Jeu courant, non initialisé */
grid_ty grid;
words_ty words;

grid_ty grid1 = {
  {'P', 'C', 'D', 'T', 'A', 'D', 'I', 'D', 'N', 'A', 'C', 'X', 'I', 'O', 'V'},
  {'O', 'A', 'O', 'R', 'B', 'E', 'P', 'B', 'T', 'A', 'D', 'N', 'A', 'M', 'O'},
  {'P', 'M', 'R', 'U', 'S', 'F', 'M', 'M', 'U', 'A', 'E', 'R', 'U', 'B', 'T'},
  {'I', 'P', 'I', 'L', 'T', 'I', 'A', 'O', 'A', 'L', 'E', 'L', 'I', 'R', 'E'},
  {'N', 'A', 'O', 'H', 'E', 'M', 'I', 'C', 'Y', 'C', 'L', 'E', 'U', 'T', 'R'},
  {'I', 'G', 'L', 'I', 'N', 'M', 'R', 'P', 'R', 'O', 'M', 'E', 'S', 'S', 'E'},
  {'O', 'N', 'O', 'I', 'T', 'C', 'E', 'L', 'E', 'T', 'T', 'I', 'T', 'S', 'C'},
  {'N', 'E', 'S', 'E', 'I', 'T', 'M', 'N', 'E', 'A', 'L', 'E', 'E', 'I', 'O'},
  {'E', 'R', 'I', 'D', 'O', 'G', 'M', 'G', 'T', 'S', 'G', 'N', 'L', 'E', 'N'},
  {'H', 'B', 'D', 'U', 'N', 'E', 'A', 'U', 'N', 'A', 'A', 'T', 'E', 'G', 'S'},
  {'P', 'M', 'R', 'A', 'V', 'R', 'R', 'A', 'D', 'T', 'I', 'T', 'C', 'E', 'E'},
  {'A', 'A', 'R', 'R', 'F', 'C', 'G', 'N', 'E', 'O', 'U', 'R', 'T', 'T', 'I'},
  {'R', 'H', 'R', 'F', 'S', 'O', 'O', 'U', 'R', 'P', 'E', 'S', 'E', 'R', 'L'},
  {'A', 'C', 'U', 'T', 'L', 'S', 'R', 'D', 'E', 'B', 'A', 'T', 'U', 'A', 'O'},
{'P', 'S', 'T', 'S', 'I', 'E', 'P', 'D', 'N', 'I', 'T', 'U', 'R', 'C', 'S'}};

words_ty words1 = {
  "ABSTENTION", "BULLETIN", "BUREAU", "CAMP", "CAMPAGNE",
  "CANDIDAT", "CARTE", "CHAMBRE", "CONSEIL", "COUT",
  "DEBAT", "DEFI", "DEPUTE", "DROIT", "ELECTEUR",
  "ELECTION", "ELIRE", "FRAUDE", "HEMICYCLE", "ISOLOIR",
  "LISTE", "MAIRE", "MANDAT", "OPINION", "PARAPHE",
  "PARLEMENTAIRE", "PARTI", "PESER", "PROGRAMME", "PROMESSE",
  "RANG", "SCRUTATEUR", "SCRUTIN", "SENATEUR", "SIEGE",
  "SLOGANS", "SONDAGE", "SUFFRAGE", "TOUR", "VOIX",
"VOTER"};

grid_ty grid2 = {
  {'L', 'M', 'K', 'E', 'T', 'A', 'N', 'G', 'P', 'R', 'E', 'S', 'L', 'A', 'V'},
  {'N', 'O', 'G', 'A', 'L', 'E', 'S', 'E', 'R', 'U', 'V', 'N', 'A', 'E', 'A'},
  {'E', 'U', 'N', 'U', 'Y', 'L', 'D', 'E', 'R', 'O', 'A', 'I', 'G', 'U', 'M'},
  {'E', 'L', 'I', 'O', 'V', 'A', 'O', 'E', 'M', 'Y', 'G', 'A', 'U', 'Q', 'A'},
  {'G', 'E', 'T', 'N', 'L', 'J', 'K', 'T', 'A', 'R', 'U', 'B', 'N', 'R', 'M'},
  {'N', 'C', 'F', 'O', 'C', 'A', 'S', 'C', 'A', 'D', 'E', 'E', 'E', 'A', 'M'},
  {'O', 'A', 'A', 'I', 'S', 'C', 'C', 'O', 'R', 'N', 'E', 'H', 'N', 'B', 'A'},
  {'L', 'L', 'R', 'T', 'T', 'U', 'B', 'O', 'I', 'R', 'E', 'U', 'T', 'S', 'H'},
  {'P', 'A', 'S', 'A', 'Y', 'Z', 'B', 'C', 'V', 'K', 'A', 'M', 'P', 'L', 'E'},
  {'Y', 'N', 'O', 'T', 'M', 'Z', 'S', 'N', 'I', 'S', 'S', 'A', 'B', 'H', 'S'},
  {'A', 'Q', 'U', 'A', 'T', 'I', 'Q', 'U', 'E', 'L', 'B', 'T', 'C', 'P', 'S'},
  {'C', 'U', 'R', 'N', 'P', 'I', 'R', 'C', 'R', 'I', 'Q', 'U', 'E', 'B', 'A'},
  {'H', 'E', 'C', 'F', 'L', 'O', 'T', 'T', 'E', 'R', 'O', 'C', 'L', 'J', 'R'},
  {'T', 'O', 'E', 'N', 'L', 'W', 'A', 'R', 'C', 'D', 'H', 'N', 'E', 'L', 'B'},
  {'N', 'A', 'E', 'C', 'O', 'R', 'A', 'G', 'E', 'E', 'U', 'G', 'I', 'D', 'E'}
};

words_ty words2 = {
  "AMPLE", "AQUAGYM", "AQUATIQUE", "ATOLL",
  "BAINS", "BARQUE", "BASSIN", "BLEU", "BOIRE",
  "BORD", "BRASSE", "BULLE", "CALANQUE", "CASCADE",
  "CORNE", "CRAWL", "CRIQUE", "DIGUE", "DOUCHE",
  "ETANG", "EUREKA", "FLOTTER", "GROG", "HAMMAM",
  "JACUZZI", "JETSKI", "KAYAK", "LAGON", "LAGUNE",
  "MARE", "MOULE", "NATATION", "OCEAN", "ORAGE",
  "PECHE", "PEDALO", "PISCINE", "PLONGEE", "RAFTING",
  "RIVIERE", "SAUNA", "SOURCE", "SPA", "THERMES", "TITRE",
  "TRIMARAN", "VAGUE", "VALSER", "VOILE", "YACHT"
};

grid_ty grid3 = {
  {'A', 'B', 'D', 'O', 'M', 'E', 'N', 'M', 'O', 'E', 'X', 'P', 'I', 'B', 'I'},
  {'R', 'I', 'O', 'T', 'I', 'B', 'U', 'S', 'E', 'E', 'G', 'E', 'B', 'O', 'T'},
  {'S', 'U', 'N', 'I', 'M', 'R', 'E', 'T', 'D', 'R', 'R', 'P', 'I', 'N', 'E'},
  {'U', 'A', 'N', 'F', 'O', 'R', 'A', 'N', 'I', 'M', 'A', 'L', 'L', 'U', 'M'},
  {'B', 'M', 'I', 'F', 'A', 'P', 'I', 'N', 'V', 'C', 'T', 'U', 'A', 'S', 'C'},
  {'I', 'U', 'T', 'M', 'E', 'R', 'C', 'M', 'E', 'D', 'I', 'M', 'C', 'U', 'R'},
  {'N', 'T', 'A', 'U', 'H', 'O', 'C', 'U', 'O', 'C', 'S', 'F', 'R', 'M', 'U'},
  {'M', 'A', 'L', 'D', 'G', 'S', 'B', 'T', 'M', 'J', 'S', 'S', 'E', 'O', 'M'},
  {'O', 'M', 'L', 'N', 'N', 'P', 'N', 'A', 'U', 'A', 'U', 'D', 'D', 'D', 'E'},
  {'A', 'I', 'I', 'E', 'V', 'E', 'T', 'O', 'V', 'S', 'N', 'N', 'O', 'U', 'F'},
  {'N', 'T', 'V', 'R', 'M', 'C', 'G', 'I', 'P', 'A', 'E', 'N', 'I', 'L', 'A'},
  {'O', 'L', 'U', 'E', 'M', 'T', 'D', 'A', 'T', 'A', 'L', 'E', 'A', 'O', 'E'},
  {'S', 'U', 'M', 'F', 'S', 'U', 'L', 'A', 'M', 'S', 'A', 'I', 'L', 'A', 'R'},
  {'T', 'I', 'C', 'E', 'F', 'S', 'I', 'T', 'A', 'S', 'T', 'I', 'B', 'I', 'A'},
  {'T', 'M', 'I', 'R', 'E', 'T', 'N', 'I', 'M', 'U', 'M', 'I', 'X', 'A', 'M'}
};

words_ty words3 = {
  "ABDOMEN", "AGENDA", "ALEA", "ALIAS", "ALIBI",
  "ALINEA", "ANIMAL", "BONUS", "CREDO", "CURSUS",
  "DEFICIT", "DIVA", "FEMUR", "FORUM", "GRATIS",
  "IDEM", "INCOGNITO", "INDEX", "INFARCTUS", "INTERIM",
  "ITEM", "JUNIOR", "LAPSUS", "LATIN", "LAVABO", "MALUS",
  "MAXIMUM", "MEMENTO", "MODULO", "OMNIBUS", "PEPLUM",
  "PROSPECTUS", "REFERENDUM", "SATISFECIT", "SCENARIO", "SUBITO",
  "TANDEM", "TERMINUS", "TIBIA", "ULTIMATUM", "VETO",
  "VIDEO", "VILLA"
};

/**
 * Valeurs indefinies
 */
pos_ty pos_undef = {-1,-1,DIR_N};//Initialise la structure pos_undef
game_ty game_undef = {{}, {}};


/**
 * Controle du remplissage du jeu courant (grid,words)
 * Il faut que les lettres soient en majuscule
 * Il faut que la taille des mots ne depasse pas SZ_WORDS
*/
void
mm15_check()
{
	int i,j;
	for(i=0;i<SZ_GRID;i++)
		for(j=0;j<SZ_GRID;j++)
			if(grid[i][j]<65 || grid[i][j]>90)
				break;//On s'arrete si une case ne contient pas une majuscule
	if(i==SZ_GRID && j==SZ_GRID)//Si on arrive a la fin, elles sont toutes en majuscules
		printf("Les lettres de la grille sont conformes\n");
	else//Sinon, il y au moins une case qui ne contient pas de majuscule
		printf("Les lettres de la grille ne sont pas toutes des majuscules\n");
	for(i=0;i<SZ_WORDS;i++)
	{
		j=0;
		while(words[i][j]!='\0')
		{
			if(j>SZ_GRID)//Si le nombre de lettre du mot depasse SZ_GRID la boucle s'arrete
				break;
			j++;
		}
	}
	if(i==SZ_WORDS && j<=SZ_GRID)//Si on arrive a la fin, aucun mot ne depasse SZ_GRID
		printf("La liste des mots est conforme.\n");
	else//Sinon il existe au moins un mot de grande taille
		printf("Vous avez entre au moins un mot de grande taille.\n");
}

/**
 * Initialisation du jeu courant (grid,words) par l'ustilisateur au clavier
 * Chaque ligne de la grille (grid) est lue comme une chaine de caracteres (SZ_GRID lignes)
 * les mots de (words) sont lues un par un (SZ_WORDS mots)
 * Finalement, la fonction verifie la conformite de (grid,words) par mm15_check
 * @param chaines de caracteres a entrer au clavier
*/
void
mm15_read_keyboard()
{
	int i,j;
	char input[SZ_GRID+1];//la chaine de caracteres entree par scanf ne depasse pas SZ_GRID et +1 pour le '\0'
	printf("Entrez chaque ligne de la grille comme un seul mot.\n");
	for(i=0;i<SZ_GRID;i++)
	{
		printf("Entrez la ligne %d\n",i+1);//Affichage du nombre de la ligne commancant par 1 (et non par 0)
		scanf("%s",input);
		j=0;
		while(input[j]!='\0' && j<SZ_GRID)
			{
				if(input[j]>96 && input[j]<123)//Si une miniscule
					grid[i][j]=input[j]-32;//La met en majuscule
				else
					grid[i][j]=input[j];//Remplissage normal de grid
				j++;
			}
	}
	printf("Entrez la liste des mots un par un\n");
	for(i=0;i<SZ_WORDS;i++)
	{
		printf("Entrez le mot %d\n",i+1);//Affichage du nombre de mots
		scanf("%s",input);
		j=0;
		while(input[j]!='\0')//Ajoute input dans words
		{
			if(input[j]>96 && input[j]<123)//Conversion en majuscule
				words[i][j]=input[j]-32;
			else
				words[i][j]=input[j];
			j++;
		}
		words[i][j]='\0';
	}
	mm15_check();//Verifie la conformite, ne sert a rien de verifier les majuscules car on convertie toutes les minuscules
}

/**
 * Lire un fichier ligne par ligne et stocker les mots dans wt
*/
int
fread_words(FILE* f, char wt[][SZ_GRID], int sz)
{
	int nw = 0;
	int nmax = 0;

	if (f == NULL)
		return 0;

	fscanf (f, "%d", &nmax);//Lire la ligne

	for (nw = 0 ; nw < nmax && nw < sz; nw ++) {//parcourire chaque mot dans le fichier
		int nchar = fscanf (f, " %s", wt[nw]);//Lire chaque mot
		if (nchar == 0)
			break;
	}
	return nw;
}

/**
 * Remplir wt a partir d'un fichier dont le nom est donne par l'utilisateur
 *
*/
int
mm15_read_words(char wt[][SZ_GRID], int sz)
{
	FILE* f = NULL;
	char fname[100] = {};  /* Variable to store the file name */
	int nread=0; /* Variables to count */

	printf ("Quel est le fichier a lire: \n");
	scanf (" %s", fname); //L'utilisateur donne le nom du fichier

	f = fopen (fname, "r");//Ouvrir le fichier en lecture
	if (f == NULL)//Si le fichier est vide
	{
		printf ("Fichier illisible, fin.\n");
		return 0;
	}

	nread = fread_words(f, wt, 100);//Lire le fichier ligne par ligne et stocker les mots dans wt

	fclose (f);
	return nread;
}

/*
 * Copier le contenu de la grille dans un fichier
*/
void
mm15_write_grid(grid_ty g, int sz)
{
	int i,j;
	FILE* f = NULL;
	char fname[100] = {};  //variable to store the file name

	printf ("Quel est le fichier a modifier: \n");
	scanf (" %s", fname);
	f = fopen (fname, "a");//Ouvre le fichier en ecriture

	for(i=0;i<sz;i++)
	{//Parcours la grille
		for(j=0;j<sz;j++)
		{
			if(j!=sz-1)//Si on n'est pas a la fin de la ligne
				fprintf(f, "%c ", g[i][j]);//Ecrit la lettre dans le fichier
			else//A la fin de la ligne
				fprintf(f, "%c", g[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

/**
 * Donner le choix a l'utilisateur de choisir entre 2 lectures et enregistrement de la grille
 * f : lecture par un fichier
 * c : lecture par clavier
 * e : enregistrer grid dans un fichier
 * @param choix  un entier entre f, c et e
 */
void
mm15_read()
{
	int a=0;
	a=a+1;//Set ligne permet d'enlever le message de warning, qui indique que a n'a pas ete utilise
	char c;
	printf("Choix possibles pour l :\n");
	printf("\tf : lecture par un fichier\n");
	printf("\tc : lecture par clavier\n");
	printf("\te : enregistrer grid dans un fichier\n");
	scanf(" %c",&c);//Lit l'option
	switch(c)
	{
		case 'f': {a=mm15_read_words(words,SZ_GRID);break;}
		case 'c': {mm15_read_keyboard();break;}
		case 'e': {mm15_write_grid(grid, SZ_GRID);break;}
		default: break;
	}
}

/**
 * Change le jeu courant (grid,words) avec le jeu
 * (grid1,words1) pour choix == 1, etc.
 * @param choix  un entier entre 1 et 3
 */
void
mm15_set_game (int choix)
{
	int i,j;	//2 compteurs i et j
	if(choix==1)	//Si le choix vaut 1
	{
		for(i=0;i<SZ_GRID;i++)//On parcours le tableau grid
			for(j=0;j<SZ_GRID;j++)
				grid[i][j]=grid1[i][j];	//Remplir le tableau
		for(i=0;i<SZ_WORDS;i++)//Ces 10 lignes peuvent etre remplassees par strcpy() de <string.h> mais cela n'est pas autorise dans la question
		{
			j=0;
			while(words1[i][j]!='\0')//Tant que le mot du tableau words1 a la ligne i et colonne j est different de '\0'
			{
				words[i][j]=words1[i][j];//Alors le mot du tableau words1 a la ligne i et colonne j prend la valeur du mot du tableau words a la meme position
				j++;
			}
			words[i][j]='\0';//On termine la chaine de caracteres par '\0'
		}
	}
	if(choix==2)//De meme, en remplacant grid1 par grid2 et words1 par words2
	{
		for(i=0;i<SZ_GRID;i++)
			for(j=0;j<SZ_GRID;j++)
				grid[i][j]=grid2[i][j];
		for(i=0;i<SZ_WORDS;i++)
		{
			j=0;
			while(words2[i][j]!='\0')
			{
				words[i][j]=words2[i][j];
				j++;
			}
			words[i][j]='\0';
		}
	}
	if(choix==3)//De meme
	{
		for(i=0;i<SZ_GRID;i++)
			for(j=0;j<SZ_GRID;j++)
				grid[i][j]=grid3[i][j];
		for(i=0;i<SZ_WORDS;i++)
		{
			j=0;
			while(words3[i][j]!='\0')
			{
				words[i][j]=words3[i][j];
				j++;
			}
			words[i][j]='\0';
		}
	}

}

/**
 * Initialisation d'une grille vide avec des espaces ' '
*/
void
mm15_init_default()
{
	int i,j;
	for(i=0;i<SZ_GRID;i++)//On parcours le tableau grid
		for(j=0;j<SZ_GRID;j++)
			grid[i][j]=' ';//Les variables du tableau grid prennent la valeur ' '
}

/**
 * Affiche le jeu courant (grid,words) sous un format agreable
 * Par exemple:
 * +---+---+---+
 * | A | I | E |
 * +---+---+---+
 * | S | C | T |
 * +---+---+---+
 * | I | I | E |
 * +---+---+---+
 */
void
mm15_dump_default ()
{
	int i,j;
	printf("\nGrille :\n");
	if(grid[0][0]<65 || grid[0][0]>90)//Verifier si le caractere de la case est une majuscule
		mm15_init_default();
	for(i=0;i<SZ_GRID;i++)//Construction du tableau
	{
		for(j=0;j<SZ_GRID;j++)//la ligne de grille
			printf("+---");
		printf("+\n");
		for(j=0;j<SZ_GRID;j++)//la ligne du contenue
			printf("| %c ",grid[i][j]);
		printf("|\n");
	}
	for(j=0;j<SZ_GRID;j++)//Construction de la derniere ligne du la grille
		printf("+---");
	printf("+\n\nMots :");
	for(i=0;i<SZ_WORDS;i++)//Affichage des mots de words
	{
		if(i%9==0)//Apres 9 mots un retour a ligne pour que les mots ne soient pas tous dans une seule ligne
			printf("\n");
		printf("%s ",words[i]);
	}
	printf("\n\n");
}

/**
 * Affiche la position d'un mot dans la grile
 * @param p 	position a afficher
 */
void
mm15_dump_pos (pos_ty p)
{
	printf("Position du mot: (lin=%d ; col=%d ; dir=%d)\n", p.lin, p.col, p.dir);//Affichage lin,col,dir
}

/**
 * Affiche la solution d'un jeu sur nbm mots
 * @param s 	solution a afficher
 * @param nbm   le nombre de mots dans la solution
 */
void
mm15_dump_sol (sol_ty s, int nbm)
{
	int i;
	pos_ty s_line;
	printf("Nombre de solutions :%d\n",nbm);//Affiche le nombre de mots
	for(i=0;i<SZ_WORDS;i++)
	{
		s_line=s[i];
		//Affiche que les solutions et pas les cases vides vides de sol qui n'ont pas ete remplis par mm15_solve
		if(s_line.dir>0 && s_line.lin<SZ_GRID && s_line.col>0 && s_line.col<SZ_GRID)
		{
			printf("(lin=%d ; col=%d ; dir=%d)\n", s_line.lin, s_line.col, s_line.dir);
		}
	}
}

/**
 * Affiche le jeu donne en parametre
 * @param g 	jeu a afficher
 */
void
mm15_dump_game (game_ty g)
{
	int i,j;
	printf("\nGrid :\n");
	for(i=0;i<SZ_GRID;i++)//Construction du tableau
	{
		for(j=0;j<SZ_GRID;j++)//la ligne de grille
			printf("+---");
		printf("+\n");
		for(j=0;j<SZ_GRID;j++)//la ligne du contenu
			printf("| %c ",g.grid[i][j]);
		printf("|\n");
	}
	for(j=0;j<SZ_GRID;j++)//Construction de la derniere ligne du la grille
		printf("+---");
	printf("+\n\nMots :");
	for(i=0;i<SZ_WORDS;i++)//Affichage des mots de words
	{
		if(i%9==0)//Apres 9 mots, on met un retour a ligne pour que les mots ne soient pas tous sur une seule ligne
			printf("\n");
		printf("%s ",g.words[i]);
	}
	printf("\n\n");
}
