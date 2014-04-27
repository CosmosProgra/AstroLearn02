#ifndef Ingresar_h
#define Ingresar_h

#include "cocos2d.h" 

/**
	Clase ingresar. Se utiliza para generar la pantalla con la que el usuario accesa a su cuenta.
*/

class Ingresar : public cocos2d::Layer
{
	
public:
	/// Metodo para crear la escena donde se generará la pantalla.
	static cocos2d::Scene* createScene();

	/// Retorna un booleano, se usa para generar los elementos que conforman la pantalla.
	virtual bool init();

	/// Se invoca cuando el jugador presiona el boton 'regresar al inicio' y se dirige a la pantalla principal.
	void returnGameMenu(cocos2d::Ref* pSender);

	///Se invoca cuando el jugador presiona 'Aceptar' y se dirige a la pantalla de los niveles.
	void levels(cocos2d::Ref* pSender);

	/// Implementa the "static create()" método manual.
	CREATE_FUNC(Ingresar);

private:
	/// Crea los botones necesarios para enlazar la pantalla con otras.
	void createMenu();
};

#endif // Ingresar_h
