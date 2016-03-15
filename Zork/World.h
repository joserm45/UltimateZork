#ifndef Zork_World
#define Zork_World

#include "Rooms.h"
#include "Exits.h"
#include "Player.h"


class World {
private:
	Room* rooms = nullptr;
	Exit* exits= nullptr;
	Player* player = nullptr;
public:
	void CreateWorld();

	World();
	
	~World();
	
};

#endif

