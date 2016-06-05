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
	bool exitFound=false;
	

	for (i = 0; i < world->entity_list.size() ; i++)
	{
		if (world->entity_list[i]->type == EXIT)
		{

			Exit* tmp = ((Exit*)world->entity_list[i]);

			if (tmp->source == room_position->index && tmp->direction == adress)
			{
				exitFound = true;

				if (tmp->openDoor == true)
				{
					room_position = world->Value_to_room(tmp->destiny);
					if (type == PLAYER)
					{
						printf("%s \n %s \n", room_position->name.c_str(), room_position->description.c_str());

					}
					if (type == ZOMBIE)
					{
						//printf("\nZombie has moved to:%s  ", world->exits[i]->Get_adress_char(adress));

					}

				
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
