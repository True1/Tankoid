#include "MapObject.h"

class Region 
{
public:
	Region();

	static void setRegionSize(int newWidth, int newHeight);
	
	static int width;
	static int height;

	MapObject* landscape;
};

