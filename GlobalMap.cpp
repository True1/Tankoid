#include "LocalMap.h"

MapFriends::GlobalMap::GlobalMap()
{
	_worldX = 0;
	_worldY = 0;
	_worldMap = 0;
};

MapFriends::GlobalMap::GlobalMap(int worldX, int worldY)
{
	_worldX = worldX;
	_worldY = worldY;

	_worldMap = new Field*[_worldX];

	for(int i = 0; i < worldX; i++)
	{
		_worldMap[i] = new Field[_worldY];
	}
};

MapFriends::GlobalMap::~GlobalMap()
{
	for(int i = 0; i < _worldX; i++)
	{
		delete[] _worldMap[i];
	}

	delete[] _worldMap;

	_worldX = 0;
	_worldY = 0;
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

int MapFriends::GlobalMap::getFieldType(int posX, int posY)
{
	return _worldMap[posX][posY].getType();
};

int MapFriends::GlobalMap::getWorldX()
{
	return _worldX;
};

int MapFriends::GlobalMap::getWorldY()
{
	return _worldY;
};