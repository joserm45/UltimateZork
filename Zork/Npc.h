#ifndef NPC_H
#define NPC_H

#include "Creature.h"
//enum Npc_state { IDLE };
class Player;

class Npc : public Creature
{
public:
//	Npc_state state;
	Npc(char* name, char* description, int health, int attack, Item*, int coins, Room*);
	
	void DisplayInventory()const;
	void BuyFromPlayer(const char*, Player*);
	void SellToPlayer(const char*, Player*);

	~Npc();
};
#endif //end