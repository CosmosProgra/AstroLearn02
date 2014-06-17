#include "MercuryScene.h"
#include <iostream>
#include <algorithm>

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
	createCharacter("maps/personajepequeno.png");
	tileMap->addChild(Player1, 2);
	//setIncrements();
	//setTouchEnabled(true);
	//setEvents();
	//metaCheck(Player1->getPosition());
	//meta = tileMap->layerNamed("Meta");
//	meta->setVisible(false);
	this->addChild(tileMap, -1, 1);
	setPointOfView(Point(Player1->getPosition()));
	printf("x mapPosition %f", tileMap->getPosition().x);
	printf("x mapPosition %f", tileMap->getPosition().y);

	
		auto listener = EventListenerKeyboard::create();
		listener->onKeyPressed = CC_CALLBACK_2(MercuryScene::keyPressed, this);
		listener->onKeyReleased = CC_CALLBACK_2(MercuryScene::keyReleased, this);
		this->schedule(schedule_selector(MercuryScene::onKeyHold));
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto personaje = objetos->getObject("Astronauta");
	CCASSERT(!personaje.empty(), "Astronauta object not found");
	//saco las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = personaje["x"].asFloat() + 315;
	float y = personaje["y"].asFloat() + 28;
	//Crea el sprite y lo posiciona
	astronautaSprite = Sprite::create("Animations/meteorito.png");
	astronautaSprite->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));
}

void MercuryScene::onKeyHold(float interval){
	
	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_UP_ARROW) != heldKeys.end()){
		// up pressed
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_DOWN_ARROW) != heldKeys.end()){
		// down pressed
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_RIGHT_ARROW) != heldKeys.end()){
		// right pressed
		CCLog("Flecha arriba");
		setPlayerPosition(Point(Player1->getPositionX() + 5, Player1->getPositionY()));
		//Player1->setPosition(Player1->getPositionX()+5, Player1->getPositionY());
		setPointOfView(Point(Player1->getPosition()));
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
		/*auto label = LabelTTF::create(metaCheck(Point(Player1->getPosition())), "Arial", 72);

		// position the label on the center of the screen
		label->setPosition(Point(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		addChild(label, 5);*/
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_LEFT_ARROW) != heldKeys.end()){
		// left pressed
		setPlayerPosition(Point(Player1->getPositionX() - 5, Player1->getPositionY()));
		//Player1->setPosition(Player1->getPositionX()+5, Player1->getPositionY());
		setPointOfView(Point(Player1->getPosition()));
	}

}

void MercuryScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end()){
		heldKeys.push_back(keyCode);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{

	/*	CCLog("Flecha arriba");
		Player1->setPosition(Player1->getPositionX() + 5, Player1->getPositionX());
		setPointOfView(Point(Player1->getPosition()));
		
		CCLog("Flecha izquierda");
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
		auto label = LabelTTF::create(metaCheck(Point(Player1->getPosition())), "Arial", 72);

		// position the label on the center of the screen
		label->setPosition(Point(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		addChild(label, 5);
		CCLog("W key was pressed");
		*/
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		CCLog("Flecha arriba");
		Player1->setPosition(Player1->getPositionX() + 5, 0.0 - 5);
		setPointOfView(Point(Player1->getPosition()));
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		CCLog("Flecha derecha");
	}
}
void MercuryScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{

	}
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

