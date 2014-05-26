#ifndef OptionScene_h
#define OptionScene_h

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

/// Crea la pantalla para opciones de juego. La pantalla va a aparecer una vez el jugador inicie su partida con su nombre de usuario
class OptionScene : public cocos2d::Layer /*!< Hereda de Layer. */
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	/// Metodo que crea la escena de la pantalla opciones
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	/// Se invoca cuando el jugador presiona el boton 'Atras' en la pantalla Opciones
	void returnGameMenu(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton Nueva partida en la pantalla Opciones
    void iniciarJuego(cocos2d::Ref* pSender);

	///Método que lleva a un juego ya comenzado
	void continuarjuego(cocos2d::Ref* pSender);

	///Metodo que muestra informacion del juego
	void acercade(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(OptionScene);

private:
	/// Crea los botones que aparecen en la pantalla de opciones 
	void createMenu();
};

#endif // Login_h