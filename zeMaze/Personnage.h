#pragma once

#include "sdlclg.h";
#include "constante.h";

struct Position
{ 
	int x; 
	int y; 
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
	bool verifieConditionDeplacement(Position p);
private:
	bool isInsideLimits(Position p);
};

