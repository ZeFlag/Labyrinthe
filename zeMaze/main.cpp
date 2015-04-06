#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fmod.hpp>
#include "sdlclg.h"
#include "Indiana.h"
#include "constante.h"
#include "Labyrinthe.h"
using namespace std;

vector<FMOD::Sound*> buildSound(FMOD::System* system)
{
	using namespace FMOD;
	Sound *sound1, *sound2, *sound3, *sound4, *sound5, *sound6;
	vector<Sound*> v = vector<Sound*>(6);
	v.push_back(sound1);
	v.push_back(sound2);
	v.push_back(sound3);
	v.push_back(sound4);
	v.push_back(sound5);
	v.push_back(sound6);

	system->init(32, FMOD_INIT_NORMAL, 0);

	system->createSound("../zeMaze/menu.mp3", FMOD_HARDWARE, 0, &v.at(0));
	system->createSound("../zeMaze/theme.mp3", FMOD_HARDWARE, 0, &v.at(1));
	system->createSound("../zeMaze/victoire.mp3", FMOD_HARDWARE, 0, &v.at(2));
	system->createSound("../zeMaze/perdu.mp3", FMOD_HARDWARE, 0, &v.at(3));
	system->createSound("../zeMaze/pickup.mp3", FMOD_HARDWARE, 0, &v.at(4));
	system->createSound("../zeMaze/start.wav", FMOD_HARDWARE, 0, &v.at(5));

	return v;
}

void playSound(FMOD::System* system,FMOD::Sound* sound)
{
	system->playSound(FMOD_CHANNEL_FREE, sound, false, 0);
}

void releaseSound(FMOD::System* system, vector<FMOD::Sound*> sounds){
	for (FMOD::Sound* sound : sounds)
		sound->release();
	system->close();
	system->release();
}

int main(int argc, char *argv[])
{
	int CompteurDeSou = 0;

	srand(static_cast<unsigned int>(time(0)));
	Evenement e; // ? a garder ?
	//Initialisation du labyrinthe
	Labyrinthe zeLab;
	//ouverture de la fenetre avec fond decran
	InitialiserAffichage("zeMaze", SIZE_WINDOW, SIZE_WINDOW);
	//initialisation de Indiana Jones
	Indiana indianaJones(zeLab);
	//Initialisation des sounds
	FMOD::System *system;
	System_Create(&system);
	vector<FMOD::Sound*> sounds = buildSound(system);
	playSound(system, sounds.at(0));
	//Menu
	zeLab.paintTitle();
	while (AttendreEvenement() != EVEspace);
	sounds.at(0)->release();
	playSound(system, sounds.at(5));
	sounds.at(5)->release();
	//affiche le decors
	zeLab.paint();
	SDL_EnableKeyRepeat(100, 100);
	playSound(system, sounds.at(1));
	do
	{
		zeLab.repaint();
		if (indianaJones.pickUpItem())
			playSound(system, sounds.at(4));
	} while (indianaJones.move(AttendreEvenement()) && CompteurDeSou != NB_TORCHS);
	//Désactivation de la répétition des touches (remise à 0)
	SDL_EnableKeyRepeat(0, 0);      
	sounds.at(1)->release();             

	return 0;
}