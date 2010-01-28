#include "LocalMap.h"

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

void MapFriends::LocalMap::draw()
{

};