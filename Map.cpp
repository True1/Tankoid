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

	Region::setRegionSize(resolutionWidth / 2, resolutionHeight / 2);

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

bool Map::GlobalMap::setLandscapeImage()
{
	bool load = false;

	load = background.LoadFromFile("F:/my/Programming/tankoid/sources/Tankoid/back2.jpg");

	return load;
};

Map::LocalView::LocalView(int centerPositionX, int centerPositionY, 
						  int resolutionX, int resolutionY) :
	camera(sf::Vector2f(centerPositionX / 2, centerPositionY / 2), 
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
	camera.Move(offsetX, offsetY);
};

void Map::LocalView::setWindow(sf::RenderWindow& curWindow)
{
	curWindow.SetView(camera);
}

sf::Sprite& Map::LocalView::getRegionSprite(int positionX, int positionY)
{
	sf::Sprite* drawingRegionLandscape = new sf::Sprite(renderingMap->background);
	int realX = positionX * Region::width;
	int realY = positionY * Region::height;

	drawingRegionLandscape->SetPosition(realX, realY);

	return *drawingRegionLandscape;
}