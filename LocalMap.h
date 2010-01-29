#include "GlobalMap.h"

//represents one screen. Part of GlobalMap.
//some kind of iterator for GlobalMap
class MapFriends::LocalMap
{
	//Class GlobalMap creates LocalMap. Its the only one way to get valid LocalMap
	friend MapFriends::LocalMap& MapFriends::GlobalMap::getLocalMap(int minX, int maxX, int minY, int maxY);

private:

	//Pointer to global map
	GlobalMap* _renderMap;

	//Global position of viewing textures - rectangle
	int _minX, _minY, _maxX, _maxY;
	
public:

	//basic constructor. To create valid LocalMap use method GlobalMap.getLocalMap 
	LocalMap();

	//note: You don't need to destroy GLobalMap object
	~LocalMap();

	//@WILL DE MOVED TO ANOTHER CLASS
	//draws all map elements in the screen
	//void draw(unsigned int width, unsigned int height);
};