#include "Field.h"

void Field::Field()
{ 
	globalPosititionX = 0;
	globalPosititionY = 0;
	type = 0;
};

void Field::Field(int globalPosititionX, int globalPosititionY, int type)
{ 
	this->globalPosititionX = globalPosititionX;
	this->globalPosititionY = globalPosititionY;
	this->type = type;
};

static int Field::getFieldWidth()
{
	return 50;	//constant
};

static int Field::getFieldHeight()
{
	return 50;	//constant
};

int Field::getType()
{
	return type;
};