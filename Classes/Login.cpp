#include "Login.h"
#include <SimpleAudioEngine.h>

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 
 
Scene* Login::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Login::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Login::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /// Crea el fondo de la pantalla del menu "Login" del juego
    auto sprite = Sprite::create("Fondos/pantallaopciones.jpg");

    /// Posiciona el sprite (fondo de pantalla) para que quede centralizado en la pantalla
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    /// Hace visible el fondo de pantalla
    this->addChild(sprite, 0);
	
	createMenu();
    
	/// Se utiliza para reproducir la musica cuando se cambia a esta pantalla (Login).
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

    return true;
}

// Crea los botones que aparecerán en la pantalla
void Login::createMenu()
{

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	
	/// Se crea el boton (buttonAtras) para retroceder al menu principal.		
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonAtras = MenuItemImage::create("botones/boton_atras.png", "botones/botonatras_down.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));
	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);

	
	//Botón 1
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button01 = MenuItemImage::create("botones/teclado/01.png", "botones/teclado_down/01.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button01->setPosition(Point(visibleSize.width / 2.8, origin.y + visibleSize.height * 0.734f));
	/// Crea el botón
	auto buttonn01 = Menu::create(button01, NULL);
	buttonn01->setPosition(Point::ZERO);
	/// Agrega el boton '1' en la pantalla.
	this->addChild(buttonn01, 3);


	//Botón 2
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button02 = MenuItemImage::create("botones/teclado/02.png", "botones/teclado_down/02.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button02->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.734f));
	/// Crea el botón
	auto buttonn02 = Menu::create(button02, NULL);
	buttonn02->setPosition(Point::ZERO);
	/// Agrega el boton '2' en la pantalla.
	this->addChild(buttonn02, 3);


	//Botón 3
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button03 = MenuItemImage::create("botones/teclado/03.png", "botones/teclado_down/03.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button03->setPosition(Point(visibleSize.width / 1.680, origin.y + visibleSize.height * 0.734f));
	/// Crea el botón
	auto buttonn03 = Menu::create(button03, NULL);
	buttonn03->setPosition(Point::ZERO);
	/// Agrega el boton '3' en la pantalla.
	this->addChild(buttonn03, 3);


	//Botón 4
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button04 = MenuItemImage::create("botones/teclado/04.png", "botones/teclado_down/04.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button04->setPosition(Point(visibleSize.width / 2.8, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn04 = Menu::create(button04, NULL);
	buttonn04->setPosition(Point::ZERO);
	/// Agrega el boton '4' en la pantalla.
	this->addChild(buttonn04, 3);


	//Botón 5
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button05 = MenuItemImage::create("botones/teclado/05.png", "botones/teclado_down/05.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button05->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn05 = Menu::create(button05, NULL);
	buttonn05->setPosition(Point::ZERO);
	/// Agrega el boton '5' en la pantalla.
	this->addChild(buttonn05, 3);


	//Botón 6
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button06 = MenuItemImage::create("botones/teclado/06.png", "botones/teclado_down/06.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button06->setPosition(Point(visibleSize.width / 1.680, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn06 = Menu::create(button06, NULL);
	buttonn06->setPosition(Point::ZERO);
	/// Agrega el boton '6' en la pantalla.
	this->addChild(buttonn06, 3);


	//Botón 7
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button07 = MenuItemImage::create("botones/teclado/07.png", "botones/teclado_down/07.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button07->setPosition(Point(visibleSize.width / 2.8, origin.y + visibleSize.height * 0.459f));
	/// Crea el botón
	auto buttonn07 = Menu::create(button07, NULL);
	buttonn07->setPosition(Point::ZERO);
	/// Agrega el boton '6' en la pantalla.
	this->addChild(buttonn07, 3);


	//Botón 8
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button08 = MenuItemImage::create("botones/teclado/08.png", "botones/teclado_down/08.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button08->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.459f));
	/// Crea el botón
	auto buttonn08 = Menu::create(button08, NULL);
	buttonn08->setPosition(Point::ZERO);
	/// Agrega el boton '7' en la pantalla.
	this->addChild(buttonn08, 3);


	//Botón 9
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button09 = MenuItemImage::create("botones/teclado/09.png", "botones/teclado_down/09.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button09->setPosition(Point(visibleSize.width / 1.680, origin.y + visibleSize.height * 0.459f));
	/// Crea el botón
	auto buttonn09 = Menu::create(button09, NULL);
	buttonn09->setPosition(Point::ZERO);
	/// Agrega el boton '9' en la pantalla.
	this->addChild(buttonn09, 3);


	//Botón 0
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button00 = MenuItemImage::create("botones/teclado/00.png", "botones/teclado_down/00.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la pantalla.
	button00->setPosition(Point(visibleSize.width / 2.8, origin.y + visibleSize.height * 0.325f));
	/// Crea el botón
	auto buttonn00 = Menu::create(button00, NULL);
	buttonn00->setPosition(Point::ZERO);
	/// Agrega el boton '10' en la pantalla.
	this->addChild(buttonn00, 3);


	//Botón enter
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonenter = MenuItemImage::create("botones/teclado/enter.png", "botones/teclado_down/enter.png", CC_CALLBACK_1(Login::opciones, this));
	/// Posiciona el boton en la pantalla.
	buttonenter->setPosition(Point(visibleSize.width / 1.850, origin.y + visibleSize.height * 0.325f));
	/// Crea el botón
	auto buttonnenter = Menu::create(buttonenter, NULL);
	buttonnenter->setPosition(Point::ZERO);
	/// Agrega el boton 'Enter' en la pantalla.
	this->addChild(buttonnenter, 3);
}

#include "OptionScene.h"
void Login::opciones(Ref* pSender)
{
	///Crea la escena de login
	//	auto newScene = Ingresar::createScene(); 
	auto newScene = OptionScene::createScene();
	///Reemplaza la escena actual por la escena de Ingresar
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}

//Para confirmar el pin
void leerpin()
{
}

#include "Ingresar.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */

/// Metodo que es invocado al ser presionado el boton atras.
void Login::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = Ingresar::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}
