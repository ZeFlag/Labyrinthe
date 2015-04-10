#pragma once
#include "Personnage.h"

class Indiana :
	public Personnage
{
	int nb_move = 100;
	int vision = 3;
public:
	Indiana(Labyrinthe& l);
	~Indiana();

	bool move(Evenement e, bool& pickUp) override;
	void showVision();
	bool pickUpItem();
};

