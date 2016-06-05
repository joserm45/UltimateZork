#ifndef Zork_World
#define Zork_World
#include "Vector.h"
#include <Windows.h>
#include "Entity.h"


class Zombie;
class Room;
class Exit;
class Player;
class Npc;

class World 
{
public:
	unsigned int initialtime = GetTickCount();
	unsigned int currenttime = GetTickCount();

	Vector <Entity*> entity_list;
	Player* player = nullptr;

	//Vector <Room*> rooms;
	//Vector <Exit*> exits;
//	Vector <Zombie*> zombie;
//	Vector <Npc*> npc;
//	Player* players = nullptr;	
	bool lose=false;
	char* Get_adress_char(dir direction);
	void CreateWorld();
	bool Update();
	Room* Value_to_room(int);
	void Creating_zombie();

	World();
	
	~World();
	
};

#endif

