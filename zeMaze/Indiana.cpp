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

bool Indiana::move(Evenement e, bool& pickUp, bool& victory)
{
	Position oldPosition = position;
	bool leave = false;
	switch (e)
	{
	case EVHaut:
		if (verifieConditionDeplacement({ position.x, position.y - 1 }))
		{
			--position.y;
		}
		break;
	case EVBas:
		if (verifieConditionDeplacement({ position.x, position.y + 1 }))
		{
			++position.y;
		}
		break;
	case EVGauche:
		if (verifieConditionDeplacement({ position.x - 1, position.y }))
		{
			--position.x;
		}
		break;
	case EVDroite:
		if (verifieConditionDeplacement({ position.x + 1, position.y }))
		{
			++position.x;
		}
		break;
	case EVQuitter:
		leave = true;
		break;
	}
	if (position != oldPosition){
		--nb_move;
		pickUp = pickUpItem(victory);
		zeLab->moveCaracter(HERO, position, oldPosition);
	}
	return victory || leave || nb_move <= 0;
}

bool Indiana::pickUpItem(bool& victory)
{ 
	ImageId image = zeLab->getGrille()[position.x].column[position.y];
	if (image == zeLab->getImages().at(TORCH))
	{
		++vision;
		return true;
	}
	else if (image == zeLab->getImages().at(BEER))
	{
		nb_move += rand() % (NB_CASES - MIN_MOVE_ADD) + MIN_MOVE_ADD;
		return true;
	}
	else if (image == zeLab->getImages().at(DOOR))
		victory = true;
	return false; 
}

void Indiana::showVision()
{
	AfficherImage(zeLab->getImages().at(BACKGROUND),0,0);
	for (size_t x = 0; x < NB_CASES; ++x)
	{
		for (size_t y = 0; y < NB_CASES; ++y)
		{
			if (x >= position.x + vision || x <= position.x - vision && x >= 0 ||
				y >= position.y + vision || y <= position.y - vision && y >= 0)
			{
				AfficherImage(zeLab->getImages().at(BLACK), x*NB_PIXELS_CASE, y*NB_PIXELS_CASE);
			}
			else
			{
				if (zeLab->getGrille()[x].column[y] != -1)
				{
					AfficherImage(zeLab->getGrille()[x].column[y], x*NB_PIXELS_CASE, y*NB_PIXELS_CASE);
				}
			}
		}
	}
	RafraichirFenetre();
}