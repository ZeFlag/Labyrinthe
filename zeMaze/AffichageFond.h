#ifndef _AffichageFond_h
#define _AffichageFond_h

#include <time.h>
#include <vector>
#include <list>
#include "Constante.h"
#include "sdlclg.h"

//D�claration des structures
struct Position
{
	int x;
	int y;
};

struct Ligne
{
	ImageId Colonne[NbCases];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: Afficher
//But: Affichage du fond, des murs, des sous, des ennemis et de Mario.
//Intrants: La grille de jeu, l'ImageId du fond, des murs, de la porte, des objets, ainsi que leur position.
//Extrants: Aucun
void Afficher(Ligne Grille[], int fond, int mur, int porte, int torche, int biere, int mario, Position Personnage);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: InitialiserGrille
//But: Initialise la grille de jeu en mettant les cases � vide.
//Intrants: La grille de jeu
//Extrants: Aucun
void InitialiserGrille(Ligne Grille[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: GenererMaze
//But: G�n�re un labyrinthe al�atoire
//Intrants: La grille de jeu, et l'imageId de l'image
//Extrants: Aucun
void GenererMaze(Ligne Grille[], int ImageId);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: PlacerPorte
//But: Placer la porte
//Intrants: La grille de jeu et l'imageId de l'image
//Extrants: Aucun
void PlacerPorte(Ligne Grille[], int ImageId, Position Personnage);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: PlacerObject
//But: Placer les objects
//Intrants: La grille de jeu, le nombre d'objects a initialiser et l'imageId de l'image
//Extrants: Aucun
void PlacerObject(Ligne Grille[], int NbObject, int ImageId);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: AfficherObject
//But: Afficher les objects a leur position respective
//Intrants: La grille de jeu, le nombre d'objects a initialiser et l'imageId de l'image a afficher.
//Extrants: Aucun
void AfficherObject(Ligne Grille[], int NbObject, int ImageId);

#endif _AffichageFond_h