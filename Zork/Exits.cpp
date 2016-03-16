#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"



Exit::Exit()
{
	source = new Room;
	destiny = new Room;
}


