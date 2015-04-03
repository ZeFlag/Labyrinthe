#include "Personnage.h"

void Personnage::move(Evenement e) { return; }

bool Personnage::verifieConditionDeplacement(Position p)
{
	return zeLab.getGrille()[p.x].column[p.y] != zeLab.getImages().at(WALL) && isInsideLimits(p);
}

bool Personnage::isInsideLimits(Position p)
{
	return p.x < NB_CASES && p.x > 0 && p.y < NB_CASES && p.y > 0;
}

void Personnage::setLabyrinthe(Labyrinthe l)
{
	zeLab = l;
}

Position Personnage::getStartPosition(ImageName imageName)
{
	Position p = { 0,0 };
	for (Line line : zeLab.getGrille()){
		for (ImageId imageId : line.column){
			if (imageId == zeLab.getImages().at(imageName))
				return p;
				++p.y;
		}
		++p.x;
	}
}