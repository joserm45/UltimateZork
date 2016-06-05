#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <Windows.h>

#include "conio.h"
#include "String.h"
#include "Zombie.h"
#include "Item.h"
#include "World.h"
#include "Player.h"
#include "Npc.h"
#include "Rooms.h"
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"
#define _CTR_SECURE_NO_WARNINGS

World::World(){

	

//	Vector <Player*> players;

	//rooms = new Room[11];
//	players = new Player;
	//exits = new Exit[22];
	//player -> player = this;
}

char* World::Get_adress_char(dir direction)
{
	switch (direction)
	{
	case(north) :
		return "NORTH";
		break;
	case(south) :
		return "SOUTH";
		break;
	case(west) :
		return "WEST";
		break;
	case(east) :
		return "EAST";
		break;
	default:
		break;
	}
}

void World::CreateWorld(){
	//	rooms = new Room;

	Item* sword = new Item("sword", "Sharppened",150);
	sword->atackweapon = 4;
	Item* gun = new Item("gun", "Can kill zombies!",300);
	gun->atackweapon = 8;

	Item* hammer = new Item("hammer", "Perfect to break zombies heads!",60);
	hammer->atackweapon = 3;

	Item* knife = new Item("knife", "It's okay to defense!",30);
	knife->atackweapon = 2;

	Item* chest = new Item("chest", "Save items!",0);


	//push_back((new Room("Reception Room:", "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange.")));
	Room* new_room = new Room("Reception Room:", "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange.",0);
	entity_list.push_back(new_room);

	new_room->items.push_back(sword);
	new_room->items.push_back(gun);
	new_room->items.push_back(chest);
	new_room->items.push_back(hammer);

	player = new Player(NULL, new_room);
	

		 new_room = new Room("WC's", "A slight breathing is heard in the room. It seems that something scary this about to happen.",1);
		 entity_list.push_back(new_room);

		 Npc* new_npc = new Npc("Diana", "Can trade items!", 10, 10, NULL, 0, new_room);
		 entity_list.push_back(new_npc);
		 Item* sword2 = new Item("sword", "Sharppened", 150);
		 sword2->atackweapon = 4;

		 Item* gun2 = new Item("gun", "Can kill zombies!", 300);
		 gun2->atackweapon = 8;

		 Item* hammer2 = new Item("hammer", "Perfect to break zombies heads!", 60);
		 hammer2->atackweapon = 3;

		 Item* knife2 = new Item("knife", "It's okay to defense!", 30);
		 knife2->atackweapon = 2;

		 Item* shotgun2 = new Item("shotgun", "It seems very powerfull", 400);
		 shotgun2->atackweapon = 10;

		 Item* vaccine = new Item("vaccine", "It cures you from zombie bite", 350);

		 new_npc->items.push_back(knife2);
		 new_npc->items.push_back(hammer2);
		 new_npc->items.push_back(sword2);
		 new_npc->items.push_back(gun2);
		 new_npc->items.push_back(shotgun2);
		 new_npc->items.push_back(vaccine);

	
	     new_room = new Room("Living Room", "You can see a lot of papers on the floor.",2);
		 entity_list.push_back(new_room);

		 new_room = new Room("Control Room", "You can see a lot of radios and whires broken.",3);
		 entity_list.push_back(new_room);

		 new_room = new Room("Window building", "After this jump are so exhausted need to repose for a moment.",4);
		 entity_list.push_back(new_room);

		 new_room = new Room("Secret room", "You didn't see nothing interesting but a big air comes frome some part...",5);
		 entity_list.push_back(new_room);

		 new_room = new Room("Cave", "A barrier is colapsing the way, will need something strong to move it.",6);
		 entity_list.push_back(new_room);

	//	 new_room = new Room("Final boss", "The Zombie king was waitting you, now he will make you pay with the death...");
	//	 rooms.push_back(new_room);

		 new_room = new Room("Disco room", "An innocent place to meet with people... All things are on the float even the top of a ventilation shaft",7);
		 entity_list.push_back(new_room);

		 new_room = new Room("Bunker", "It seems a good place to endure, but you will not survive with out food.",8);
		 entity_list.push_back(new_room);

		 new_room = new Room("Terrace", "A big place with a landing symbol in the middle.",9);
		 entity_list.push_back(new_room);




		 int random_room = rand() % 9;

		 while (random_room == player->room_position->index)
		 {
			 random_room = rand() % 9;
		 }
		 for (unsigned int i = 0; i < entity_list.size(); i++)
		 {
			 if (entity_list[i]->type == ROOM)
			 {
				 Room* tmp = (Room*)entity_list[i];
				 if (random_room == tmp->index)
				 {

					 entity_list.push_back(new Zombie("Josep", "A beautiful bad man", 10, 2, NULL, 100, tmp, currenttime));
					 break;
				 }
			 }
		 }
		 random_room = rand() % 9;
		
		 while (random_room == player->room_position->index)
		 {
			 random_room = rand() % 9;
		 }
		 for (unsigned int i = 0; i < entity_list.size(); i++)
		 {
			 if (entity_list[i]->type == ROOM)
			 {
				 Room* tmp = (Room*)entity_list[i];
				 if (random_room == ((Room*)entity_list[i])->index)
				 {
					 Item* shotgun = new Item("shotgun", "It seems very powerfull", 400);
					 shotgun->atackweapon = 10;
					 entity_list.push_back(new Zombie("Ricard", "A beautiful bad man, with something strange", 20, 3, shotgun, 100, tmp, currenttime));
					 break;
				 }
			 }
		 }
		

		 //zombie.push_back(new Zombie("Ricard", "A beautiful bad man,with something strange", 20, 3, shotgun, 100, rooms[random_room],currenttime));

		  random_room = rand() % 9;

		 while (random_room == player->room_position->index)
		 {
			 random_room = rand() % 9;
		 }
		 for (unsigned int i = 0; i < entity_list.size(); i++)
		 {
			 if (entity_list[i]->type == ROOM)
			 {
				 Room* tmp = (Room*)entity_list[i];
				 if (random_room == ((Room*)entity_list[i])->index)
				 {
					 entity_list.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, tmp, currenttime));
					 break;
				 }
			 }
		 }
		//zombie.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, rooms[random_room],currenttime));

		// Player* new_player = new Player;
	//	 players.push_back( rooms[0]);

	Exit* new_exit = new Exit( "WC's", "A terrifyng noise comes from that direction...");
	entity_list.push_back(new_exit);

	new_exit->source = 0;
	new_exit->destiny = 1;
	new_exit->direction = east;
	new_exit->openDoor = false;


	new_exit = new Exit("Living room", "You don't see nothing strange.");
	entity_list.push_back(new_exit);

	new_exit->source = 0;
	new_exit->destiny = 2;
	new_exit->direction = west;
	new_exit->openDoor = true;

	

	new_exit = new Exit("Control Room", "Only see rubish around the floor.");
	entity_list.push_back(new_exit);

	new_exit->source = 1;
	new_exit->destiny = 3;
	new_exit->direction = east;
	new_exit->openDoor = true;

	new_exit = new Exit("Reception room", "It seems like a big room where you can find things...");
	entity_list.push_back(new_exit);

	new_exit->source = 1;
	new_exit->destiny = 0;
	new_exit->direction = west;
	new_exit->openDoor = true;

	new_exit = new Exit("WC's", "A terrifyng noise comes from that direction...");
	entity_list.push_back(new_exit);

	new_exit->source = 3;
	new_exit->destiny = 1;
	new_exit->direction = south;
	new_exit->openDoor = true;

	new_exit = new Exit("Hotel", "You need to do a big jump to arrive.");
	entity_list.push_back(new_exit);

	new_exit->source = 3;
	new_exit->destiny = 4;
	new_exit->direction = east;
	new_exit->openDoor = false;////

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	entity_list.push_back(new_exit);

	new_exit->source = 3;
	new_exit->destiny =5;
	new_exit->direction = north;
	new_exit->openDoor = true;

	new_exit = new Exit("Control room", "Only see rubish around the floor.");
	entity_list.push_back(new_exit);

	new_exit->source = 4;
	new_exit->destiny = 3;
	new_exit->direction = west;
	new_exit->openDoor = true;

	new_exit = new Exit("Control room", "Only see rubish around the floor.");
	entity_list.push_back(new_exit);

	new_exit->source = 5;
	new_exit->destiny = 3;
	new_exit->direction = east;
	new_exit->openDoor = true;

	new_exit = new Exit("Cave", "You can see a big barrier on the final.");
	entity_list.push_back(new_exit);

	new_exit->source = 5;
	new_exit->destiny = 6;
	new_exit->direction = south;
	new_exit->openDoor = true;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	entity_list.push_back(new_exit);

	new_exit->source = 5;
	new_exit->destiny = 7;
	new_exit->direction = west;
	new_exit->openDoor = true;

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	entity_list.push_back(new_exit);

	new_exit->source = 6;
	new_exit->destiny = 5;
	new_exit->direction = north;
	new_exit->openDoor = true;

	/*new_exit = new Exit("Forest", "A big shadow figure is moving in the distance...");
	exits.push_back(new_exit);

	new_exit->source = rooms[6];
	new_exit->destiny = rooms[7];
	new_exit->direction = south;
	new_exit->openDoor = true;

	new_exit = new Exit("Cave", "You can see a big barrier on the final.");
	exits.push_back(new_exit);

	new_exit->source = rooms[7];
	new_exit->destiny = rooms[6];
	new_exit->direction = north;
	new_exit->openDoor = true;*/

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	entity_list.push_back(new_exit);

	new_exit->source = 7;
	new_exit->destiny = 5;
	new_exit->direction = east;
	new_exit->openDoor = true;

	new_exit = new Exit("Bunker", "It looks like resistant...");
	entity_list.push_back(new_exit);

	new_exit->source = 7;
	new_exit->destiny = 8;
	new_exit->direction = south;
	new_exit->openDoor = false;

	new_exit = new Exit("Living room", "You don't see nothing strange.");
	entity_list.push_back(new_exit);

	new_exit->source = 7;
	new_exit->destiny =2;
	new_exit->direction = west;
	new_exit->openDoor = true;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	entity_list.push_back(new_exit);

	new_exit->source = 8;
	new_exit->destiny = 7;
	new_exit->direction = north;
	new_exit->openDoor = true;

	new_exit = new Exit("Reception room", "It seems like a big room where you can find things...");
	entity_list.push_back(new_exit);

	new_exit->source = 2;
	new_exit->destiny = 0;
	new_exit->direction = east;
	new_exit->openDoor = true;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	entity_list.push_back(new_exit);

	new_exit->source = 2;
	new_exit->destiny = 7;
	new_exit->direction = north;
	new_exit->openDoor = true;

	new_exit = new Exit("Terrace", "It seems a good exit with an helicopter...");
	entity_list.push_back(new_exit);

	new_exit->source = 2;
	new_exit->destiny = 9;
	new_exit->direction = west;
	new_exit->openDoor = false;

	new_exit = new Exit("Living room", "You don't see nothing strange.");
	entity_list.push_back(new_exit);

	new_exit->source = 9;
	new_exit->destiny = 2;
	new_exit->direction = south;
	new_exit->openDoor = true;

	//20 Exits


	/*Reception Room -> (NULL, NULL, WC, Living room);
	WC->setExits(NULL, NULL, Control Room, Reception room);
	Control room->setExits(Secret room, WC, Dinning room Exit);
	Dinning room->setExits(NULL, NULL, NULL, NULL);
	Secret room->setExits(NULL, Cave, Control room, Disco room);
	Cave->setExits(Secret room, Final boss, NULL, NULL);
	Final boss->setExits(Cave, NULL, NULL, NULL);
	Disco room->setExits(NULL, Bunker, Secret room, Living room);
	Bunker->setExits(Disco room, NULL, NULL, NULL);
	Living room->setExits(Disco room, NULL, Reception room, Terrace);
	Terrace->setExits(NULL, Living Room, NULL, NULL);*/
}

