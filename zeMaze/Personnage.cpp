#include "Personnage.h"

bool Personnage::verifieConditionDeplacement(const Position& p) const
{
	return isInsideLimits(p) && zeLab->getGrille()[p.x].column[p.y] != zeLab->getImages().at(WALL);
}

bool Personnage::isInsideLimits(const Position& p) const 
{
	return p.x < NB_CASES && p.x >= 0 && p.y < NB_CASES && p.y >= 0;
}

void Personnage::setLabyrinthe(Labyrinthe& l)
{
	zeLab = &l;
}

Position Personnage::getStartPosition(const ImageName& imageName) const
{
	for (size_t x = 0; x < NB_CASES; x++)
	{
		for (size_t y = 0; y < NB_CASES; y++)
		{
			if (zeLab->getGrille()[x].column[y] == zeLab->getImages().at(imageName))
				return{ x, y };
		}
	}
	return { 17, 17 };
}