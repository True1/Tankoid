#include "MapNet.h"

class LocalView : public IDraw
{
public:
	LocalView();
	LocalView(MapNet* mapToView);

	void setCenterPosition(float globalPositionX, float globalPositionY);
	void move(float offsetX, float offsetY);

	virtual void draw(sf::RenderWindow& drawTarget) const;

	sf::View originalView;//temp;
private:
	void resizeView(float newWidth, float newHeight);

	MapNet* viewingMap;

};