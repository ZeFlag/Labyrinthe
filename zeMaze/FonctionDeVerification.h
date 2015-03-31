#ifndef _FonctionDeVerification_h
#define _FonctionDeverification_h
#include "AffichageFond.h"
#include "Constante.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: InitialiserPositionPersonnage.
//But: Sert a initialiser la postion du personnage au hasard en vérifiant qu'il n'y ait pas de mur.
//Intrants: la grille de jeu, l'imageId des murs.
//Extrants: la position du personnage concerné.
Position InitialiserPositionPersonnage(Ligne Grille[], int imageMurId);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierObjetRamasser.
//But: Verifier s'il y a un objet en dessus du Personnage. Si oui, le faire ramasser.
//Intrants: la grille de jeu, l'imageId de l'objet, la position du personnage.
//Extrants: variable bool.
bool VerifierObjetRamasser(Ligne Grille[], int imageId, Position Personnage);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierSortie.
//But: Verifier si le personnage se trouve sur la sortie
//Intrants: la grille de jeu, l'imageId des l'image qui sert de sortie, la position du personnage
//Extrants: variable bool.
bool VerifierSortie(Ligne Grille[], int imageId, Position Personnage);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierMur.
//But: Verifier s'il y a un mur autour du Personnage. Si oui, contraindre son déplacement.
//Intrants: La grille de jeu, l'imageId des murs, la position du Personnage et les conditions de déplacements de ce Personnage.
//Extrants: Aucun
void VerifierMur(Ligne Grille[], int Mur, Position Mario, string& ConditionHaut, string& ConditionBas, string& ConditionGauche, string& ConditionDroite);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: VerifierLimiteJeu
//But: Verifier si le Personnage est proche des limites de la grille de jeu. Si oui, contraindre ses mouvements.
//Intrants: Position du Personnage, la condition des limites de Mario.
//Extrants: Aucun
void VerifierLimiteJeu(Position Personnage, string& ConditionLimite);

#endif _FonctionDeVerification_h