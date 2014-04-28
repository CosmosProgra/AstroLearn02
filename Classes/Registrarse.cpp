#include "Registrarse.h"
#include <SimpleAudioEngine.h>

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 
 
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



    /// Crea el fondo de la pantalla del menu "Registrarse" del juego
    auto sprite = Sprite::create("registrarse.jpg");

    /// Posiciona el sprite (fondo de pantalla) para que quede centralizado en la pantalla
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    /// Hace visible el fondo de pantalla
    this->addChild(sprite, 0);
	
	createMenu();
    
	/// Se utiliza para reproducir la musica cuando se cambia a esta pantalla (registrarse).
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

    return true;
}

void Registrarse::createMenu()
{

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	
	/// Se crea el boton (buttonAtras) para retroceder al menu principal.	
	
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "botonatras_down.png", CC_CALLBACK_1(Registrarse::returnGameMenu, this));
	
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));

	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);

	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);
	


	/// Se crea el boton aceptar (buttonAceptar) para continuar a la pantalla de juego.

	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "iniciarJuego" el cual le da la funcionalidad al botón una vez sea implementado.
	auto buttonAceptar = MenuItemImage::create("boton_aceptar.png", "botonaceptar_down.png", CC_CALLBACK_1(Registrarse::iniciarJuego, this));
	
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAceptar->setPosition(Point(visibleSize.width / 1.4 + buttonAtras->getContentSize().width*1.63f, origin.y + visibleSize.height * 0.40f));
	
	/// Crea el botón
	auto buttonJuego = Menu::create(buttonAceptar, NULL);
	buttonJuego->setPosition(Point::ZERO);

	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonJuego, 2);	
}


#include "HelloWorldScene.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */

/// Metodo que es invocado al ser presionado el boton atras.
void Registrarse::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = HelloWorld::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}


/// Metodo para cambiar la pantalla por la del juego.
void Registrarse::iniciarJuego(Ref* pSender)
{

}