/*
 * Fonctions de lecture/ecriture pour le jeu
 * 'mots mélés' avec grilles de 15x15.
 *
 * Auteurs : Abd Bari ABBASSI
 */

#include <stdbool.h>

/** Grille et liste de mots du jeu courant */
extern grid_ty grid;
extern words_ty words;

/** Change le jeu courant avec le choix */
void mm15_set_game (int choix);

/** Initialisation du jeu courant par l'utilisateur */
void mm15_read ();

/** Controle le jeu courant */
bool mm15_check ();

/** Affiche le jeu courant */
void mm15_dump_default ();

/** Affiche la position d'un mot dans la grile */
void mm15_dump_pos (pos_ty p);

/** Affiche la solution d'un jeu pour nb mots */
void mm15_dump_sol (sol_ty s, int nbm);

/** Affiche le jeu donne en parametre */
void mm15_dump_game (game_ty g);

/** Remplir wt a partir d'un fichier */
int mm15_read_words(char wt[][SZ_GRID], int sz);

/** Enregistrer grid dans un fichier */
void mm15_write_grid(grid_ty g, int sz);
