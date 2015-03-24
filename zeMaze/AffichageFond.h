#ifndef _AffichageFond_h
#define _AffichageFond_h

#include <time.h>
#include <vector>
#include <list>
#include "Constante.h"
#include "sdlclg.h"

//Déclaration des structures
struct Position
{
	int x;
	int y;
};

struct Ligne
{
	ImageId Colonne[NOMBRE_CASES];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: Afficher
//But: Affichage du fond, des murs, des sous, des ennemis et de Mario.
//Intrants: La grille de jeu, l'ImageId du fond, des murs, des sous, des ennemis et de Mario, ainsi que leur position.
//Extrants: Aucun
void Afficher(Ligne Grille[], int fond, int mur, int sou, int mario, Position Mario);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: InitialiserGrille
//But: Initialise la grille de jeu en mettant les cases à vide.
//Intrants: La grille de jeu
//Extrants: Aucun
void InitialiserGrille(Ligne Grille[]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: GenererMaze
//But: Génère un labyrinthe aléatoire
//Intrants: La grille de jeu, et l'imageId de l'image
//Extrants: Aucun
void GenererMaze(Ligne Grille[], int ImageId);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Nom: PlacerObject
//But: Placer les objects (comme les murs et les sous)
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