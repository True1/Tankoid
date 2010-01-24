#include "Field.h"

void Field::Field()
{ 
	type = 0;
};

void Field::Field(int type)
{ 
	this->type = type;
};

void Field::~Field();
{ 
	type = 0;
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