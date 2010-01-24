#include "GlobalMap.h"

MapFriends::GlobalMap::GlobalMap()
{
	_globalX = 0;
	_globalY = 0;
	_globalMap = 0;
};

MapFriends::GlobalMap::GlobalMap(int globalX, int globalY)
{
	_globalX = globalX;
	_globalY = globalY;

	_globalMap = new Field*[_globalX];

	for(int i = 0; i < globalX; i++)
	{
		_globalMap[i] = new Field[_globalY];
	}
};

MapFriends::GlobalMap::~GlobalMap()
{
	for(int i = 0; i < _globalX; i++)
	{
		delete[] _globalMap[i];
	}

	delete[] _globalMap;

	_globalX = 0;
	_globalY = 0;
};

MapFriends::LocalMap& MapFriends::GlobalMap::getLocalMap(int minX, int maxX, int minY, int maxY)
{
	LocalMap* localMap = new LocalMap();
	localMap->_renderMap = this;
	localMap->_maxX = maxX;
	localMap->_minY = minY;

	localMap->_minX = minX;
	localMap->_maxY = maxY;

	return *localMap;
}