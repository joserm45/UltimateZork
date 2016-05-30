#ifndef Zork_World
#define Zork_World
#include "Vector.h"
#include <Windows.h>


class Zombie;
class Room;
class Exit;
class Player;
class Npc;

class World {
public:
	unsigned int initialtime = GetTickCount();
	unsigned int currenttime = GetTickCount();
	Vector <Room*> rooms;
	Vector <Exit*> exits;
	Vector <Player*> players;
	Vector <Zombie*> zombie;
	Vector <Npc*> npc;
//	Player* players = nullptr;	
	bool lose=false;

	void CreateWorld();
	bool Update();

	World();
	
	~World();
	
};

#endif

