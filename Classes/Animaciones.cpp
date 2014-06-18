#include "Animaciones.h"

 USING_NS_CC;

 
void Animaciones::rotar(Node *child)
{
	RotateBy* rotar = RotateBy::create(2.5f, 220.0f, 220.0f);

	// Se usa para repetir la acción rotar por un número de veces ilimitado.
	auto repeatAnimation = RepeatForever::create(rotar);

	// Hace que la estrella realize la acción de rotar.
	child->runAction(repeatAnimation);

}

// Mover a la derecha un objeto del layer hasta un punto en especifico
void Animaciones::moverDerecha(cocos2d::Node *child, const Point& position)
{
	MoveTo* mover = MoveTo::create(2.5f, position);

	auto repeatAnimation = RepeatForever::create(mover);

	child->runAction(repeatAnimation);
}

// Mover a la izquierda un objeto del layer hasta un punto en especifico
void Animaciones::moverIzquierda(cocos2d::Node *child, const Point& position)
{	
	MoveTo* mover = MoveTo::create(2.5f,position);

	auto repeatAnimation = RepeatForever::create(mover);

	child->runAction(repeatAnimation);	
}

