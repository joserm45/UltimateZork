#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "conio.h"
#include "String.h"
#include "Zombie.h"
#include "Item.h"
#include "World.h"
#include "Player.h"
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


void World::CreateWorld(){
	//	rooms = new Room;

	Item* sword1 = new Item("Sword", "Sharppened");
	sword1->atackweapon = 4;
	Item* gun = new Item("Sun", "Can kill zombies!");
	gun->atackweapon = 6;

	Item* chest = new Item("Chest", "Save items!");



	Room* new_room = new Room("Reception Room:", "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange.");
	rooms.push_back(new_room);

	Player*	new_players = new Player(NULL, rooms[0]);
	players.push_back(new_players);


	rooms[0]->items.push_back(sword1);
	rooms[0]->items.push_back(gun);
	rooms[0]->items.push_back(chest);

		 new_room = new Room("WC's", "A slight breathing is heard in the room. It seems that something scary this about to happen.");
		 rooms.push_back(new_room);
	
	     new_room = new Room("Living Room", "You can see a lot of papers on the floor.");
		 rooms.push_back(new_room);

		 new_room = new Room("Window building", "After this jump are so exhausted need to repose for a moment.");
		 rooms.push_back(new_room);

		 new_room = new Room("Secret room", "You didn't see nothing interesting but a big air comes frome some part...");
		 rooms.push_back(new_room);

		 new_room = new Room("Cave", "A barrier is colapsing the way, will need something strong to move it.");
		 rooms.push_back(new_room);

		 new_room = new Room("Final boss", "The Zombie king was waitting you, now he will make you pay with the death...");
		 rooms.push_back(new_room);

		 new_room = new Room("Disco room", "An innocent place to meet with people... All things are on the float even the top of a ventilation shaft");
		 rooms.push_back(new_room);

		 new_room = new Room("Bunker", "It seems a good place to endure, but you will not survive with out food.");
		 rooms.push_back(new_room);

		 new_room = new Room("Terrace", "A big place with a landing symbol in the middle.");
		 rooms.push_back(new_room);

		 int random_room = rand() % 9;

		 while (rooms[random_room] == players[0]->room_position)
		 {
			 random_room = rand() % 9;
		 }

		 zombie.push_back(new Zombie("Josep", "A beautiful bad man", 10, 2, NULL, 100, rooms[random_room]));  

		 random_room = rand() % 9;

		 while (rooms[random_room] == players[0]->room_position)
		 {
			 random_room = rand() % 9;
		 }
		 Item* sword2 = new Item("Sword", "Sharppened");
		 sword1->atackweapon = 4;
		 zombie.push_back(new Zombie("Ricard", "A beautiful bad man", 10, 2, sword1, 100, rooms[0]));

		  random_room = rand() % 9;

		 while (rooms[random_room] == players[0]->room_position)
		 {
			 random_room = rand() % 9;
		 }

		 zombie.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, rooms[random_room]));

		// Player* new_player = new Player;
	//	 players.push_back( rooms[0]);

	Exit* new_exit = new Exit( "WC's", "A terrifyng noise comes from that direction...");
	exits.push_back(new_exit);

	exits[0]->source = rooms[0];
	exits[0]->destiny = rooms[1];
	exits[0]->direction = east;
	exits[0]->openDoor = false;


	new_exit = new Exit("Living room", "You don't see nothing strange.");
	exits.push_back(new_exit);

	exits[1]->source = rooms[0];
	exits[1]->destiny = rooms[2];
	exits[1]->direction = west;
	exits[1]->openDoor = false;

	

	new_exit = new Exit("Control Room", "Only see rubish around the floor.");
	exits.push_back(new_exit);

	exits[2]->source = rooms[1];
	exits[2]->destiny = rooms[3];
	exits[2]->direction = east;
	exits[2]->openDoor = true;

	new_exit = new Exit("Reception room", "It seems like a big room where you can find things...");
	exits.push_back(new_exit);

	exits[3]->source = rooms[1];
	exits[3]->destiny = rooms[0];
	exits[3]->direction = west;
	exits[3]->openDoor = true;

	new_exit = new Exit("WC's", "A terrifyng noise comes from that direction...");
	exits.push_back(new_exit);

	exits[4]->source = rooms[3];
	exits[4]->destiny = rooms[1];
	exits[4]->direction = south;
	exits[4]->openDoor = false;

	new_exit = new Exit("Hotel", "You need to do a big jump to arrive.");
	exits.push_back(new_exit);

	exits[5]->source = rooms[3];
	exits[5]->destiny = rooms[4];
	exits[5]->direction = east;
	exits[5]->openDoor = false;

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	exits.push_back(new_exit);

	exits[6]->source = rooms[3];
	exits[6]->destiny = rooms[5];
	exits[6]->direction = north;
	exits[6]->openDoor = true;

	new_exit = new Exit("Control room", "Only see rubish around the floor.");
	exits.push_back(new_exit);

	exits[7]->source = rooms[4];
	exits[7]->destiny = rooms[3];
	exits[7]->direction = west;
	exits[7]->openDoor = true;

	new_exit = new Exit("Control room", "Only see rubish around the floor.");
	exits.push_back(new_exit);

	exits[8]->source = rooms[5];
	exits[8]->destiny = rooms[3];
	exits[8]->direction = east;
	exits[8]->openDoor = false;

	new_exit = new Exit("Cave", "You can see a big barrier on the final.");
	exits.push_back(new_exit);

	exits[9]->source = rooms[5];
	exits[9]->destiny = rooms[6];
	exits[9]->direction = south;
	exits[9]->openDoor = false;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	exits.push_back(new_exit);

	exits[10]->source = rooms[5];
	exits[10]->destiny = rooms[8];
	exits[10]->direction = west;
	exits[10]->openDoor = true;

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	exits.push_back(new_exit);

	exits[11]->source = rooms[6];
	exits[11]->destiny = rooms[5];
	exits[11]->direction = north;
	exits[11]->openDoor = true;

	new_exit = new Exit("Forest", "A big shadow figure is moving in the distance...");
	exits.push_back(new_exit);

	exits[12]->source = rooms[6];
	exits[12]->destiny = rooms[7];
	exits[12]->direction = south;
	exits[12]->openDoor = true;

	new_exit = new Exit("Cave", "You can see a big barrier on the final.");
	exits.push_back(new_exit);

	exits[13]->source = rooms[7];
	exits[13]->destiny = rooms[6];
	exits[13]->direction = north;
	exits[13]->openDoor = true;

	new_exit = new Exit("Secret room", "You feel a frozen air coming from it.");
	exits.push_back(new_exit);

	exits[14]->source = rooms[8];
	exits[14]->destiny = rooms[5];
	exits[14]->direction = east;
	exits[14]->openDoor = true;

	new_exit = new Exit("Bunker", "It looks like resistant...");
	exits.push_back(new_exit);

	exits[15]->source = rooms[8];
	exits[15]->destiny = rooms[9];
	exits[15]->direction = south;
	exits[15]->openDoor = false;

	new_exit = new Exit("Living room", "You don't see nothing strange.");
	exits.push_back(new_exit);

	exits[16]->source = rooms[8];
	exits[16]->destiny = rooms[2];
	exits[16]->direction = west;
	exits[16]->openDoor = true;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	exits.push_back(new_exit);

	exits[17]->source = rooms[9];
	exits[17]->destiny = rooms[8];
	exits[17]->direction = north;
	exits[17]->openDoor = false;

	new_exit = new Exit("Reception room", "It seems like a big room where you can find things...");
	exits.push_back(new_exit);

	exits[18]->source = rooms[2];
	exits[18]->destiny = rooms[0];
	exits[18]->direction = east;
	exits[18]->openDoor = true;

	new_exit = new Exit("Disco room", "It seems to have been unturned to search  something there...");
	exits.push_back(new_exit);

	exits[19]->source = rooms[2];
	exits[19]->destiny = rooms[8];
	exits[19]->direction = north;
	exits[19]->openDoor = true;

	new_exit = new Exit("Terrace", "It seems a good exit with an helicopter...");
	exits.push_back(new_exit);

	exits[20]->source = rooms[2];
	exits[20]->destiny = rooms[10];
	exits[20]->direction = west;
	exits[20]->openDoor = false;

	new_exit = new Exit("Living room", "You don't see nothing strange.");
	exits.push_back(new_exit);

	exits[21]->source = rooms[10];
	exits[21]->destiny = rooms[2];
	exits[21]->direction = south;
	exits[21]->openDoor = true;

	//21 Exits


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

