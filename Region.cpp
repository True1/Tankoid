#include "Region.h"
#include <iostream>

ImageSource loading;

Region::Region() : drawingBackground()
{

};

/*
Region(float globalPositionX, float globalPositionY)
{
	for(int i = 0; i < numberDecoration; i++)
	{
		setDecorationPosition(i, 
								  globalPositionX + i * 100, globalPositionY + i * 100)
	}

	setPosition(globalPositionX, globalPositionY);
}
*/
/*
void Region::setDecorationPosition(int index, 
								   float relativePositionX, float relativePositionY)
{
	objectDecoration[index].setPosition(relativePositionX, relativePositionY);
};
*/

void Region::setPosition(float globalPositionX, float globalPositionY)
{
	drawingBackground.SetPosition(globalPositionX, globalPositionY);
}

void Region::setBackground(const sf::Image& sourseImage)
{
	backgroundImage = sourseImage;

	int numberDecoration = 4;
	BackgroundObject* objectDecoration = new BackgroundObject[numberDecoration];

	for(int i = 0; i < numberDecoration; i++)
	{
		addDecorationImage(loading.getImageForBackgroundObject(i), 64 * i, 64 * i);
	}

	drawingBackground.SetImage(backgroundImage);
};

void Region::draw(sf::RenderWindow& drawTarget) const
{
	drawTarget.Draw(drawingBackground);
};

void Region::addDecorationImage(sf::Image decorationImage, 
	int relativePositionX, int relativePositionY)
{
	backgroundImage.Copy(decorationImage, relativePositionX , relativePositionY, 
		sf::IntRect(0, 0, 0, 0), true);
};


