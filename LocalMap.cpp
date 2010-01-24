#include "GlobalMap.h"

LocalMap::LocalMap()
{
	_renderMap = 0;
	_minX = _minY = _maxX = _maxY = 0;
};

LocalMap::~LocalMap()
{
	_renderMap = 0;
	_minX = _minY = _maxX = _maxY = 0;
};

Field& LocalMap::getElementOnPosition(int globalX, int globalY)
{
	return _renderMap->_globalMap[globalX][globalY];
};

void LocalMap::draw()
{
};