bool World::Update()
{
	char command[50];
	int temp_command = 0;
	//bool firsttimeinloop = true;


	unsigned int charcommandnum = 0;
	mString last_command;
	fflush(stdin);
	//	gets_s(command);
	while (1)
	{
		temp_command = 0;
		//Execute the code every X fractions of second (DELAY)

		currenttime = GetTickCount();
		/*if (currenttime >= (initialtime + 1000)){
			printf("Hy.\n");
			initialtime = currenttime;
			}*/
		if (_kbhit())
		{
			if (charcommandnum < (50 - 2))
			{
				command[charcommandnum] = _getch();
				command[charcommandnum + 1] = '\0';
				system("cls");
				player->Look();
				printf(" Write a comand:\n");
				//printf("%s\n", command); //Print the command 
				charcommandnum++;

				if (command[charcommandnum - 1] == '\b' && charcommandnum>1) //when you press delete, delete .
				{
					charcommandnum -= 2;
					command[charcommandnum] = '\0';
					//	printf("Your command is: %s\n\n", command);

					/*last_command = command;
					temp_command++;*/
				}
				printf("%s\n", command); //Print the command 
				if (command[charcommandnum - 1] == '\r') //when you press enter, print the command and then we clean.
				{
					//system("cls");
					printf("Your command is: %s\n\n", command);
					command[charcommandnum - 1] = '\0';
					charcommandnum = 0;
					last_command = command;
					temp_command++;
				}

			}
			else
			{
				command[50 - 1] = '\0';
				temp_command++;
			}
		}

		currenttime = GetTickCount();
		Vector <mString> Input;

		if (temp_command >= 1)
		{

			last_command.tokenize(Input);

			/*mString str1 = command;
			Vector <mString> Input;         No time librery
			str1.tokenize(Input);*/
			if (Input.size() == NULL)
			{
				printf("Write a command!\n");
				//return true;
			}



			//	strcpy_s(first, strtok_s(command, " ", &safe));
			//	if (strcmp(safe, "") != 0){
			//	strcpy_s(second, strtok_s(safe, " ", &trash));
			//}
			else
			{
				//COMMAND LOOK DIRECTION.

				if (Input[0] == "look" && Input.size() == 1)
				{
					player->Look(this);
				}
				else if (Input[0] == "look" && Input.size() == 2)
				{
					if (Input[1] == "north" || Input[1] == "n")
					{
						player->LookCommand(this, north);
					}
					else if (Input[1] == "south" || Input[1] == "s")
					{
						player->LookCommand(this, south);
					}
					else if (Input[1] == "east" || Input[1] == "e")
					{
						player->LookCommand(this, east);
					}
					else if (Input[1] == "west" || Input[1] == "w")
					{
						player->LookCommand(this, west);
					}
				}


				//COMMANDS MOVEMENT

				else if (Input[0] == "north" || Input[0] == "n")
				{

					player->Move(this, north);
				}
				else if (Input[0] == "south" || Input[0] == "s")
				{
					player->Move(this, south);
				}
				else if (Input[0] == "east" || Input[0] == "e")

				{
					player->Move(this, east);
				}

				else if (Input[0] == "west" || Input[0] == "w")
				{
					player->Move(this, west);
				}

				//COMMANDS TO GO:

				else if (Input.size() == 2 && Input[0] == "go")
				{
					if (Input[1] == "north" || Input[1] == "n")
						player->Move(this, north);

					else if (Input[1] == "south" || Input[1] == "s")
						player->Move(this, south);

					else if (Input[1] == "east" || Input[1] == "e")
						player->Move(this, east);

					else if (Input[1] == "west" || Input[1] == "w")
						player->Move(this, west);

				}


				//COMMAND OPEN DOOR

				else if (Input[0] == "open" && Input.size() == 2)
				{

					if (Input[1] == "north" || Input[1] == "n")
					{
						player->OpenDoor(this, north);
					}
					else if (Input[1] == "south" || Input[1] == "s")
					{
						player->OpenDoor(this, south);
					}
					else if (Input[1] == "east" || Input[1] == "e")
					{
						player->OpenDoor(this, east);
					}
					else if (Input[1] == "west" || Input[1] == "w")
					{
						player->OpenDoor(this, west);
					}
				}

				//COMMAND CLOSE DOOR

				else if (Input[0] == "close" && Input.size() == 2)
				{

					if (Input[1] == "north" || Input[1] == "n")
					{
						player->CloseDoor(this, north);
					}
					else if (Input[1] == "south" || Input[1] == "s")
					{
						player->CloseDoor(this, south);
					}
					else if (Input[1] == "east" || Input[1] == "e")
					{
						player->CloseDoor(this, east);
					}
					else if (Input[1] == "west" || Input[1] == "w")
					{
						player->CloseDoor(this, west);
					}
				}
				//COMMAND ATTACK
				else if (Input[0] == "attack" && Input.size() == 1) //ATTACK
				{
					player->Attack(this, currenttime);
				}

				//COMMAND SPECIAL ATTACK

				else if (Input[0] == "special" && Input[1] == "bomb" && Input.size() == 2)
				{
					player->SpecialAttack(this, currenttime);
				}
				//COMMAND PICK

				else if (Input[0] == "pick" && Input.size() == 2)
				{
					player->Pick(Input[1]);
				}

				// COMAND DROP

				else if (Input[0] == "drop" && Input.size() == 2)
				{
					player->Drop(Input[1].c_str());
				}
				//INVENTORY
				else if (Input[0] == "inventory" || Input[0] == "inv" || Input[0] == "i" && Input.size() == 1)
				{
					player->DisplayInv();
				}
				//EQUIP
				else if (Input[0] == "equip"  && Input.size() == 2)
				{
					player->equiped(Input[1].c_str());
				}
				//UNEQUIP
				else if (Input[0] == "unequip"  && Input.size() == 2)
				{
					player->unequiped(Input[1].c_str());
				}
				//BUY INVENTORY DIANA
				else if (Input[0] == "buy" && Input[1] == "diana" && Input.size() == 2 || Input[0] == "buy" && Input[1] == "Diana" && Input.size() == 2)
				{
					for (unsigned int i = 0; i < entity_list.size(); i++)
					{
						if (entity_list[i]->type == NPC)
						{
							Npc* tmp = ((Npc*)entity_list[i]);
							if (tmp->room_position->index == player->room_position->index)
							{
								tmp->DisplayInventory();
								break;
							}
							
						}
					}

				}

				//BUY FROM DIANA
				else if ((Input.size() == 4 && Input[0] == "buy" && Input[2] == "from" && Input[3] == "diana") || (Input.size() == 4 && Input[2] == "from" && Input[0] == "buy" && Input[3] == "Diana"))
				{
					bool found = false;
					for (unsigned int i = 0; i < entity_list.size(); i++)
					{
						if (entity_list[i]->type == NPC)
						{
							Npc* tmp = ((Npc*)entity_list[i]);
							if (tmp->room_position->index == player->room_position->index)
							{
								tmp->SellToPlayer(Input[1].c_str(), player);
								found = true;
								break;
							}
							
						}
					}
					if (found == false)
					{
						printf("There is no NPC called Diana in the room!");
					}
				}
				//SELL FROM DIANA
				else if ((Input.size() == 4 && Input[0] == "sell" && Input[2] == "to" && Input[3] == "diana") || (Input.size() == 4 && Input[2] == "to" && Input[0] == "sell" && Input[3] == "Diana"))
				{
					bool found = false;
					for (unsigned int i = 0; i < entity_list.size(); i++)
					{
						if (entity_list[i]->type == NPC)
						{
							Npc* tmp = ((Npc*)entity_list[i]);
							if (tmp->room_position->index == player->room_position->index)
							{
								tmp->BuyFromPlayer(Input[1].c_str(), player);
								found = true;
								break;
							}
						}
						
					}
					if (found == false)
					{
						printf("There is no NPC called Diana in the room!");
					}
				}
				//DEBUG
				else if ((Input.size() == 2 && Input[0] == "free" && Input[1] == "coins"))
				{
					player->coins += 1000;
					printf("You get 1000 coins!\n");
				}
				//TELEPORT
				else if ((Input.size() == 3 && Input[0] == "teleport" && Input[1] == "room"))
				{
					int room_num = std::stoi(Input[2].c_str());
					bool found = false;
					for (unsigned int i = 0; i < entity_list.size(); i++)
					{
						if (entity_list[i]->type == ROOM)
						{
							if (((Room*)entity_list[i])->index == room_num)
							{
								player->room_position = ((Room*)entity_list[i]);
								found = true;
								break;
							}
						}
					}
					if (found == true)
					{
						system("cls");
						player->Look();
						printf("\nYou have been teleported!\n");
					}

					else printf("The room doesn't exist.\n");

				}

				// PUT SWORD INTO BOX

				else if (Input[0] == "put" && Input[2] == "into"  && Input.size() == 4)
				{
					player->Put(Input[1], Input[3]);
				}
				// get SWORD from BOX

				else if (Input[0] == "get" && Input[2] == "from"  && Input.size() == 4)
				{
					player->Get(Input[1], Input[3]);
				}
				// COMMAND HELP

				else if (Input[0] == "help" && Input.size() == 1)
				{
					player->Help();
				}

				//QUIT GAMME
				else if (Input[0] == "quit" && Input.size() == 1)
				{
					return false;
				}
				//NO ONE COMMAND

				else
				{
					printf("I don't understand that command. \n");
				}

			}
		}

		if (player->Update(this, currenttime) == false)
		{
			lose = true;
		}

		for (unsigned int i = 0; i < entity_list.size() && lose == false; i++)
		{
			if (entity_list[i]->type == ZOMBIE)
			{
				Zombie* tmp = ((Zombie*)entity_list[i]);
				//printf("Zombie update numero: %i", i);
				if (tmp->type == ZOMBIE && tmp->Update(this, player, currenttime) == false)
				{

					entity_list.Pick(i);
					i--;
					delete tmp;
					tmp = NULL;

					Creating_zombie();
				}
			}
			/*	if (zombie[i]->room_position == player->room_position)
				{
				zombie[i]->state = ATTACK;
				}
				*/
		}
		if (lose == true)
		{
			return false;
		}

	}
	return true;
}

