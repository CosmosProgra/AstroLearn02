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

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("Comenzar aventura", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .64f));

	// add the label as a child to this layer
	this->addChild(label, 1);

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

	/*// Boton de la casita, para retornar al menu del juego, ubicado en la esquina superior izquierda
	auto buttonHome = MenuItemImage::create("boton_aceptar.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	buttonHome->setPosition(Point(origin.x + buttonHome->getContentSize().width / 2.0f + 5.0f, origin.y + visibleSize.height - buttonHome->getContentSize().height / 2.0f - 5.0f));
	auto buttonHomeMenu = Menu::create(buttonHome, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);*/

	// Boton registrarse
	auto buttonatras = MenuItemImage::create("boton_atras.png", "boton_atras.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	buttonatras->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.57f));	auto buttonAwardsMenu = Menu::create(buttonatras, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAwardsMenu, 2);
}

#include "HelloWorldScene.h"
void Ingresar::returnGameMenu(Ref* pSender)
{
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionMoveInR::create(0.75f, newScene));
}
