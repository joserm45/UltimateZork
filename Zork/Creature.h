#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

class Item;
class Room;
class World;
enum dir;
enum creature_type{ NPC, ZOMBIE, PLAYER };
class Creature : public Entity
{
public:

	Creature(){}
	Creature(char* name, char* description,int health, int attack, Item*, int coins, Room*);

	creature_type type;
	int health = 20;
	int coins=100;
	int attack = 2;
	Vector <Item*> items;
	Room* room_position = nullptr;
	Room* room_zombie = nullptr;
	void Attack(World* world);
	void Move(World* world, dir adress);
	
	~Creature();
};



#endif //end 