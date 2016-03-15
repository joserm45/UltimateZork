#ifndef Zork_Exit
#define Zork_Exit

#include "Rooms.h"
#include "Exits.h"
#include "World.h"

enum dir{ North, South, East, West };

class Exit{
public:
	char name[30];
	char description[300];
	Room* source;
	Room* destiny;
	bool open = false;
	dir direction;

	Exit();
	~Exit();
};

#endif