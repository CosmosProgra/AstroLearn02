#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include "TileMaps.h"
///Estructura del player para todo el juego


struct Player
{
	friend class TileMaps;
	friend class MercuryScene;
protected:
	cocos2d::Sprite* PlayerSprite;
	int points = 0;
	bool colision = false;
public:
	Player();
	~Player();


};

#endif // PLAYER_H