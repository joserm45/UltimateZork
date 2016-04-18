#ifndef Zork_Player
#define Zork_Player
#include "Vector.h"

class Item;
class Room;
enum dir;
class World;

class Player{
	public:
	
		Vector <Item*> items;
	//	Item* equipped_left;
		Item* equipped;
		int max_slots;


		Room* posPlayer = nullptr;

		

	void Look()const;
	void Drop(const char* to_drop);
	void Pick(const char* to_pick);
	void LookCommand(World* world, dir adress);
	void MovePlayer(World* world, dir adress);
	void OpenDoor(World* world, dir adress);
	void CloseDoor(World* world, dir adress);
	void Help()const;
};


#endif