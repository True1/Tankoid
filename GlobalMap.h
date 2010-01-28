#include "Field.h"
#include "MapFriends.h"

//Global map
class MapFriends::GlobalMap
{
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
	//@Warinng : Uses LocalMap can change _worldMap field.
	MapFriends::LocalMap& getLocalMap(int minX, int maxX, int minY, int maxY);
	
	//returns map size
	int getWorldX();
	int getWorldY();
	
	//get field 'type'
	int getFieldType(int posX, int posY);
};