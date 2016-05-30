#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Item.h"



Item::Item()
{

	
}
void Item::Look()const
{
	printf("\n%s %s", name.c_str(), description.c_str());
}

Item::Item(const char* new_name, const char* desc,int new_price) : Entity(new_name, desc)
{
	price = new_price;
}
Item::~Item()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}