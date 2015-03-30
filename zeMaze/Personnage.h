#pragma once

#include "sdlclg.h";

struct Position
{ 
	int x; 
	int y; 
};

enum Condition
{
	DROITE_IMPOSSIBLE, GAUCHE_IMPOSSIBLE, HAUT_IMPOSSIBLE, BAS_IMPOSSIBLE, SORTIE, AUCUN
};

class Personnage
{
protected: 
	Position position;
	int visibilite;
public:
	Personnage();
	~Personnage();

	virtual void move(Evenement e);
	virtual void paint(int image);
	virtual void loadImage(string image);
protected:
	Condition verifieConditionDeplacement(Position p);
	bool isInsideLimits(Po)
};

