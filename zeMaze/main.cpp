#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fmod.hpp>
#include "sdlclg.h"
#include "constante.h"
#include "AffichageFond.h"
#include "FonctionDeVerification.h"
using namespace std;

int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(0)));
	int CompteurDeSou = 0;
	Evenement e;

	Ligne Grille[NbCases];                                                     //Déclaration de la grille de jeu.
	InitialiserGrille(Grille);
	InitialiserAffichage("zeMaze", TailleImage, TailleImage);              //Initialisation de la fenêtre

	int title = ChargerImage("Title.bmp");
	int fond = ChargerImage("fond.bmp");
	int personnage = ChargerImage("indiana.bmp");
	int mur = ChargerImage("mur.bmp");                                  //Chargement des images en mémoire
	int torche = ChargerImage("torche.bmp");
	int biere = ChargerImage("beer.bmp");
	int gagne = ChargerImage("gagne.bmp");
	int perdu = ChargerImage("perdu.bmp");
	int porte = ChargerImage("door.bmp");

	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3, *sound4, *sound5, *sound6;

	FMOD::System_Create(&system);
	system->init(32, FMOD_INIT_NORMAL, 0);                                                 //initialiser FMOD

	system->createSound("../zeMaze/menu.mp3", FMOD_HARDWARE, 0, &sound1);
	system->createSound("../zeMaze/theme.mp3", FMOD_HARDWARE, 0, &sound2);
	system->createSound("../zeMaze/victoire.mp3", FMOD_HARDWARE, 0, &sound3);        //Charger les sons
	system->createSound("../zeMaze/perdu.mp3", FMOD_HARDWARE, 0, &sound4);
	system->createSound("../zeMaze/pickup.mp3", FMOD_HARDWARE, 0, &sound5);
	system->createSound("../zeMaze/start.wav", FMOD_HARDWARE, 0, &sound6);

	system->playSound(FMOD_CHANNEL_FREE, sound1, false, 0);

	do
	{
		AfficherImage(title, 0, 0);
		RafraichirFenetre();                                      //Boucle de l'écran titre

		e = AttendreEvenement();
	} while (e != EVEspace);

	sound1->release();
	system->playSound(FMOD_CHANNEL_FREE, sound6, false, 0);

	GenererMaze(Grille, mur);
	
	PlacerObject(Grille, NbTorches, torche);                               //Appel a la fonction pour placer les items
	PlacerObject(Grille, NbBieres, biere);

	Position posPersonnage;
	posPersonnage = InitialiserPositionPersonnage(Grille, mur);
	string ConditionMario = "Vivant";                                  //Déclaration et initialisation de la position des personnages

	PlacerPorte(Grille, porte, posPersonnage);

	SDL_EnableKeyRepeat(100, 100);                     //Lorsqu'on appuie sur une touche pendant un certain delai, l'action se répete plusieur fois

	system->playSound(FMOD_CHANNEL_FREE, sound2, false, 0);

	do
	{

		Afficher(Grille, fond, mur, porte, torche, biere, personnage, posPersonnage);

		string ConditionHaut = "Aucune";
		string ConditionBas = "Aucune";
		string ConditionGauche = "Aucune";                        //Déclaration des conditions
		string ConditionDroite = "Aucune";
		string ConditionLimite = "Aucune";

		int Temp = CompteurDeSou;
		VerifierSou(Grille, torche, posPersonnage, CompteurDeSou);
		VerifierPorte(Grille, porte, posPersonnage);

		if (Temp != CompteurDeSou)
		{
			system->playSound(FMOD_CHANNEL_FREE, sound5, false, 0);    //Jouer un son lorsque Mario ramasse un sou
		}

		e = AttendreEvenement();                                        //Attendre que l'usager appuie sur une touche.

		VerifierMur(Grille, mur, posPersonnage, ConditionHaut, ConditionBas, ConditionGauche, ConditionDroite);
		VerifierLimiteJeu(posPersonnage, ConditionLimite);


		if (e == EVHaut && ConditionHaut != "HautImpossible" && ConditionLimite != "HautImpossible")
		{
			posPersonnage.y -= 1;
		}

		if (e == EVBas && ConditionBas != "BasImpossible" && ConditionLimite != "BasImpossible")
		{
			posPersonnage.y += 1;
		}

		if (e == EVDroite && ConditionDroite != "DroiteImpossible" && ConditionLimite != "DroiteImpossible")
		{
			posPersonnage.x += 1;
		}

		if (e == EVGauche && ConditionGauche != "GaucheImpossible" && ConditionLimite != "GaucheImpossible")
		{
			posPersonnage.x -= 1;
		}

	} while (e != EVQuitter && CompteurDeSou != NbTorches && ConditionMario == "Vivant");            //Boucle d'animation

	SDL_EnableKeyRepeat(0, 0);                  //Désactivation de la répétition des touches (remise à 0)
	sound2->release();

	Afficher(Grille, fond, mur, porte, torche, biere, personnage, posPersonnage);

	if (ConditionMario != "Vivant")
	{
		system->playSound(FMOD_CHANNEL_FREE, sound4, false, 0);
		AfficherImage(perdu, 120, 190);           //Si la condition de Mario n'est pas vivant, afficher au joueur qu'il a perdu
		RafraichirFenetre();
		Attendre(7000);
	}

	if (CompteurDeSou == NbTorches)
	{
		system->playSound(FMOD_CHANNEL_FREE, sound3, false, 0);
		AfficherImage(gagne, 120, 190);          //Si le compteur de sou égale au nombre sou tatal, afficher au joueur qu'il a gagné
		RafraichirFenetre();
		Attendre(7000);
	}

	sound3->release();
	sound4->release();
	sound5->release();                     //Relachement des sons
	sound6->release();
	system->close();
	system->release();

	QuitterAffichage();                   //Fermeture de la fenetre SDL

	return 0;
}
