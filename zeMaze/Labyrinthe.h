#pragma once

#include <list>
#include <map>
#include <time.h>
#include <vector>

#include "constante.h"
#include "sdlclg.h"

struct Line
{
	vector<ImageId> column = vector<ImageId>(NB_CASES);
};

enum ImageName
{
	BACKGROUND,BEER,DOOR,HERO,LOSS,TITLE,TORCH,WALL,WIN
};

struct Position
{
	int x;
	int y;
};

typedef map<ImageName, ImageId> Map;

class Labyrinthe
{
private:
	Map images;
	vector<Line> grille = vector<Line>(NB_CASES);

	void GenererMaze(int imageId);
	void InitObjects();
	void InitCaracters();
	void InitDoor();
	void PutObject(int nbObject, int imageId);
	void loadImages();
	void paintObjects() const;
public:
	Labyrinthe();
	~Labyrinthe();

	void paint() const;
	void paintTitle() const;
	void repaint() const;

	Map getImages() const { return images; }
	vector<Line> getGrille() const { return grille; };
};