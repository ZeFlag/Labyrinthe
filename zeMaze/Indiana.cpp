#include "Indiana.h"
#include "constante.h"


Indiana::Indiana(Labyrinthe& l)
{
	setLabyrinthe(l);
	setPosition(getStartPosition(HERO));
}

Indiana::~Indiana()
{
}

bool Indiana::move(Evenement e, bool& pickUp)
{
	Position oldPosition = position;
	bool leave = false;
	switch (e)
	{
	case EVHaut:
		if (verifieConditionDeplacement({ position.x, position.y - 1}))
			--position.y;
		break;
	case EVBas:
		if (verifieConditionDeplacement({ position.x, position.y + 1 }))
			++position.y;
		break;
	case EVGauche:
		if (verifieConditionDeplacement({ position.x - 1, position.y }))
			--position.x;
		break;
	case EVDroite:
		if (verifieConditionDeplacement({ position.x + 1, position.y }))
			++position.x;
		break;
	case EVQuitter:
		leave = true;
		break;
	}
	--nb_move;
	pickUp = pickUpItem();
	zeLab->moveCaracter(HERO, position, oldPosition);
	return leave;
}

bool Indiana::pickUpItem()
{ 
	if (zeLab->getGrille()[position.x].column[position.y] == zeLab->getImages().at(TORCH))
	//return true;
	//si cest une torch augmenter le champ de vision
	//return true;
	return false; 
}