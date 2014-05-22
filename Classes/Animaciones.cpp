#include "Animaciones.h"

 USING_NS_CC;

void Animaciones::rotar(Node *child)
{
	/// Crea un movimiento rotativo
	RotateBy* rotar = RotateBy::create(2.5f, 220.0f, 220.0f);

	/// Se usa para repetir la acción rotar por un número de veces ilimitado.
	auto repeatAnimation = RepeatForever::create(rotar);

	/// Hace que la estrella realize la acción de rotar.
	child->runAction(repeatAnimation);

}

void Animaciones::moverDerecha(cocos2d::Node *child, const Point& position)
{


	MoveTo* mover = MoveTo::create(2.5f, position);

	auto repeatAnimation = RepeatForever::create(mover);


	child->runAction(repeatAnimation);


}


void Animaciones::moverIzquierda(cocos2d::Node *child, const Point& position)
{
	

	MoveTo* mover = MoveTo::create(2.5f,position);

	auto repeatAnimation = RepeatForever::create(mover);

	child->runAction(repeatAnimation);
	

}


Animaciones* Animaciones::display(const std::string& string, const std::string& fontName, float fontSize,
	const Size &dimensions, TextHAlignment hAlignment,
	TextVAlignment vAlignment)
{
	Animaciones *ret = new Animaciones();
	if (ret && ret->initWithString(string, fontName, fontSize, dimensions, hAlignment, vAlignment))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}