#pragma once

#include <list>
#include <map>
#include <time.h>
#include <iostream>
#include <vector>

#include "constante.h"
#include "sdlclg.h"
#include "Sounds.hpp"

struct Line
{
	vector<ImageId> column;
};

enum ImageName
{
	BACKGROUND, BEER, BLACK, DOOR, HERO, LOSS, TITLE, TORCH, WALL, WIN
};

struct Position
{
	int x;
	int y;

	inline const Position & Position::operator = (const Position &newPosition){
		if (this != &newPosition){
			x = newPosition.x;
			y = newPosition.y;
		}
		return *this;
	}
	inline const bool Position::operator != (const Position &p){
		return x != p.x || y != p.y;
	}
};

typedef map<ImageName, ImageId> Map;

class Labyrinthe
{
	Map images;
	vector<Line> grille;
	bool victory = false;

	void GenererMaze(ImageId);
	void InitObjects();
	void InitCaracters();
	void InitDoor();
	void PutObject(int, ImageId);
	void loadImages();
	void paintObjects() const;
public:
	Labyrinthe();
	~Labyrinthe();

	void paint() const;
	void paintTitle() const;
	void repaint() const;
	void showResult(FMOD::System*, vector<FMOD::Sound*>) const;

	Map getImages() const { return images; }
	vector<Line> getGrille() { return grille; };
	bool isVictory() const { return victory; }

	void moveCaracter(const ImageName&, const Position&, const Position&);
	void setVictory(bool b) { victory = b; }

	const Labyrinthe & operator=(Labyrinthe&);
	void Copy(Labyrinthe&);

private:
	//Pour la verifiaction de la solvabilite du labiyrinthe
	Position startCase;
	bool wasHere[NB_CASES][NB_CASES];
	bool correctPath[NB_CASES][NB_CASES];

	bool checkSolve(Position);
};