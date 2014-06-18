#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

/**
* @brief clase para egenerar la pantalla principal del juego AstroLearn.
*
*/

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

class HelloWorld : public cocos2d::Layer /*!< Hereda de Layer. */ 
{
public:

	/**
	* @brief Metodo crea la escena de la pantalla principal.
	* @return Scene*, para que se le puedan agregar los diferentes elementos.
	*/
    static cocos2d::Scene* createScene();

	/**
	* @brief metodo para generar los componentes que posee la pantalla principal.
	* @return retorna true si el metodo logro generar los elementos y agregarlos a la capa.
	*/
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	/**
	* @brief metodo para redirigir a la pantalla de ingresar, se invoca cuando el boton 'ingresar' es presionado.
	* @param cocos2d::Ref* pSender, puntero a la otra escena.
	*/
	void Iniciarsesion(cocos2d::Ref* pSender);

	/**
	* @brief metodo para terminar la ejecucion del programa.
	* @param cocos2d::Ref* pSender, puntero a la otra escena.
	*/
    // a selector callback, metodo que termina el programa
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:

	/**
	* @brief metodo para colocar los botones en la pantalla principal
	*/
	void createGameMenu(); 
};

#endif // __HELLOWORLD_SCENE_H__
