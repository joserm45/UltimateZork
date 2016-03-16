#ifndef Zork_Player
#define Zork_Player

#include "Rooms.h"
#include "Exits.h"


class World;

class Player{
	public:
	
		Room* posPlayer;
		

	void Look()const;
	void LookCommand(World* world, dir adress);
	void MovePlayer(World* world, dir adress);
	void OpenDoor(World* world, dir adress);
	void CloseDoor(World* world, dir adress);
	void Help()const;
};


#endif