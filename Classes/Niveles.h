#ifndef Niveles_h
#define Niveles_h

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

/// Crea la pantalla para seleccionar los niveles (planetas).
class Niveles : public cocos2d::Layer /*!< Hereda de Layer. */ 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	/// Metodo que crea la escena de la pantalla "Niveles"
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    /// Se invoca cuando el jugador presiona el boton 'Atras' en la pantalla "Niveles".
    void returnGameMenu(cocos2d::Ref* pSender);


	/////Listado de planetas

	///Llamado a la primera pantalla Mercurio
    void Mercurio(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Venus
	void Venus(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Tierra
	void Tierra(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Marte
	void Marte(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Jupiter
	void Jupiter(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Saturno
	void Saturno(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Urano
	void Urano(cocos2d::Ref* pSender);

	///Llamado a la primera pantalla Neptuno
	void Neptuno(cocos2d::Ref* pSender);

	
    // implement the "static create()" method manually
    CREATE_FUNC(Niveles);

private:
	/// Crea los botones que aparecen en la pantalla de Niveles
	void createMenu();
};

#endif // Niveles_h