#include "Region.h"

Region::Region()
{

};

void Region::setPosition(float globalPositionX, float globalPositionY)
{
	drawingBackground.SetPosition(globalPositionX, globalPositionY);
}

void Region::setBackground(const sf::Image& sourseImage)
{
	drawingBackground.SetImage(sourseImage);
};

void Region::draw(sf::RenderWindow& drawTarget) const
{
	drawTarget.Draw(drawingBackground);
};

