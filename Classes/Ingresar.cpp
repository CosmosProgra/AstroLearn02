#include "Ingresar.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* Ingresar::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Ingresar::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Ingresar::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 3. add your codes below...

	
	// Crear el fondo del menu del juego
	auto sprite = Sprite::create("iniciarsesion.jpg");

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	createMenu();

	// Reproducir la musica de la seleccion del nivel: quiza sea mejor dejar la misma del menu
	// principal y cambiarla cuando se haya iniciado el nivel. Se deja aqui por propositos
	// ilustrativos
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion2.mp3", true);

	return true;
}

void Ingresar::createMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton para regresar a la pantalla principal, ubicado en la parte central de la pantalla.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "boton_atras.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	buttonAtras->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.45f));	auto buttonAwardsMenu = Menu::create(buttonAtras, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAwardsMenu, 2);

	// Boton para continuar con la selección de la misión, ubicado en la parte central junto al boton 'Atras'.
	auto buttonAceptar = MenuItemImage::create("boton_aceptar.png", "boton_aceptar.png", CC_CALLBACK_1(Ingresar::levels, this));
	buttonAceptar->setPosition(Point(visibleSize.width / 2 + buttonAtras->getContentSize().width*1.2f, origin.y + visibleSize.height * 0.45f));
	auto buttonHomeMenu = Menu::create(buttonAceptar, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);

}

#include "HelloWorldScene.h"
#include "Ingresar.h"

void Ingresar::returnGameMenu(Ref* pSender)
{
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionMoveInR::create(0.75f, newScene));
}

void Ingresar::levels(Ref* pSender)
{

}