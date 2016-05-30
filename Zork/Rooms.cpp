#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"

Room::Room(){}

Room::Room(const char* names, const char* descrip) : Entity(names,descrip)
{
	
}
Room::~Room()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}


