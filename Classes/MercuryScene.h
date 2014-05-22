#ifndef MERCURYSCENE_H
#define MERCURYSCENE_H

#include "cocos2d.h"
#include "TileMaps.h"

class MercuryScene :public TileMaps
{
public:

	MercuryScene();
	// Aquí se genera la escena de Mercurio
	static cocos2d::Scene* createScene();

protected:
	cocos2d::Sprite* meteorito;

public:
	// Metodo Init
	virtual bool init();

	//void returnGameMenu(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MercuryScene);

protected:
	void cargarfondo();
};

#endif