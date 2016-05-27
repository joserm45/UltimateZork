#include "Zombie.h"
#include "Exits.h"
#include <stdlib.h>
#include "Player.h"
#include "World.h"
#include "Item.h"

Zombie::Zombie(char* name, char* description, int health, int attack, Item* object, int coins, Room* room) : Creature(name,description,health,attack,object,coins,room)
{
	type = ZOMBIE;
}
bool Zombie::Update(World* world,Player* player)
{
	switch (state)
	{
	case IDLE:
	{
	    dir direction = static_cast<dir>(rand() % 4);
		Move(world, direction);
		break;
	}

	case ATTACK:
	{
		UpdateAttack(world, player);
		break;
	}
	case DEAD:
	{
		 return false;
		 break;
	}
	
	default:
	{
		break;
	}
	
	}
	return true;

}
void Zombie::Die(World* world, Player* player)
{
	printf("The zombie has dropped a '%s' in the room and you have earned %i coins", items[0]->name, coins);
	room_position->items.push_back(*items.Pick(0));
	player->coins += coins;
	state = DEAD;
	

}
void Zombie::UpdateAttack(World* world, Player* player)
{
	if (your_attack == true)
	{
		player->health = player->health - attack;
		your_attack = false;
		player->your_attack = true;
		printf("Zombie hit player, player health: %i\n", player->health);
		if (player->health <= 0)
		{
			printf("You lose!");
			world->lose = true;
		}
	}

	
}