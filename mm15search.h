/**
 * Fonctions pour chercher un mot dans le jeu
 * 'mots mélés' pour des grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include "mm15types.h"

/** Teste si le mot w peut commencer à la position ligne, colonnes dans la direction d */
bool mm15_search_pos(grid_ty g, int sz, char w[], int lin, int col, dir_ty d);

/** Cherche le mot w dans la grille g de taille sz x sz */
pos_ty mm15_search (grid_ty g, int sz, char w[]);
