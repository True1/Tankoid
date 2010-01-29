#include "LocalMap.h"

MapFriends::LocalMap::LocalMap()
{
	_renderMap = 0;
	_beginX = _beginY = 0;
	_viewWidth = _viewHeight = 0;
};

MapFriends::LocalMap::~LocalMap()
{
	_renderMap = 0;
	_beginX = _beginY = 0;
	_viewWidth = _viewHeight = 0;
};

int MapFriends::LocalMap::getFieldType(int posX, int posY)
{
	return _renderMap->_worldMap[posX][posY].getType();
}

//@WILL DE MOVED TO ANOTHER CLASS
/*
void MapFriends::LocalMap::draw(unsigned int width, unsigned int height)
{
	int lastWidthIndex = width / Field::getFieldWidth() + static_cast<bool>(width % Field::getFieldWidth();
	int lastHeightIndex = height / Field::getFieldHeight() + static_cast<bool>(width % Field::getFieldHeight()

	sf::Sprite drawingSprite;

	for(int i = 0; i < lastWidthIndex); i++)
	{
		for(int j = 0; j < lastHeightIndex; j++)
		{
			switch(_renderMap->getFieldType(i, j))
			{
			case Field::Ground::GROUND_GRASS:
				{
					//drawingSprite.SetImage();
					drawingSprite.SetX(i * Field::getFieldWidth());
					drawingSprite.SetY(j * Field::getFieldHeight());
					break;
				}
			}
		}
	}
};
*/