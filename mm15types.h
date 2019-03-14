/**
 * Types et constantes utilises pour le jeu
 * 'mots meles'
 *
 * Auteurs : Abd Bari ABBASSI
 */

#ifndef MM15TYPES_H
#define MM15TYPES_H

/**
 * Constantes
 */
#define SZ_GRID 	15
#define SZ_WORDS 	50

/**
 * Types
 */

/** Type pour la direction d'un mot
 *            DIR_N
 *   DIR_NW     ^    DIR_NE
 *          \   |   /
 *           +-----+
 *   DIR_W --| 'Z' |-- DIR_E
 *           +-----+
 *          /   |   \
 *   DIR_SW     v    DIR_SE
 *            DIR_S
 */
typedef enum dir_e
{
  DIR_N = 0, DIR_NE, DIR_E, DIR_SE, DIR_S, DIR_SW, DIR_W, DIR_NW
} dir_ty;

/** Type pour la position d'un mot */
typedef struct pos_st { int lin; int col; dir_ty dir; } pos_ty;

/** Valeur undefinie pour les positions */
extern pos_ty pos_undef;	/* A COMPLETER S2 */

/** Type pour une solution du jeu */
typedef pos_ty sol_ty[SZ_WORDS];/* A COMPLETER S3 */

/** Type pour une grille */
typedef char grid_ty[SZ_GRID][SZ_GRID];

/** Type pour une liste de mots */
typedef char words_ty[SZ_WORDS][SZ_GRID];

/** Type pour un jeu */
typedef struct game_st { grid_ty grid; words_ty words; } game_ty;

/** Valeur undefinie pour le jeu */
extern game_ty game_undef;	/* A COMPLETER S4 */

/**
 * Variables globales
 */

/** Grille et liste de mots du jeu courant, definie en mm15io.c */
extern grid_ty grid;
extern words_ty words;

#endif
