#ifndef MERCURYSCENE_H
#define MERCURYSCENE_H

#include "cocos2d.h"
#include "TileMaps.h"

/// Crea la pantalla del nivel de Mercurio
class MercuryScene :public TileMaps
{
public:

	MercuryScene();
	// Aquí se genera la escena de Mercurio
	static cocos2d::Scene* createScene();

protected:
	// Hace referencia al sprite utilizado para personaje del juego (Astronauta)
	cocos2d::Sprite* astronautaSprite;

public:
	// Metodo Init
	virtual bool init();

	//void returnGameMenu(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MercuryScene);

protected:
	/// Metodo para cargar el objeto 'Astronauta' del Tilemap de Mercurio(fondo.tmx)
	void cargarfondo();
};

#endif