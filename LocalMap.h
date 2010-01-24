#include "Field.h"

class GlobalMap;

class LocalMap
{
	friend GlobalMap;

private:
	GlobalMap* _renderMap;
	int _minX, _minY, _maxX, _maxY;

protected:
	Field& getElementOnPosition(int globalX, int globalY);

public:
	LocalMap();

	~LocalMap();

	void draw();
};