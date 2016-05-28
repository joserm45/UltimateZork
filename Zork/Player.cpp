#include <stdio.h>
#include "Creature.h"
#include "Zombie.h"
#include "Player.h"
#include "World.h"
#include "Rooms.h"
#include "Entity.h"
#include "Exits.h"
#include "Item.h"

Player:: Player() : Creature ("Mikel", "Young and beautiful man", 30,2,NULL,coins,NULL)
{
	type = PLAYER;
}
Player::Player(Item* object, Room* room) : Creature("Mikel", "Young and beautiful man", 30, 2, object, coins, room)
{
	type = PLAYER;
}

void Player::Look()const{
	printf("%s \n %s \n", room_position->name.c_str(), room_position->description.c_str());
	for (unsigned int i = 0; i < room_position->items.size(); i++)
	{
		printf("%s\n %s\n", room_position->items[i]->name.c_str(), room_position->items[i]->description.c_str());
	}
}

void Player::DisplayInv()const
{
	if (items.size() == 0)
	{
		printf("You don't have any item!");
		
	}
	for (unsigned int i = 0; i < items.size(); i++)
		printf("%s\n", items[i]->name);

	printf("You have %i coins\n", coins);
}

void Player::equiped(const char* to_equip)
{
	for (unsigned int i =0; i < items.size();i++)

	if (items[i]->name == to_equip)
	{
		if (equipped != NULL)
		{
			unequiped(equipped->name.c_str());
		}
		equipped = *items.Pick(i);
		attack = items[i]->atackweapon ;

			printf("You got the %s with %i atack damage: ", to_equip, attack);
	}
	else printf("You can't do this: ");
}

void Player::unequiped(const char* to_equip)
{
	if (equipped == NULL)
	{
		printf("You don't have any thing! ");
	}

	else if (equipped->name == to_equip)
	{
		
		printf("You unequiped the '%s': ", to_equip);
		room_position->items.push_back(equipped);
		equipped = NULL;
		attack = 2;
	}
	else
	{
		printf("You don't have the same item!");
	}
}

void Player::Put(mString to_put, mString to_into)
{
	bool found = false;
	bool found2 = false;
	int temp;
	int temp2;
	if (to_into == "chest")
	{
		for (unsigned int i = 0; i < room_position->items.size(); i++) // searching chest
		{
			if (room_position->items[i]->name == to_into)
			{
				temp = i;
				found = true;
				break;
			}
		}

		if (found == false)
		{
			printf("There is no item '%s' in the room: ", to_into.c_str());
			return;
		}

		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (items[i]->name == to_put)
			{
				found2 = true;
				temp2 = i;
				break;
			}
		}
		if (found2 == false)
		{
			printf("There is no item '%s' in the room : ", to_put.c_str());
			return;
		}
		printf("You put '%s into '%s'", to_put.c_str(), to_into.c_str());
		room_position->items[temp]->items.push_back(items[temp2]);
		items.Pick(temp2);
	}
	else
		printf("You can't put this!");
}
void Player::Get(mString to_pick, mString to_from)
{
	bool found = false;
	bool found2 = false;
	int temp;
	int temp2;
	if (to_from == "chest")
	{
		for (unsigned int i = 0; i < room_position->items.size(); i++) // searching chest
		{
			if (room_position->items[i]->name == to_from)
			{
				temp = i;
				found = true;
				break;
			}
		}

		if (found == false)
		{
			printf("There is no item '%s' in the room: ", to_from.c_str());
			return;
		}

		for (unsigned int i = 0; i < room_position->items[temp]->items.size(); i++)
		{
			if (room_position->items[temp]->items[i]->name == to_pick)
			{
				found2 = true;
				temp2 = i;

				break;
			}
		}
		if (found2 == false)
		{
			printf("There is no item '%s' in the room : ", to_pick.c_str());
			return;
		}
		printf("You get '%s from '%s'", to_pick.c_str(), to_from.c_str());
		items.push_back(room_position->items[temp]->items[temp2]);
		room_position->items[temp]->items.Pick(temp2);

	}
	else
		printf("\nYou can't get items from there!");
}

