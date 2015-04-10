#pragma once

#include "Labyrinthe.h"

class  Personnage
{
protected:
	Labyrinthe* zeLab;
	Position position;
public:
	Personnage(){}
	~Personnage(){}

	virtual bool move(Evenement, bool&) = 0;

	Position getPosition() const { return position; }
	Position getStartPosition(const ImageName&) const;

	void setLabyrinthe(Labyrinthe&);
	void setPosition(const Position& p){ position = p; }
protected:
	bool verifieConditionDeplacement(const Position&) const;
	bool isInsideLimits(const Position&) const;
};