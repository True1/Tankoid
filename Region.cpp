#include "Region.h"
#include <iostream>

ImageSource loading;

Region::Region() : drawingBackground()
{
	numberDecoration = 4;
	objectDecoration = new BackgroundObject[numberDecoration];

	for(int i = 0; i < numberDecoration; i++)
	{
		objectDecoration[i].setImage(loading.getImageForBackgroundObject(i));
	}
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
	/*
	float currentObjectRelativeX = 0;
	float currentObjectRelativeY = 0;

	for(int i = 0; i < numberDecoration; i++)
	{
		currentObjectRelativeX = objectDecoration[i].getPositionX() 
			- drawingBackground.GetPosition().x;

		currentObjectRelativeY = objectDecoration[i].getPositionY()
			- drawingBackground.GetPosition().y;

		objectDecoration[i].setPosition(globalPositionX + currentObjectRelativeX, 
			globalPositionY + currentObjectRelativeY);
	}*/

	drawingBackground.SetPosition(globalPositionX, globalPositionY);

	for(int i = 0; i < numberDecoration; i++)
	{
		objectDecoration[i].setPosition(globalPositionX + i * 70, 
			globalPositionY + i * 70);
	}
}

void Region::setBackground(const sf::Image& sourseImage)
{
	drawingBackground.SetImage(sourseImage);
};

void Region::draw(sf::RenderWindow& drawTarget) const
{
	drawTarget.Draw(drawingBackground);

	for(int i = 0; i < numberDecoration; i++)
	{
		objectDecoration[i].draw(drawTarget);
	}
};

