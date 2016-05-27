#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Creature.h"
enum zombie_state {IDLE,ATTACK,DEAD};
class Player;

class Zombie : public Creature
{
public:
	zombie_state state;
	Zombie(char* name, char* description, int health, int attack, Item*, int coins, Room*);
	bool your_attack;
	void Die(World* world, Player* player);
	bool Update(World*,Player*);
	void UpdateAttack(World*, Player*);
};
#endif //end