#include "MercuryScene.h"
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
	tileMap->addChild(playerOne->PlayerSprite, 2);
	


	// loadSpritesheet();



	this->addChild(tileMap, -1, 1);
	setPointOfView(Point(playerOne->PlayerSprite->getPosition()));
	printf("x mapPosition %f", tileMap->getPosition().x);
	printf("x mapPosition %f", tileMap->getPosition().y);
    auto listener = EventListenerKeyboard::create();

	cocos2d::Sprite* ptr = playerOne->PlayerSprite;
	while (metaCheck(Point(ptr->getPositionX(), ptr->getPositionY()-3)) == "Normal")
	{
<<<<<<< HEAD
		ptr->setPosition(Point(ptr->getPositionX() + 0.5, ptr->getPositionY() - 0.5));
=======
		ptr->setPosition(Point(ptr->getPositionX(), playerOne->PlayerSprite->getPositionY() - 1.5));
>>>>>>> 18e72883a33349b322532b95562d3aa51c5d4a2a
		setPointOfView(Point(ptr->getPosition()));
	}

	listener->onKeyPressed = CC_CALLBACK_2(MercuryScene::keyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(MercuryScene::keyReleased, this);
	this->schedule(schedule_selector(MercuryScene::onKeyHold));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	loadStars();
	return true;
}





/*


SpriteFrameCache* cache;

void MercuryScene::loadSpritesheet()
{
	playerOne = new Player();
	auto PlayerObjeto = objetos->getObject("Astronauta");
	float x = PlayerObjeto["x"].asFloat() + 10;
	float y = PlayerObjeto["y"].asFloat() + 60;

	SpriteBatchNode* spritebatch = SpriteBatchNode::create("/maps/animation/Spritesheet/Astronaut.png");

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("/maps/animation/Spritesheet/Astronaut.plist");

	playerOne->PlayerSprite = Sprite::createWithSpriteFrameName("0000008.png");

	playerOne->PlayerSprite->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));

	playerOne->PlayerSprite->setAnchorPoint(Point(0.9f, 0.0f));

	spritebatch->addChild(playerOne->PlayerSprite, 2);

	addChild(spritebatch);
}


void MercuryScene::AnimateSpritesheet()
{
	Vector<SpriteFrame*> spriteFrame(15);
	char str[100] = { 0 };
	for (int i = 10; i < 30; i++)
	{
		sprintf(str, "00000%d.png", i++);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		spriteFrame.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(spriteFrame, 0.05f);
	playerOne->PlayerSprite->runAction(RepeatForever::create(Animate::create(animation)));
}


*/





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
<<<<<<< HEAD


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
=======
		
>>>>>>> 18e72883a33349b322532b95562d3aa51c5d4a2a
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW && metaCheck(Point(playerOne->PlayerSprite->getPositionX(), playerOne->PlayerSprite->getPositionY()-3.5)) != "Normal")
	{
		cocos2d::Sprite* ptr = playerOne->PlayerSprite;
		animacion.mover(ptr, 1.5f, Point((ptr->getPositionX()), (ptr->getPositionY() + 200.0f)));
		setPointOfView(Point((ptr->getPositionX() + 150.0f), (ptr->getPositionY() + 200.0f)));


	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
<<<<<<< HEAD


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
=======
		
>>>>>>> 18e72883a33349b322532b95562d3aa51c5d4a2a
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
	if (metaCheck(Point(ptr->getPositionX(), ptr->getPositionY() - 3.5)) == "Normal")
	{
		animacion.mover(ptr, 0.01f, Point(ptr->getPositionX(), playerOne->PlayerSprite->getPositionY() - 1.0));
		setPointOfView(Point(ptr->getPosition()));
	}

	setPointOfView(Point(ptr->getPosition()));

}

//Metodo de prueba para cargar estrellas en pantalla
void MercuryScene::loadStars()
{

	for (size_t i = 0; i <= starsNumber; ++i){
		Sprite* star = Sprite::create("Animations/coins.png", Rect(0, 0, 40, 40));
		auto animation = Animation::create();
		for (int i = 0; i < 4; ++i)
			animation->addSpriteFrame(SpriteFrame::create("Animations/coins.png", Rect(0, i * 43, 40, 40)));
		animation->setDelayPerUnit(0.1333f);
		auto repeatAnimation = RepeatForever::create(Animate::create(animation));
		star->runAction(repeatAnimation);
		star->setAnchorPoint(Point(0.0f, 0.0f));
		star->setPosition(rand() % maxCoorderX, rand() % 100 + groundCoorderY);
		stars.push_back(star);
		tileMap->addChild(star, 4);
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

