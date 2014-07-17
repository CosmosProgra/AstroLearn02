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
	/// Hace referencia al sprite utilizado para personaje del juego (Astronauta)
	cocos2d::Sprite* astronautaSprite;

	/// Para poder hacer que el personaje se mueva hacia arriba o abajo
	Animaciones animacion;
public:
	///vector para guardar el resultado de apretar una tecla.
	std::vector<cocos2d::EventKeyboard::KeyCode> heldKeys;

	/**
	* @brief metodo para generar los componentes que posee la pantalla principal.
	* @return retorna true si el metodo logro generar los elementos y agregarlos a la capa.
	*/
	virtual bool init();


	/**
	* @brief metodo para enviar a otra pantalla
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	* @brief metodo para realizar ciertas acciones cuando las teclas son presionadas.
	*/
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	/**
	* @brief metodo para realizar ciertas acciones cuando las teclas son soltadas.
	*/
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	/**
	* @brief metodo para realizar ciertas acciones cuando las teclas son presiondas y se mantienen así.
	*/
	void onKeyHold(float interval);

	/**
	* @brief metodo atraer el personaje hacia abajo.
	*/
	void aplicarGravedad();

	// implement the "static create()" method manually
	CREATE_FUNC(MercuryScene);

protected:
	/// Metodo para cargar el objeto 'Astronauta' del Tilemap de Mercurio(fondo.tmx)
	void cargarfondo();

	///Metodo de prueba!!
	/// Se encarga de cargar las estrellas dentro del juego
	void loadStars();
	///Se encarga de verificar la recoleccion de estrellas
	void verificarrecoleccion();
	void actualizarmarcador();
	/// Se encarga de cargar los propulsores dentro del juego
	void cargarPropulsores();
	///Se encarga de verificar el contacto con los propulsores
	void verificarContacto();
	

	cocos2d::Sprite* nave;

	///Se encarga de cambiar la escena por la de Venus
	void cambioDeNivel();

	void cargarNave();
	///Se encarga de cargar la nave dentro del juego
	void contactoNave();
	


	///Actualizar
    void updateColision(float df);

	void marcadores();

	///vector que posee las imaganes de las estrellas
	std::vector<cocos2d::Sprite*> stars;

	///Vector que posee las imagenes de los propulsores
	std::vector<cocos2d::Sprite*> propulsores;
	cocos2d::LabelTTF* marcador;



public:
	/**
	* @brief metodo para cargar las imagenes de la animacion del personaje
	*/
	void loadSpritesheet();

	/**
	* @brief metodo para animcar al personaje
	*/
	void AnimateSpritesheet();
};

#endif