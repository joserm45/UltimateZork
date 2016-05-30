#include "Npc.h"
#include "Exits.h"
#include <stdlib.h>
#include "Player.h"
#include "World.h"
#include "Item.h"

Npc::Npc(char* name, char* description, int health, int attack, Item* object, int coins, Room* room) : Creature(name, description, health, attack, object, coins, room)
{
	type = NPC;
}

Npc::~Npc()
{

}