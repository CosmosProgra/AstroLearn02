#include "Ingresar.h" /*!< Inclusion de la biblioteca Ingresar.h */
#include <SimpleAudioEngine.h> /*!< Se incluye la biblioteca para poder colocar sonido de fondo */ 

USING_NS_CC; /*!< Se incluye el espacio de nombres de cocos */ 

/// M�todo para crear la escena de la pantalla para ingresar.
/// Retorna una escena

Scene* Ingresar::createScene()
{
	// Se crea el objeto 'scene' que es donde ocurrir�n las interraciones de los elementos.
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

	/// Crear el fondo que lleva la pantalla para que usuario pueda acceder.
	auto sprite = Sprite::create("iniciarsesion.jpg");

	/// posiciona la imagen en el centro de la pantalla.
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	/// agrega la imagen a la pantalla en la capa m�s profunda.
	this->addChild(sprite, 0);

	/// Se llama al m�todo "createMenu" para construir los botones que enlazan las pantallas.
	createMenu();

	/// Se utiliza para reproducir la m�sica en ese momento.
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion2.mp3", true);

	/// devuelve verdadero cuando el met�do se logro completar.
	return true;
}

/// Metodo que coloca los botones en pantalla y les proporciona funcionalidad
void Ingresar::createMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/// Se crea el bot�n 'buttonAtras', para regresar a la pantalla del men�. 
	/// Se coloca las imaganes para que el bot�n tenga una ilustraci�n, adem�s, hacer que se vea interactivo
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "botonatras_down.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	
	/// Se le da posici�n al bot�n en la esquina inferior izquierda de la pantalla.
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));	auto buttonAwardsMenu = Menu::create(buttonAtras, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);

	/// Se agrega al bot�n atras
	this->addChild(buttonAwardsMenu, 2);

	/// Crea 'buttonAceptar' para poder continuar con la pantalla que contiene los niveles.
	/// Coloca la imagenes para que el bot�n 'Aceptar' se vea interactivo.
	auto buttonAceptar = MenuItemImage::create("boton_aceptar.png", "botonaceptar_down.png", CC_CALLBACK_1(Ingresar::levels, this));
	
	/// Se le da posici�n el bot�n 'Atras' cerca del centro de la pantalla
	buttonAceptar->setPosition(Point(visibleSize.width / 2 + buttonAtras->getContentSize().width*1.2f, origin.y + visibleSize.height * 0.45f));
	
	/// Se crea el bot�n
	auto buttonNextPage = Menu::create(buttonAceptar, NULL);
	buttonNextPage->setPosition(Point::ZERO);

	/// Se agrega a la capa correspondiente de la pantalla.
	this->addChild(buttonNextPage, 2);

}

#include "HelloWorldScene.h" /*!< Inclusion de la biblioteca HelloWorldScene.h */
#include "Ingresar.h" /*!< Inclusion de la biblioteca Ingresar.h */

void Ingresar::returnGameMenu(Ref* pSender)
{
	/// Crea la escena de la pantalla principal
	auto newScene = HelloWorld::createScene();

	/// Remplaza la pantalla actual por la principal, mediante una transici�n
	Director::getInstance()->replaceScene(CCTransitionMoveInR::create(0.75f, newScene));
}

void Ingresar::levels(Ref* pSender)
{
	/// M�todo para dirigir a la pantalla que contiene los niveles.
}