#include <stdio.h>
#include "Creature.h"
#include "Zombie.h"
#include "Player.h"
#include "World.h"
#include "Rooms.h"
#include "Entity.h"
#include "Exits.h"
#include "Npc.h"
#include "Item.h"

Player:: Player() : Creature ("Mikel", "Young and beautiful man", 50,2,NULL,coins,NULL)
{
	type = PLAYER;
}
Player::Player(Item* object, Room* room) : Creature("Mikel", "Young and beautiful man", 50, 2, object, coins, room)
{
	type = PLAYER;
}

void Player::Look()const{
	printf("%s \n %s \n", room_position->name.c_str(), room_position->description.c_str());

	
	
}

void Player::Look(World* world)const
{
	if (world->npc[0]->room_position == room_position)
	{
		printf("You see a beautiful lady called Diana.\n");
	}
	//printf("%s \n %s \n", room_position->name.c_str(), room_position->description.c_str());
	if (room_position->items.size() == 0)
	{
		printf("You don't see nothing interesting.\n");
	}
	else
	{
		for (unsigned int i = 0; i < room_position->items.size(); i++)
		{
			printf("You see a:%s\n Description:%s\n\n", room_position->items[i]->name.c_str(), room_position->items[i]->description.c_str());
		}
		int temp = 0;
		for (unsigned int i = 0; i < world->zombie.size(); i++)
		{
			if (world->zombie[i]->room_position == room_position)
			{
				temp++;

			}

		}
	

	if (temp > 1)
	{
		printf("\nYou see %i zombies.", temp); //// HERE!

	}
	if (temp == 1)
	{
		printf("\nYou see %i zombie ", temp);
	}

}
}

void Player::DisplayInv()const
{
	if (items.size() == 0)
	{
		printf("You don't have any item!\n");
		
	}
	for (unsigned int i = 0; i < items.size(); i++)
		printf("%s\n", items[i]->name);

	printf("You have %i coins\n", coins);
	printf("You have %i health\n", health);

}

void Player::equiped(const char* to_equip)
{
	bool found_equp = false;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->name == to_equip)
		{
			if (equipped != NULL)
			{
				unequiped(equipped->name.c_str());
			}
			equipped = *items.Pick(i);
		
			printf("You got the %s. You have %i + (%i) atack damage:\n", to_equip, attack, equipped->atackweapon);
			attack = equipped->atackweapon + attack ;
			found_equp = true;
		}

	}
	if (found_equp == false)
	{
		printf("You don't have '%s' in your inventory!:\n ",to_equip);
	}

	
}

void Player::unequiped(const char* to_equip)
{
	if (equipped == NULL)
	{
		printf("You don't have any thing!\n");
	}

	else if (equipped->name == to_equip)
	{
		
		printf("You unequiped the '%s':\n", to_equip);
		room_position->items.push_back(equipped);
		equipped = NULL;
		attack = 2;
	}
	else
	{
		printf("You don't have the same item!\n");
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
			printf("There is no item '%s' in the room:\n", to_into.c_str());
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
			printf("There is no item '%s' in the room:\n ", to_put.c_str());
			return;
		}
		printf("You put '%s into '%s'", to_put.c_str(), to_into.c_str());
		room_position->items[temp]->items.push_back(items[temp2]);
		items.Pick(temp2);
	}
	else
		printf("You can't put this!\n");
}

void Player::Move(World* world, dir adress)
{
	if (state == PLAYER_ATTACK)
	{
		state = PLAYER_IDLE;
		zombie_to_attack->state = IDLE;
		zombie_to_attack = NULL;
	}
	
	Creature::Move(world, adress);
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
			printf("\nThere is no item '%s' in the room: ", to_from.c_str());
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
			printf("\nThere is no item '%s' in the room : ", to_pick.c_str());
			return;
		}
		printf("\nYou get '%s from '%s'", to_pick.c_str(), to_from.c_str());
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
			printf("This item don't exist or isn't there!\n");
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
			printf("You dropped the %s:\n", to_drop);
		}
		if (found == true)
			break;
	}
	if (found == false)
		printf("This item don't exist or isn't there!\n");
}





