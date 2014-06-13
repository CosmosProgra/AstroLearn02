#include "TileMaps.h"

USING_NS_CC;


void TileMaps::setPointOfView(Point elemento)
{
	auto winSize = Director::getInstance()->getWinSize();

	int x = MAX(elemento.x, winSize.width / 2);
	int y = MAX(elemento.y, winSize.height / 2);
	x = MIN(x, (tileMap->getContentSize().width * tileMap->getContentSize().width) - winSize.width / 2);
	y = MIN(y, (tileMap->getContentSize().height * tileMap->getContentSize().height) - winSize.height / 2);

	auto actualPosition = Point(x, y);
	auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
	auto viewPoint = centerOfView - actualPosition;

	tileMap->setPosition(CC_POINT_PIXELS_TO_POINTS(viewPoint));


}

void TileMaps::setEventHandlers()
{
	//Create a "one by one" touch event listener (processes one touch at a time)
	auto listener = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener->setSwallowTouches(true);

	// Example of using a lambda expression to implement onTouchBegan event callback function
	listener->onTouchBegan = [&](Touch* touch, Event* event){
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
			movePlayer(locationInNode);
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
	//Add listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, tileMap);
}


Point TileMaps::tileCoordForPosition(Point position)
{

	log("POSITIONX %f", position.x);
	log("POSITIONY %f", position.y);

	int x = position.x / tileMap->getTileSize().width;
	int y = ((tileMap->getMapSize().height * tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;

	Size tileSize = tileMap->getTileSize();
	Size mapSize = tileMap->getMapSize();

	Point pos = position;
	log("x mapposition %f", pos.x);
	log("y mapposition %f", pos.y);
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

	log("Tile Position %d ,%d", x, y);
	return Point(x, y);

}

std::string TileMaps::metaCheck(Point posicion)
{
	std::string resultado = "Normal";
	Point tileCoord = tileCoordForPosition(posicion);
	int tileGid = meta->tileGIDAt(tileCoord);
	log("tileGid %d", tileGid);
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

void TileMaps::loadMap(const std::string& mapTmx, const std::string& objectGroupName, const std::string& ambiente2, const std::string& ambiente1,
	const std::string& f1LayerName, const std::string& f2LayerName, const std::string& bgLayerName, const std::string& metaLayerName)
{
	tileMap = TMXTiledMap::create(mapTmx);
	CCAssert(tileMap != nullptr, "'mapTmx' map not found");
	tileMap->setAnchorPoint(Point(0.0f, 0.0f));
	objetos = tileMap->getObjectGroup(objectGroupName);
	Rocas2 = tileMap->getLayer(ambiente2);
	CCAssert(Rocas2 != nullptr, "'f1LayerName' not found");
	Rocas1 = tileMap->getLayer(ambiente1);
	CCAssert(Rocas1 != nullptr, "'f1LayerName' not found");
	foreground1 = tileMap->getLayer(f1LayerName);
	CCAssert(foreground1 != nullptr, "'f1LayerName' not found");
	foreground2 = tileMap->getLayer(f2LayerName);
	CCAssert(foreground2 != nullptr, "'f2LayerName' not found");
	background = tileMap->getLayer(bgLayerName);
	CCAssert(background != nullptr, "'bgLayerName' not found");
	meta = tileMap->getLayer(metaLayerName);
	CCAssert(meta != nullptr, "'metaLayerNAme' not found");
	
}

void TileMaps::createCharacter(std::string imagen)
{
	auto PlayerObjeto = objetos->getObject("Astronauta");
	CCASSERT(!PlayerObjeto.empty(), "PlayerInit object not found");
	float x = PlayerObjeto["x"].asFloat() + 370;
	float y = PlayerObjeto["y"].asFloat();
	Player1 = Sprite::create(imagen);
	Player1->setPosition(CC_POINT_PIXELS_TO_POINTS(Point(x, y)));
}



void TileMaps::setIncrements()
{
	IncrementX = tileMap->getTileSize().width / 6;
	IncrementY = tileMap->getTileSize().height / 6;
}


void TileMaps::movePlayer(Point placeToMove)
{
	Point playerPos = Player1->getPosition();
	Point diff = (placeToMove - playerPos);
	if (fabs(diff.x) > abs(diff.y)) {
		if (diff.x > 0) {
			playerPos.x += IncrementX;
		}
		else {
			playerPos.x -= IncrementX;
		}
	}
	else {
		if (diff.y > 0) {
			playerPos.y += IncrementY;
		}
		else {
			playerPos.y -= IncrementY;
		}
	}

	this->setPlayerPosition(playerPos);
	this->setPointOfView(Player1->getPosition());
}

void TileMaps::setEvents()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(TileMaps::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, tileMap);

}

bool TileMaps::onTouchBegan(Touch *touch, Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	//Get the position of the current point relative to the button
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	//Check the click area
	if (rect.containsPoint(locationInNode))
	{
		log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
		movePlayer(locationInNode);
		return true;
	}
	return false;
}


void TileMaps::setPlayerPosition(Point position){
	if (metaCheck(position) == "Normal"){
		Player1->setPosition(Point(position));
	}
}