#include "Niveles.h"
#include <SimpleAudioEngine.h>

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 
 
Scene* Niveles::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Niveles::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Niveles::init()
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
    auto sprite = Sprite::create("sistema.jpg");

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

void Niveles::createMenu()
{

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	
	/// Se crea el boton (buttonAtras) para retroceder al menu principal.	
	
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "botonatras_down.png", CC_CALLBACK_1(Niveles::returnGameMenu, this));
	
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));

	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);

	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);
}


#include "HelloWorldScene.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */

/// Metodo que es invocado al ser presionado el boton atras.
void Niveles::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = HelloWorld::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}
