#include "GlobalMap.h"

GlobalMap::GlobalMap()
{
	_globalX = 0;
	_globalY = 0;
	_globalMap = 0;
};

GlobalMap::GlobalMap(int globaxX, int globalY)
{
};

GlobalMap::~GlobalMap()
{
	for(int i = 0; i < _globalX; i++)
	{
		delete[] _globalMap[i];
	}

	delete[] _globalMap;

	_globalX = 0;
	_globalY = 0;
};

LocalMap& GlobalMap::getLocalMap(int minX, int maxX, int minY, int maxY)
{
	LocalMap* localMap = new LocalMap();
	localMap->_renderMap = this;
	localMap->_maxX = maxX;
	localMap->_minY = minY;

	localMap->_minX = minX;
	localMap->_maxY = maxY;

	return *localMap;
}