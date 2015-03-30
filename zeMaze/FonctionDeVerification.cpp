#include "FonctionDeVerification.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Fonction de Vérification ////////////////////////////////////////////


Position InitialiserPositionPersonnage(Ligne Grille[], int Mur)
{
	Position Personnage;

	Personnage.x=rand()%18;
	Personnage.y=rand()%18;

	for(int i=0;i<NOMBRE_CASES;i++)
	{
		for(int j=0;j<NOMBRE_CASES;j++)
		{
			if(Grille[Personnage.x].Colonne[Personnage.y]==Mur)                    //Définition de la fonction VerifierSou
			{
				Personnage.x=rand()%18;
				Personnage.y=rand()%18;
			}
		}
	}
	return Personnage;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierSou(Ligne Grille[], int Sou, Position Mario, int& CompteurDeSou)
{
	for(int i=0;i<NOMBRE_CASES;i++)
	{
		for(int j=0;j<NOMBRE_CASES;j++)
		{
			if(Grille[Mario.x].Colonne[Mario.y]==Sou)                    //Définition de la fonction VerifierSou
			{
				Grille[Mario.x].Colonne[Mario.y]=CASE_VIDE;
				CompteurDeSou++;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierMur(Ligne Grille[], int Mur, Position Mario, string& ConditionHaut, string& ConditionBas, string& ConditionGauche, string& ConditionDroite)
{
	for(int i=0;i<NOMBRE_CASES;i++)
	{
		for(int j=0;j<NOMBRE_CASES;j++)
		{
			if(Grille[Mario.x+1].Colonne[Mario.y]==Mur)                    
			{
				ConditionDroite="DroiteImpossible";
			}

			if(Grille[Mario.x].Colonne[Mario.y-1]==Mur)                    
			{
				ConditionHaut="HautImpossible";
			}

			if(Grille[Mario.x-1].Colonne[Mario.y]==Mur)                    
			{
				ConditionGauche="GaucheImpossible";
			}

			if(Grille[Mario.x].Colonne[Mario.y+1]==Mur)                    
			{
				ConditionBas="BasImpossible";
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierLimiteJeu(Position Personnage, string& ConditionLimite)
{
	if(Personnage.x==17)                    
	{
		ConditionLimite="DroiteImpossible";
	}

	if(Personnage.y==0)                    
	{
		ConditionLimite="HautImpossible";
	}

	if(Personnage.x==0)                    
	{
		ConditionLimite="GaucheImpossible";
	}

	if(Personnage.y==17)                    
	{
		ConditionLimite="BasImpossible";
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void VerifierConditionMario(Position Mario, Position Koopa, Position Goomba, Position Bomb, string& ConditionMario)
{
	if(Mario.x == Koopa.x && Mario.y == Koopa.y)
	{
		ConditionMario="Mort";
	}

	if(Mario.x == Goomba.x && Mario.y == Goomba.y)
	{
		ConditionMario="Mort";
	}

	if(Mario.x == Bomb.x && Mario.y == Bomb.y)
	{
		ConditionMario="Mort";
	}
}