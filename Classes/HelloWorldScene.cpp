#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

   
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("principal.jpg");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	createGameMenu();

	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);
    return true;
}

void HelloWorld::createGameMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton ingresar
	auto buttoningresar = MenuItemImage::create("boton_ingresar.png", "boton_ingresar.png", CC_CALLBACK_1(HelloWorld::Iniciarsesion, this));
	buttoningresar->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.33f));
	auto buttonStartMenu = Menu::create(buttoningresar, NULL);
	buttonStartMenu->setPosition(Point::ZERO);
	this->addChild(buttonStartMenu, 2);

	// Boton registrarse
	auto buttonregistrarse = MenuItemImage::create("boton_registrarse.png", "boton_registrarse.png", CC_CALLBACK_1(HelloWorld::registrarusuario, this));
	buttonregistrarse->setPosition(Point(buttoningresar->getPositionX(), buttoningresar->getPositionY() - buttoningresar->getContentSize().height - 10));
	auto buttonAwardsMenu = Menu::create(buttonregistrarse, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAwardsMenu, 2);
}

#include "Ingresar.h"
void HelloWorld::Iniciarsesion(Ref* pSender)
{
	auto newScene = Ingresar::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}

void HelloWorld::registrarusuario(Ref *pSender)
{
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
