#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"



Exit::Exit()
{
	type = EXIT;
	//source = new Room;
	//destiny = new Room;
}


Exit::Exit(const char* new_name, const char* desc) : Entity(new_name,desc)
{
	type = EXIT;
}


Exit::~Exit(){}