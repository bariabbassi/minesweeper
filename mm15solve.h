/**
 * Fonctions pour chercher tous les mots dans le jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"

/** Cherche les mots du tableau wt de taille szt dans la grille g de taille sz x sz */
int mm15_solve (grid_ty g, int sz, words_ty wt, int szt, sol_ty sol);
