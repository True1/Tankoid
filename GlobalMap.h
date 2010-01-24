#include "LocalMap.h"

class GlobalMap
{
	friend Field& LocalMap::getElementOnPosition(int globalX, int globalY);

private:
	int _globalX, _globalY;
	Field** _globalMap;

protected:

public:
	GlobalMap();
	GlobalMap(int globaxX, int globalY);

	~GlobalMap();

	LocalMap& getLocalMap(int minX, int maxX, int minY, int maxY);
};