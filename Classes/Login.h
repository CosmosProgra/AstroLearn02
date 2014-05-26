#ifndef Login_h
#define Login_h

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

/// Crea la pantalla para iniciar sesion (Login) .
class Login : public cocos2d::Layer /*!< Hereda de Layer. */ 
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	/// Metodo que crea la escena de la pantalla "Login"
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    /// Se invoca cuando el jugador presiona el boton 'Atras' en la pantalla "Login".
    void returnGameMenu(cocos2d::Ref* pSender);

	/// Se invoca cuando el jugador presiona el boton 'Enter' en la pantalla "Login".
   	void opciones(cocos2d::Ref* pSender);

	/// Metodo para confirmar el pin  ingresado por el jugador
	void leerpin();

    // implement the "static create()" method manually
    CREATE_FUNC(Login);

private:
	/// Crea los botones que aparecen en la pantalla de "Login"
	void createMenu();
};

#endif // Login_h