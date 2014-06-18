#ifndef Ingresar_h
#define Ingresar_h

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */


/**
 * @brief Clase ingresar. Se utiliza para generar la pantalla con la que el usuario accesa a su cuenta.
 *
 */

class Ingresar : public cocos2d::Layer /*!< Hereda de Layer. */ 
{
	
public:

	/**
	* @brief Metodo para crear la escena de la pantalla para ingresar.
	* @return Scene*, para que se le puedan agregar los diferentes elementos.
	*/
	static cocos2d::Scene* createScene();

	/**
	* @brief metodo para generar los componentes que posee la pantalla principal.
	* @return retorna true si el metodo logro generar los elementos y agregarlos a la capa.
	*/
	virtual bool init();

	/**
	* @brief metodo para redirigir a la pantalla de principal, se invoca cuando el boton 'Atras' es presionado.
	* @param cocos2d::Ref* pSender, puntero a la otra escena.
	*/
	void returnGameMenu(cocos2d::Ref* pSender);

	/**
	* @brief metodo para redirigir a la pantalla de Login, se invoca cuando el boton 'Aceptar' es presionado.
	* @param cocos2d::Ref* pSender, puntero a la otra escena.
	*/
	void login(cocos2d::Ref* pSender);

	/**
	* @brief metodo para redirigir a la pantalla para crear un nuevo avatar, se invoca cuando el boton '+' es presionado.
	* @param cocos2d::Ref* pSender, puntero a la otra escena.
	*/
	void registrar(cocos2d::Ref* pSender);

	/// Implementa the "static create()" metodo manual.
	CREATE_FUNC(Ingresar);

private:
	/**
	* @brief metodo para colocar los botones en la pantalla Ingresar y que puedar generar un enlace con las otras pantallas.
	*/
	void createMenu();
};

#endif // Ingresar_h
