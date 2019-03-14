/**
 * Fonctions pour chercher un mot dans le jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"
#include "mm15io.h"
#include "mm15search.h"

/**
 * Teste si le mot w peut commencer à la position ligne, colonnes dans la direction d
 * @param g	grille de lettres majuscules de taille sz x sz
 * @param sz 	taille de la grille
 * @param w     mot de lettres majuscules
 * @param lin   numero de la ligne pour la case testee
 * @param col   numero de la colonne pour la case testee
 * @param d     direction cherche
 * @return      true si le mot est trouve, false sinon
 */
bool
mm15_search_pos(grid_ty g, int sz, char w[], int lin, int col, dir_ty d)
{
	int wl,i,j,i_step,j_step;//i_step et j_step sont le pas d'avencement de i et j
	if(lin<0 || lin>=sz || col<0 || col>=sz)//Verifier si lin et col sont valides
		return false;
	switch(d)//Choisir le pas de i et j en fonction de la direction
	{
		case DIR_N:	{i_step=-1 ; j_step=0 ; break;}
		case DIR_NE:	{i_step=-1 ; j_step=1 ; break;}
		case DIR_E:	{i_step=0 ; j_step=1 ; break;}
		case DIR_SE:	{i_step=1 ; j_step=1 ; break;}
		case DIR_S:	{i_step=1 ; j_step=0 ; break;}
		case DIR_SW:	{i_step=1 ; j_step=-1 ; break;}
		case DIR_W:	{i_step=0 ; j_step=-1 ; break;}
		case DIR_NW:	{i_step=-1 ; j_step=-1; break;}
		default:break;
	}
	wl=0;//wl parcours w
	i=lin;
	j=col;
	while(w[wl]!='\0')
	{
		if(w[wl]>96 && w[wl]<123)//Si la lettre est une minuscule
			w[wl]=w[wl]-32;//On la convertie en majuscule
		if(g[i][j]!=w[wl])//Si la lettre n'a pas ete trouvee
			return false;
		wl++;
		i=i+i_step;//incrementation par le pas corespondant a la direction
		j=j+j_step;
	}
	return true;
}

/**
 * Cherche le mot w dans la grille g de taille sz x sz
 * @param g      grille de lettres majuscules de taille sz x sz
 * @param sz     taille de la grille
 * @param w      mot de lettres majuscules
 * @return       la position du mot (ligne et colonne) ainsi que la direction dir_ty
 *               ou undefini si pas de mot dans la grille
 */
pos_ty
mm15_search (grid_ty g, int sz, char w[])
{
	int i,j,dir;
	if(w[0]=='\0') return pos_undef;
	pos_ty res;//Structure a remplir avec les (lin,col,dir) si le mot est trouve
	for(i=0;i<sz;i++)//lignes
		for(j=0;j<sz;j++)//colonnes
			for(dir=0;dir<8;dir++)//Parcours les directions
			{
				if(mm15_search_pos(g, sz, w, i, j, dir) == true)//Si le mot est trouve
				{
					res.lin = i;//Remplissage de res avec (lin,col,dir) trouvees
					res.col = j;
					res.dir = dir;
					return res;
				}
			}
	return pos_undef;
}
