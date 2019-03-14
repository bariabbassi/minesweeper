/**
 * Fonctions pour construire un jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"
#include "mm15io.h"
#include "mm15build.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Construit un jeu en partant des mots utilisateur
 * @param        le jeu a modifier
 * @return       1 si success, 0 sinon
*/
int
mm15_build (game_ty * g)
{
	int i,j,swp,a,b,k,l,used=0;
	*g=game_undef;//On initialise *g
	int L = mm15_read_words(g->words, SZ_GRID);//Lire les mots a partir d'un fichier, on utilise file.txt pour tester
	int *sorted_index = malloc(L*sizeof(int));//Initialiser une liste de la taille L
	for(i=0;i<L;i++)//Remplisage avec les indexes des mots, donc de 0 a L-1
		sorted_index[i]=i;

	for (j=0;j<(L-1);j++)//On trie les indexes en fonction de la taille du mot correspondant
		for (i=0;i<(L-1);i++)//C'est un tri a bulles, du plus petit au plus grand
		{
			a=strlen(g->words[sorted_index[i+1]]);//taille d'un mot
			b=strlen(g->words[sorted_index[i]]);//taille du mot suivant
			if (a < b)//si le mot suivant est plus long, on echange les 2 mots
			{
				swp = sorted_index[i];
				sorted_index[i] = sorted_index[i + 1];
				sorted_index[i + 1] = swp;
			}
		}

	bool *used_index=malloc(L*sizeof(bool));//Intialiser une liste de taille L
	for(i=0;i<L;i++)//Remplissage avec des false
		used_index[i]=false;

	for(i=0;i<SZ_GRID;i++)//Pour chaque ligne de la grille
	{
		j=0;
		while(g->words[sorted_index[L-i-1]][j]!='\0' && j<SZ_GRID)
		{//Remplissage de la ligne i de la grille avec le plus long mot
			g->grid[i][j]=g->words[sorted_index[L-i-1]][j];
			j++;
		}
		used_index[sorted_index[L-i-1]]=true;//On declare que le mot a ete utilise
		used++;//Incrementer le nombre des mots mis dans la grille
		if(SZ_GRID-j>0)//Si le mot n'a pas remplis toute la ligne
		{
			for(k=0;k<L;k++)
			{//On parcours les mots a partir du mot le plus petit
				if(strlen(g->words[sorted_index[k]])<=SZ_GRID-j
				&& used_index[sorted_index[k]]==false)
				{//Si ce mot peut tenir de le reste de la ligne et il n'a pas encore ete utilise
					l=0;
					while(g->words[sorted_index[k]][l]!='\0')
					{//Remplissage du reste de la ligne
						g->grid[i][j]=g->words[sorted_index[k]][l];
						j++;
						l++;
					}
					used_index[sorted_index[k]]=true;//On declare que le mot a ete utilise
					used++;//Incrementer le nombre des mots mis dans la grille
				}
				if(k==L-1)//Si il reste encore de la place dans la ligne
					while(j<SZ_GRID)
					{//On remplit le reste de la ligne avec des lettres aleatoires
						g->grid[i][j]='A'+rand()%26;
						j++;
					}
			}
		}
	}
	return used;//On retourne le nombre des mots mis dans la grille
}