void Player::Pick( const mString to_pick)
{
	bool found = false;
	if (to_pick == "chest")
	{
		printf("\nYou can't pick a chest!");
		
	}
	else
	{
		for (unsigned int i = 0; i < room_position->items.size(); i++)
		{
			//mString str4 = posPlayer->items[i]->name;
			if (room_position->items[i]->name == to_pick)
			{
				found = true;
				items.push_back(room_position->items[i]);

				room_position->items.Pick(i);
				printf("\nYou picked a '%s'. ", to_pick.c_str());
			}
			if (found == true)
				break;
		}
		if (found == false)
			printf("\nThis item don't exist or isn't there!");
	}
}

void Player::Drop(const char* to_drop)
{
	bool found = false;

	for (unsigned int i = 0; i < items.size(); i++)
	{

		if (items[i]->name == to_drop)
		{
			found = true;

			room_position->items.push_back(items[i]);

			items.Pick(i);
			printf("You dropped the %s: ", to_drop);
		}
		if (found == true)
			break;
	}
	if (found == false)
		printf("This item don't exist or isn't there!");
}





void Player::LookCommand(World* world, dir adress)
{
	int i = 0;
	bool look_dir=false;
	for (i = 0; i < 21; i++){
		if (world->exits[i]->source == room_position && world->exits[i]->direction == adress)
		{

			look_dir = true;


			printf("%s \n %s \n ", world->exits[i]->name.c_str(), world->exits[i]->description.c_str());

		}
				
		}
	if (look_dir=false)
	printf("There is a wall there.\n");
}
		
		
		

void Player::OpenDoor(World* world, dir adress){
	int i = 0;
	for (i = 0; i < 21; i++){
		if (world->exits[i]->source == room_position && world->exits[i]->direction == adress){
			if (world->exits[i]->openDoor==false){
				world->exits[i]->openDoor = true;
				printf("You opened the door.\n");
			}
			else{
				printf("The door is already opened.\n");
			}
		}
	}
}

void Player::CloseDoor(World* world, dir adress){
	int i = 0;
	for (i = 0; i < 21; i++){
		if (world->exits[i]->source == room_position && world->exits[i]->direction == adress){
			if (world->exits[i]->openDoor == true){
				world->exits[i]->openDoor = false;
				printf("The door is closed.\n");

			}
			else{
				printf("The door is already closed.\n");
			}
		}
	}
}
void Player::Update(World* world)
{
	switch (state)
	{

	case PLAYER_IDLE:
	{

		break;
	}
		
	case PLAYER_ATTACK:
	{
	    UpdateAttack(world);
		break;
	}
		
	default:
		break;
	}
}
void Player::SpecialAttack(World* world, const char* to_attack)
{
	if (to_attack == "attack")
	{
		int temp = 0;
		for (unsigned int i = 0; i < world->zombie.size();i++)
		{

			if (world->zombie[i]->room_position == room_position)
			{
				temp++;
			}
		}
		printf("\nYou kill %i zombies and you earned %i coins", temp,temp*100);
		//60 second delay
	}
	else 
		printf("\nI don't know this command!");
}
void Player::Attack(World* world)
{
	if (state == PLAYER_IDLE)
	{
		for (unsigned int i = 0; i < world->zombie.size(); i++)
		{
			if (world->zombie[i]->room_position == room_position)
			{
				your_attack = true;
				state = PLAYER_ATTACK;

				zombie_to_attack = world->zombie[i];
				zombie_to_attack->your_attack = false;  //ZOMBIE
				zombie_to_attack->state = ATTACK;
				break;
			}
		}

		if (zombie_to_attack == NULL)
		{
			printf("You can't attack zombies, because there aren't any zombies!");
		}

	}
	else
		printf("You are already in combat!");
}


void Player::UpdateAttack(World* world)
{
	if (your_attack == true)
	{
		zombie_to_attack->health = zombie_to_attack->health - attack;
		your_attack = false;
		zombie_to_attack->your_attack = true;
		printf("Player hit zombie, zombie health: %i\n", zombie_to_attack->health);
		if (zombie_to_attack->health <= 0)
		{
			printf("You killed the zombie!\n");
			zombie_to_attack->Die(world, this);
		}
	}
}


void Player::Help()const{
	printf("You can move around the room with the keyboard keys (n/s/w/e) or with the words north, south, east , west.");
	printf("Also you can write go and the words north,south,east,west. If you write look you can see our room, but if you write look north you will see the north room.\n ");
	printf("To finish the commands you can close and open the doors with the same method of the command look, and quit the game pressing the 'q'.\n ");
}