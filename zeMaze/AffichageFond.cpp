#include "AffichageFond.h"


void Afficher(Ligne Grille[], int fond, int mur, int sou, int mario, Position Mario)
{
	AfficherImage(fond, 0, 0);
	AfficherObject(Grille, NOMBRE_CASES*NOMBRE_CASES, mur);
	AfficherObject(Grille, NOMBRE_TORCHES, sou);
	AfficherImage(mario, Mario.x*NOMBRE_PIXELS_PAR_CASE, Mario.y*NOMBRE_PIXELS_PAR_CASE);  //Affichage de mario
	RafraichirFenetre();
}


void InitialiserGrille(Ligne Grille[])
{
	for (int i = 0; i < NOMBRE_CASES; i++)
	{                                                     //Initialise la grille de jeu à vide.
		for (int j = 0; j < NOMBRE_CASES; j++)
		{
			Grille[i].Colonne[j] = CASE_VIDE;
		}
	}
}

void GenererMaze(Ligne Grille[], int ImageId)
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
		{
		if (maze[y][x] == false)
			Grille[y].Colonne[x] = ImageId;
		}
}

void PlacerObject(Ligne Grille[], int NbObject, int ImageId)
{
	for (int Cpt = 0; Cpt < NbObject; Cpt++)
	{
		int i = rand() % NOMBRE_CASES;
		int j = rand() % NOMBRE_CASES;

		if (Grille[i].Colonne[j] == CASE_VIDE)
		{
			Grille[i].Colonne[j] = ImageId;
		}
		else
		{
			Cpt--;
		}
	}
}

void AfficherObject(Ligne Grille[], int NbObject, int ImageId)
{
	for (int i = 0; i < NOMBRE_CASES; i++)
	{
		for (int j = 0; j < NOMBRE_CASES; j++)
		{
			if (Grille[i].Colonne[j] == ImageId)
			{
				AfficherImage(ImageId, i*NOMBRE_PIXELS_PAR_CASE, j*NOMBRE_PIXELS_PAR_CASE);
			}
		}
	}
}
