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

	auto map = TMXTiledMap::create("maps/Pantallamercurio/Mercurio.tmx");
	addChild(map, 0, 1);
	setEventHandlers(map);
	Size CC_UNUSED s = map->getContentSize();
	CCLOG("ContentSize: %f, %f", s.width, s.height);

	/*loadMap("maps/Pantallamercurio/Mercurio.tmx", "FondoPrincipal", "bg1", "bg2", "Rocas1", "Rocas2", "Meta", "Objetos");

	//Se hace llamado al metodo 'cargarfondo'
	cargarfondo();

	metaCheck(astronautaSprite->getPosition());
	map->addChild(astronautaSprite, 1);
	setEventHandlers();
	
	// Agrega el mapa a la pantalla
	//this->addChild(tileMap, 0, 1);
	// La posicion del mapa es establecida segun la posicion del sprite del Astronauta
	Point View = setPointOfView(Point(astronautaSprite->getPositionX(), astronautaSprite->getPositionY()));
	map->setPosition(CC_POINT_PIXELS_TO_POINTS(View)); */

	//setEventHandlers();
	return true;
}

void MercuryScene::cargarfondo()
{
	//carga el objeto del mapa
	auto astronauta = objetos->getObject("Astronauta");
	CCASSERT(!astronauta.empty(), "Astronauta object not found");
	//saca las coordenadas del objeto en el tilemap
	//se hace la suma debido al error en cocos2d
	float x = astronauta["x"].asFloat();
	float y = astronauta["y"].asFloat();
	//Crea el sprite y lo posiciona en la pantalla
	astronautaSprite = Sprite::create("Animations/meteorito.png", Rect(9, 54, 4.250, 5.750));
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