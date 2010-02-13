#include "IDraw.h"

class MapObject : public IDraw
{
private:
	sf::Sprite drawingImage;

public:
	MapObject();

	void setPosition(float globalPositionX, float globalPositionY);
	void setImage(const sf::Image& sourseImage);
	
	virtual void draw(sf::RenderWindow& drawTarget) const;
};