void Player::LookCommand(World* world, dir adress)
{
	int i = 0;
	bool look_dir=false;
	for (i = 0; i <= 19; i++){
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
	for (i = 0; i <= 19; i++){
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
	for (i = 0; i < 19; i++){
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
bool Player::Update(World* world,int currentTime)
{
	if (world->rooms[8] == room_position )
	{
		if (InBunker == false)
		{
			InBunker = true;
			if (cured == true)
			{
				printf("You have made it to the bunker with the cure!\n\n You WIN!\n");
				return false;
			}
			else
				printf("You have made it to the bunker but you don't have the cure!\n");
		}
		
	}
	else
		InBunker = false;
	switch (state)
	{

	case PLAYER_IDLE:
	{

		break;
	}
		
	case PLAYER_ATTACK:
	{
	    UpdateAttack(world,currentTime);
		break;
	}
		
	default:
		break;
	}
	if (infected == true && cured==false)
	{
		if (currentTime - infected_time > 5000)
		{
			infected_time = currentTime;
			health--;
			printf("You are poisoned, you lose 1 health point\n");
			if (health <= 0)
			{
				printf("You lose!!\n");
				return false;
			}
			
		}
	}
	return true;
}
void Player::SpecialAttack(World* world,int time)
{		
		
		if (time-special_attack_time >= 30000)
		{
			special_attack_time = time;
			printf("You use a BIG BOOOM!\n\n");
			for (unsigned int i = 0; i < world->zombie.size(); i++)
			{

				if (world->zombie[i]->room_position == room_position)
				{
					world->zombie[i]->Die(world,this);
				}
			}
		
			//30 second delay
			state = PLAYER_IDLE;
			world->initialtime = world->currenttime;
		}
		else
			printf(" You need to wait %i seconds to use:\n", (30000-(time-special_attack_time )) / 1000);
		//world->initialtime = GetTickCount();
}

void Player::MoveClosestZombies(World* world, int time)
{
	for (unsigned int i = 0; i < world->exits.size(); i++)
	{
		if (world->exits[i]->destiny == room_position)
		{
			for (unsigned int z = 0; z < world->zombie.size(); z++)
			{
				if (world->exits[i]->source == world->zombie[z]->room_position)
				{
					world->zombie[z]->Move(world,world->exits[i]->direction,this);
					world->zombie[z]->startMoveTime = time;
				}
			}
		}
	}
	
}
void Player::Attack(World* world,int currentTime)
{
	startTurnTime = currentTime;
	startTurnTime -= 1000;
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
				printf("You can't attack zombies, because there aren't any zombies!\n");
			}

		}
		else
			printf("You are already in combat!\n");
	
}


void Player::UpdateAttack(World* world,int currentTime)
{
	if (currentTime - startTurnTime >= 1000)
	{
		if (your_attack == true)
		{
			if ((equipped != NULL  && equipped->name == "gun") || (equipped != NULL && equipped->name == "shotgun"))
			{
				printf("\nYou shot a zombie with your gun. It made a loud noise\n");
				MoveClosestZombies(world, currentTime);
			}
			/*else
				printf("Player hit zombie, zombie health: %i\n", zombie_to_attack->health);
			*/
			if (zombie_to_attack->health <= attack)
			{
				zombie_to_attack->health = 0;
			}
			else
			{
				zombie_to_attack->health = zombie_to_attack->health - attack;
				zombie_to_attack->your_attack = true;
				zombie_to_attack->startTimeZombie = currentTime;
			}

			your_attack = false;


			printf("Player hit zombie, zombie health: %i\n", zombie_to_attack->health);
			if (zombie_to_attack->health <= 0)
			{
				printf("You killed the zombie!\n");
				zombie_to_attack->Die(world, this);
				state = PLAYER_IDLE;
				zombie_to_attack = NULL;
			}
		}
	}
}

void Player::Buy(World* world)
{

}

//BuyItem

void Player::Help()const{
	printf("You can move around the room with the keyboard keys (n/s/w/e) or with the words north, south, east , west.");
	printf("Also you can write go and the words north,south,east,west. If you write look you can see our room, but if you write look north you will see the north room.\n ");
	printf("To finish the commands you can close and open the doors with the same method of the command look, and quit the game pressing the 'q'.\n ");
}
Player::~Player()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
	if (equipped)
	{
		delete equipped;
		equipped = NULL;
	}
}