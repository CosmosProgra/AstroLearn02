#include "Registrarse.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* Registrarse::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Registrarse::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Registrarse::init()
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
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    //auto label = LabelTTF::create("", "Arial", 24);

    // position the label on the center of the screen
    //label->setPosition(Point(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * .64f));

    // add the label as a child to this layer
    //this->addChild(label, 1);

    // Crear el fondo del menu del juego
    auto sprite = Sprite::create("registrarse.jpg");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	
	createMenu();
    
	// Reproducir la musica de la seleccion del nivel: quiza sea mejor dejar la misma del menu
	// principal y cambiarla cuando se haya iniciado el nivel. Se deja aqui por propositos
	// ilustrativos
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

    return true;
}

void Registrarse::createMenu()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	// Boton para regresar a la pantalla principal, ubicado en la parte central de la pantalla.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "boton_atras.png", CC_CALLBACK_1(Registrarse::returnGameMenu, this));
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);


	//////
	// Boton para ir a la pantalla de juego. 
	// El iniciarJuego lo hice solo por poner algo, hagale los cambios necesarios

	auto buttonAceptar = MenuItemImage::create("boton_aceptar.png", "boton_aceptar.png", CC_CALLBACK_1(Registrarse::iniciarJuego, this));
	buttonAceptar->setPosition(Point(visibleSize.width / 1.4 + buttonAtras->getContentSize().width*1.63f, origin.y + visibleSize.height * 0.40f));
	auto buttonJuego = Menu::create(buttonAceptar, NULL);
	buttonJuego->setPosition(Point::ZERO);
	this->addChild(buttonJuego, 2);




	
}


#include "HelloWorldScene.h"

void Registrarse::returnGameMenu(Ref* pSender)
{
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}


void Registrarse::iniciarJuego(Ref* pSender)
{
	
}