#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

class Item;
class Room;
class World;
enum dir;

class Creature : public Entity
{
public:

	Creature(){}
	Creature(char* name, char* description,int health, int attack, Item*, int coins, Room*);

	int health = 20;
	int coins=100;
	int attack = 2;
	Vector <Item*> items;
	Room* room_position = nullptr;

	void Attack();
	void Move(World* world, dir adress);
	
	~Creature();
};



#endif //end 