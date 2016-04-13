#ifndef Zork_Exit
#define Zork_Exit

#include "Entity.h"
#include "Rooms.h"




enum dir{ north, south, east, west };

class Exit: public Entity{

public:

	Room* source;
	Room* destiny;
	bool openDoor = false;
	dir direction;

	Exit();
	Exit(const char* name, const char* desc);
	~Exit();
};

#endif