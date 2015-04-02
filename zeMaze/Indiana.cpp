#include "Indiana.h"
#include "constante.h"


Indiana::Indiana(Labyrinthe l)
{
	setLabyrinthe(l);
	setPosition(getStartPosition(HERO));
}

Indiana::~Indiana()
{
}

void Indiana::move(Evenement e)
{
	;
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
	}
}

void Indiana::pickUpItem(){}