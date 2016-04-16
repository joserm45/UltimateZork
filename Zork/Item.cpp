#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Item.h"



Item::Item()
{

	
}
void Item::Look()const
{
	printf("\n%s\n%s", name.c_str(), description.c_str());
}

Item::Item(const char* new_name, const char* desc) : Entity(new_name, desc)
{

}
Item::~Item(){}