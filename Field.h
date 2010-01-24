//fixed sized texture on the map.
class Field
{
protected:
	//number in global map:
	int globalPosititionX;	
	int globalPosititionY;

	//what sprite will be on this texture
	int type;
public:
	//public constructors:
	Field();
	Field(int globalPosititionX, int globalPosititionY, int type);

	//get size (methods provide constants):
	static int getFieldWidth();
	static int getFieldHeight();

	//get type
	int getType();
};