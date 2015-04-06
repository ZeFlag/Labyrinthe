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
	Labyrinthe* zeLab;
	Position position;
	int visibilite;
public:
	Personnage(){}
	~Personnage(){}

	virtual bool move(Evenement e);

	Position getPosition() const { return position; }
	Position getStartPosition(const ImageName& imageName) const;

	void setLabyrinthe(Labyrinthe& l);
	void setPosition(const Position& p){ position = p; }
protected:
	bool verifieConditionDeplacement(const Position& p) const;
	bool isInsideLimits(const Position& p) const;
};