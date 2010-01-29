#include <SFML/Graphics.hpp>

#include "GlobalMap.h"

//represents one screen. Part of GlobalMap.
//some kind of iterator for GlobalMap
class MapFriends::LocalMap
{
	//Class GlobalMap creates LocalMap. Its the only one way to get valid LocalMap
	friend MapFriends::LocalMap& MapFriends::GlobalMap::getLocalMap(int width, int height);

private:

	//Pointer to global map
	GlobalMap* _renderMap;

	//Global position of viewing textures
	int _beginX, _beginY;

	//How many textures will be drawn (processing on the window resolution
	int _viewWidth, _viewHeight;
	
public:

	//basic constructor. To create valid LocalMap use method GlobalMap.getLocalMap 
	LocalMap();

	//note: You don't need to destroy GLobalMap object
	~LocalMap();

	int getFieldType(int posX, int posY);

	//@WILL DE MOVED TO ANOTHER CLASS
	//draws all map elements in the screen
	//void draw(unsigned int width, unsigned int height);
};