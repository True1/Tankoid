#include "BackgroundObject.h"

class Region : public IDraw
{
	sf::Sprite drawingBackground;
	sf::Image backgroundImage;

public:
	Region();
	//Region(float globalPositionX, float globalPositionY);

	void setPosition(float globalPositionX, float globalPositionY);

	void setBackground(const sf::Image& sourseImage);

	//void setDecorationPosition(int index, float relativePositionX, float relativePositionY);

	virtual void draw(sf::RenderWindow& drawTarget) const;

	void addDecorationImage(sf::Image decorationImage, 
		int relativePositionX, int relativePositionY);
};

