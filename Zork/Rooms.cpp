#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"

Room::Room(){}

Room::Room(const char* names, const char* descrip,int new_index) : Entity(names,descrip)
{
	index = new_index;
	type = ROOM;
}
Room::~Room()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}