bool World::Update(){
	char command[50];
	
	//bool firsttimeinloop = true;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;
	mString last_command;
	fflush(stdin);
	while (1)
	{
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
				printf("String: %s\n", command); //Print the command with the delay
				charcommandnum++;
				if (command[charcommandnum - 1] == '\r') //when you press enter, print the command and then we clean.
				{
					printf("Your command is: %s\n", command);
					command[charcommandnum] = '\0';
					charcommandnum = 0;
					last_command = command;
				}
			}
			else
			{
				command[50 - 1] = '\0';
			}
		}

		//currenttime = GetTickCount();
		Vector <mString> Input;
		last_command = command;
		
		last_command.tokenize(Input);
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
				players[0]->Look();
			}
			else if (Input[0] == "look" && Input.size() == 2)
			{
				if (Input[1] == "north" || Input[1] == "n")
				{
					players[0]->LookCommand(this, north);
				}
				else if (Input[1] == "south" || Input[1] == "s")
				{
					players[0]->LookCommand(this, south);
				}
				else if (Input[1] == "east" || Input[1] == "e")
				{
					players[0]->LookCommand(this, east);
				}
				else if (Input[1] == "west" || Input[1] == "w")
				{
					players[0]->LookCommand(this, west);
				}
			}


			//COMMANDS MOVEMENT

			else if (Input[0] == "north" || Input[0] == "n")
			{
				players[0]->Move(this, north);
			}
			else if (Input[0] == "south" || Input[0] == "s")
			{
				players[0]->Move(this, south);
			}
			else if (Input[0] == "east" || Input[0] == "e")

			{
				players[0]->Move(this, east);
			}

			else if (Input[0] == "west" || Input[0] == "w")
			{
				players[0]->Move(this, west);
			}

			//COMMANDS TO GO:

			else if (Input.size() == 2 && Input[0] == "go")
			{
				if (Input[1] == "north" || Input[1] == "n")
					players[0]->Move(this, north);

				else if (Input[1] == "south" || Input[1] == "s")
					players[0]->Move(this, south);

				else if (Input[1] == "east" || Input[1] == "e")
					players[0]->Move(this, east);

				else if (Input[1] == "west" || Input[1] == "w")
					players[0]->Move(this, west);

			}


			//COMMAND OPEN DOOR

			else if (Input[0] == "open" && Input.size() == 2)
			{

				if (Input[1] == "north" || Input[1] == "n")
				{
					players[0]->OpenDoor(this, north);
				}
				else if (Input[1] == "south" || Input[1] == "s")
				{
					players[0]->OpenDoor(this, south);
				}
				else if (Input[1] == "east" || Input[1] == "e")
				{
					players[0]->OpenDoor(this, east);
				}
				else if (Input[1] == "west" || Input[1] == "w")
				{
					players[0]->OpenDoor(this, west);
				}
			}

			//COMMAND CLOSE DOOR

			else if (Input[0] == "close" && Input.size() == 2)
			{

				if (Input[1] == "north" || Input[1] == "n")
				{
					players[0]->CloseDoor(this, north);
				}
				else if (Input[1] == "south" || Input[1] == "s")
				{
					players[0]->CloseDoor(this, south);
				}
				else if (Input[1] == "east" || Input[1] == "e")
				{
					players[0]->CloseDoor(this, east);
				}
				else if (Input[1] == "west" || Input[1] == "w")
				{
					players[0]->CloseDoor(this, west);
				}
			}
			//COMMAND ATTACK
			else if (Input[0] == "attack" && Input.size() == 1) //ATTACK
			{
				players[0]->Attack(this);
			}

			//COMMAND SPECIAL ATTACK

			else if (Input[0] == "special" && Input.size() == 2)
			{
				//players[0]->SpecialAttack(this, Input[1].c_str);
			}
			//COMMAND PICK

			else if (Input[0] == "pick" && Input.size() == 2)
			{
				players[0]->Pick(Input[1]);
			}

			// COMAND DROP

			else if (Input[0] == "drop" && Input.size() == 2)
			{
				players[0]->Drop(Input[1].c_str());
			}
			//INVENTORY
			else if (Input[0] == "inventory" || Input[0] == "inv" || Input[0] == "i" && Input.size() == 1)
			{
				players[0]->DisplayInv();
			}
			//EQUIP
			else if (Input[0] == "equip"  && Input.size() == 2)
			{
				players[0]->equiped(Input[1].c_str());
			}
			//UNEQUIP
			else if (Input[0] == "unequip"  && Input.size() == 2)
			{
				players[0]->unequiped(Input[1].c_str());
			}

			// PUT SWORD INTO BOX

			else if (Input[0] == "put" && Input[2] == "into"  && Input.size() == 4)
			{
				players[0]->Put(Input[1], Input[3]);
			}
			// get SWORD from BOX

			else if (Input[0] == "get" && Input[2] == "from"  && Input.size() == 4)
			{
				players[0]->Get(Input[1], Input[3]);
			}
			// COMMAND HELP

			else if (Input[0] == "help" && Input.size() == 1)
			{
				players[0]->Help();
			}

			//QUIT GAMME
			else if (Input[0] == "quit" && Input.size() == 1)
			{
				return false;
			}
			//NO ONE COMMAND

			else
			{
				//printf("I don't understand that command. \n");
			}

		}
		players[0]->Update(this);

		for (unsigned int i = 0; i < zombie.size() && lose == false; i++)
		{

		//	printf("Zombie update numero: %i", i);
			if (zombie[i]->Update(this, players[0]) == false)
			{
				zombie.Pick(i);
				i--;
			}

		}
		while (zombie.size() <= 2)
		{
			int random = rand() % 2;
			int random_room = rand() % 9;

			while (rooms[random_room] == players[0]->room_position)
			{
				random_room = rand() % 9;
			}
			switch (random)
			{
			case 0:
			{
					  zombie.push_back(new Zombie("Josep", "A beautiful bad man", 10, 2, NULL, 100, rooms[random_room]));


			}
			case 1:
			{
					  Item* sword1 = new Item("Sword", "Sharppened");
					  sword1->atackweapon = 4;
					  zombie.push_back(new Zombie("Ricard", "A beautiful bad man", 10, 2, sword1, 100, rooms[random_room]));
			}

			case 2:
			{
					  zombie.push_back(new Zombie("Jordi", "A beautiful bad man", 10, 2, NULL, 100, rooms[random_room]));
			}
			default:
				break;
			}
		}
		if (lose == true)
		{
			return false;
		}
		
	}
	return true;
}





World::~World()
{

//	delete[] rooms;
//	delete  players;
//	delete[] exits;
}