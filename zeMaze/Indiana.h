#pragma once

#include "Personnage.h"

class Indiana :
	public Personnage
{
	int nb_move = 60;
public:
	Indiana(Labyrinthe& l);
	~Indiana();

	bool move(Evenement e, bool& pickUp);
	bool pickUpItem();
};

