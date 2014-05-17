#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

///Clase que genera la pantalla principal de AstroLearn

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

class HelloWorld : public cocos2d::Layer /*!< Hereda de Layer. */ 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	///Metodo que crea la escena de la pantalla principal del juego, muestra las opciones de registrarse e iniciar sesion
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	/// Se invoca cuando el jugador presiona el boton ingresar en la pantalla principal
	void Iniciarsesion(cocos2d::Ref* pSender);

    
    // a selector callback, metodo que termina el programa
    void menuCloseCallback(cocos2d::Ref* pSender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
	void createGameMenu(); /*!< Metodo que coloca los botones en pantalla en la pantalla principal */ 
};

#endif // __HELLOWORLD_SCENE_H__
