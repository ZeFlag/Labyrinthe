#include <cstdlib>
#include <ctime>
#include "Indiana.h"

int main(int argc, char *argv[])
{
	const int KEY_REPEATER_MAX = 100;

	srand(static_cast<unsigned int>(time(0)));
	//Initialisation du labyrinthe
	Labyrinthe* zeLab = new Labyrinthe;
	//ouverture de la fenetre avec fond decran
	InitialiserAffichage("zeMaze", SIZE_WINDOW, SIZE_WINDOW);
	//initialisation de Indiana Jones
	Indiana indianaJones(*zeLab);
	//Initialisation des sounds
	FMOD::System *system;
	System_Create(&system);
	std::vector<FMOD::Sound*> sounds = loadSound(system);
	playSound(system, sounds.at(0));
	//Menu
	zeLab->paintTitle();
	while (AttendreEvenement() != EVEspace);
	sounds.at(0)->release();
	playSound(system, sounds.at(5));
	sounds.at(5)->release();
	SDL_EnableKeyRepeat(KEY_REPEATER_MAX, KEY_REPEATER_MAX);
	playSound(system, sounds.at(1));
	bool pickUp = false;
	do
	{
		indianaJones.showVision();
		if (pickUp)
			playSound(system, sounds.at(4));
	} while (!indianaJones.move(AttendreEvenement(), pickUp));
	SDL_EnableKeyRepeat(0, 0);      
	sounds.at(1)->release();    

	zeLab->showResult(system,sounds);
	releaseSound(system, sounds);

	return 0;
}