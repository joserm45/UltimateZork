#ifndef Zork_World
#define Zork_World

#include "Rooms.h"
#include "Player.h"
#include "Exits.h"

class World {
public:
	Room* rooms = nullptr;
	Exit* exits= nullptr;
	Player* player = nullptr;	

	void CreateWorld();
	char Command();

	World();
	
	~World();
	
};

#endif

