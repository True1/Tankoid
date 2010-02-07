#include "Region.h"

namespace Map 
{
	class GlobalMap;
	class LocalView;
};

class Map::GlobalMap 
{
	friend Map::LocalView;

public:
	GlobalMap();
	GlobalMap(int resolutionWidth, int resolutionHeight,
		int mapWidth, int mapHeight);

	bool setLandscapeImage();

	int getWorldNetX();
	int getWorldNetY();

private:
	int windowWidth;
	int windowHeight;
	int worldNetX;
	int worldNetY;
	Region** worldNet;
	sf::Image background;
};

class Map::LocalView
{
public:
	LocalView(int centerPositionX, int centerPositionY, int resolutionX, int resolutionY);
	void setGlobalMap(GlobalMap* renderMap);

	void move(int offsetX, int offsetY);

	void setWindow(sf::RenderWindow& curWindow);

	sf::Sprite& getRegionSprite(int positionX, int positionY);

private:
	sf::View camera;
	GlobalMap* renderingMap;


};