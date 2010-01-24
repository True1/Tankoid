#include "LocalMap.h"

//Global map
class MapFriends::GlobalMap
{
	////this function should have access to private & protected values
	friend Field& MapFriends::LocalMap::getElementOnPosition(int globalX, int globalY);

private:

	//size
	int _globalX, _globalY;

	//mas of fields.
	Field** _globalMap;

public:
	//basic constructor
	GlobalMap();

	//constructor with size
	GlobalMap(int globalX, int globalY);

	//Destroys all data in class
	~GlobalMap();

	//get LocalMap(some kind of iterator) for this GlobalMap
	MapFriends::LocalMap& getLocalMap(int minX, int maxX, int minY, int maxY);
};