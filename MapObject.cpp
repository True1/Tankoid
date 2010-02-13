#include "MapObject.h"

MapObject::MapObject()
{
};
	
void MapObject::setPosition(float globalPositionX, float globalPositionY)
{
	drawingImage.SetPosition(globalPositionX, globalPositionY);
}

void MapObject::setImage(const sf::Image& sourseImage)
{
	drawingImage.SetImage(sourseImage);
};

void MapObject::draw(sf::RenderWindow& drawTarget) const
{
	drawTarget.Draw(drawingImage);
};