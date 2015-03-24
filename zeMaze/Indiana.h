#pragma once
#include "Personnage.h"
class Indiana :
	public Personnage
{
	int nombre_pas;
public:
	Indiana();
	~Indiana();

	void loadImage(string s);
	void move(Evenement e);
	void paint(int image);
	void pickUpItem();
};

