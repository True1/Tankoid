#include "Map.h"
#include <iostream>

Map::GlobalMap::GlobalMap()
{
	worldNetX = 0;
	worldNetY = 0;
	worldNet = 0;
};

Map::GlobalMap::GlobalMap(int resolutionWidth, int resolutionHeight,
		int mapWidth, int mapHeight)
{
	windowWidth = resolutionWidth;
	windowHeight = resolutionHeight;

	Region::setRegionSize(resolutionWidth / 4, resolutionHeight / 4);

	worldNetX = mapWidth / (resolutionWidth / 4)
		+ static_cast<bool>(mapWidth % (resolutionWidth / 4));

	worldNetY = mapHeight / (resolutionHeight / 4)
		+ static_cast<bool>(mapHeight % (resolutionHeight / 4));

	worldNet = new Region*[worldNetX];

	for(int i = 0; i < worldNetX; i++)
	{
		worldNet[i] = new Region[worldNetY];
	}

	std::cout << "Global map created : " << std::endl;
	std::cout << "netX: " << worldNetX << std::endl;
	std::cout << "netY: " << worldNetY << std::endl;
	std::cout << "windowWidth: " << windowWidth << std::endl;
	std::cout << "windowHeight: " << windowHeight << std::endl;
};

int Map::GlobalMap::getWorldNetX()
{
	return worldNetX;
};

int Map::GlobalMap::getWorldNetY()
{
	return worldNetY;
};

Map::LocalView::LocalView(int centerPositionX, int centerPositionY, 
						  int resolutionX, int resolutionY) :
	camera(sf::Vector2f(centerPositionX, centerPositionY), 
	   sf::Vector2f(resolutionX / 2, resolutionY / 2))
{
	renderingMap = 0;
	std::cout << "created local view in: ";
	std::cout <<"( " << centerPositionX << ", " << centerPositionY << " )" << std::endl;
	std::cout << "with resolution: ";
	std::cout <<"( " << resolutionX / 2 << ", " << resolutionY / 2 << " )" << std::endl;
};

void Map::LocalView::setGlobalMap(GlobalMap* renderMap)
{
	renderingMap = renderMap;
};

void Map::LocalView::move(int offsetX, int offsetY)
{
	std::cout << "moving camera" << std::endl;
	camera.Move(offsetX, offsetY);
};

void Map::LocalView::setWindow(sf::RenderWindow& curWindow)
{
	curWindow.SetView(camera);
}