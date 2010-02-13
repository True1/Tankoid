#include "LocalView.h"

LocalView::LocalView()
{
	viewingMap = 0;
};

LocalView::LocalView(MapNet* mapToView)
{
	viewingMap = mapToView;
	resizeView(viewingMap->getRegionWidth() * 2, viewingMap->getRegionHeight() * 2);
	setCenterPosition(0, 0);
};

void LocalView::setCenterPosition(float globalPositionX, float globalPositionY)
{
	originalView.SetCenter(globalPositionX, globalPositionY);
};

void LocalView::move(float offsetX, float offsetY)
{
	originalView.Move(offsetX, offsetY);
};

void LocalView::resizeView(float newHalfWidth, float newHalfHeight)
{
	originalView.SetHalfSize(newHalfWidth, newHalfHeight);
}

void LocalView::draw(sf::RenderWindow& drawTarget) const
{
	int indexI = viewingMap->getMapWidth();
	int indexJ = viewingMap->getMapHeight();
	for(int i = 0; i < indexI; i++)
	{
		for(int j = 0; j < indexJ; j++)
		{
			viewingMap->regionsNet[i][j].draw(drawTarget);
		}
	}
};