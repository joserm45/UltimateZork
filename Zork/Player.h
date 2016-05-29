#ifndef Zork_Player
#define Zork_Player

#include "Vector.h"
#include "String.h"
#include "Creature.h"

class Item;
class Room;
enum dir;
class World;

enum player_state {PLAYER_IDLE, PLAYER_ATTACK};
class Player : public Creature
{
public:
	Player();
	Player(Item*,Room*);

	Item* equipped;
	int max_slots;
	player_state state;
	Zombie* zombie_to_attack=nullptr;

	bool your_attack;
	
	void Get(mString to_pick, mString to_pick2);
	void Put(mString to_pick, mString to_pick2);
	void equiped(const char* to_equip);
	void unequiped(const char* to_equip);
	void DisplayInv()const;
	void Look()const;
	void Look(World*)const;
	void Drop(const char* to_drop);
	void Pick(const mString to_pick);
	void LookCommand(World* world, dir adress);
	void OpenDoor(World* world, dir adress); //Look here! Zombis can destroy the door?
	void CloseDoor(World* world, dir adress);
	void Update(World*);
	void SpecialAttack(World*, const char*);
	void Attack(World*);
	void UpdateAttack(World* world);
	void Help()const;
};


#endif