#ifndef Animaciones_h
#define Animaciones_h

/**
* @brief clase para agregar animaciones.
*
*/

#include <cocos2d.h> /*!< Inclusion de cocos2d para poder utilizar sus metodos */

class Animaciones : public cocos2d::LabelTTF /*!< Hereda de Layer. */

{
public:

	/**
	* @brief metodo generar la rotación de un nodo hijo del layer.
	* @param Node*child, puntero que se señala al objeto que se quiere animar.
	* @return bool.
	*/
	void rotar(cocos2d::Node *child) const;

	/**
	* @brief metodo para mover un nodo hijo del layer.
	* @param Node*child, puntero que se señala al objeto que se quiere animar.
	* @return bool.
	*/
	void mover(cocos2d::Node *child, float duration, const cocos2d::Point& position) const;


	/// metodo para crear un label
	LabelTTF* tituloAnimado(const std::string& string, const std::string& fontName, float fontSize,
		const cocos2d::Size& dimensions = cocos2d::Size::ZERO, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::CENTER,
		cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);

};

#endif // Animaciones_h