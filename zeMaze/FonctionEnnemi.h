#ifndef _FonctionEnnemi_h
#define _FonctionEnnemi_h
#include "AffichageFond.h"
#include "FonctionDeVerification.h"

void AnimationKoopa(Ligne Grille[], int Mur, Position& Koopa, string& DirectionKoopa);
void AnimationGoomba(Ligne Grille[], int Mur, Position& Goomba, string& DirectionGoomba);
void AnimationBomb(Ligne Grille[], int Mur, Position Mario, Position& Bomb);

#endif _FonctionEnnemi_h