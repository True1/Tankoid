#include "Field.h"
#include "MapFriends.h"

//represents one screen. Part of GlobalMap.
//some kind of iterator for GlobalMap
class MapFriends::LocalMap
{
	//Class GlobalMap creates LocalMap. Its the only one way to get valid LocalMap
	friend MapFriends::GlobalMap;

private:

	//Pointer to global map
	MapFriends::GlobalMap* _renderMap;

	//Global position of viewing textures - rectangle
	int _minX, _minY, _maxX, _maxY;

protected:

	//gets Field element on position.
	//can access private & protected values of GlobalMap
	Field& getElementOnPosition(int globalX, int globalY);

public:

	//basic constructor. To create valid LocalMap use method GlobalMap.getLocalMap 
	LocalMap();

	//note: You don't need to destroy GLobalMapObject
	~LocalMap();

	//draws all map elements in the screen
	void draw();
};