#include "MercuryScene.h"

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

	loadMap("maps/Pantallamercurio/terrenomercurio.tmx", "FondoPrincipal", "EscenarioPrincipal", "EscenarioDeFondo", "Meta", "ElementosDeEscenario");

	cargarfondo();
	metaCheck(astronautaSprite->getPosition());
	tileMap->addChild(astronautaSprite, 1);
	setEventHandlers();
	this->addChild(tileMap, -1, 1);
	Point View = setPointOfView(Point(astronautaSprite->getPositionX(), astronautaSprite->getPositionY()));
	tileMap->setPosition(CC_POINT_PIXELS_TO_POINTS(View));
	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto astronauta = objetos->getObject("Astronauta");
	CCASSERT(!astronauta.empty(), "Astronauta object not found");
	//saco las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = astronauta["x"].asFloat();
	float y = astronauta["y"].asFloat();
	//Crea el sprite y lo posiciona
	astronautaSprite = Sprite::create("Animations/meteorito.png", Rect(0, 0, 64, 64));
	astronautaSprite->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));

}
