#ifndef Zork_Exit
#define Zork_Exit

#include "Entity.h"
#include "Rooms.h"






class Exit: public Entity{

public:

	int source;
	int destiny;
	bool openDoor = false;
	dir direction;
	
	Exit();
	Exit(const char* name, const char* desc);
	~Exit();
};

#endif