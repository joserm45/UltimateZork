#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"



Exit::Exit()
{

	source = new Room;
	destiny = new Room;
}


Exit::Exit(const char* new_name, const char* desc) : Entity(new_name,desc)
{
	
}

char* Exit::Get_adress_char(dir direction)
{
	switch (direction)
	{
	case(north) :
		return "NORTH";
		break;
	case(south) :
		return "SOUTH";
		break; 
	case(west) :
		return "WEST";
		break; 
	case(east) :
		return "EAST";
		break;
	default:
		break;
	}
}
Exit::~Exit(){}