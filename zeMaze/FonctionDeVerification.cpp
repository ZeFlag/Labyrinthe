#include "FonctionDeVerification.h"

////////////////////////////////////// Fonctions de Vérification ////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
Position InitialiserPositionPersonnage(Ligne Grille[], int imageMurId)
{
	Position Personnage;

	do
	{
		Personnage.x = rand() % NOMBRE_CASES;
		Personnage.y = rand() % NOMBRE_CASES;
	} while (Grille[Personnage.x].Colonne[Personnage.y] == imageMurId);

	return Personnage;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool VerifierObjetRamasser(Ligne Grille[], int imageId, Position Personnage)
{
	if (Grille[Personnage.x].Colonne[Personnage.y] == imageId)
	{
		Grille[Personnage.x].Colonne[Personnage.y] = CASE_VIDE;
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool VerifierSortie(Ligne Grille[], int imageId, Position Personnage)
{
	if (Grille[Personnage.x].Colonne[Personnage.y] == imageId)
		return true;
	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierMur(Ligne Grille[], int Mur, Position Mario, string& ConditionHaut, string& ConditionBas, string& ConditionGauche, string& ConditionDroite)
{
	if (Grille[Mario.x + 1].Colonne[Mario.y] == Mur)
	{
		ConditionDroite = "DroiteImpossible";
	}

	if (Grille[Mario.x].Colonne[Mario.y - 1] == Mur)
	{
		ConditionHaut = "HautImpossible";
	}

	if (Grille[Mario.x - 1].Colonne[Mario.y] == Mur)
	{
		ConditionGauche = "GaucheImpossible";
	}

	if (Grille[Mario.x].Colonne[Mario.y + 1] == Mur)
	{
		ConditionBas = "BasImpossible";
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierLimiteJeu(Position Personnage, string& ConditionLimite)
{
	if (Personnage.x == NOMBRE_CASES-1)
	{
		ConditionLimite = "DroiteImpossible";
	}

	if (Personnage.y == 0)
	{
		ConditionLimite = "HautImpossible";
	}

	if (Personnage.x == 0)
	{
		ConditionLimite = "GaucheImpossible";
	}

	if (Personnage.y == NOMBRE_CASES-1)
	{
		ConditionLimite = "BasImpossible";
	}
}