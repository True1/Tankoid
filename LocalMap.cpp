#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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