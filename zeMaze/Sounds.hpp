#pragma once
#include <fmod.hpp>
#include <vector>

static std::vector<FMOD::Sound*> loadSound(FMOD::System* system)
{
	using namespace FMOD;
	Sound *sound1, *sound2, *sound3, *sound4, *sound5, *sound6;
	std::vector<Sound*> v = std::vector<Sound*>(6);
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

static void playSound(FMOD::System* system, FMOD::Sound* sound)
{
	system->playSound(FMOD_CHANNEL_FREE, sound, false, 0);
}

static void releaseSound(FMOD::System* system, std::vector<FMOD::Sound*> sounds)
{
	for (size_t i = 2; i < 4; i++)
		sounds.at(i)->release();
	system->close();
	system->release();
}