#include "BackgroundObject.h"

class Region : public IDraw
{
	sf::Sprite drawingBackground;
	BackgroundObject* objectDecoration;
	int numberDecoration;

public:
	Region();
	//Region(float globalPositionX, float globalPositionY);

	void setPosition(float globalPositionX, float globalPositionY);

	void setBackground(const sf::Image& sourseImage);

	//void setDecorationPosition(int index, float relativePositionX, float relativePositionY);

	virtual void draw(sf::RenderWindow& drawTarget) const;
};

