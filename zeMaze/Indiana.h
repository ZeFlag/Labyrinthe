#pragma once

#include "Personnage.h"

class Indiana :
	public Personnage
{
	int nombre_pas;
public:
	Indiana(Labyrinthe& l);
	~Indiana();

	bool move(Evenement e);
	bool pickUpItem();
};

