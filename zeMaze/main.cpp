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
	int CompteurPas = NOMBRE_PAS_MAX;
	bool victoire = false;
	Evenement e;

	Ligne Grille[NOMBRE_CASES];                                                     //Déclaration de la grille de jeu.
	InitialiserGrille(Grille);
	InitialiserAffichage("zeMaze", TAILLE_IMAGE, TAILLE_IMAGE);              //Initialisation de la fenêtre

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

	GenererMaze(Grille, mur);											//Génère le labyrinthe aléatoirement
	
	PlacerObject(Grille, NOMBRE_TORCHES, torche);                               //Appel a la fonction pour placer les items
	PlacerObject(Grille, NOMBRE_BIERES, biere);

	Position posPersonnage;
	posPersonnage = InitialiserPositionPersonnage(Grille, mur);
	string ConditionMario = "Vivant";                                  //Déclaration et initialisation de la position des personnages

	PlacerPorte(Grille, porte, posPersonnage);

	SDL_EnableKeyRepeat(100, 100);                     //Lorsqu'on appuie sur une touche pendant un certain delai, l'action se répete plusieur fois

	system->playSound(FMOD_CHANNEL_FREE, sound2, false, 0);

	while (e != EVQuitter && !victoire && CompteurPas != 0)            //Boucle d'animation
	{
		Afficher(Grille, fond, mur, porte, torche, biere, personnage, posPersonnage);

		string ConditionHaut = "Aucune";
		string ConditionBas = "Aucune";
		string ConditionGauche = "Aucune";                        //Déclaration des conditions
		string ConditionDroite = "Aucune";
		string ConditionLimite = "Aucune";

		e = AttendreEvenement();                                        //Attendre que l'usager appuie sur une touche.

		VerifierMur(Grille, mur, posPersonnage, ConditionHaut, ConditionBas, ConditionGauche, ConditionDroite);
		VerifierLimiteJeu(posPersonnage, ConditionLimite);

		if (e == EVHaut && ConditionHaut != "HautImpossible" && ConditionLimite != "HautImpossible")
		{
			posPersonnage.y -= 1;
			--CompteurPas;
		}

		if (e == EVBas && ConditionBas != "BasImpossible" && ConditionLimite != "BasImpossible")
		{
			posPersonnage.y += 1;
			--CompteurPas;
		}

		if (e == EVDroite && ConditionDroite != "DroiteImpossible" && ConditionLimite != "DroiteImpossible")
		{
			posPersonnage.x += 1;
			--CompteurPas;
		}

		if (e == EVGauche && ConditionGauche != "GaucheImpossible" && ConditionLimite != "GaucheImpossible")
		{
			posPersonnage.x -= 1;
			--CompteurPas;
		}


		if (VerifierObjetRamasser(Grille, torche, posPersonnage))  //Vérifie si une torche est a ramasser
		{
			system->playSound(FMOD_CHANNEL_FREE, sound5, false, 0);

			//TODO: Augmenter le champ de vision...
		}
			
		if (VerifierObjetRamasser(Grille, biere, posPersonnage)) //Vérifie si une bière est a ramasser
		{
			system->playSound(FMOD_CHANNEL_FREE, sound5, false, 0);    

			CompteurPas += 10;
		}
			
		victoire = VerifierSortie(Grille, porte, posPersonnage);		//Vérifie si le personnage a trouvé la sortie

	} 

	SDL_EnableKeyRepeat(0, 0);                  //Désactivation de la répétition des touches (remise à 0)
	sound2->release();

	Afficher(Grille, fond, mur, porte, torche, biere, personnage, posPersonnage);

	if (CompteurPas == 0)				//Si le joueur a perdu...
	{
		system->playSound(FMOD_CHANNEL_FREE, sound4, false, 0);
		AfficherImage(perdu, 120, 190);           
		RafraichirFenetre();
		Attendre(5000);
	}

	if (victoire)					  //Si le joueur a gagner...
	{
		system->playSound(FMOD_CHANNEL_FREE, sound3, false, 0);
		AfficherImage(gagne, 120, 190);          
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
