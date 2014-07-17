#ifndef MERCURYSCENE_H
#define MERCURYSCENE_H

#include "cocos2d.h"
#include "TileMaps.h"
#include "Animaciones.h"


/// Crea la pantalla del nivel de Mercurio
class MercuryScene :public TileMaps
{
	//Variables de prueba para las estrellas de puntaje
	static const size_t starsNumber = 60;
	static const size_t maxCoorderX = 6368;
	static const size_t groundCoorderY = 1088;

public:

	MercuryScene();
	// Aquí se genera la escena de Mercurio
	static cocos2d::Scene* createScene();

protected:
	// Hace referencia al sprite utilizado para personaje del juego (Astronauta)
	cocos2d::Sprite* astronautaSprite;
	Animaciones animacion;

public:
	// Metodo Init
	virtual bool init();
	std::vector<cocos2d::EventKeyboard::KeyCode> heldKeys;
	void returnGameMenu(cocos2d::Ref* pSender);
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onKeyHold(float interval);

	void gravedad();

	// implement the "static create()" method manually
	CREATE_FUNC(MercuryScene);

protected:
	/// Metodo para cargar el objeto 'Astronauta' del Tilemap de Mercurio(fondo.tmx)
	void cargarfondo();

	///Metodo de prueba!!
	/// Se encarga de cargar las monedas dentro del juego
	void loadStars();
	///Se encarga de verificar la recoleccion de estrellas
	void verificarrecoleccion();
	///Actualizar
    void updateColision(float df);
	void marcadores();
	std::vector<cocos2d::Sprite*> stars;
	cocos2d::LabelTTF* marcador;


public:

	void loadSpritesheet();

	void AnimateSpritesheet();

};

#endif