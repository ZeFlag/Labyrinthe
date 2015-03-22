#include "AffichageFond.h"


void Afficher(Ligne Grille[],int fond, int mur, int sou, int mario, int koopa, int goomba, int bomb, 
Position Mario, Position Koopa, Position Goomba, Position Bomb)
{
	AfficherImage(fond, 0, 0);
	AfficherObject(Grille, NbMur, mur);
	AfficherObject(Grille, NbSou, sou);
	AfficherImage(mario, Mario.x*NbPixelsParCase, Mario.y*NbPixelsParCase);  //Affichage de mario
	AfficherImage(koopa, Koopa.x*NbPixelsParCase, Koopa.y*NbPixelsParCase);  //Affichage de koopa
	AfficherImage(goomba, Goomba.x*NbPixelsParCase, Goomba.y*NbPixelsParCase);  //Affichage de Goomba
	AfficherImage(bomb, Bomb.x*NbPixelsParCase, Bomb.y*NbPixelsParCase);  //Affichage de Bomb
	RafraichirFenetre();
}


void InitialiserGrille(Ligne Grille[])
{
   for(int i=0;i<NbCases;i++)
   {                                                     //Initialise la grille de jeu à vide.
      for(int j=0;j<NbCases;j++)
      {
         Grille[i].Colonne[j]=Vide;
      }
   }
}

void PlacerObject(Ligne Grille[],int NbObject, int ImageId)
{

   for(int Cpt=0;Cpt<NbObject;Cpt++)
   {
      int i=rand()%NbCases;
      int j=rand()%NbCases;                               //Définition de la fonction PlacerObject

      if(Grille[i].Colonne[j]==Vide)
      {
         Grille[i].Colonne[j]=ImageId;
      }
      else
      {
         Cpt--;
      }
   }
}

void AfficherObject(Ligne Grille[],int NbObject, int ImageId)
{
   for(int i=0;i<NbCases;i++)
   {
      for(int j=0;j<NbCases;j++)
      {
         if(Grille[i].Colonne[j]==ImageId)                                       //Définition de la fonction AfficherObject
         {
            AfficherImage(ImageId, i*NbPixelsParCase,j*NbPixelsParCase);
         }
      }
   }
}
