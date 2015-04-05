#pragma once

#include "sdlclg.h";
#include "constante.h"
#include "Labyrinthe.h"

enum Condition
{
	DROITE_IMPOSSIBLE, GAUCHE_IMPOSSIBLE, HAUT_IMPOSSIBLE, BAS_IMPOSSIBLE, SORTIE, AUCUN
};

class Personnage
{
protected:
	Labyrinthe zeLab;
	Position position;
	int visibilite;
public:
	Personnage(){}
	~Personnage(){}

	virtual bool move(Evenement e);

	Position getPosition(){ return position; }
	Position getStartPosition(ImageName imageName);

	void setLabyrinthe(Labyrinthe l);
	void setPosition(Position p){ position = p; }
protected:
	bool verifieConditionDeplacement(Position p);
	bool isInsideLimits(Position p);
};