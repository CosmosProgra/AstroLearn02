#include "Niveles.h"
#include <SimpleAudioEngine.h>

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 
 
Scene* Niveles::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Niveles::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Niveles::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /// Crea el fondo de la pantalla de selección de niveles (Sistema Solar)
    auto sprite = Sprite::create("Fondos/sistemasolar.jpg");

    /// Posiciona el sprite (fondo de pantalla) para que quede centralizado en la pantalla
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    /// Hace visible el fondo de pantalla
    this->addChild(sprite, 0);
	
	createMenu();
    
	/// Se utiliza para reproducir la musica cuando se cambia a esta pantalla (niveles).
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion4.mp3", true);

    return true;
}

void Niveles::createMenu()
{

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	
	/// Se crea el boton (buttonAtras) para retroceder al menu principal.	
	
	/// Se utilizan imagenes, las cuales son diferentes, para darle efecto cuando el botón es presionado.
	/// Se hace el llamado al metodo "returnGameMenu" el cual le da la funcionalidad al botón.
	auto buttonAtras = MenuItemImage::create("botones/boton_atras.png", "botones/botonatras_down.png", CC_CALLBACK_1(Niveles::returnGameMenu, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));
	/// Crea el botón
	auto buttonHomeMenu = Menu::create(buttonAtras, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(buttonHomeMenu, 2);


	/////// Botones de los planetas

	//// Mercurio

	auto buttonMercurio = MenuItemImage::create("botones/planetas/originales/mercurio.png", "botones/planetas/pequenos/mercurio.png", CC_CALLBACK_1(Niveles::Mercurio, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonMercurio->setPosition(Point(visibleSize.width / 4.8, origin.y + visibleSize.height * 0.32f));
	/// Crea el botón
	auto mercury = Menu::create(buttonMercurio, NULL);
	mercury->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(mercury, 2);


	//// Venus

	auto buttonVenus = MenuItemImage::create("botones/planetas/originales/venus.png", "botones/planetas/pequenos/venus.png", CC_CALLBACK_1(Niveles::Venus, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonVenus->setPosition(Point(visibleSize.width / 3.60, origin.y + visibleSize.height * 0.38f));
	/// Crea el botón
	auto Venus = Menu::create(buttonVenus, NULL);
	Venus->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(Venus, 2);


	//// Tierra

	auto buttonTierra = MenuItemImage::create("botones/planetas/originales/tierra.png", "botones/planetas/pequenos/tierra.png", CC_CALLBACK_1(Niveles::Tierra, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonTierra->setPosition(Point(visibleSize.width / 2.65, origin.y + visibleSize.height * 0.44f));
	/// Crea el botón
	auto Earth = Menu::create(buttonTierra, NULL);
	Earth->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(Earth, 2);


	//// Marte

	auto buttonMarte = MenuItemImage::create("botones/planetas/originales/marte.png", "botones/planetas/pequenos/marte.png", CC_CALLBACK_1(Niveles::Marte, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonMarte->setPosition(Point(visibleSize.width / 2.18, origin.y + visibleSize.height * 0.50f));
	/// Crea el botón
	auto Mars = Menu::create(buttonMarte, NULL);
	Mars->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(Mars, 2);


	//// Jupiter

	auto buttonJupiter = MenuItemImage::create("botones/planetas/originales/jupiter.png", "botones/planetas/pequenos/jupiter.png", CC_CALLBACK_1(Niveles::Jupiter, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonJupiter->setPosition(Point(visibleSize.width / 1.80, origin.y + visibleSize.height * 0.60f));
	/// Crea el botón
	auto Jupiter = Menu::create(buttonJupiter, NULL);
	Jupiter->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	this->addChild(Jupiter, 2);


	//// Saturno

	auto buttonSaturno = MenuItemImage::create("botones/planetas/originales/saturno.png", "botones/planetas/pequenos/saturno.png", CC_CALLBACK_1(Niveles::Saturno, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonSaturno->setPosition(Point(visibleSize.width / 1.36, origin.y + visibleSize.height * 0.68f));
	/// Crea el botón
	auto Saturn = Menu::create(buttonSaturno, NULL);
	Saturn->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	// La capa es 1 para que el sprite de Saturno quede detrás del de Jupiter
	this->addChild(Saturn, 1);

	
	//// Urano

	auto buttonUrano = MenuItemImage::create("botones/planetas/originales/urano.png", "botones/planetas/pequenos/urano.png", CC_CALLBACK_1(Niveles::Urano, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonUrano->setPosition(Point(visibleSize.width / 1.16, origin.y + visibleSize.height * 0.77f));
	/// Crea el botón
	auto Uranus = Menu::create(buttonUrano, NULL);
	Uranus->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	// La capa es 1 para que el sprite de Saturno quede detrás del de Jupiter
	this->addChild(Uranus, 0);

	
	//// Neptuno

	auto buttonNeptuno = MenuItemImage::create("botones/planetas/originales/neptuno.png", "botones/planetas/pequenos/neptuno.png", CC_CALLBACK_1(Niveles::Urano, this));
	/// Posiciona el boton en la esquina inferior izquierda de la pantalla.
	buttonNeptuno->setPosition(Point(visibleSize.width / 1.06, origin.y + visibleSize.height * 0.81f));
	/// Crea el botón
	auto Neptune = Menu::create(buttonNeptuno, NULL);
	Neptune->setPosition(Point::ZERO);
	/// Agrega el boton atras en la pantalla.
	// La capa es 1 para que el sprite de Saturno quede detrás del de Jupiter
	this->addChild(Neptune, 0);


}


/////////Listado de planetas

////Mercurio

#include "MercuryScene.h"
void Niveles::Mercurio(Ref* pSender)
{
	///Crea la escena de Mercurio
	auto newScene = MercuryScene::createScene();
	///Reemplaza la escena actual por la escena de Mercurio
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
}


////Venus

#include "VenusScene.h"
void Niveles::Venus(Ref* pSender)
{

	
	///Crea la escena de Venus
	auto newScene = VenusScene::createScene();
	///Reemplaza la escena actual por la escena de Venus
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	
	
}


////Tierra

//#include "TierraScene.h"
void Niveles::Tierra(Ref* pSender)
{

	/*
	///Crea la escena de la Tierra
	auto newScene = TierraScene::createScene();
	///Reemplaza la escena actual por la escena de Tierra
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}


////Marte

//#include "MarteScene.h"
void Niveles::Marte(Ref* pSender)
{

	/*
	///Crea la escena de Marte
	auto newScene = MarteScene::createScene();
	///Reemplaza la escena actual por la escena de Marte
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}


////Jupiter

//#include "JupiterScene.h"
void Niveles::Jupiter(Ref* pSender)
{

	/*
	///Crea la escena de Jupiter
	auto newScene = JupiterScene::createScene();
	///Reemplaza la escena actual por la escena de Jupiter
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}


////Saturno

//#include "SaturnoScene.h"
void Niveles::Saturno(Ref* pSender)
{

	/*
	///Crea la escena de Saturno
	auto newScene = SaturnoScene::createScene();
	///Reemplaza la escena actual por la escena de Saturno
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}


////Urano

//#include "UranoScene.h"
void Niveles::Urano(Ref* pSender)
{

	/*
	///Crea la escena de Urano
	auto newScene = UranoScene::createScene();
	///Reemplaza la escena actual por la escena de Urano
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}


////Neptuno

//#include "NeptunoScene.h"
void Niveles::Neptuno(Ref* pSender)
{

	/*
	///Crea la escena de Neptuno
	auto newScene = NeptunoScene::createScene();
	///Reemplaza la escena actual por la escena de Neptuno
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	*/

}





#include "HelloWorldScene.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */
/// Metodo que es invocado al ser presionado el boton atras.
void Niveles::returnGameMenu(Ref* pSender)
{

	/// Crea la escena del menu principal
	auto newScene = HelloWorld::createScene();
	/// Reemplaza la escena actual por la del menu principal. Tambien se le asigna una animación a la transcición de pantalla.
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.75f, newScene));
}
