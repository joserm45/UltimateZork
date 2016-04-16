#ifndef Zork_Rooms
#define Zork_Rooms

#include "String.h"
#include "Entity.h"
#include "Vector.h"

class Item;

class Room: public Entity{
public:

	Vector <Item*> items;

	Room();
	
	Room(const char* name, const char* desc);

	~Room();
};

#endif