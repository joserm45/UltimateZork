#ifndef Zork_World
#define Zork_World
#include "Vector.h"
class Room;
class Exit;
class Player;

class World {
public:

	Vector <Room*> rooms;
	Vector <Exit*> exits;
	Player* players = nullptr;	

	void CreateWorld();
	bool Command();

	World();
	
	~World();
	
};

#endif

