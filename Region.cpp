#include "Region.h"



Region::Region()
{
	Region::width = 0;
	Region::height = 0;
};

void Region::setRegionSize(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
};

bool Region::setLandscapeImage()
{
	bool load = false;

	if(background)
	{
		load = background->LoadFromFile("F:/my/Programming/tankoid/sources/Tankoid/back3.bmp");
	}

	return load;
};