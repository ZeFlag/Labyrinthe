#include "AffichageFond.h"


void Afficher(Ligne Grille[], int fond, int mur, int porte, int torche, int biere, int mario, Position Personnage)
{
	AfficherImage(fond, 0, 0);
	AfficherObject(Grille, NbCases*NbCases, mur);
	AfficherObject(Grille, 1, porte);
	AfficherObject(Grille, NbTorches, torche);
	AfficherObject(Grille, NbBieres, biere);
	AfficherImage(mario, Personnage.x*NbPixelsParCase, Personnage.y*NbPixelsParCase);  //Affichage du personnage
	RafraichirFenetre();
}


void InitialiserGrille(Ligne Grille[])
{
	for (int i = 0; i < NbCases; i++)
	{                                                     //Initialise la grille de jeu à vide.
		for (int j = 0; j < NbCases; j++)
		{
			Grille[i].Colonne[j] = Vide;
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

void PlacerPorte(Ligne Grille[], int ImageId, Position Personnage)
{
	int i, j = -1;

	do 
	{
		i = rand() % NbCases;
		j = rand() % NbCases;

	} while ((Grille[i].Colonne[j] == Vide)); //TODO: Ajouter condition pour un écart minimum...

		
	Grille[i].Colonne[j] = ImageId;
}

void PlacerObject(Ligne Grille[], int NbObject, int ImageId)
{
	for (int Cpt = 0; Cpt < NbObject; Cpt++)
	{
		int i = rand() % NbCases;
		int j = rand() % NbCases;

		if (Grille[i].Colonne[j] == Vide)
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
	for (int i = 0; i < NbCases; i++)
	{
		for (int j = 0; j < NbCases; j++)
		{
			if (Grille[i].Colonne[j] == ImageId)
			{
				AfficherImage(ImageId, i*NbPixelsParCase, j*NbPixelsParCase);
			}
		}
	}
}
