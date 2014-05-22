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
	loadMap("Maps/terrenomercurio.tmx", "bg", "foreground1", "foreground2", "meta", "objetos");
	cargarfondo();
	metaCheck(meteorito->getPosition());
	tileMap->addChild(meteorito, 1);
	setEventHandlers();
	this->addChild(tileMap, -1, 1);
	Point View = setPointOfView(Point(meteorito->getPositionX(), meteorito->getPositionY()));
	tileMap->setPosition(CC_POINT_PIXELS_TO_POINTS(View));
	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto meteoro = objetos->getObject("Meteorito");
	CCASSERT(!meteoro.empty(), "Meteorito object not found");
	//saco las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = meteoro["x"].asFloat() + 315;
	float y = meteoro["y"].asFloat() + 10;
	//Crea el sprite y lo posiciona
	meteorito = Sprite::create("Animations/meteorito.png", Rect(0, 0, 64, 64));
	meteorito->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));
	//crea la animacion del meteorito
	auto animation = Animation::create();
	for (int i = 0; i < 5; ++i)
		animation->addSpriteFrame(SpriteFrame::create("Animations/meteorito.png", Rect(i * 64, 0, 64, 64)));
	animation->setDelayPerUnit(0.1333f);
	auto repeatAnimation = RepeatForever::create(Animate::create(animation));
	meteorito->runAction(repeatAnimation);

}
