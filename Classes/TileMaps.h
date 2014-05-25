#ifndef MAP_H
#define MAP_H

#include "cocos2d.h"

class TileMaps : public cocos2d::Layer
{
protected:
	cocos2d::TMXTiledMap* tileMap;
	cocos2d::TMXLayer* meta;
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* foreground1;
	cocos2d::TMXLayer* foreground2;
	cocos2d::TMXLayer* foreground3;
	cocos2d::TMXLayer* foreground4;
	cocos2d::TMXObjectGroup* objetos;
protected:
	/**
	* @brief Posiciona el punto de vista en el juego.
	* Se encarga de determinar el punto optimo de posicion del mapa para evitar los espacios en negro,
	* tomando como referencia un elemento en el mapa,vista y tamano del mapa.
	* @param Elemento que se toma como referencia en el mapa para posicionar la vista
	* @param tileMap es el tileMap en el que se esta trabajando actualmente.
	* @return cocos2d::Point
	*/
	virtual cocos2d::Point setPointOfView(cocos2d::Point elemento);
	/**
	* @brief traduce el touch en la pantalla a la localizacion del un tile en el Mapa
	* @param position es la posicion de la pantalla que se quiere traducir a tiles
	* @param tileMap es el tileMap en el que se esta trabajando actualmente
	* @return cocos2d::Point
	*/
	virtual cocos2d::Point tileCoordForPosition(cocos2d::Point position);
	/**
	* @brief Verifica las propiedades dle cuadro donde se hace touch
	* Se encarga de tomar las propiedades del tilemap y leerlas en el programa y retornar el resultado
	* @param Posicion del mapa a la cual se le quiere hacer el proceso
	* @param tileMap es el tileMap en el que se esta trabajando actualmente
	* @param meta es  la capa donde se guardan las propiedades del tileMap
	* @return string
	*/
	std::string metaCheck(cocos2d::Point posicion); \
		/**
		* @brief Coloca los Eventos y Listeners en el tileMap
		* @param tileMap es el tileMap en el que se esta trabajando actualmente
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
	virtual void loadMap(const std::string& mapTmx, const std::string& bgLayerName, const std::string& f1LayerName
		, const std::string& f2LayerName, const std::string& f3LayerName
		, const std::string& f4LayerName, const std::string& metaLayerName
		, const std::string& objectGroupName);
};

#endif // MAP_H