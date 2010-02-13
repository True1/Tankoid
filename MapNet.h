#include "Region.h"

class MapNet
{
	friend class LocalView;
private:
	int regionWidth;
	int regionHeight;

	sf::Image backgroundImage;
	
	static const int limNetHeight = 8;
	static const int limNetWidth = 8;

	int mapNetHeight;
	int mapNetWidth;

	Region regionsNet[limNetWidth][limNetHeight];

	void regionResize(int newRegionWidth, int newRegionHeight);
	void mapNetResize(int newMapNetHeight, int newMapNetWidth);

public:
	MapNet();
	MapNet(int var);

	int getRegionWidth() const;
	int getRegionHeight() const;
	int getMapWidth() const;
	int getMapHeight() const;
};