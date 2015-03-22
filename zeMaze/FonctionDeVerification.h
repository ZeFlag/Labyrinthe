#ifndef _FonctionDeVerification_h
#define _FonctionDeverification_h
#include "AffichageFond.h"
#include "Constante.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: InitialiserPositionPersonnage.
//But: Sert a initialiser la postion des personnages (ennemis+Mario) au hasard en vérifiant qu'il n'y ait pas de mur.
//Intrants: la grille de jeu, l'imageId des murs.
//Extrants: la position du personnage concerné.
Position InitialiserPositionPersonnage(Ligne Grille[], int Mur);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierSou.
//But: Verifier s'il y a un sou en dessus de Mario. Si oui, le faire disparaitre et ajouter 1 sou au compteur.
//Intrants: la grille de jeu, l'imageId des sous, la position de Mario, le compteur de sou.
//Extrants: Aucun.
void VerifierSou(Ligne Grille[], int Sou, Position Mario, int& CompteurDeSou);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierMur.
//But: Verifier s'il y a un mur autour de Mario. Si oui, contraindre son déplacement.
//Intrants: La grille de jeu, l'imageId des murs, la position de Mario et les conditions de déplacements de Mario.
//Extrants: Aucun
void VerifierMur(Ligne Grille[], int Mur, Position Mario, string& ConditionHaut, string& ConditionBas, string& ConditionGauche, string& ConditionDroite);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierLimiteJeu
//But: Verifier si Mario est proche des limites de la grille de jeu. Si oui, contraindre ses mouvements.
//Intrants: Position Personnage, la condition des limites de Mario.
//Extrants: Aucun
void VerifierLimiteJeu(Position Personnage, string& ConditionLimite);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierConditionMario
//But: Verifier si mario touche a un ennemi. Si oui, il change sa condition a "Mort".
//Intrants: la position de Mario, la position des ennemis et la condition de Mario
//Extrants: Aucun
void VerifierConditionMario(Position Mario, Position Koopa, Position Goomba, Position Bomb, string& ConditionMario);

#endif _FonctionDeVerification_h