#ifndef Zork_Exit
#define Zork_Exit

#include "Rooms.h"



enum dir{ north, south, east, west };

class Exit{
public:
	char name[50];
	char description[500];
	Room* source;
	Room* destiny;
	bool openDoor = false;
	dir direction;

	Exit();
	
};

#endif