Room* World::Value_to_room(int value)
{
	for (unsigned int i = 0; i < entity_list.size(); i++)
	{
		if (entity_list[i]->type == ROOM)
		{
			if (((Room*)entity_list[i])->index == value)
			{
				return ((Room*)entity_list[i]);
				break;
			}
		}		
	}
	return NULL;
}

void World::Creating_zombie()
{
	int random = rand() % 2;
	int random_room = rand() % 9;

	while (random_room == player->room_position->index)
	{
		random_room = rand() % 9;
	}
	switch (random)
	{
	case 0:
	{
			  for (unsigned int i = 0; i < entity_list.size(); i++)
			  {
				  if (entity_list[i]->type == ROOM)
				  {
					  if (((Room*)entity_list[i])->index == random_room)
					  {
						  entity_list.push_back(new Zombie("Josep", "A beautiful bad man", 10, 2, NULL, 100, ((Room*)entity_list[i]), currenttime));
					  }
				  }
			  }


	}
	case 1:
	{
			  for (unsigned int i = 0; i < entity_list.size(); i++)
			  {
				  if (entity_list[i]->type == ROOM)
				  {
					  if (((Room*)entity_list[i])->index == random_room)
					  {
						  Item* sword1 = new Item("Sword", "Sharppened", 150);
						  sword1->atackweapon = 4;
						  entity_list.push_back(new Zombie("Ricard", "A beautiful bad man", 10, 2, sword1, 100, ((Room*)entity_list[i]), currenttime));
					  }
				  }
			  }
			  /* Item* sword1 = new Item("Sword", "Sharppened", 150);
			   sword1->atackweapon = 4;
			   entity_list.push_back(new Zombie("Ricard", "A beautiful bad man", 10, 2, sword1, 100, random_room, currenttime));*/
	}

	case 2:
	{
			  for (unsigned int i = 0; i < entity_list.size(); i++)
			  {
				  if (entity_list[i]->type == ROOM)
				  {
					  if (((Room*)entity_list[i])->index == random_room)
					  {
						  entity_list.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, ((Room*)entity_list[i]), currenttime));
					  }
				  }
			  }

			  // entity_list.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, random_room, currenttime));
	}
	default:
		break;
	}

}
World::~World()
{
	/*for (unsigned int i = 0; i < entity_list.size(); i++)
	{
		if (entity_list[i]!=NULL)
		delete entity_list[i];
	}*/
	
	
	delete player;
	
	entity_list.clear();
//	delete[] rooms;
//	delete  players;
//	delete[] exits;
}