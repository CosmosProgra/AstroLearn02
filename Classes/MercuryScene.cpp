#include "MercuryScene.h"
#include <iostream>

USING_NS_CC;

MercuryScene::MercuryScene()
{
	//Constructor
}

cocos2d::Scene *MercuryScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MercuryScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MercuryScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	loadMap("maps/PantallaMercurio/Mercurio.tmx", "Objetos", "Rocas2", "Rocas1", "bg1", "bg2", "FondoPrincipal", "Meta");
	cargarfondo();
	setEventHandlers();
	tileMap->addChild(astronautaSprite, 1);
	createCharacter("maps/prueba.png");
	tileMap->addChild(Player1, 2);
	//setIncrements();
	//setTouchEnabled(true);
	//setEvents();
	//metaCheck(Player1->getPosition());
	this->addChild(tileMap, -1, 1);
	setPointOfView(Point(Player1->getPosition()));
	printf("x mapPosition %f", tileMap->getPosition().x);
	printf("x mapPosition %f", tileMap->getPosition().y);


	//Listener keyboard
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(MercuryScene::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(MercuryScene::keyReleased, this);
	//EventDispatcher::getInstance()->addEventListenerWithSceneGraphPriority(listener, this); // use if your version is below cocos2d-x 3.0alpha.1
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this); 

	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto Fogata = objetos->getObject("Astronauta");
	CCASSERT(!Fogata.empty(), "Astronauta object not found");
	//saco las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = Fogata["x"].asFloat() + 315;
	float y = Fogata["y"].asFloat() + 28;
	//Crea el sprite y lo posiciona
	astronautaSprite = Sprite::create("Animations/meteorito.png");
	astronautaSprite->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));
}

void MercuryScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	//put this inside keyPressed or keyReleased
	if (keyCode == EventKeyboard::KeyCode::KEY_W)
	{
		CCLog("W key was pressed");
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		CCLog("Flecha abajo");
	//	returnGameMenu();
		CC_CALLBACK_1(MercuryScene::returnGameMenu, this);
	}
}
void MercuryScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

}

//Prueba
#include "Ingresar.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */

/// Metodo que es invocado al ser presionado el boton atras.
void MercuryScene::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = Ingresar::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}

