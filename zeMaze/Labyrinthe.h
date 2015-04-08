#pragma once

#include <list>
#include <map>
#include <time.h>
#include <vector>

#include "constante.h"
#include "sdlclg.h"

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

	const Position & Position::operator = (const Position &newPosition){
		if (this != &newPosition){
			x = newPosition.x;
			y = newPosition.y;
		}
		return *this;
	}
	const bool Position::operator != (const Position &p){
		if (this != &p)
			return true;
		return x != p.x && y != p.y;
	}
};

typedef map<ImageName, ImageId> Map;

class Labyrinthe
{
private:
	Map images;
	vector<Line> grille;

	void GenererMaze(ImageId imageId);
	void InitObjects();
	void InitCaracters();
	void InitDoor();
	void PutObject(int nbObject, ImageId imageId);
	void loadImages();
	void paintObjects() const;
public:
	Labyrinthe();
	~Labyrinthe();

	void paint() const;
	void paintTitle() const;
	void repaint() const;

	Map getImages() const { return images; }
	vector<Line> getGrille() { return grille; };

	void moveCaracter(const ImageName& name, const Position& p, const Position& oldPos);

	const Labyrinthe & operator=(Labyrinthe &newLab);
	void Copy(Labyrinthe &newLab);
};