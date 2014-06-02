#include "TileMaps.h"

USING_NS_CC;


Point TileMaps::setPointOfView(Point elemento)
{
	auto winSize = Director::getInstance()->getWinSize();

	int x = MAX(elemento.x, winSize.width / 2);
	int y = MAX(elemento.y, winSize.height / 2);
	x = MIN(x, (tileMap->getContentSize().width * tileMap->getContentSize().width) - winSize.width / 2);
	y = MIN(y, (tileMap->getContentSize().height * tileMap->getContentSize().height) - winSize.height / 2);

	auto actualPosition = Point(x, y);
	auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
	auto viewPoint = centerOfView - actualPosition;
	return viewPoint;


}

void TileMaps::setEventHandlers(Node *child)
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, child);

	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), labelGameTitle);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), labelGameTitle);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1,labelGameTitle);




}


Point TileMaps::tileCoordForPosition(Point position)
{
	int x = position.x / tileMap->getTileSize().width;
	int y = ((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;


	Size tileSize = tileMap->getTileSize();
	Size mapSize = tileMap->getMapSize();

	Point pos = position - tileMap->getPosition();
	float halfMapWidth = tileMap->getMapSize().width * 0.5f;
	float mapHeight = tileMap->getMapSize().height;
	float tileWidth = tileMap->getTileSize().width;
	float tileHeight = tileMap->getTileSize().height;
	Point tilePosDiv = Point(pos.x / tileWidth, pos.y / tileHeight);
	float inverseTileY = mapHeight - tilePosDiv.y;

	float posX = (int)(inverseTileY + tilePosDiv.x - halfMapWidth);
	float posY = (int)(inverseTileY - tilePosDiv.x + halfMapWidth);

	x = MAX(0, posX);
	x = MIN(tileMap->getMapSize().width - 1, posX);
	y = MAX(0, posY);
	y = MIN(tileMap->getMapSize().height - 1, posY);


	//CCLog("Tile Position %d ,%d",x,y);
	return Point(x, y);

}

std::string TileMaps::metaCheck(Point posicion)
{
	std::string resultado = "";
	Point tileCoord = this->tileCoordForPosition(posicion);
	int tileGid = meta->tileGIDAt(tileCoord);
	if (tileGid)
	{
		Value propiedades = tileMap->getPropertiesForGID(tileGid);
		auto propiedad = propiedades.asValueMap();
		auto p = propiedad["colision"].asString();

		if (p.compare("colision") == 0)
		{
			log("colision");
			resultado = "colision";
		}
	}
	return resultado;
}

void TileMaps::loadMap(const std::string& mapTmx, const std::string& bgLayerName, const std::string& f1LayerName,
	const std::string& f2LayerName, const std::string& f3LayerName,
	const std::string& f4LayerName, const std::string& metaLayerName,
	const std::string& objectGroupName)
{
	tileMap = TMXTiledMap::create(mapTmx);
	CCAssert(tileMap != nullptr, "'mapTmx' map not found");
	tileMap->setAnchorPoint(Point(0.0f, 0.0f));
	background = tileMap->getLayer(bgLayerName);
	CCAssert(background != nullptr, "'bgLayerName' not found");
	foreground1 = tileMap->getLayer(f1LayerName);
	CCAssert(foreground1 != nullptr, "'f1LayerName' not found");
	foreground2 = tileMap->getLayer(f2LayerName);
	CCAssert(foreground2 != nullptr, "'f2LayerName' not found");

	foreground3 = tileMap->getLayer(f3LayerName);
	CCAssert(foreground3 != nullptr, "'f4LayerName' not found");
	foreground4 = tileMap->getLayer(f4LayerName);
	CCAssert(foreground4 != nullptr, "'f4LayerName' not found");

	meta = tileMap->getLayer(metaLayerName);
	CCAssert(meta != nullptr, "'metaLayerNAme' not found");
	objetos = tileMap->getObjectGroup(objectGroupName);
	CCAssert(objetos != nullptr, "'objetos' object group not found");
}