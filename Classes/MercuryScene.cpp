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

