#pragma once
#include "Personnage.h"

class Indiana :
	public Personnage
{
	int nb_move = 100;
	int vision = 3;
public:
	Indiana(Labyrinthe&);
	~Indiana();

	bool move(Evenement, bool&) override;
	void showVision();
	bool pickUpItem();
};

