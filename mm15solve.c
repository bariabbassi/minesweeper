/**
 * Fonctions pour chercher tous les mots dans le jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"
#include "mm15io.h"
#include "mm15solve.h"
#include "mm15search.h"
#include <stdio.h>

/*
 * Remplir les indices des mots de wt dans la case correspondante alphabetiquement de la matrice c[26][26][2]
 * @param wt     lableau de mots de taille szt
 * @param szt    taille du tableau wt
 * @param c	une matrice de taille 26*26*2
*/
void
mm15_classify(words_ty wt, int szt, int c[26][26][2])
{
	int i,j;
	int a,b;
	for(i=0;i<26;i++)
		for(j=0;j<26;j++)
		{//Le remplissage avec -1 permetra d'identifier ensuite les couples de lettres qui n'existent pas, par exemple: il n'existe pas un mot qui commence par AA
			c[i][j][0]=-1;
			c[i][j][1]=-1;
		}
	i=0;
	while(i<szt)
	{
		a=wt[i][0];//La 1ere lettre du mot
		b=wt[i][1];//La 2eme lettre du mot
		c[a-65][b-65][0]=i+1;//L'indice du 1er mot commencant par les 2 lettres a et b, -65 permet la conversion de [A,Z] vers [0,25]
		while(i<szt && wt[i][0]==a && wt[i][1]==b)
			i++;//On parcours les mots qui commencent par les 2 lettrs a et b
		c[a-65][b-65][1]=i;//L'indice du dernier mot commencant par les 2 lettres a et b
	}
}

/**
 * Methode 2 : recherche par case
 * Cherche les mots du tableau wt de taille szt dans la grille g de taille sz x sz
 * @param g      grille de lettres majuscules de taille sz x sz
 * @param sz     taille de la grille
 * @param wt     lableau de mots de taille szt
 * @param szt    taille du tableau wt
 * @param sol    la position de chaque mot de wt ou undefini si pas dans la grille
 * @return       nombre de mots trouves
*/
int
mm15_solve2(grid_ty g, int sz, words_ty wt, int szt, sol_ty sol)
{
	int i,j,dir,i_step,j_step,a,b,k,nb_solves=0;
	for(i=0;i<SZ_WORDS;i++)//Le remplissage avec -1 permetra ensuite d'ilimener le cas ou un mot existe plusieurs fois dans la grille
		sol[i].lin=-1;//Si le meme a ete trouve plus d'une fois, on le compte qu'une seule fois
	int c[26][26][2];
	mm15_classify(wt, szt, c);//On remplie la matrice en fonction de wt
	for(i=0;i<sz;i++)
		for(j=0;j<sz;j++)
			for(dir=0;dir<8;dir++)
			{
				switch(dir)
				{//On incremante i et j avec -1, 0 ou 1 en fonction de la direction
					case DIR_N: {i_step=-1 ; j_step=0 ; break;}
					case DIR_NE:{i_step=-1 ; j_step=1 ; break;}
					case DIR_E: {i_step=0 ; j_step=1 ; break;}
					case DIR_SE:{i_step=1 ; j_step=1 ; break;}
					case DIR_S: {i_step=1 ; j_step=0 ; break;}
					case DIR_SW:{i_step=1 ; j_step=-1 ; break;}
					case DIR_W: {i_step=0 ; j_step=-1 ; break;}
					case DIR_NW:{i_step=-1 ; j_step=-1; break;}
					default:break;
				}
				a=g[i][j]-65;//La 1ere lettre du mot
				b=g[i+i_step][j+j_step]-65;//La 2eme lettre du mot
				if(c[a][b][0]>0 && a>=0 && a<26 && b>=0 && b<26)
				{//Si il existe des mots qui commence par les 2 lettres a et b dans wt
					for(k=c[a][b][0]-1;k<c[a][b][1];k++)
					{//On parcours tout les mots qui commencent par a et b
						if(mm15_search_pos(g, sz, wt[k], i, j, dir) && sol[k].lin<0)
						{//Si un de ces mots a ete trouve et si c'est la 1ere fois qu'on trouve ce mot dans la grille
							sol[k].lin=i;//Remplissage de sol
							sol[k].col=j;
							sol[k].dir=dir;
							nb_solves++;//Incrementer le nombre de solutions
						}
					}
				}
			}
	return nb_solves;
}


/**
 * Methode 1 : recherche par mot
 * Cherche les mots du tableau wt de taille szt dans la grille g de taille sz x sz
 * @param g      grille de lettres majuscules de taille sz x sz
 * @param sz     taille de la grille
 * @param wt     lableau de mots de taille szt
 * @param szt    taille du tableau wt
 * @param sol    la position de chaque mot de wt ou undefini si pas dans la grille
 * @return       nombre de mots trouves
*/
int
mm15_solve1(grid_ty g, int sz, words_ty wt, int szt, sol_ty sol)
{
	int i,nb_solves=0;
	pos_ty p;
	for(i=0;i<szt;i++)
	{//On parcours les mots
		p = mm15_search(g, sz, wt[i]);//On teste chaque mot
		//Pour grid1, on a compte le nombre de fois mm15_search_pos a ete appellee pour chaque mot
		//min = 4 fois (PARLEMENTAIRE: lin=0 , col=0 , dir=3)
		//max = 1799 fois (SCRUTIN: lin=14 , col=14 , dir=6)
		//moyenne = 872.7
		//En total, pour grid1, mm15_search_pos a ete appellee 35790 fois
		//Ce nombre une trop grand
		if(p.lin != -1)
		{//Si on trouve le mot dans la grille
			sol[i]=p;//Remplissage de sol
			nb_solves++;//Incrementer le nombre de solutions
		}
	}
	return nb_solves;
}

/**
 * Donner le choix a l'utilisateur entre 2 methodes de mm15_solve
 * 1 : recherche par mot, appelle mm15_solve1
 * 2 : recherche par case, appelle mm15_solve2
*/
int
mm15_solve(grid_ty g, int sz, words_ty wt, int szt, sol_ty sol)
{
	int nb_solves=0;
	char c;
	printf("Choisir la methode :\n");
	printf("\t1 : recherche par mot\n");
	printf("\t2 : recherche par grille\n");
	scanf(" %c",&c);
	switch(c)
	{
		case '1': {nb_solves=mm15_solve1(g, sz, wt, szt, sol);break;}
		case '2': {nb_solves=mm15_solve2(g, sz, wt, szt, sol);break;}
		default: break;
	}
	return nb_solves;
}
