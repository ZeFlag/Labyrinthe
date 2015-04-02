#pragma once

#include "Personnage.h"

class Indiana :
	public Personnage
{
	int nombre_pas;
public:
	Indiana(Labyrinthe l);
	~Indiana();

	void move(Evenement e);
	void pickUpItem();
};

