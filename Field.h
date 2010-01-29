//fixed sized texture on the map.
class Field
{
protected:
	//what sprite will be on this texture
	int type;
public:
	//public constructors:
	Field();
	Field(int type);

	~Field();

	//get size (methods provide constants):
	static int getFieldWidth();
	static int getFieldHeight();

	//get type
	int getType();

	static enum Ground
	{
		GROUND_GRASS
	};
};