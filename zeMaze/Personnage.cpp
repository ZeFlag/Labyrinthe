#include "Personnage.h"


Personnage::Personnage()
{
}


Personnage::~Personnage()
{
}

void Personnage::move(Evenement e) { return; }
void Personnage::paint(int image){ return; }
void Personnage::loadImage(string image) { return; }
	
bool Personnage::verifieConditionDeplacement(Position p)
{
	//return Grille[p.x].Colonne[p.y] != MUR && isInsideLimits(p);
	return true; //TODO temp
}

bool Personnage::isInsideLimits(Position p)
{
	return p.x < NOMBRE_CASES && p.x > 0 && p.y < NOMBRE_CASES && p.y > 0;
}