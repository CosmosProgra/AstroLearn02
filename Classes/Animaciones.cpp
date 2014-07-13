#include "Animaciones.h"

USING_NS_CC;


void Animaciones::rotar(Node *child) const
{
	RotateBy* rotar = RotateBy::create(2.5f, 220.0f, 220.0f);

	// Se usa para repetir la acción rotar por un número de veces ilimitado.
	auto repeatAnimation = RepeatForever::create(rotar);

	// Hace que la estrella realize la acción de rotar.
	child->runAction(repeatAnimation);

}

void Animaciones::mover(cocos2d::Node *child, float duration, const Point& position) const
{
	MoveTo* mover = MoveTo::create(duration, position);

	child->runAction(mover);

}

LabelTTF* Animaciones::tituloAnimado(const std::string& string, const std::string& fontName, float fontSize,
	const Size &dimensions, TextHAlignment hAlignment,
	TextVAlignment vAlignment)
{
	LabelTTF* titulo = LabelTTF::create(string,fontName,fontSize,dimensions,hAlignment,vAlignment);

	int inicio = rand() % 256;
	int final = rand() % 256;
	titulo->setColor(Color3B(inicio, (inicio + final), final));

	int azar = rand() % 3;
	int size = rand() % int(fontSize) + azar;
	titulo->setFontSize(size);

	return titulo;
}




