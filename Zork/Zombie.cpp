#include "Zombie.h"
#include "Exits.h"
#include <stdlib.h>
#include "Player.h"
#include "World.h"
#include "Item.h"

Zombie::Zombie(char* name, char* description, int health, int attack, Item* object, int coins, Room* room,int time) : Creature(name,description,health,attack,object,coins,room)
{
	startMoveTime = time;
	type = ZOMBIE;
}
bool Zombie::Update(World* world,Player* player,int currentTime)
{
	switch (state)
	{
	case IDLE:
	{
		if (currentTime - startMoveTime >= 3000)
		{
			
			if (player->room_position == room_position)
			{
				Attack(world, player, currentTime);
			}
			else
			{
				dir direction = static_cast<dir>(rand() % 4);
				Move(world, direction, player);
				startMoveTime = currentTime;
			}
		}
		break;
	}

	case ATTACK:
	{
		UpdateAttack(world, player,currentTime);
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

void Zombie::Move(World *world, dir direction, Player* player)
{
	Creature::Move(world, direction);
	if (room_position == player->room_position)
	{
		int dir_num = static_cast<int>(direction);
		if (static_cast<int>(direction) % 2 == 0)
		{
			direction = static_cast<dir>(dir_num + 1);
		}
		else
		{
			direction = static_cast<dir>(dir_num - 1);
		}
		printf("A zombie has entered to room comming from %s!\n", world->exits[0]->Get_adress_char(direction));
	}
}
void Zombie::Die(World* world, Player* player)
{

	if (items.size() != 0)
	{
		printf("The zombie has dropped a '%s' in the room.\n", items[0]->name.c_str());
		room_position->items.push_back(*items.Pick(0));
	}
	

	printf("You have earned %d coins\n", coins);
	
	player->coins += coins;
	state = DEAD;

}
void Zombie::Attack(World* world, Player* player, int currentTime)
{
	if (player->state == PLAYER_IDLE)
	{
		startTimeZombie = currentTime;
		startTimeZombie -= 1000;

		player->state = PLAYER_ATTACK;
		state = ATTACK;
		player->zombie_to_attack = this;
		your_attack = true;
		player->your_attack = false;

		printf("A zombie attacks you, now you are in combat!\n");
	}
}
void Zombie::UpdateAttack(World* world, Player* player,int currentTime)
{
	if (currentTime - startTimeZombie >= 1000)
	{
		if (your_attack == true)
		{
			if (player->health <= attack)
			{
				player->health = 0;
				state = IDLE;
			}
			else
			{
				player->health = player->health - attack;
				player->your_attack = true;
				player->startTurnTime = currentTime;
			}

			your_attack = false;

			printf("Zombie hit player, player health: %i\n", player->health);
			if (player->health <= 0)
			{
				printf("You lose!\n");
				world->lose = true;
			}
		}
	}
	
}

Zombie::~Zombie()
{

}