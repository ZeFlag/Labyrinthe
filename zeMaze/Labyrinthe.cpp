#include "Labyrinthe.h"

Labyrinthe::Labyrinthe()
{
	for (size_t i = 0; i < NB_CASES; i++)
	{
		Line line;
		for (size_t j = 0; j < NB_CASES; j++)
			line.column.push_back(EMPTY_CASE);
		grille.push_back(line);
	}
	loadImages();
	GenererMaze(images.at(WALL));
	InitObjects();
	InitDoor();
}


Labyrinthe::~Labyrinthe()
{
	QuitterAffichage();
}

void refresh() { RafraichirFenetre(); }

void Labyrinthe::paint() const
{
	AfficherImage(images.at(BACKGROUND), 0, 0);
	paintObjects();
	refresh();
}

void Labyrinthe::paintTitle() const
{
	AfficherImage(images.at(TITLE), 0, 0);
	refresh();
}

void Labyrinthe::repaint() const { paint(); }

void Labyrinthe::paintObjects() const
{
	auto i = 0, j = 0;
	for (Line line : grille){
		for (ImageId _case : line.column){
			if (_case != EMPTY_CASE)
				AfficherImage(_case, i*NB_PIXELS_CASE, j*NB_PIXELS_CASE);
			++j;
		}
		++i;
	}
}

void Labyrinthe::loadImages()
{
	images.insert(make_pair(BACKGROUND, ChargerImage("fond.bmp")));
	images.insert(make_pair(BEER, ChargerImage("beer.bmp")));
	images.insert(make_pair(DOOR, ChargerImage("door.bmp")));
	images.insert(make_pair(HERO, ChargerImage("indiana.bmp")));
	images.insert(make_pair(LOSS, ChargerImage("perdu.bmp")));
	images.insert(make_pair(TITLE, ChargerImage("Title.bmp")));
	images.insert(make_pair(TORCH, ChargerImage("torche.bmp")));
	images.insert(make_pair(WALL, ChargerImage("mur.bmp")));
	images.insert(make_pair(WIN, ChargerImage("gagne.bmp")));
}

void Labyrinthe::InitObjects()
{
	PutObject(NB_TORCHS, images.at(TORCH));
	PutObject(NB_BEERS,	 images.at(BEER));
}

void Labyrinthe::InitDoor()
{
	auto i = 0, j = 0;
	do
	{
		i = rand() % NB_CASES;
		j = rand() % NB_CASES;
	} while ((grille[i].column[j] == EMPTY_CASE)); //TODO: Ajouter condition pour un écart minimum...

	grille[i].column[j] = images.at(DOOR);
}

void Labyrinthe::PutObject(int nbObject, ImageId imageId)
{
	int cpt = 0;
	while (cpt < nbObject)
	{
		int i = rand() % NB_CASES;
		int j = rand() % NB_CASES;

		if (grille[i].column[j] == EMPTY_CASE){
			grille[i].column[j] = imageId;
			++cpt;
		}
	}
}

void Labyrinthe::InitCaracters()
{
	Position Personnage;
	do
	{
		Personnage.x = rand() % NB_CASES;
		Personnage.y = rand() % NB_CASES;
	} while (grille[Personnage.x].column[Personnage.y] != EMPTY_CASE);
	grille[Personnage.x].column[Personnage.y] = images.at(HERO);
}

void Labyrinthe::GenererMaze(ImageId imageId)
{
	srand(time(0));

	const int maze_size_x = 18;
	const int maze_size_y = 18;
	vector < vector < bool > > maze;
	list < pair < int, int> > drillers;

	maze.resize(maze_size_y);
	for (size_t y = 0; y < maze_size_y; y++)
		maze[y].resize(maze_size_x);

	for (size_t x = 0; x < maze_size_x; x++)
		for (size_t y = 0; y < maze_size_y; y++)
			maze[y][x] = false;

	drillers.push_back(make_pair(maze_size_x / 2, maze_size_y / 2));
	while (drillers.size()>0)
	{
		list < pair < int, int> >::iterator m, _m, temp;
		m = drillers.begin();
		_m = drillers.end();
		while (m != _m)
		{
			bool remove_driller = false;
			switch (rand() % 4)
			{
			case 0:
				(*m).second -= 2;
				if ((*m).second < 0 || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second + 1][(*m).first] = true;
				break;
			case 1:
				(*m).second += 2;
				if ((*m).second >= maze_size_y || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second - 1][(*m).first] = true;
				break;
			case 2:
				(*m).first -= 2;
				if ((*m).first < 0 || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second][(*m).first + 1] = true;
				break;
			case 3:
				(*m).first += 2;
				if ((*m).first >= maze_size_x || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second][(*m).first - 1] = true;
				break;
			}
			if (remove_driller)
				m = drillers.erase(m);
			else
			{
				drillers.push_back(make_pair((*m).first, (*m).second));
				// uncomment the line below to make the maze easier 
				//if (rand()%2) 
				drillers.push_back(make_pair((*m).first, (*m).second));

				maze[(*m).second][(*m).first] = true;
				++m;
			}
		}
	}

	// Done 
	for (size_t y = 0; y < maze_size_y; y++)
		for (size_t x = 0; x < maze_size_x; x++)
			if (maze[y][x] == false)
				grille[y].column[x] = imageId;
}

const Labyrinthe & Labyrinthe::operator=(Labyrinthe &newLab){
	if (this != &newLab){
		Copy(newLab);
	}
	return *this;
}

void Labyrinthe::Copy(Labyrinthe &newLab){
	images = newLab.images;
	for (size_t i = 0; i < NB_CASES; i++)
		for (size_t j = 0; j < NB_CASES; j++)
			grille[i].column[j] = newLab.getGrille()[i].column[j];
}