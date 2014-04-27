#ifndef Ingresar_h
#define Ingresar_h

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

/**
	Clase ingresar. Se utiliza para generar la pantalla con la que el usuario accesa a su cuenta.
*/

class Ingresar : public cocos2d::Layer
{
	
public:
	
	/// Metodo para crear la escena, muestra los botones para ir a la pantalla principal y a la que contiene los niveles.
	static cocos2d::Scene* createScene();

	/// Retorna un booleano, se usa para generar los elementos que conforman la pantalla.
	virtual bool init();

	/// Se invoca cuando el jugador presiona el boton 'Atras' y se dirige a la pantalla principal.
	void returnGameMenu(cocos2d::Ref* pSender);

	///Se invoca cuando el jugador presiona 'Aceptar' y se dirige a la pantalla de los niveles.
	void levels(cocos2d::Ref* pSender);

	/// Implementa the "static create()" método manual.
	CREATE_FUNC(Ingresar);

private:
	/// Crea los botones necesarios para enlazar la pantalla con las otras.
	void createMenu();
};

#endif // Ingresar_h
