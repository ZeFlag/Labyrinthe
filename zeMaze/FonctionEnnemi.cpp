#include "FonctionEnnemi.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// Animation Ennemi ///////////////////////////////////////////////////////

void AnimationKoopa(Ligne Grille[], int Mur, Position& Koopa, string& DirectionKoopa)
{
	string ConditionLimiteJeu;
	VerifierLimiteJeu(Koopa, ConditionLimiteJeu); 

	if(Grille[Koopa.x+1].Colonne[Koopa.y]==Mur || ConditionLimiteJeu=="DroiteImpossible")                    
	{
		DirectionKoopa="Gauche";
	}

	if(Grille[Koopa.x-1].Colonne[Koopa.y]==Mur || ConditionLimiteJeu=="GaucheImpossible")                    
	{
		DirectionKoopa="Droite";
	}


	if(DirectionKoopa=="Droite")
	{
		Koopa.x+=1;
	}

	if(DirectionKoopa=="Gauche")
	{
		Koopa.x-=1;
	}

}

void AnimationGoomba(Ligne Grille[], int Mur, Position& Goomba, string& DirectionGoomba)
{
	string ConditionLimiteJeu;
	VerifierLimiteJeu(Goomba, ConditionLimiteJeu); 
   int Possibilite=1;

   if(Possibilite==1)
   {
	   if((Grille[Goomba.x+1].Colonne[Goomba.y]==Mur || ConditionLimiteJeu=="DroiteImpossible") && DirectionGoomba=="Droite")                    
	   {
		   DirectionGoomba="Haut";
	   }
      else
      {
         Possibilite=2;
      }
   }


   if(Possibilite==2)
   {
	   if((Grille[Goomba.x].Colonne[Goomba.y-1]==Mur || ConditionLimiteJeu=="HautImpossible") && DirectionGoomba=="Haut")                    
	   {
		   DirectionGoomba="Gauche";
	   }
      else
      {
         Possibilite=3;
      }
   }

   if(Possibilite==3)
   {
	   if((Grille[Goomba.x-1].Colonne[Goomba.y]==Mur || ConditionLimiteJeu=="GaucheImpossible") && DirectionGoomba=="Gauche")                    
	   {
		   DirectionGoomba="Bas";
	   }
      else
      {
         Possibilite=4;
      }
   }

   if(Possibilite==4)
   {
	   if((Grille[Goomba.x].Colonne[Goomba.y+1]==Mur || ConditionLimiteJeu=="BasImpossible") && DirectionGoomba=="Bas")                    
	   {
		   DirectionGoomba="Droite";
	   }
      else
      {
         Possibilite=1;
      }
   }


	if(DirectionGoomba=="Droite")
	{
		Goomba.x+=1;
	}

	if(DirectionGoomba=="Gauche")
	{
		Goomba.x-=1;
	}

	if(DirectionGoomba=="Haut")
	{
		Goomba.y-=1;
	}

	if(DirectionGoomba=="Bas")
	{
		Goomba.y+=1;
	}
}


void AnimationBomb(Ligne Grille[], int Mur, Position Mario, Position& Bomb)
{
	string DirectionYBomb;
	string DirectionXBomb;
	string ConditionLimiteJeu;
	VerifierLimiteJeu(Bomb, ConditionLimiteJeu);

   while(true)
   {
      if(Bomb.y > Mario.y)                    
      {
         DirectionYBomb="Haut";
         break;
      }

      if(Bomb.y < Mario.y)                    
      {   
         DirectionYBomb="Bas";
         break;
      }

      if(Bomb.x > Mario.x)                    
      {
         DirectionXBomb="Gauche";
         break;
      }

      if(Bomb.x < Mario.x)                    
      {
         DirectionXBomb="Droite";
         break;
      }
   }

	if(DirectionYBomb=="Haut" && Grille[Bomb.x].Colonne[Bomb.y-1]!=Mur && ConditionLimiteJeu !="HautImpossible")
	{
		Bomb.y-=1;                //Direction Haut
	}

	if(DirectionYBomb=="Bas" && Grille[Bomb.x].Colonne[Bomb.y+1]!=Mur && ConditionLimiteJeu !="BasImpossible")
	{
		Bomb.y+=1;                 //Direction Bas
	}

	if(DirectionXBomb=="Droite" && Grille[Bomb.x+1].Colonne[Bomb.y]!=Mur && ConditionLimiteJeu !="DroiteImpossible")
	{
		Bomb.x+=1;                 //Direction Droite
	}

	if(DirectionXBomb=="Gauche" && Grille[Bomb.x-1].Colonne[Bomb.y]!=Mur && ConditionLimiteJeu !="GaucheImpossible")
	{
		Bomb.x-=1;                 //Direction Gauche
	}
}