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

    /// Crea el fondo de la pantalla del menu "Registrarse" del juego
    auto sprite = Sprite::create("fondoteclado.jpg");

    /// Posiciona el sprite (fondo de pantalla) para que quede centralizado en la pantalla
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    /// Hace visible el fondo de pantalla
    this->addChild(sprite, 0);
	
	createMenu();
    
	/// Se utiliza para reproducir la musica cuando se cambia a esta pantalla (registrarse).
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

    return true;
}

void Login::createMenu()
{

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	
	/// Se crea el boton (buttonAtras) para retroceder al menu principal.	
	
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "botonatras_down.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));
	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);

	//Botón 1
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button01 = MenuItemImage::create("/Originales/01.png", "/Pequeños/01.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	button01->setPosition(Point(visibleSize.width / 3.0, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn01 = Menu::create(button01, NULL);
	buttonn01->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonn01, 3);
	//Botón 2
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button02 = MenuItemImage::create("/Originales/02.png", "/Pequeños/02.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	button02->setPosition(Point(visibleSize.width / 2.2, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn02 = Menu::create(button02, NULL);
	buttonn02->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonn02, 3);
	//Botón 3
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button03 = MenuItemImage::create("/Originales/03.png", "/Pequeños/03.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	button03->setPosition(Point(visibleSize.width / 1.741, origin.y + visibleSize.height * 0.6f));
	/// Crea el botón
	auto buttonn03 = Menu::create(button03, NULL);
	buttonn03->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonn03, 3);
	//Botón 4
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto button04 = MenuItemImage::create("/Originales/04.png", "/Pequeños/04.png", CC_CALLBACK_1(Login::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	button04->setPosition(Point(visibleSize.width / 3.0, origin.y + visibleSize.height * 0.459f));
	/// Crea el botón
	auto buttonn04 = Menu::create(button04, NULL);
	buttonn04->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonn04, 3);
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
