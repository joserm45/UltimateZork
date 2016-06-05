#ifndef Zork_Rooms
#define Zork_Rooms

#include "String.h"
#include "Entity.h"
#include "Vector.h"

class Item;

class Room: public Entity{
public:

	Vector <Item*> items;
	int index;
	Room();
	
	Room(const char* name, const char* desc,int index);

	~Room();
};

#endif