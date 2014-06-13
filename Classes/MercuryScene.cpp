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

	loadMap("maps/PantallaMercurio/Mercurio.tmx", "Objetos", "Rocas2", "Rocas1", "bg1", "bg2", "FondoPrincipal", "Meta");
	cargarfondo();
	tileMap->addChild(astronautaSprite, 1);
	createCharacter("Animations/meteorito.png");
	tileMap->addChild(Player1, 2);
	//setIncrements();
	//setTouchEnabled(true);
	//setEvents();
	//metaCheck(Player1->getPosition());
	//setEventHandlers();
	this->addChild(tileMap, -1, 1);
	setPointOfView(Point(Player1->getPosition()));
	log("x mapPosition %f", tileMap->getPosition().x);
	log("x mapPosition %f", tileMap->getPosition().y);

	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto Fogata = objetos->getObject("Astronauta");
	CCASSERT(!Fogata.empty(), "Fogata object not found");
	//saco las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = Fogata["x"].asFloat() + 315;
	float y = Fogata["y"].asFloat() + 28;
	//Crea el sprite y lo posiciona
	astronautaSprite = Sprite::create("Animations/meteorito.png");
	astronautaSprite->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));
}

/*void MercuryScene::setEventHandlers()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener->onTouchBegan = [](Touch* touch, Event* event){
		// event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		//Get the position of the current point relative to the button
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//Check the click area
		if (rect.containsPoint(locationInNode))
		{
			log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			return true;
		}
		return false;
	};
	//Trigger when moving touch
	listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//Move the position of current button sprite
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	//Process the touch end event
	listener->onTouchEnded = [=](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		log("sprite onTouchesEnded.. ");
		target->setOpacity(255);
		//Reset zOrder and the display sequence will change

	};
	//auto listener1 = EventListenerKeyboard::create();
	//listener1->onKeyPressed = CC_CALLBACK_2(CatchMe::onKeyPressed, this);
	//listener1->onKeyReleased = CC_CALLBACK_2(CatchMe::onKeyReleased, this);

	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), labelGameTitle);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), labelGameTitle);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1,labelGameTitle);




}*/