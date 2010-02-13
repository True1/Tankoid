#include <SFML/Graphics.hpp>

class IDraw
{
public:
	virtual void draw(sf::RenderWindow& drawTarget) const = 0;
};