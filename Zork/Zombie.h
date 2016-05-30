#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Creature.h"
enum zombie_state {IDLE,ATTACK,DEAD};
class Player;

class Zombie : public Creature
{
public:
	zombie_state state;
	int startTimeZombie=0;
	int startMoveTime = 0;
	Zombie(char* name, char* description, int health, int attack, Item*, int coins, Room*,int );
	bool your_attack;
	void Move(World*,dir, Player*);
	void Die(World* world, Player* player);
	void Attack(World*, Player*, int);
	void UpdateAttack(World*, Player*, int);
	bool Update(World*,Player*,int);
	
	~Zombie();
};
#endif //end