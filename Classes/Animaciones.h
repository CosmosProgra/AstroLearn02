#ifndef Animaciones_h
#define Animaciones_h

/**
* @brief clase para agregar animaciones.
*
*/

#include "cocos2d.h" /*!< Inclusion de cocos2d para poder utilizar sus metodos */

class Animaciones : public cocos2d::LabelTTF /*!< Hereda de Layer. */

{
public:

	/**
	* @brief metodo generar la rotación de un nodo hijo del layer.
	* @param Node*child, puntero que se señala al objeto que se quiere animar.
	* @return bool.
	*/
	static void rotar(cocos2d::Node *child);

	/**
	* @brief metodo para mover a la derecha un objeto añadido como un nodo hijo.
	* @param Node*child, puntero que se señala al objeto que se quiere animar.
	* @param const cocos2d::Point& position indica el punto en el layer donde se quiere llegar.
	*/
	static void moverDerecha(cocos2d::Node *child, const cocos2d::Point& position);
	
	/**
	* @brief metodo para mover a la izquierda un objeto añadido como un nodo hijo.
	* @param Node*child, puntero que se señala al objeto que se quiere animar.
	* @param const cocos2d::Point& position indica el punto en el layer donde se quiere llegar.
	*/
	static void moverIzquierda(cocos2d::Node *child, const cocos2d::Point& position);


};

#endif // Animaciones_h