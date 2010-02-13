#include "MapNet.h"

MapNet::MapNet()
{
	regionHeight = regionWidth = mapNetHeight = mapNetWidth = 0;
};

MapNet::MapNet(int var)
{
	int localW = 400, localH = 300;

	regionResize(localW, localH);
	mapNetResize(limNetWidth, limNetHeight);

	backgroundImage.LoadFromFile
		("F:/my/Programming/tankoid/sources/Tankoid/back2.jpg");

	for(int i = 0; i < limNetWidth; i++ )
	{
		for(int j = 0; j < limNetHeight; j++)
		{
			regionsNet[i][j].setBackground(backgroundImage);
			regionsNet[i][j].setPosition(i * localW, j * localH);
		}
	}
};

void MapNet::regionResize(int newRegionWidth, int newRegionHeight)
{
	regionHeight = newRegionHeight;
	regionWidth = newRegionWidth;
};

void MapNet::mapNetResize(int newMapNetHeight, int newMapNetWidth)
{
	 mapNetHeight = newMapNetHeight;
	 mapNetWidth = newMapNetWidth;
};

int MapNet::getRegionHeight() const
{
	return regionHeight;
};

int MapNet::getRegionWidth() const
{
	return regionWidth;
};

int MapNet::getMapWidth() const
{
	return mapNetWidth;
};
	
int MapNet::getMapHeight() const
{
	return mapNetHeight;
};