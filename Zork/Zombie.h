#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Creature.h"

class Zombie : public Creature
{
public:
	Zombie(char* name, char* description, int health, int attack, Item*, int coins, Room*);

void Update(World*);
};
#endif //end