#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"

#include "String.h"


#include "World.h"
#include "Player.h"
#include "Rooms.h"
#include "Exits.h"
#include "Entity.h"

#define _CTR_SECURE_NO_WARNINGS

World::World(){


	//Vector <Room*> rooms;
//	Vector <Player*> players;
//	Vector <Exit*> exits;
	rooms = new Room[11];
	players = new Player;
	exits = new Exit[22];
	//player -> player = this;
}


void World::CreateWorld(){
//	rooms = new Room;
//	rooms.push_back(new Room("Reception Room:", "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange."));
	rooms[0].name = "Reception Room:";

	rooms[0].description= "In the middle of the room there is a large broken counter. You can also see a lot of wires on the ground, as if it had been something strange.";
	rooms[1].name= "WC's";
	rooms[1].description= "a slight breathing is heard in the room. It seems that something scary this about to happen.";
	rooms[2].name= "Living Room";
	rooms[2].description= "You can see a lot of papers on the floor.";
	rooms[3].name= "Control room";
	rooms[3].description= "You can not see well, but you can perceive brokens machines on the floor, and many broken radios...\n";
	rooms[4].name= "Window building";
	rooms[4].description= "After this jump are so exhausted need to repose for a moment.\n";
	rooms[5].name= "Secret room";
	rooms[5].description = "You didn't see nothing interesting but a big air comes frome some part...\n";
	rooms[6].name= "Cave";
	rooms[6].description = "A barrier is colapsing the way, will need something strong to move it.";
	rooms[7].name= "Final boss";
	rooms[7].description = "The king Zombie was waitting you, now he will make you pay with the death...\n";
	rooms[8].name= "Disco room";
	rooms[8].description= "An innocent place to meet with people... All things are on the float even the top of a ventilation shaft\n";
	rooms[9].name= "Bunker";
	rooms[9].description= "It seems a good place to endure, but you will not survive with out food.\n";
	rooms[10].name= "Terrace";
	rooms[10].description= "A big place with a landing symbol in the middle.\n";

	

	players->posPlayer = &rooms[0];

	exits[0].source = &rooms[0];
	exits[0].destiny = &rooms[1];
	exits[0].direction = east;
	exits[0].openDoor = false;
	exits[0].name= "WC's";
	exits[0].description= "A terrifyng noise comes from that direction...\n";


	exits[1].source = &rooms[0];
	exits[1].destiny = &rooms[2];
	exits[1].direction = west;
	exits[1].openDoor = false;
	exits[1].name= "Living room";
	exits[1].description= "You don't see nothing strange.\n";


	exits[19].source = &rooms[1];
	exits[19].destiny = &rooms[3];
	exits[19].direction = east;
	exits[19].openDoor = true;
	exits[19].name = "Control Room";
	exits[19].description = "Only see rubish around the floor.\n";


	exits[2].source = &rooms[1];
	exits[2].destiny = &rooms[0];
	exits[2].direction = west;
	exits[2].openDoor = true;
	exits[2].name= "Reception room";
	exits[2].description= "It seems like a big room where you can find things...\n";


	exits[3].source = &rooms[3];
	exits[3].destiny = &rooms[1];
	exits[3].direction = south;
	exits[3].openDoor = false;
	exits[3].name= "WC's";
	exits[3].description= "A terrifyng noise comes from that direction...\n";


	exits[4].source = &rooms[3];
	exits[4].destiny = &rooms[4];
	exits[4].direction = east;
	exits[4].openDoor = false;
	exits[4].name= "Hotel";
	exits[4].description= "You need to do a big jump to arrive.\n";

	exits[5].source = &rooms[3];
	exits[5].destiny = &rooms[5];
	exits[5].direction = north;
	exits[5].openDoor = true;
	exits[5].name= "Secret room";
	exits[5].description= "You feel a frozen air coming from it.\n";

	exits[6].source = &rooms[4];
	exits[6].destiny = &rooms[3];
	exits[6].direction = west;
	exits[6].openDoor = true;
	exits[6].name= "Control room";
	exits[6].description= "Only see rubish around the floor.\n";


	exits[7].source = &rooms[5];
	exits[7].destiny = &rooms[3];
	exits[7].direction = east;
	exits[7].openDoor = false;
	exits[7].name= "Control room";
	exits[7].description= "Only see rubish around the floor.\n";


	exits[8].source = &rooms[5];
	exits[8].destiny = &rooms[6];
	exits[8].direction = south;
	exits[8].openDoor = false;
	exits[8].name= "Cave";
	exits[8].description= "You can see a big barrier on the final.\n";

	exits[9].source = &rooms[5];
	exits[9].destiny = &rooms[8];
	exits[9].direction = west;
	exits[9].openDoor = true;
	exits[9].name= "Disco room";
	exits[9].description= "It seems to have been unturned to search  something there...\n";

	exits[10].source = &rooms[6];
	exits[10].destiny = &rooms[5];
	exits[10].direction = north;
	exits[10].openDoor = true;
	exits[10].name= "Secret room";
	exits[10].description= "You feel a frozen air coming from it.\n";

	exits[11].source = &rooms[6];
	exits[11].destiny = &rooms[7];
	exits[11].direction = south;
	exits[11].openDoor = true;
	exits[11].name, "Forest";
	exits[11].description, "A big shadow figure is moving in the distance...\n";

	exits[20].source = &rooms[7];
	exits[20].destiny = &rooms[6];
	exits[20].direction = north;
	exits[20].openDoor = true;
	exits[20].name= "Cave";
	exits[20].description= "You can see a big barrier on the final.\n";

	exits[12].source = &rooms[8];
	exits[12].destiny = &rooms[5];
	exits[12].direction = east;
	exits[12].openDoor = true;
	exits[12].name= "Secret room";
	exits[12].description= "You feel a frozen air coming from it.\n";

	exits[13].source = &rooms[8];
	exits[13].destiny = &rooms[9];
	exits[13].direction = south;
	exits[13].openDoor = false;
	exits[13].name, "Bunker";
	exits[13].description, "It looks like resistant...\n";


	exits[14].source = &rooms[8];
	exits[14].destiny = &rooms[2];
	exits[14].direction = west;
	exits[14].openDoor = true;
	exits[14].name, "Living room";
	exits[14].description, "You don't see nothing strange.\n";


	exits[15].source = &rooms[9];
	exits[15].destiny = &rooms[8];
	exits[15].direction = north;
	exits[15].openDoor = false;
	exits[15].name, "Disco room";
	exits[15].description, "It seems to have been unturned to search  something there...\n";


	exits[16].source = &rooms[2];
	exits[16].destiny = &rooms[0];
	exits[16].direction = east;
	exits[16].openDoor = true;
	exits[16].name= "Reception room";
	exits[16].description= "It seems like a big room where you can find things...\n";


	exits[21].source = &rooms[2];
	exits[21].destiny = &rooms[8];
	exits[21].direction = north;
	exits[21].openDoor = true;
	exits[21].name= "Disco room";
	exits[21].description= "It seems to have been unturned to search  something there...\n";


	exits[17].source = &rooms[2];
	exits[17].destiny = &rooms[10];
	exits[17].direction = west;
	exits[17].openDoor = false;
	exits[17].name= "Terrace";
	exits[17].description= "It seems a good exit with an helicopter...\n";


	exits[18].source = &rooms[10];
	exits[18].destiny = &rooms[2];
	exits[18].direction = south;
	exits[18].openDoor = true;
	exits[18].name= "Living room";
	exits[18].description= "You don't see nothing strange.\n";

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
		strcpy_s(second, strtok_s(safe, " ", &trash));
	}
system("cls");
	

	//COMMAND LOOK DIRECTION.


	if (strcmp(first, "look") == 0){
		if (strcmp(second, "void") == 0){
			players->Look();
		}
		else if (strcmp(safe, "north") == 0 || strcmp(second, "n") == 0){
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