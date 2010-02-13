#include "IDraw.h"

class Region : public IDraw
{
	sf::Sprite drawingBackground;

public:
	Region();

	void setPosition(float globalPositionX, float globalPositionY);
	void setBackground(const sf::Image& sourseImage);

	virtual void draw(sf::RenderWindow& drawTarget) const;
};

