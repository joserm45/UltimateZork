#include "Npc.h"
#include "Exits.h"
#include <stdlib.h>
#include "Player.h"
#include "World.h"
#include "Item.h"
#include "String.h"

Npc::Npc(char* name, char* description, int health, int attack, Item* object, int coins, Room* room) : Creature(name, description, health, attack, object, coins, room)
{
	type = NPC;
}

void Npc::DisplayInventory()const
{
	
	printf(" DIANA'S INVENTORY:\n\n");
	for (unsigned int i = 0; i < items.size(); i++)
	{
		printf("Item %i: %s\n   %s\n   Price: %i\n\n", i+1,items[i]->name.c_str(), items[i]->description.c_str(), items[i]->price);
	}
}

void Npc::BuyFromPlayer(const char* to_buy, Player* player)
{
	Item * picked = nullptr;
	bool founded = false;
	for (unsigned int i = 0; i < player->items.size(); i++)
	{
		if (player->items[i]->name == to_buy)
		{
			founded = true;
			picked = *player->items.Pick(i);
			player->coins += picked->price;
			printf("You sell the '%s' for %i coins.\n", to_buy, picked->price);
			break;
		}
	}
	if (founded == false)
	{
		printf("You don't have this item!\n");
	}
}

void Npc::SellToPlayer(const char* to_sell, Player* player)
{
	
	bool founded = false;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->name == to_sell )
		{
			founded = true;
			if (items[i]->price < player->coins)
			{
				
				Item* new_item = new Item(items[i]->name.c_str(), items[i]->description.c_str(), items[i]->price);
				player->coins -= new_item->price;
				player->items.push_back(new_item);
				printf("You buy the '%s' for %i coins.\n", to_sell, new_item->price);
				mString tmp ((char* )to_sell);
				if (tmp == "vaccine" && player->cured==false)
				{
					player->cured = true;
					printf("Now you have immunity 
						
						zombie bite!\n");

				}
				break;
			}
			else
				printf("You don't have enough money!\n");
		}
	}
	if (founded == false)
	{
		printf("You don't have this item!\n");
	}
}

Npc::~Npc()
{

}