#include "MapObject.h"

class Region 
{
public:
	Region();

	static void setRegionSize(int newWidth, int newHeight);
	static bool setLandscapeImage();

private:
	static int width;
	static int height;
	static sf::Image* background;

	MapObject* landscape;
};

