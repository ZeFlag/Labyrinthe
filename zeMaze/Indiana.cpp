#include "Indiana.h"

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
		if (verifieConditionDeplacement({ position.x, position.y - 1 }))
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
	if (position != oldPosition){
		--nb_move;
		pickUp = pickUpItem();
		std::cout << "Pas restant: " << nb_move << endl;
		zeLab->moveCaracter(HERO, position, oldPosition);
	}
	return zeLab->isVictory() || leave || nb_move <= 0;
}

bool Indiana::pickUpItem()
{ 
	ImageId image = zeLab->getGrille()[position.x].column[position.y];
	if (image == zeLab->getImages().at(TORCH))
	{
		++vision;
		std::cout << "Champ de vison augmente!" << endl;
		return true;
	}
	else if (image == zeLab->getImages().at(BEER))
	{
		int add = rand() % (NB_CASES - MIN_MOVE_ADD) + MIN_MOVE_ADD;
		std::cout << "Nombre de pas augmente de " << add << "!" << endl;
		nb_move += add;
		return true;
	}
	zeLab->setVictory(image == zeLab->getImages().at(DOOR));
	return false; 
}

void Indiana::showVision()
{
	AfficherImage(zeLab->getImages().at(BACKGROUND),0,0);
	for (int x = 0; x < NB_CASES; ++x)
	{
		for (int y = 0; y < NB_CASES; ++y)
		{
			if (x < position.x + vision && x > position.x - vision &&
				y < position.y + vision && y > position.y - vision)
			{
				if (zeLab->getGrille()[x].column[y] != -1)
					AfficherImage(zeLab->getGrille()[x].column[y], x*NB_PIXELS_CASE, y*NB_PIXELS_CASE);
			}
			else
			{
				AfficherImage(zeLab->getImages().at(BLACK), x*NB_PIXELS_CASE, y*NB_PIXELS_CASE);
			}
		}
	}
	RafraichirFenetre();
}