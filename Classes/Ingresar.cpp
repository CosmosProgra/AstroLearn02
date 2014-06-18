#include "Ingresar.h" /*!< Inclusion de la biblioteca Ingresar.h */
#include <SimpleAudioEngine.h> /*!< Se incluye la biblioteca para poder colocar sonido de fondo */ 

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 

// Metodo para crear la escena de la pantalla para ingresar.
// Retorna una escena
// Contiene los botones para ir a la pantalla principal y a la que posee los niveles.

Scene* Ingresar::createScene()
{
	// Se crea el objeto 'scene' que es donde ocurrirán las interraciones de los elementos.
	auto scene = Scene::create();

	// Se crea el objeto 'layer' para poder acomodar los elementos en capas y que sean visibles.
	auto layer = Ingresar::create();

	// Agrega el 'layer' a la escena.
	scene->addChild(layer);

	// Devuelve el objeto escena.
	return scene;
}

// on "init" you need to initialize your instance
bool Ingresar::init()
{
	// Si el 'layer' no ha sido creado, retorna falso.
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Crea el fondo que lleva la pantalla para que usuario pueda acceder.
	auto sprite = Sprite::create("Fondos/jugar.jpg");

	// Posiciona la imagen en el centro de la pantalla.
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// Agrega la imagen a la pantalla en la capa mas profunda.
	this->addChild(sprite, 0);

	// Se llama al metodo "createMenu" para construir los botones que enlazan las pantallas.
	createMenu();

	// Se utiliza para reproducir la musica en ese momento.
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion2.mp3", true);

	// Devuelve verdadero cuando el metodo se logro completar.
	return true;
}

// Metodo que coloca los botones en pantalla y les proporciona funcionalidad
void Ingresar::createMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Se crea el boton 'buttonAtras', para regresar a la pantalla del menu. 
	// Se coloca las imaganes para que el botón tenga una ilustracion, ademas, hacer que se vea interactivo
	auto buttonAtras = MenuItemImage::create("botones/boton_atras.png", "botones/botonatras_down.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	
	// Se le da posicion al boton en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));	auto buttonAwardsMenu = Menu::create(buttonAtras, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);

	// Se agrega al boton atras
	this->addChild(buttonAwardsMenu, 2);

	// Crea 'buttonAceptar' para poder continuar con la pantalla que contiene los niveles.
	// Coloca la imagenes para que el boton 'Aceptar' se vea interactivo.
	auto buttonAceptar = MenuItemImage::create("botones/avatar.png", "botones/avatar_down.png", CC_CALLBACK_1(Ingresar::registrar, this));
	
	// Se le da posicion el botón 'Atras' cerca del centro de la pantalla
	buttonAceptar->setPosition(Point(visibleSize.width / 2 + buttonAtras->getContentSize().width*3.0f, origin.y + visibleSize.height * 0.62f));
	
	// Se crea el boton
	auto buttonNextPage = Menu::create(buttonAceptar, NULL);
	buttonNextPage->setPosition(Point::ZERO);

	// Se agrega a la capa correspondiente de la pantalla.
	this->addChild(buttonNextPage, 2);


	//Ejemplo donde luego ira el personaje
	// Se crea el boton 'personaje'
	// Se coloca las imagenes para que el botón tenga una ilustracion, ademas, hacer que se vea interactivo
	auto button = MenuItemImage::create("estrella.png", "estrella.png", CC_CALLBACK_1(Ingresar::login, this));
	// Se le da posicion al boton 
	button->setPosition(Point(visibleSize.width / 3.0, origin.y + visibleSize.height * 0.6f));	
	auto buttonnivel = Menu::create(button, NULL);
	buttonnivel->setPosition(Point::ZERO);
	this->addChild(buttonnivel, 2);

}

#include "HelloWorldScene.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */

void Ingresar::returnGameMenu(Ref* pSender)
{
	// Crea la escena de la pantalla principal
	auto newScene = HelloWorld::createScene();

	// Remplaza la pantalla actual por la principal, mediante una transicion
	Director::getInstance()->replaceScene(CCTransitionMoveInR::create(0.75f, newScene));
}

#include "Login.h"
void Ingresar::login(Ref* pSender)
{
	//Crea la escena de iniciar sesion (Login)
	auto newScene = Login::createScene(); 
	//Reemplaza la escena actual por la escena de Login
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	
}

#include "Registrarse.h"
// Metodo para dirigir a la pantalla que contiene el registro
void Ingresar::registrar(Ref* pSender)
{
	//Crea la escena de Registrarse
	auto newScene = Registrarse::createScene();
	//Reemplaza la escena actual por la escena de Registrarse
	Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.75f, newScene));
	
}