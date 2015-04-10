#pragma once

#include "Labyrinthe.h"

class  Personnage
{
protected:
	Labyrinthe* zeLab;
	Position position;
public:
	Personnage(){}
	virtual ~Personnage() = 0;

	virtual bool move(Evenement e) = 0;

	Position getPosition() const { return position; }
	Position getStartPosition(const ImageName& imageName) const;

	void setLabyrinthe(Labyrinthe& l);
	void setPosition(const Position& p){ position = p; }
protected:
	bool verifieConditionDeplacement(const Position& p) const;
	bool isInsideLimits(const Position& p) const;
};