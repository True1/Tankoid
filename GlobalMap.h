#include "Field.h"
#include "MapFriends.h"

//Global map
class MapFriends::GlobalMap
{
	//iterator is a friend
	friend MapFriends::LocalMap;

private:
	//size
	int _worldX, _worldY;

	//mas of fields.
	Field** _worldMap;

public:
	//basic constructor
	GlobalMap();

	//constructor with size
	GlobalMap(int worldX, int worldY);

	//Destroys all data in class
	~GlobalMap();

	//get LocalMap(some kind of iterator) for this GlobalMap. 
	MapFriends::LocalMap& getLocalMap(int width, int height);
	
	//returns map size
	int getWorldX();
	int getWorldY();
};