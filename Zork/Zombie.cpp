#include "Zombie.h"
#include "Exits.h"
#include <stdlib.h>

Zombie::Zombie(char* name, char* description, int health, int attack, Item* object, int coins, Room* room) : Creature(name,description,health,attack,object,coins,room)
{
	type = ZOMBIE;
}
void Zombie::Update(World* world)
{
	dir direction = static_cast<dir>(rand() % 4);
	Move(world, direction);
}