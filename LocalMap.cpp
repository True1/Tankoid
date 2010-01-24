#include "GlobalMap.h"

MapFriends::LocalMap::LocalMap()
{
	_renderMap = 0;
	_minX = _minY = _maxX = _maxY = 0;
};

MapFriends::LocalMap::~LocalMap()
{
	_renderMap = 0;
	_minX = _minY = _maxX = _maxY = 0;
};

Field& MapFriends::LocalMap::getElementOnPosition(int globalX, int globalY)
{
	return _renderMap->_globalMap[globalX][globalY];
};

void MapFriends::LocalMap::draw()
{
};