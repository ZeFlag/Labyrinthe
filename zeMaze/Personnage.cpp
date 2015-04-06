#include "Personnage.h"

bool Personnage::move(Evenement e) { return false; }

bool Personnage::verifieConditionDeplacement(const Position& p) const
{
	return zeLab->getGrille()[p.x].column[p.y] != zeLab->getImages().at(WALL) && isInsideLimits(p);
}

bool Personnage::isInsideLimits(const Position& p) const 
{
	return p.x < NB_CASES && p.x > 0 && p.y < NB_CASES && p.y > 0;
}

void Personnage::setLabyrinthe(Labyrinthe& l)
{
	zeLab = &l;
}

Position Personnage::getStartPosition(const ImageName& imageName) const
{
	Position p = { 0,0 };
	for (Line line : zeLab->getGrille()){
		for (ImageId imageId : line.column){
			if (imageId == zeLab->getImages().at(imageName))
				return p;
			++p.y;
		}
		++p.x;
	}
	return p;
}