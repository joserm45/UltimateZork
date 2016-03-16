#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Exits.h"


#include "World.h"
#include "Player.h"
#include "Rooms.h"
#include "Exits.h"

#define _CTR_SECURE_NO_WARNINGS

World::World(){

	rooms = new Room[10];
	players = new Player;
	exits = new Exit[22];
	//player -> player = this;
}


void World::CreateWorld(){

	strcpy_s(rooms[0].name, "Reception Room:");
	strcpy_s(rooms[0].description, "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange.");
	strcpy_s(rooms[1].name, "WC's");
	strcpy_s(rooms[1].description, "a slight breathing is heard in the room. It seems that something scary this about to happen.");
	strcpy_s(rooms[2].name, "Living Room");
	strcpy_s(rooms[2].description, "You can see a lot of papers on the floor.");
	strcpy_s(rooms[3].name, "Control room");
	strcpy_s(rooms[3].description, "Reception Room");
	strcpy_s(rooms[4].name, "Window building");
	strcpy_s(rooms[4].description, "Reception Room");
	strcpy_s(rooms[5].name, "Secret room");
	strcpy_s(rooms[5].description, "Reception Room");
	strcpy_s(rooms[6].name, "Cave");
	strcpy_s(rooms[6].description, "Reception Room");
	strcpy_s(rooms[7].name, "Final boss");
	strcpy_s(rooms[7].description, "Reception Room");
	strcpy_s(rooms[8].name, "Disco room");
	strcpy_s(rooms[8].description, "Reception Room");
	strcpy_s(rooms[9].name, "Bunker");
	strcpy_s(rooms[9].description, "Reception Room");
	strcpy_s(rooms[10].name, "Terrace");
	strcpy_s(rooms[10].description, "Reception Room");

	

	players->posPlayer = &rooms[0];

	exits[0].source = &rooms[0];
	exits[0].destiny = &rooms[1];
	exits[0].direction = east;
	exits[0].openDoor = false;
	strcpy_s(exits[0].name, "WC's");
	strcpy_s(exits[0].description, "ddddddd");


	exits[1].source = &rooms[0];
	exits[1].destiny = &rooms[2];
	exits[1].direction = west;
	exits[1].openDoor = false;
	strcpy_s(exits[1].name, "Living room");
	strcpy_s(exits[1].description, "kk");


	exits[19].source = &rooms[1];
	exits[19].destiny = &rooms[3];
	exits[19].direction = east;
	exits[19].openDoor = true;
	strcpy_s(exits[19].name, "Control Room");
	strcpy_s(exits[19].description, "pp");


	exits[2].source = &rooms[1];
	exits[2].destiny = &rooms[0];
	exits[2].direction = west;
	exits[2].openDoor = false;
	strcpy_s(exits[2].name, "Reception room");
	strcpy_s(exits[2].description, "fddd");


	exits[3].source = &rooms[3];
	exits[3].destiny = &rooms[1];
	exits[3].direction = south;
	exits[3].openDoor = false;
	strcpy_s(exits[3].name, "WC's");
	strcpy_s(exits[3].description, "jjjj");


	exits[4].source = &rooms[3];
	exits[4].destiny = &rooms[4];
	exits[4].direction = east;
	exits[4].openDoor = false;
	strcpy_s(exits[4].name, "Hotel");
	strcpy_s(exits[4].description, "gg");

	exits[5].source = &rooms[3];
	exits[5].destiny = &rooms[5];
	exits[5].direction = north;
	exits[5].openDoor = true;
	strcpy_s(exits[5].name, "Secret room");
	strcpy_s(exits[5].description, "ddfs");

	exits[6].source = &rooms[4];
	exits[6].destiny = &rooms[3];
	exits[6].direction = west;
	exits[6].openDoor = true;
	strcpy_s(exits[6].name, "Control room");
	strcpy_s(exits[6].description, "ddfs");


	exits[7].source = &rooms[5];
	exits[7].destiny = &rooms[3];
	exits[7].direction = east;
	exits[7].openDoor = false;
	strcpy_s(exits[7].name, "Control room");
	strcpy_s(exits[7].description, "yeee");


	exits[8].source = &rooms[5];
	exits[8].destiny = &rooms[6];
	exits[8].direction = south;
	exits[8].openDoor = false;
	strcpy_s(exits[8].name, "Cave");
	strcpy_s(exits[8].description, "ddfs");

	exits[9].source = &rooms[5];
	exits[9].destiny = &rooms[8];
	exits[9].direction = west;
	exits[9].openDoor = true;
	strcpy_s(exits[9].name, "Disco room");
	strcpy_s(exits[9].description, "ddfs");

	exits[10].source = &rooms[6];
	exits[10].destiny = &rooms[5];
	exits[10].direction = north;
	exits[10].openDoor = true;
	strcpy_s(exits[10].name, "Secret room");
	strcpy_s(exits[10].description, "ddfs");

	exits[11].source = &rooms[6];
	exits[11].destiny = &rooms[7];
	exits[11].direction = south;
	exits[11].openDoor = true;
	strcpy_s(exits[11].name, "Forest");
	strcpy_s(exits[11].description, "ddfs");

	exits[20].source = &rooms[7];
	exits[20].destiny = &rooms[6];
	exits[20].direction = north;
	exits[20].openDoor = true;
	strcpy_s(exits[20].name, "Cave");
	strcpy_s(exits[20].description, "ddfs");

	exits[12].source = &rooms[8];
	exits[12].destiny = &rooms[5];
	exits[12].direction = east;
	exits[12].openDoor = true;
	strcpy_s(exits[12].name, "Secret room");
	strcpy_s(exits[12].description, "ddfs");

	exits[13].source = &rooms[8];
	exits[13].destiny = &rooms[9];
	exits[13].direction = south;
	exits[13].openDoor = false;
	strcpy_s(exits[13].name, "Bunker");
	strcpy_s(exits[13].description, "ddfs");


	exits[14].source = &rooms[8];
	exits[14].destiny = &rooms[2];
	exits[14].direction = west;
	exits[14].openDoor = true;
	strcpy_s(exits[14].name, "Living room");
	strcpy_s(exits[14].description, "ddfs");


	exits[15].source = &rooms[9];
	exits[15].destiny = &rooms[8];
	exits[15].direction = north;
	exits[15].openDoor = false;
	strcpy_s(exits[15].name, "Disco room");
	strcpy_s(exits[15].description, "ddfs");


	exits[16].source = &rooms[2];
	exits[16].destiny = &rooms[0];
	exits[16].direction = east;
	exits[16].openDoor = true;
	strcpy_s(exits[16].name, "Reception room");
	strcpy_s(exits[16].description, "ddfs");


	exits[21].source = &rooms[2];
	exits[21].destiny = &rooms[8];
	exits[21].direction = north;
	exits[21].openDoor = true;
	strcpy_s(exits[21].name, "Disco room");
	strcpy_s(exits[21].description, "ddfs");


	exits[17].source = &rooms[2];
	exits[17].destiny = &rooms[10];
	exits[17].direction = west;
	exits[17].openDoor = false;
	strcpy_s(exits[17].name, "Terrace");
	strcpy_s(exits[17].description, "ddfs");


	exits[18].source = &rooms[10];
	exits[18].destiny = &rooms[2];
	exits[18].direction = south;
	exits[18].openDoor = true;
	strcpy_s(exits[18].name, "Living room");
	strcpy_s(exits[18].description, "ddfs");

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

bool World::Command(){
	char command[20];
	char command1;
	char first[15];
	char second[15];
	char* safe;
	char* safe2;
	char* trash;
	fflush(stdin);
	strcpy_s(second, "void");
	
	gets_s(command);
	if (strcmp("\0", command) == 0){
		printf("Write a command!\n");
		return  true;
	}
	

	strcpy_s(first, strtok_s(command, " ", &safe));
	if (strcmp(safe, "") != 0){
		strcpy_s(second, strtok_s(NULL, " ", &safe2));
	}
	

	//COMMAND LOOK DIRECTION.


	if (strcmp(first, "look") == 0){
		if (strcmp(second, "void") == 0){
			players->Look();
		}
		else if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0){
			players->LookCommand(this, north);
		}
		else if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0){
			players->LookCommand(this, south);
		}
		else if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0){
			players->LookCommand(this, east);
		}
		else if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0){
			players->LookCommand(this, west);
		}

	}


		//COMMANDS MOVEMENT

		else if (strcmp(first, "north") == 0 || strcmp(first, "n") == 0){
			players->MovePlayer(this, north);
		}
		else if (strcmp(first, "south") == 0 || strcmp(first, "s") == 0){
			players->MovePlayer(this, south);
		}
		else if (strcmp(first, "east") == 0 || strcmp(first, "e") == 0){
			players->MovePlayer(this, east);
		}
		else if (strcmp(first, "west") == 0 || strcmp(first, "w") == 0){
			players->MovePlayer(this, west);
		}

		//COMMANDS TO GO:

		else if (strcmp(first, "go") == 0){
			if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0){
				players->MovePlayer(this, north);
			}
			if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0){
				players->MovePlayer(this, south);

			}
			if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0){
				players->MovePlayer(this, east);

			}
			if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0){
				players->MovePlayer(this, west);

			}
		}
		



		//COMMAND OPEN DOOR

		else if (strcmp(first, "open") == 0){
			if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0){
				players->OpenDoor(this, north);
			}
			if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0){
				players->OpenDoor(this, south);
			}
			if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0){
				players->OpenDoor(this, east);
			}
			if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0){
				players->OpenDoor(this, west);
			}
		}

		//COMMAND CLOSE DOOR

		else if (strcmp(first, "close") == 0){
			if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0){
				players->CloseDoor(this, north);
			}
			if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0){
				players->CloseDoor(this, south);
			}
			if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0){
				players->CloseDoor(this, east);
			}
			if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0){
				players->CloseDoor(this, west);
			}
		}

		// COMMAND HELP

		else if (strcmp(first, "help") == 0){
			players->Help();
		}

		//QUIT GAMME
		else if (strcmp(first, "quit") == 0 || strcmp(first, "q") == 0){
			return false;
		}
		//NO ONE COMMAND
	
	else{
			printf("I don't understand that command. \n");
		}

		return true;
	
}





World::~World(){

	delete[] rooms;
	delete  players;
	delete[] exits;
}