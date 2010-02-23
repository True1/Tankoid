#include "LocalView.h"

LocalView::LocalView() : originalView()
{
	viewingMap = 0;
};

LocalView::LocalView(MapNet* mapToView)
{
	viewingMap = mapToView;
	resizeView(viewingMap->getRegionWidth(), viewingMap->getRegionHeight());
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
	int regionX = viewingMap->getRegionWidth();
	int regionY = viewingMap->getRegionHeight();

	int viewCenterX = originalView.GetCenter().x;
	int viewCenterY = originalView.GetCenter().y;

	int viewHalfX = originalView.GetHalfSize().x;
	int viewHalfY = originalView.GetHalfSize().y;


	int indexMinI = (viewCenterX - viewHalfX) / regionX;

	int indexMinJ = (viewCenterY - viewHalfY) / regionY;

	int indexMaxI = (viewCenterX + viewHalfX) / regionX
		+ static_cast<bool>((viewCenterX - viewHalfX) % regionX);
		
	int indexMaxJ = (viewCenterY + viewHalfY) / regionY
		+ static_cast<bool>((viewCenterY - viewHalfY) % regionY);

	int maxMapIndexI = viewingMap->getMapWidth();
	int maxMapIndexJ = viewingMap->getMapHeight();

	for(int i = indexMinI; i < indexMaxI; i++)
	{
		for(int j = indexMinJ; j < indexMaxJ; j++)
		{
			if( (i >= 0) && (j >= 0) 
				&& 
				(i < maxMapIndexI) && (j < maxMapIndexJ) )
				viewingMap->regionsNet[i][j].draw(drawTarget);
		}
	}

};