#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h> /*!< Se incluye la biblioteca para poder colocar sonido de fondo */ 

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 

/// Definicion del metodo de crear escena de HelloWorld
/// El metodo retorna un objeto tipo scene
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create(); /*!< Se crea la escena */ 
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create(); /*!< Se crea la capa */ 

    // add layer as a child to scene
    scene->addChild(layer); /*!< Se agrega a la escena la capa que va a contener los elementos en pantalla */ 

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
	///Este codigo coloca en pantalla un boton para cerrar la ventana
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)); /*!< Se llama al metodo que cierra el programa */ 
    
	///Se coloca en pantalla el boton para cerrar el programa
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

   
    // add "HelloWorld" splash screen"
	///Aqui se coloca un sprite que contiene la imagen de fondo de la pantalla
    auto sprite = Sprite::create("Fondos/principal.jpg");

    // position the sprite on the center of the screen
	///Se coloca el sprite (imagen de fondo) en pantalla
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
	///Se agrega el sprite a la capa que va a contener todos los elementos en pantalla, esto lo hara visible
    this->addChild(sprite, 0);
	createGameMenu();

	/// crea la imagen de la estrella
	auto estrella = Sprite::create("Estrella.png");

	/// Establece la posición de la estrella en la pantalla.
	estrella->setPosition(Point(visibleSize.width * 0.16f , origin.y + visibleSize.height * 0.44f));

	///Agrega la estrella
	this->addChild(estrella, 1);

	animateSprite(estrella);


	auto label = LabelTTF::create("CatchMe", "fonts/led_display-7.ttf", 7);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width,
		origin.y + visibleSize.height / 2));

	this->addChild(label, 1);



	// Reproducir la musica del menu principal
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/Thrust Sequence_0.mp3", true);
    return true;
}


LabelTTF HelloWorld::display(const std::string& filename, std::string nombre)

{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

    auto label = LabelTTF::create(nombre, filename , 72);

	// position the label on the center of the screen
	label->setPosition(Point(origin.x + visibleSize.width,
							origin.y + visibleSize.height/2));

	this-> addChild(label,1);

	MoveTo* mover = MoveTo::create(2.5f, Point(origin.x, visibleSize.height/2 + origin.y) );

	auto repeatAnimation = RepeatForever::create(mover);

	label->runAction(repeatAnimation);

}


void HelloWorld::animate(Node *child) 
{
	/// Crea un movimiento rotativo
	RotateBy* rotar = RotateBy::create(2.5f, 220.0f, 220.0f);
	
	/// Se usa para repetir la acción rotar por un número de veces ilimitado.
	auto repeatAnimation = RepeatForever::create(rotar);

	/// Hace que la estrella realize la acción de rotar.
	child->runAction(repeatAnimation);

}

///Metodo que coloca los botones del metodo en pantalla y les proporciona funcionalidad
void HelloWorld::createGameMenu()
{
	//Se obtienen las medidas de la pantalla
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Creación del boton ingresar
	///Se coloca la imagen que llevara el boton cuando este y cuando no este oprimido, ademas del metodo que sera invocado cuando el boton sea presionado, el cual llama a la pantalla iniciarsesion
	auto buttoningresar = MenuItemImage::create("botones/jugar.png", "botones/jugar_dpwn.png", CC_CALLBACK_1(HelloWorld::Iniciarsesion, this));
	///Se le da posicion en pantalla al boton ingresar
	buttoningresar->setPosition(Point(visibleSize.width / 2, origin.y + visibleSize.height * 0.33f));
	//Se crea el boton
	auto buttonStartMenu = Menu::create(buttoningresar, NULL);
	buttonStartMenu->setPosition(Point::ZERO);
	///Se agrega el boton a la capa en la cual se mostrara
	this->addChild(buttonStartMenu, 2);
}

#include "Ingresar.h" /*!< Inclusion de la biblioteca Ingresar.h */ //Original
#include "Login.h" /*!< Inclusion de la biblioteca Ingresar.h */
#include "MercuryScene.h"
///Metodo que invoca el boton ingresar, abre una nueva pantalla
void HelloWorld::Iniciarsesion(Ref* pSender)
{
	///Crea la escena de ingresar
//	auto newScene = Ingresar::createScene(); 
	auto newScene = Login::createScene(); 
	///Reemplaza la escena actual por la escena de Ingresar
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}


///Metodo que termina la ejecucion del programa
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
