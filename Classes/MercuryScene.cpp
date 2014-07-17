#include "MercuryScene.h"
#include "Colisiones.h"
#include <iostream>
#include <algorithm>
#include <windows.h>

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
	setEventHandlers();	

	createCharacter("maps/personajepequeno.png");

	//createCharacterAnimation();


	 tileMap->addChild(playerOne->PlayerSprite, 2);
	

	this->addChild(tileMap, -1, 1); 
	setPointOfView(Point(playerOne->PlayerSprite->getPosition()));
	printf("x mapPosition %f", tileMap->getPosition().x);
	printf("x mapPosition %f", tileMap->getPosition().y);
    auto listener = EventListenerKeyboard::create();

	cocos2d::Sprite* ptr = playerOne->PlayerSprite;
	while (metaCheck(Point(ptr->getPositionX(), ptr->getPositionY()-3)) == "Normal")
	{

		ptr->setPosition(Point(ptr->getPositionX() + 0.5, ptr->getPositionY() - 0.5));

		ptr->setPosition(Point(ptr->getPositionX(), playerOne->PlayerSprite->getPositionY() - 1.5));

		setPointOfView(Point(ptr->getPosition()));
	}

	listener->onKeyPressed = CC_CALLBACK_2(MercuryScene::keyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(MercuryScene::keyReleased, this);
	this->schedule(schedule_selector(MercuryScene::onKeyHold));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	loadStars();
	cargarPropulsores();

	schedule(schedule_selector(MercuryScene::updateColision));

	return true;
}



void MercuryScene::updateColision(float df)
{
	verificarContacto();
	verificarrecoleccion();
}

void MercuryScene::onKeyHold(float interval){
	
	gravedad();

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_UP_ARROW) != heldKeys.end()){
		// up pressed
		
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_DOWN_ARROW) != heldKeys.end()){
		// down pressed

		
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_RIGHT_ARROW) != heldKeys.end() ){
		// right pressed

		if (metaCheck(Point(playerOne->PlayerSprite->getPositionX() + 4, playerOne->PlayerSprite->getPositionY())) == "Normal")
		{
			playerOne->PlayerSprite->setPosition(Point(playerOne->PlayerSprite->getPositionX() + 3, playerOne->PlayerSprite->getPositionY()));
			setPointOfView(Point(playerOne->PlayerSprite->getPosition()));

			gravedad();
	
		}
		else
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();
			auto label = LabelTTF::create("Colision", "Arial", 72);

			// position the label on the center of the screen
			label->setPosition(Point(origin.x + visibleSize.width / 2,
				origin.y + visibleSize.height - label->getContentSize().height));
			addChild(label, 5);

		}
	}

	if (std::find(heldKeys.begin(), heldKeys.end(), EventKeyboard::KeyCode::KEY_LEFT_ARROW) != heldKeys.end() ){
		// left pressed

		if (metaCheck(Point(playerOne->PlayerSprite->getPositionX() - 4, playerOne->PlayerSprite->getPositionY())) == "Normal")
		{
			playerOne->PlayerSprite->setPosition(Point(playerOne->PlayerSprite->getPositionX() - 3, playerOne->PlayerSprite->getPositionY()));
			setPointOfView(Point(playerOne->PlayerSprite->getPosition()));

			gravedad();
		}
		else
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();
			auto label = LabelTTF::create("Colision", "Arial", 72);

			// position the label on the center of the screen
			label->setPosition(Point(origin.x + visibleSize.width / 2,
				origin.y + visibleSize.height - label->getContentSize().height));

			addChild(label, 5);
		}
	}

}

void MercuryScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

	gravedad();

	if (std::find(heldKeys.begin(), heldKeys.end(), keyCode) == heldKeys.end()){
		heldKeys.push_back(keyCode);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{



	//	AnimateSpritesheet();



		if (metaCheck(Point(playerOne->PlayerSprite->getPositionX() + 5, playerOne->PlayerSprite->getPositionY())) == "Normal")
		{
			playerOne->PlayerSprite->setPosition(Point(playerOne->PlayerSprite->getPositionX() + 5, playerOne->PlayerSprite->getPositionY()));
			setPointOfView(Point(playerOne->PlayerSprite->getPosition()));
		}
		else
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();
			auto label = LabelTTF::create("Colision", "Arial", 72);

			// position the label on the center of the screen
			label->setPosition(Point(origin.x + visibleSize.width / 2,
				origin.y + visibleSize.height - label->getContentSize().height));

			addChild(label, 5);
		}

	}

	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW && metaCheck(Point(playerOne->PlayerSprite->getPositionX(), playerOne->PlayerSprite->getPositionY()-3.8)) != "Normal")
	{
		cocos2d::Sprite* ptr = playerOne->PlayerSprite;
		animacion.mover(ptr, 1.5f, Point((ptr->getPositionX()), (ptr->getPositionY() + 200.0f)));
		setPointOfView(Point((ptr->getPositionX() + 150.0f), (ptr->getPositionY() + 200.0f)));


	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{



	//	AnimateSpritesheet();


		if (metaCheck(Point(playerOne->PlayerSprite->getPositionX() - 5, playerOne->PlayerSprite->getPositionY())) == "Normal")
		{
			playerOne->PlayerSprite->setPosition(Point(playerOne->PlayerSprite->getPositionX() - 5, playerOne->PlayerSprite->getPositionY()));
			setPointOfView(Point(playerOne->PlayerSprite->getPosition()));
		}
		else
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();
			Point origin = Director::getInstance()->getVisibleOrigin();
			auto label = LabelTTF::create("Colision", "Arial", 72);

			// position the label on the center of the screen
			label->setPosition(Point(origin.x + visibleSize.width / 2,
				origin.y + visibleSize.height - label->getContentSize().height));

			addChild(label, 5);
		}

	}
}

void MercuryScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	
	gravedad();

	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), keyCode), heldKeys.end());

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		playerOne->PlayerSprite->stopAllActions();
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		playerOne->PlayerSprite->stopAllActions();
	}

	

}


//Inicio de construccion de metodo para la gravedad
void MercuryScene::gravedad()
{

	cocos2d::Sprite* ptr = playerOne->PlayerSprite;
	if (metaCheck(Point(ptr->getPositionX(), ptr->getPositionY() - 3.8)) == "Normal")
	{
		animacion.mover(ptr, 0.0001f, Point(ptr->getPositionX(), playerOne->PlayerSprite->getPositionY() - 1.0));
		setPointOfView(Point(ptr->getPosition()));
	}

	setPointOfView(Point(ptr->getPosition()));

}

//Metodo de prueba para cargar estrellas en pantalla
void MercuryScene::loadStars()
{

	for (size_t i = 0; i <= starsNumber; ++i){
		Sprite* star = Sprite::create("Animations/Estrella.png");
		star->setAnchorPoint(Point(0.0f, 0.0f));
		int posiciony = rand() % groundCoorderY;
		if (posiciony < 224)
		{
			posiciony = 250;
		}

		star->setPosition(rand() % maxCoorderX, posiciony);
		stars.push_back(star);
		tileMap->addChild(star, 4);
	}
}

void MercuryScene::marcadores()
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	marcador = LabelTTF::create("0000","fonts/04B.ttf",25);
	marcador->setPosition(Point(origin.x + visibleSize.width-marcador->getContentSize().width,
									origin.y + visibleSize.height-marcador->getContentSize().height));
	addChild(marcador,4);
}


void MercuryScene::verificarrecoleccion()
{
	for (size_t i = 0; i < stars.size(); ++i)
	{
		if (Colisiones::collides(playerOne->PlayerSprite, stars[i]))
		{
			tileMap->removeChild(stars[i]);
			stars.erase(stars.begin() + i);
			playerOne->points = playerOne->points + 100;
		}
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





//Metodo de prueba para cargar estrellas en pantalla
void MercuryScene::cargarPropulsores()
{

	size_t coordX[]{42, 52, 129};	
	size_t coordY[]{60, 56, 62};
	size_t maxY = 69;

	for (size_t i = 0; i <= sizeof(coordX); i++)
	{
		Sprite* propulsor = Sprite::create("Animations/Propulsores.png");
		propulsor->setAnchorPoint(Point(0.0f, 0.0f));
		propulsor->setPosition((coordX[i] * 32), (maxY - coordY[i]) * 32);
		propulsores.push_back(propulsor);
		tileMap->addChild(propulsor, 4);
	}

}

void MercuryScene::verificarContacto()
{
	for (size_t i = 0; i < propulsores.size(); ++i)
	{
		if (Colisiones::collides(playerOne->PlayerSprite, propulsores[i]))
		{
			tileMap->removeChild(propulsores[i]);
			propulsores.erase(propulsores.begin() + i);
			animacion.mover(playerOne->PlayerSprite, 1.5f, Point((playerOne->PlayerSprite->getPositionX()), (playerOne->PlayerSprite->getPositionY() + 350.0f)));
			setPointOfView(Point((playerOne->PlayerSprite->getPositionX() + 150.0f), (playerOne->PlayerSprite->getPositionY() + 350.0f)));
		}
	}
}