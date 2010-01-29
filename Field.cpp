#include "Field.h"

Field::Field()
{ 
	type = 0;
};

Field::Field(int type)
{ 
	this->type = type;
};

Field::~Field()
{ 
	type = 0;
};

int Field::getFieldWidth()
{
	return 64;	//constant
};

int Field::getFieldHeight()
{
	return 64;	//constant
};

int Field::getType()
{
	return type;
};