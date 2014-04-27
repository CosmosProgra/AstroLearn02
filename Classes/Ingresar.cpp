#include "Ingresar.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;

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

	// Crear el fondo que lleva el menú del juego.
	auto sprite = Sprite::create("iniciarsesion.jpg");

	// posiciona la imagen en el centro de la pantalla.
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// agrega la imagen a la pantalla en la capa más profunda.
	this->addChild(sprite, 0);

	//Se llama al método "createMenu" para construir los botones que enlazan las pantallas.
	createMenu();

	// se utiliza para reproducir la música en ese momento.
	auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
	sound->stopBackgroundMusic();
	sound->playBackgroundMusic("Music/cancion2.mp3", true);

	// devuelve verdadero cuando ya han sido creados los elementos necesarios.
	return true;
}

void Ingresar::createMenu()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// Se crea el botón 'buttonAtras', para regresar a la pantalla del menú. Esta posicionado cerca del centro.
	auto buttonAtras = MenuItemImage::create("boton_atras.png", "botonatras_down.png", CC_CALLBACK_1(Ingresar::returnGameMenu, this));
	buttonAtras->setPosition(Point(visibleSize.width / 14.5, origin.y + visibleSize.height * 0.06f));	auto buttonAwardsMenu = Menu::create(buttonAtras, NULL);
	buttonAwardsMenu->setPosition(Point::ZERO);
	this->addChild(buttonAwardsMenu, 2);

	// Crea 'buttonAceptar' para poder continuar con la pantalla que contiene los niveles.
	auto buttonAceptar = MenuItemImage::create("boton_aceptar.png", "botonaceptar_down.png", CC_CALLBACK_1(Ingresar::levels, this));
	buttonAceptar->setPosition(Point(visibleSize.width / 2 + buttonAtras->getContentSize().width*1.2f, origin.y + visibleSize.height * 0.45f));
	auto buttonHomeMenu = Menu::create(buttonAceptar, NULL);
	buttonHomeMenu->setPosition(Point::ZERO);
	this->addChild(buttonHomeMenu, 2);

}

#include "HelloWorldScene.h"
#include "Ingresar.h"

void Ingresar::returnGameMenu(Ref* pSender)
{
	// Se dirige a la escena que contiene la pantalla principal. 
	auto newScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(CCTransitionMoveInR::create(0.75f, newScene));
}

void Ingresar::levels(Ref* pSender)
{

}