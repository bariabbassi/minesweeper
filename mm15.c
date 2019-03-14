/**
 * Programme principal pour le fonctionalités du jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include <stdio.h>  	// pour interface utilisateur

#include "mm15types.h"  // pour les types definis
#include "mm15io.h"  	// pour lecture/ecriture grilles et mots
#include "mm15search.h" // pour recherche d'un mot
#include "mm15solve.h"  // pour resoudre le jeu
#include "mm15build.h"  // pour construire une jeu

/**
 * Fonction principale
 */
int
main ()
{
  char c = 'q';			/* lecture du choix de l 'utilisateur */

  /* boucle principale */
  do
  {
    /* Affiche message aux utilisateur */
    printf ("**** Mon jeu de mots meles **** \n");

    printf ("Jeu courant : \n");
    mm15_dump_default ();

    printf ("Choix possibles :\n");
    printf ("\t l : lire nouvelle grille 15x15\n");
    printf ("\t r : recherche un mot dans la grille courante\n");
    printf ("\t s : resoudre le jeu courant\n");
    printf ("\t b : creer une grille 15x15\n");
    printf ("\t x : choisir un jeu entre 1, 2 ou 3\n");
    printf ("\t q : terminer\n");

    /* Lecture du choix de l 'utilisateur */
    scanf (" %c", &c);
    switch (c)
    {
    case 'x':
      {
	int choix = 1;		/* lecture choix, par defaut 1 */
	printf ("\nDonnez votre choix : \n");
	scanf ("%d", &choix);
	mm15_set_game (choix);	/* dans le fichier mm15io.c */
	break;
      }
    case 'l':
      {
	/* lance dialogue avec utilisateur pour lire un jeu */
	mm15_read ();		/* dans le fichier mm15io.c */
	printf ("Jeu lu : \n");
	mm15_dump_default ();
	break;
      }
    case 'r':
      {
	/* lire un mot */
	char mot[16] = "";
	printf ("Donnez le mot à chercher : \n");
	scanf ("%s", mot);
	/* appel fonction de recherche dans mm15search.c */
	pos_ty p = mm15_search (grid, SZ_GRID, mot);
	/* afficher solution dans mm15io.c */
	mm15_dump_pos (p);
	break;
      }
    case 's':
      {
	/* appel fonction de resolution dans mm15solve.c */
	sol_ty s;
	int nbm = mm15_solve (grid, SZ_GRID, words, SZ_WORDS, s);
	/* affiche solution */
	mm15_dump_sol (s, nbm);
	break;
      }
    case 'b':
      {
	/* appel fonction de creation grille dans mm15build.c */
	game_ty g;
	int success = mm15_build (&g);
	if (success > 0)
	{
	  printf ("Nouveau jeu:\n");
	  /* affiche nouvel jeu */
	  mm15_dump_game (g);
	}
	else
	  printf ("Echec de la construction du jeu\n");
	break;
      }
    default:
      break;
    }

  } while (c != 'q');

  return 0;
}
