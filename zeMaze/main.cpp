#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fmod.hpp>
#include "sdlclg.h"
#include "constante.h"
#include "AffichageFond.h"
#include "FonctionDeVerification.h"
#include "FonctionEnnemi.h"
using namespace std;


int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(0)));
	int CompteurDeSou = 0;
	Evenement e;

	Ligne Grille[NbCases];                                                     //Déclaration de la grille de jeu.
	InitialiserGrille(Grille);
	InitialiserAffichage("Jeux Mario", TailleImage, TailleImage);              //Initialisation de la fenêtre

	int title = ChargerImage("Title.bmp");
	int fond = ChargerImage("fond.bmp");
	int mario = ChargerImage("mario_bas.bmp");
	int mur = ChargerImage("mur.bmp");                                  //Chargement des images en mémoire
	int sou = ChargerImage("sou.bmp");
	int koopa = ChargerImage("koopa.bmp");
	int goomba = ChargerImage("champi.bmp");
	int bomb = ChargerImage("bomb.bmp");
	int gagne = ChargerImage("gagne.bmp");
	int perdu = ChargerImage("perdu.bmp");

	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3, *sound4, *sound5, *sound6;

	FMOD::System_Create(&system);
	system->init(32, FMOD_INIT_NORMAL, 0);                                                 //initialiser FMOD

	system->createSound("../TP Synthèse/titre.mp3", FMOD_HARDWARE, 0, &sound1);
	system->createSound("../TP Synthèse/theme2.mp3", FMOD_HARDWARE, 0, &sound2);
	system->createSound("../TP Synthèse/victoire.mp3", FMOD_HARDWARE, 0, &sound3);        //Charger les sons
	system->createSound("../TP Synthèse/over.mp3", FMOD_HARDWARE, 0, &sound4);
	system->createSound("../TP Synthèse/coin.wav", FMOD_HARDWARE, 0, &sound5);
	system->createSound("../TP Synthèse/start.wav", FMOD_HARDWARE, 0, &sound6);

	system->playSound(FMOD_CHANNEL_FREE, sound1, false, 0);

	do
	{
		AfficherImage(title, 0, 0);
		RafraichirFenetre();                                      //Boucle de l'écran titre

		e = AttendreEvenement();
	} while (e != EVEspace);

	sound1->release();
	system->playSound(FMOD_CHANNEL_FREE, sound6, false, 0);

	PlacerObject(Grille, NbMur, mur);
	PlacerObject(Grille, NbSou, sou);                               //Appel a la fonction pour placer les murs et les sous

	Position Mario;
	Mario = InitialiserPositionPersonnage(Grille, mur);
	string ConditionMario = "Vivant";                                  //Déclaration et initialisation de la position des personnages

	Position Koopa;
	Koopa = InitialiserPositionPersonnage(Grille, mur);
	string DirectionKoopa = "Droite";

	Position Goomba;
	Goomba = InitialiserPositionPersonnage(Grille, mur);
	string DirectionGoomba = "Droite";

	Position Bomb;
	Bomb = InitialiserPositionPersonnage(Grille, mur);

	SDL_EnableKeyRepeat(100, 100);                     //Lorsqu'on appuie sur une touche pendant un certain delai, l'action se répete plusieur fois

	system->playSound(FMOD_CHANNEL_FREE, sound2, false, 0);

	do
	{

		Afficher(Grille, fond, mur, sou, mario, koopa, goomba, bomb, Mario, Koopa, Goomba, Bomb);

		string ConditionHaut = "Aucune";
		string ConditionBas = "Aucune";
		string ConditionGauche = "Aucune";                        //Déclaration des conditions
		string ConditionDroite = "Aucune";
		string ConditionLimite = "Aucune";

		int Temp = CompteurDeSou;
		VerifierSou(Grille, sou, Mario, CompteurDeSou);

		if (Temp != CompteurDeSou)
		{
			system->playSound(FMOD_CHANNEL_FREE, sound5, false, 0);    //Jouer un son lorsque Mario ramasse un sou
		}


		AnimationKoopa(Grille, mur, Koopa, DirectionKoopa);             //Appel des fonctions d'Animation des ennemis
		AnimationGoomba(Grille, mur, Goomba, DirectionGoomba);
		AnimationBomb(Grille, mur, Mario, Bomb);


		e = AttendreEvenement();                                        //Attendre que l'usager appuie sur une touche.

		VerifierMur(Grille, mur, Mario, ConditionHaut, ConditionBas, ConditionGauche, ConditionDroite);
		VerifierLimiteJeu(Mario, ConditionLimite);


		if (e == EVHaut && ConditionHaut != "HautImpossible" && ConditionLimite != "HautImpossible")
		{
			Mario.y -= 1;
		}

		if (e == EVBas && ConditionBas != "BasImpossible" && ConditionLimite != "BasImpossible")
		{
			Mario.y += 1;
		}

		if (e == EVDroite && ConditionDroite != "DroiteImpossible" && ConditionLimite != "DroiteImpossible")
		{
			Mario.x += 1;
		}

		if (e == EVGauche && ConditionGauche != "GaucheImpossible" && ConditionLimite != "GaucheImpossible")
		{
			Mario.x -= 1;
		}

		VerifierConditionMario(Mario, Koopa, Goomba, Bomb, ConditionMario);

	} while (e != EVQuitter && CompteurDeSou != NbSou && ConditionMario == "Vivant");            //Boucle d'animation

	SDL_EnableKeyRepeat(0, 0);                  //Désactivation de la répétition des touches (remise à 0)
	sound2->release();

	Afficher(Grille, fond, mur, sou, mario, koopa, goomba, bomb, Mario, Koopa, Goomba, Bomb);

	if (ConditionMario != "Vivant")
	{
		system->playSound(FMOD_CHANNEL_FREE, sound4, false, 0);
		AfficherImage(perdu, 120, 190);           //Si la condition de Mario n'est pas vivant, afficher au joueur qu'il a perdu
		RafraichirFenetre();
		Attendre(2000);
	}

	if (CompteurDeSou == NbSou)
	{
		system->playSound(FMOD_CHANNEL_FREE, sound3, false, 0);
		AfficherImage(gagne, 120, 190);          //Si le compteur de sou égale au nombre sou tatal, afficher au joueur qu'il a gagné
		RafraichirFenetre();
		Attendre(4000);
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
