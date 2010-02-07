#include "Map.h"

class GameRender
{
public:
	GameRender(int width, int height);

	~GameRender();
	void mainLooP();

private:

	Map::LocalView mainView;
	Map::GlobalMap worldMap;
	sf::RenderWindow gameWindow;
};