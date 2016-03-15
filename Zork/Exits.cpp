#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"
#include "Exits.h"
#include "Player.h"
#include "World.h"

Exit::Exit()
{
	source = new Room;
	destiny = new Room;
}

Exit:: ~Exit(){
	delete[] source;
	delete[] destiny;
}