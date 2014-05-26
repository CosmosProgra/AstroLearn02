#include "OptionScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */

Scene* OptionScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OptionScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool OptionScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Crea el fondo de la pantalla del menu "Opciones" del juego	
	auto sprite = Sprite::create("Fondos/pantallaopciones.jpg");

	/// Posiciona el sprite (fondo de pantalla) para que quede centralizado en la pantalla
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	/// Hace visible el fondo de pantalla
	this->addChild(sprite, 0);

	createMenu();

	/// Se utiliza para reproducir la musica cuando se cambia a esta pantalla (Opciones).
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

	return true;
}


///Metodo que coloca los botones del menu en pantalla y les proporciona funcionalidad
void OptionScene::createMenu()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	/// Se crea el boton (buttonAtras) para retroceder al menu principal.
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón. Se devuelve a la pantalla de Ingresar
	auto buttonAtras = MenuItemImage::create("botones/boton_atras.png", "botones/botonatras_down.png", CC_CALLBACK_1(OptionScene::returnGameMenu, this));
	
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));
	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);


	//Nueva Partida
	/// Se utilizan imagenes, las cuales son diferentes para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "iniciarJuego", el cual le da la funcionalidad al botón.
	auto nuevo = MenuItemImage::create("botones/boton_nuevapartida.png", "botones/botonnueva_down.png", CC_CALLBACK_1(OptionScene::iniciarJuego, this));
	/// Posiciona el boton en la pantalla.
	nuevo->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.8f));
	/// Crea el botón
	auto botonuevo = Menu::create(nuevo, NULL);
	botonuevo->setPosition(Point::ZERO);
	/// Agrega el boton 'Nueva Partida' en la pantalla.
	this->addChild(botonuevo, 3);


	//Continuar
	/// Se utilizan imagenes, las cuales son diferentes para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "continuarjuego" el cual le da la funcionalidad al botón.
	auto continuar = MenuItemImage::create("botones/boton_continuar.png", "botones/botoncontinuar_down.png", CC_CALLBACK_1(OptionScene::continuarjuego, this));
	/// Posiciona el botón en la pantalla.
	continuar->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.6f));	
	/// Crea el botón
	auto botoncont = Menu::create(continuar, NULL);
	botoncont->setPosition(Point::ZERO);
	/// Agrega el boton 'Continuar' en la pantalla.
	this->addChild(botoncont, 3);
	

	//Acerca de
	/// Se utilizan imagenes, las cuales son diferentes para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "acercade" el cual le da la funcionalidad al botón.
	auto informacion = MenuItemImage::create("botones/boton_acercade.png", "botones/botonacercade_down.png", CC_CALLBACK_1(OptionScene::acercade, this));
	/// Posiciona el boton en la pantalla.
	informacion->setPosition(Point(visibleSize.width / 2.1, origin.y + visibleSize.height * 0.4f));
	/// Crea el botón
	auto botoninfo = Menu::create(informacion, NULL);
	botoninfo->setPosition(Point::ZERO);
	/// Agrega el boton 'Acerca de' en la pantalla.
	this->addChild(botoninfo, 3);
}


#include "Niveles.h"
///Metodo que invoca el boton 'Nueva Partida', abre una nueva pantalla
void OptionScene::iniciarJuego(Ref* pSender)
{
	///Crea la escena de la pantalla de selección de nivel (Sistema Solar)	
	auto newScene = Niveles::createScene();
	///Reemplaza la escena actual por la escena de Niveles
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}

///Metodo para el boton continuar
void OptionScene::continuarjuego(Ref* pSender)
{
}

///Metodo para el boton acerca de
void OptionScene::acercade(Ref* pSender)
{
}

#include "Ingresar.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */
/// Metodo que es invocado al ser presionado el boton atras.
void OptionScene::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = Ingresar::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}