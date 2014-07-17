#ifndef VenusScene_H
#define VenusScene_H

#include "cocos2d.h"
#include "TileMaps.h"
#include "Animaciones.h"
#include "Colisiones.h"

/**
* @brief clase para generar la pantalla de Venus.
*
*/
class VenusScene :public TileMaps
{
	///variables para cargar las estrellas
	static const size_t starsNumber = 60;
	static const size_t maxCoorderX = 6368;
	static const size_t groundCoorderY = 1088;

public:

	VenusScene();
	/**
	* @brief Metodo crea la escena de venus.
	* @return Scene*, para que se le puedan agregar los diferentes elementos.
	*/
	static cocos2d::Scene* createScene();

protected:
	/// Hace referencia al sprite utilizado para personaje del juego (Astronauta)
	cocos2d::Sprite* astronautaSprite;

	/// Para poder hacer que el personaje se mueva hacia arriba o abajo
	Animaciones animacion;

	/// Crea una particula de fuego.
	cocos2d::CCParticleSystemQuad*  emitter = nullptr;

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

	/**
	* @brief metodo para crear una particula de fuego
	* @param entra la posicion donde se quiere ubicar la particula
	*/
	void crearParticulaFuego(const cocos2d::Point& position);


	// implement the "static create()" method manually
	CREATE_FUNC(VenusScene);

protected:
	/// Metodo para cargar el objeto 'Astronauta' del Tilemap de Mercurio(fondo.tmx)
	void cargarfondo();

	///Metodo de prueba!!
	/// Se encarga de cargar las monedas dentro del juego
	void loadStars();

	///vector que posee las imaganes de las estrellas
	std::vector<cocos2d::Sprite*> stars;

	///Vector que posee las imagenes de los propulsores
	std::vector<cocos2d::Sprite*> propulsores;

	/// Se encarga de cargar los propulsores dentro del juego
	void cargarPropulsores();

	///Se encarga de verificar el contacto con los propulsores
	void verificarContacto();



	cocos2d::Sprite* nave;

	///Se encarga de cambiar la escena por la de Venus
	void cambioDeNivel();
	/// Carga la imagen de la nave en la pantalla
	void cargarNave();
	///Se encarga de cargar la nave dentro del juego
	void contactoNave();


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