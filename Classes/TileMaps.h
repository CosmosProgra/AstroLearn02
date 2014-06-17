#ifndef MAP_H
#define MAP_H

#include "cocos2d.h"

/**
@brief Clase base para todos los mapas del juego
*/

class TileMaps : public cocos2d::Layer
{
protected:
	cocos2d::TMXTiledMap* tileMap;
	cocos2d::TMXLayer* meta;
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* foreground1;
	cocos2d::TMXLayer* foreground2;
	cocos2d::TMXLayer* Rocas1;
	cocos2d::TMXLayer* Rocas2;
	cocos2d::TMXObjectGroup* objetos;
	cocos2d::Sprite* Player1;
	int IncrementX;
	int IncrementY;
protected:
	/**
	* @brief Posiciona el punto de vista en el juego.
	* Se encarga de determinar el punto optimo de posicion del mapa para evitar los espacios en negro,
	* tomando como referencia un elemento en el mapa,vista y tamano del mapa.
	* @param Elemento que se toma como referencia en el mapa para posicionar la vista
	*/
	virtual void setPointOfView(cocos2d::Point elemento);
	/**
	* @brief traduce el touch en la pantalla a la localizacion del un tile en el Mapa
	* @param position es la posicion de la pantalla que se quiere traducir a tiles
	* @return cocos2d::Point
	*/
	virtual cocos2d::Point tileCoordForPosition(cocos2d::Point position);
	/**
	* @brief Verifica las propiedades dle cuadro donde se hace touch
	* Se encarga de tomar las propiedades del tilemap y leerlas en el programa y retornar el resultado
	* @param Posicion del mapa a la cual se le quiere hacer el proceso
	* @param meta es la capa donde se guardan las propiedades del tileMap
	* @return string
	*/
	std::string metaCheck(cocos2d::Point posicion); \
		/**
		* @brief Coloca los Eventos y Listeners en el tileMap

		*
		*/
		virtual void setEventHandlers();
	/**
	* @brief Se encarga de cargar el archivo '.tmx' del mapa al programa,
	* junto con sus componentes
	* @param mapTmx la ruta donde se encuentra el archivo '.tmx' del mapa
	* @param bgLayerName el nombre del layer que se utiliza de background en el TileMap.
	* @param f1LayerName el nombre del primer layer sobre el background en el TileMap.
	* @param f2LayerName el nombre del segundo layer sobre el background en el TileMap.
	* @param metaLayerName el nombre del layer que se utiliza para las colisiones en el TileMap.
	* @param objectGroupName el nombre del layer que contiene los objetos del TileMap.
	*/
	virtual void loadMap(const std::string& mapTmx, const std::string& objectGroupName, const std::string& ambiente2, const std::string& ambiente1,
		const std::string& f1LayerName, const std::string& f2LayerName, const std::string& bgLayerName, const std::string& metaLayerName);
	/**
	* @brief Se encarga de cargar y posicionar el personaje
	* @param imagen ruta y nombre de la imagen que se va usar para el personaje
	*
	*/
	void createCharacter(std::string imagen);
	/**
	* @brief Determina que pasa con el jugador en la posicion a donde se quiere mover
	*
	*/
	void setPlayerPosition(cocos2d::Point position);

	/**
	* @brief Toma el tama;o del mapa actual y determina cuanto es lo apropiado que se mueva el pernaje del jugador
	*/
	void setIncrements();
	/**
	* @brief Determina a donde el jugador se quiere mover
	* @param placeToMove es el punto donde se toco la pantalla
	*/
	void movePlayer(cocos2d::Point placeToMove);
	void setEvents();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
};
#endif // MAP_H