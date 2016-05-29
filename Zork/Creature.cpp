#include "Creature.h"
#include "World.h"
#include "Exits.h"
#include "Zombie.h"
#include "Player.h"

Creature::Creature(char* name_NPC, char* description_NPC, int health_1, int attack_1, Item* items_1, int coins_1, Room* position) : Entity(name_NPC, description_NPC), health(health_1), attack(attack_1), coins(coins_1), room_position(position)
{
	if (items_1 != nullptr)
	{
		items.push_back(items_1);
	}
}

void Creature::Move(World* world, dir adress)
{
	int i = 0;
	bool exitFound;


	for (i = 0; i <= 19; i++)
	{
		if (world->exits[i]->source == room_position && world->exits[i]->direction == adress)
		{
			exitFound = true;

			if (world->exits[i]->openDoor == true)
			{
				if (type == PLAYER)
				{
					printf("%s \n %s \n", world->exits[i]->destiny->name.c_str(), world->exits[i]->destiny->description.c_str());
				}
				if (type == ZOMBIE)
				{
					//printf("\nZombie has moved to:%s  ", world->exits[i]->Get_adress_char(adress));
				}

				room_position = world->exits[i]->destiny;
				/*for (unsigned int i = 0; i < world->zombie.size(); i++)
				{
					if (world->exits[i]->)          when zombie enter to the room
				}*/
				

				break;
			}
			else
			{
				if (type == PLAYER)
				{
					printf("The door is closed...\n");
				}
				if (type == ZOMBIE)
				{
					//printf("\nZombie has smashed a door trying to go: %s ", world->exits[0]->Get_adress_char(adress));
				}

				break;
			}
		}

		exitFound = false;
	}
	if (exitFound == false)
	{
		if (type == PLAYER)
		{
			printf("You can't go there...\n");
		}
		if (type == ZOMBIE)
		{
			//printf("Zombie has smashed a wall trying to go: %s  \n", world->exits[0]->Get_adress_char(adress));
		}
		
	}

}
Creature::~Creature()
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		delete items[i];
		//items[i] = nullptr;
	}

	items.clear();
}
