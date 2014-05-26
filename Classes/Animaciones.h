#ifndef Animaciones_h
#define Animaciones_h

///Clase para utilizar animaciones

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

class Animaciones : public cocos2d::LabelTTF /*!< Hereda de Layer. */

{
public:

	static void rotar(cocos2d::Node *child);

	static void moverDerecha(cocos2d::Node *child, const cocos2d::Point& position);
	
	static void moverIzquierda(cocos2d::Node *child, const cocos2d::Point& position);


	static Animaciones * display(const std::string& string, const std::string& fontName, float fontSize,
		const cocos2d::Size& dimensions = cocos2d::Size::ZERO, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::CENTER,
		cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);

};

#endif // Animaciones_h