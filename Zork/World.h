#ifndef Zork_World
#define Zork_World

#include "Rooms.h"
#include "Player.h"
#include "Exits.h"

class World {
public:
	Room* rooms = nullptr;
	Exit* exits= nullptr;
	Player* players = nullptr;	

	void CreateWorld();
	bool Command();

	World();
	
	~World();
	
};

#endif

